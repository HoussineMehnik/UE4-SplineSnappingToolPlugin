//==========================================================================//
// Copyright Elhoussine Mehnik (ue4resources@gmail.com). All Rights Reserved.
//================== http://unrealengineresources.com/ =====================//


#include "SplineSnappingToolEdMode.h"
#include "SplineSnappingToolEdModeToolkit.h"
#include "Toolkits/ToolkitManager.h"
#include "EditorModeManager.h"
#include "Components/SplineComponent.h"
#include "EditorViewportClient.h"
#include "Engine/Selection.h"
#include "EngineUtils.h"
#include "ScopedTransaction.h"
#include "SplineSnappingEditorSettings.h"
#include "ComponentVisualizer.h"
#include "SplineSnappingToolCommands.h"
#include "Framework/Application/SlateApplication.h"
#include "SceneView.h"


#define LOCTEXT_NAMESPACE "SplineSnappingToolEdMode"

const FEditorModeID FSplineSnappingToolEdMode::EM_SplineSnappingToolEdModeId = TEXT("EM_SplineSnappingToolEdMode");



template<class T>
T* GetHitProxyUnderMouseCursor(FViewport* Viewport)
{
	if (Viewport != nullptr)
	{
		int32 HitX = Viewport->GetMouseX();
		int32 HitY = Viewport->GetMouseY();
		HHitProxy*	HitProxy = Viewport->GetHitProxy(HitX, HitY);
		if (HitProxy)
		{
			if (HitProxy->IsA(T::StaticGetType()))
			{
				return (T*)HitProxy;
			}
		}
	}
	return nullptr;
}



void CalculateCursorTraceStartEnd(FEditorViewportClient* ViewportClient, FVector& Start, FVector& End)
{
	Start = FVector(0.f, 0.f, 0.f);
	End = FVector(0.f, 0.f, 0.f);

	// Cache a copy of the world pointer	
	UWorld* World = ViewportClient->GetWorld();

	if (World == nullptr)
	{
		return;
	}

	// Compute a world space ray from the screen space mouse coordinates
	FSceneViewFamilyContext ViewFamily(FSceneViewFamilyContext::ConstructionValues(ViewportClient->Viewport, ViewportClient->GetScene(), ViewportClient->EngineShowFlags)
		.SetRealtimeUpdate(ViewportClient->IsRealtime()));

	FSceneView* View = ViewportClient->CalcSceneView(&ViewFamily);
	int32 MouseX = ViewportClient->Viewport->GetMouseX();
	int32 MouseY = ViewportClient->Viewport->GetMouseY();
	FViewportCursorLocation MouseViewportRay(View, ViewportClient, MouseX, MouseY);
	FVector MouseViewportRayDirection = MouseViewportRay.GetDirection();

	Start = MouseViewportRay.GetOrigin();
	End = Start + WORLD_MAX * MouseViewportRayDirection;
	if (ViewportClient->IsOrtho())
	{
		Start -= WORLD_MAX * MouseViewportRayDirection;
	}
}


float GetDistanceAlongSplineAtSplineInputKey(float InKey, const USplineComponent* SplineComp)
{
	// To check later 
	// Not a safe method !
	const int32 PrevPointIndex = (int32)(InKey);
	const int32 NextPointIndex = PrevPointIndex + 1;
	const float DistanceAtPrevPoint = SplineComp->GetDistanceAlongSplineAtSplinePoint(PrevPointIndex);
	const float DistanceAtNextpointPoint = SplineComp->GetDistanceAlongSplineAtSplinePoint(NextPointIndex);

	return DistanceAtPrevPoint + (DistanceAtNextpointPoint - DistanceAtPrevPoint)*(InKey - static_cast<float>(PrevPointIndex));
}



FSplineSnappingToolEdMode::FSplineSnappingToolEdMode()
	: SplineSnappingUICommandList(nullptr)
	, ScopedTransaction(nullptr)
	, SelectedSplineComp(nullptr)
	, SelectedActors(nullptr)
	, bSnapEnabled(false)
	, bSplineHovered(false)
	, bCanSelectNewSpline(false)
	, bMouseDragging(false)
{

}

FSplineSnappingToolEdMode::~FSplineSnappingToolEdMode()
{
	UnregisterCommands();
}

void FSplineSnappingToolEdMode::Initialize()
{
	FSplineSnappingToolCommands::Register();
	SplineSnappingUICommandList = TSharedPtr<FUICommandList>(new FUICommandList());
	RegisterCommands();
}

void FSplineSnappingToolEdMode::Enter()
{
	bMouseDragging = false;
	bSplineHovered = false;
	bSnapEnabled = false;
	bCanSelectNewSpline = false;
	SelectedSplineComp = nullptr;
	SelectedActors = nullptr;
	ScopedTransaction = nullptr;

	FEdMode::Enter();

	if (!Toolkit.IsValid() && UsesToolkits())
	{
		Initialize();
		Toolkit = MakeShareable(new FSplineSnappingToolEdModeToolkit);
		Toolkit->Init(Owner->GetToolkitHost());
	}
}

void FSplineSnappingToolEdMode::Exit()
{
	bMouseDragging = false;
	bSplineHovered = false;
	bSnapEnabled = false;
	bCanSelectNewSpline = false;
	SelectedSplineComp = nullptr;
	SelectedActors = nullptr;
	CancelTransaction();


	if (Toolkit.IsValid())
	{
		FToolkitManager::Get().CloseToolkit(Toolkit.ToSharedRef());
		Toolkit.Reset();
	}

	// Call base Exit method to ensure proper cleanup
	FEdMode::Exit();
}

void FSplineSnappingToolEdMode::Render(const FSceneView* View, FViewport* Viewport, FPrimitiveDrawInterface* PDI)
{
	if (HasValidSpline())
	{
		const USplineSnappingEditorSettings* SplineSnappingEditorSettings = USplineSnappingEditorSettings::Get();
		USplineComponent::Draw(PDI, View, SelectedSplineComp->GetSplinePointsPosition(), SelectedSplineComp->GetComponentTransform().ToMatrixWithScale(), SplineSnappingEditorSettings->SelectionColor, SDPG_Foreground);
	}

	FEdMode::Render(View, Viewport, PDI);
}

bool FSplineSnappingToolEdMode::HandleClick(FEditorViewportClient* InViewportClient, HHitProxy* HitProxy, const FViewportClick& Click)
{
	if (bCanSelectNewSpline && HitProxy != nullptr)
	{
		if (HActor* ActorHit = HitProxyCast<HActor>(HitProxy))
		{
			if (ActorHit->Actor && ActorHit->PrimComponent)
			{
				if (const USplineComponent* SplineComp = Cast<USplineComponent>(ActorHit->PrimComponent))
				{
					SelectedSplineComp = SplineComp;
					bCanSelectNewSpline = false;
					return true;
				}
			}
		}
		else if (HComponentVisProxy* SplineVisProxy = (HComponentVisProxy*)(HitProxy))
		{
			if (const USplineComponent* SplineComp = Cast<const USplineComponent>(SplineVisProxy->Component.Get()))
			{
				SelectedSplineComp = SplineComp;
				bCanSelectNewSpline = false;
				GEditor->SelectActor(SplineComp->GetOwner(), false, true, true, true);
				return true;
			}
		}
	}

	return FEdMode::HandleClick(InViewportClient, HitProxy, Click);
}

bool FSplineSnappingToolEdMode::InputKey(FEditorViewportClient* ViewportClient, FViewport* Viewport, FKey Key, EInputEvent Event)
{


	const USplineSnappingEditorSettings* SplineSnappingEditorSettings = USplineSnappingEditorSettings::Get();

	if (Key == SplineSnappingEditorSettings->ModifierKey)
	{
		if (Event == IE_Pressed && HasValidSpline())
		{
			SelectedActors = GEditor->GetSelectedActors();

			if (SelectedActors != nullptr && SelectedActors->Num() > 0)
			{

				BeginTransaction(LOCTEXT("SplineSnappingToolEdMode_SnappingSelectedActors", "Snapping Selected Actors To Spline"));

				for (FSelectionIterator Iter(*SelectedActors); Iter; ++Iter)
				{
					if (AActor* SelectedActor = Cast<AActor>(*Iter))
					{
						if (SelectedSplineComp->GetOwner() == SelectedActor)
						{
							continue;
						}

						SelectedActor->Modify();
					}
				}

				bSnapEnabled = true;
			}
			else
			{
				SelectedActors = nullptr;
			}
		}
		else if (Event == IE_Released)
		{
			if (bSnapEnabled)
			{
				EndTransaction();
			}
			else
			{
				CancelTransaction();
			}

			bSnapEnabled = false;
			SelectedActors = nullptr;
		}
	}


	if (Key == EKeys::MouseScrollUp || Key == EKeys::MouseScrollDown)
	{
		if (bSnapEnabled
			&& HasValidSpline()
			&& SplineSnappingEditorSettings->bRotationSnapEnabled
			&& SplineSnappingEditorSettings->MousewheelRotationAxis != EMousewheelRotationAxis::None
			&& SplineSnappingEditorSettings->RotationSpeed > 0)
		{
			return true;
		}
	}

	if (Event == IE_Pressed)
	{
		if (SplineSnappingUICommandList->ProcessCommandBindings(Key, FSlateApplication::Get().GetModifierKeys(), false))
		{
			return true;
		}
	}

	return FEdMode::InputKey(ViewportClient, Viewport, Key, Event);
}

bool FSplineSnappingToolEdMode::InputAxis(FEditorViewportClient* InViewportClient, FViewport* Viewport, int32 ControllerId, FKey Key, float Delta, float DeltaTime)
{
	if (bSnapEnabled && HasValidSpline() && Key == EKeys::MouseWheelAxis)
	{
		if (USplineSnappingEditorSettings* SplineSnappingEditorSettings = USplineSnappingEditorSettings::Get())
		{
			double* AxisPtr = nullptr;

			if (SplineSnappingEditorSettings->MousewheelRotationAxis != EMousewheelRotationAxis::None && SplineSnappingEditorSettings->RotationSpeed > 0)
			{
				switch (SplineSnappingEditorSettings->MousewheelRotationAxis)
				{
				case EMousewheelRotationAxis::X:
					AxisPtr = &SplineSnappingEditorSettings->LocalRotationOffset.Roll;
					break;
				case EMousewheelRotationAxis::Y:
					AxisPtr = &SplineSnappingEditorSettings->LocalRotationOffset.Pitch;
					break;
				case EMousewheelRotationAxis::Z:
					AxisPtr = &SplineSnappingEditorSettings->LocalRotationOffset.Yaw;
					break;
				}
			}

			if (AxisPtr != nullptr)
			{
				*AxisPtr += (SplineSnappingEditorSettings->RotationSpeed * DeltaTime * Delta);

				SnapSelectedActorsToSpline(InViewportClient);

				if (!InViewportClient->IsRealtime())
					RefreshViewport();

				return true;
			}
		}
	}

	return FEdMode::InputAxis(InViewportClient, Viewport, ControllerId, Key, Delta, DeltaTime);
}

bool FSplineSnappingToolEdMode::MouseMove(FEditorViewportClient* ViewportClient, FViewport* Viewport, int32 x, int32 y)
{
	if (ViewportClient != nullptr)
	{
		if (ViewportClient->IsRealtime())
		{
			if (bSnapEnabled)
			{
				bMouseDragging = true;
				SnapSelectedActorsToSpline(ViewportClient);
			}
		}
		else if (bSnapEnabled)
		{
			SnapSelectedActorsToSpline(ViewportClient);
			RefreshViewport();
		}

	}

	return FEdMode::MouseMove(ViewportClient, Viewport, x, y);
}


bool FSplineSnappingToolEdMode::LostFocus(FEditorViewportClient* ViewportClient, FViewport* Viewport)
{
	if (bSnapEnabled)
	{
		EndTransaction();
		bSnapEnabled = false;
		SelectedActors = nullptr;
	}

	return FEdMode::LostFocus(ViewportClient, Viewport);
}

bool FSplineSnappingToolEdMode::IsSelectionAllowed(AActor* InActor, bool bInSelection) const
{
	if (bSnapEnabled || bCanSelectNewSpline)
	{
		return false;
	}

	return true;
}

EAxisList::Type FSplineSnappingToolEdMode::GetWidgetAxisToDraw(UE::Widget::EWidgetMode InWidgetMode) const
{
	if (bSnapEnabled)
	{
		return EAxisList::None;
	}

	return FEdMode::GetWidgetAxisToDraw(InWidgetMode);
}

bool FSplineSnappingToolEdMode::GetCursor(EMouseCursor::Type& OutCursor) const
{
	if (bCanSelectNewSpline)
	{
		OutCursor = bSplineHovered ? EMouseCursor::EyeDropper : EMouseCursor::Hand;
		return true;
	}

	return FEdMode::GetCursor(OutCursor);
}

void FSplineSnappingToolEdMode::Tick(FEditorViewportClient* ViewportClient, float DeltaTime)
{
	FEdMode::Tick(ViewportClient, DeltaTime);

	if (bSplineHovered)
	{
		bSplineHovered = false;
	}


	if (ViewportClient != nullptr)
	{
		if (bSnapEnabled && bMouseDragging)
		{
			//SnapSelectedActorsToSpline(ViewportClient);
		}
		else if (bCanSelectNewSpline)
		{
			if (HActor* HitActor = GetHitProxyUnderMouseCursor<HActor>(ViewportClient->Viewport))
			{
				if (HitActor->PrimComponent != nullptr && HitActor->PrimComponent->IsA<USplineComponent>())
				{
					bSplineHovered = true;
				}
			}
			else if (HComponentVisProxy* PrimComponentVisProxy = GetHitProxyUnderMouseCursor<HComponentVisProxy>(ViewportClient->Viewport))
			{
				if (PrimComponentVisProxy->Component.IsValid() && PrimComponentVisProxy->Component.Get()->IsA<USplineComponent>())
				{
					bSplineHovered = true;
				}
			}
		}
	}

	if (bMouseDragging)
	{
		bMouseDragging = false;
	}
}

bool FSplineSnappingToolEdMode::UsesToolkits() const
{
	return true;
}


TSharedPtr<FUICommandList> FSplineSnappingToolEdMode::GetUICommandList()
{
	return SplineSnappingUICommandList;
}

void FSplineSnappingToolEdMode::RegisterCommands()
{
	const FSplineSnappingToolCommands& Commands = FSplineSnappingToolCommands::Get();


	SplineSnappingUICommandList->MapAction(
		Commands.SelectSpline,
		FExecuteAction::CreateSP(this, &FSplineSnappingToolEdMode::OnEnableSelection),
		FCanExecuteAction(),
		FIsActionChecked::CreateSP(this, &FSplineSnappingToolEdMode::IsSelectionEnabled)

	);


	SplineSnappingUICommandList->MapAction(
		Commands.ClearSelection,
		FExecuteAction::CreateSP(this, &FSplineSnappingToolEdMode::OnClearSelection),
		FCanExecuteAction::CreateSP(this, &FSplineSnappingToolEdMode::CanClearSelection)
	);


	SplineSnappingUICommandList->MapAction(
		Commands.ResetSettings,
		FExecuteAction::CreateSP(this, &FSplineSnappingToolEdMode::ResetSettingsToDefault),
		FCanExecuteAction::CreateSP(this, &FSplineSnappingToolEdMode::CanResetSettings)
	);

	SplineSnappingUICommandList->MapAction(
		Commands.SaveSettings,
		FExecuteAction::CreateSP(this, &FSplineSnappingToolEdMode::SaveSettings),
		FCanExecuteAction::CreateSP(this, &FSplineSnappingToolEdMode::CanSaveSettings)
	);

}

void FSplineSnappingToolEdMode::UnregisterCommands()
{
	FSplineSnappingToolCommands::Unregister();
}

void FSplineSnappingToolEdMode::SnapSelectedActorsToSpline(FEditorViewportClient* ViewportClient)
{
	if (HasValidSpline() && SelectedActors != nullptr && SelectedActors->Num() > 0)
	{
		FVector CursorStart(0);
		FVector CursorEnd(0);
		CalculateCursorTraceStartEnd(ViewportClient, CursorStart, CursorEnd);

		const int32 NumSubdivisions = 20;
		const int32 NumSplinePoints = SelectedSplineComp->GetNumberOfSplinePoints();
		const float SplineLength = SelectedSplineComp->GetSplineLength();

		float TempDistance = TNumericLimits<float>::Max();
		FVector  ClosestLocation = SelectedSplineComp->GetLocationAtSplineInputKey(0, ESplineCoordinateSpace::World);

		for (int32 PointIdx = 0; PointIdx < NumSplinePoints; PointIdx++)
		{
			float SubsegmentStartKey = static_cast<float>(PointIdx);
			FVector SubsegmentStart = SelectedSplineComp->GetLocationAtSplineInputKey(SubsegmentStartKey, ESplineCoordinateSpace::World);

			for (int32 Step = 1; Step < NumSubdivisions; Step++)
			{
				const float SubsegmentEndKey = PointIdx + Step / static_cast<float>(NumSubdivisions);
				const FVector SubsegmentEnd = SelectedSplineComp->GetLocationAtSplineInputKey(SubsegmentEndKey, ESplineCoordinateSpace::World);

				FVector SplineClosest;
				FVector RayClosest;
				FMath::SegmentDistToSegmentSafe(SubsegmentStart, SubsegmentEnd, CursorStart, CursorEnd, SplineClosest, RayClosest);

				const float Distance = FVector::DistSquared(SplineClosest, RayClosest);
				if (Distance < TempDistance)
				{
					TempDistance = Distance;
					ClosestLocation = SplineClosest;
				}

				SubsegmentStartKey = SubsegmentEndKey;
				SubsegmentStart = SubsegmentEnd;
			}

		}



		const USplineSnappingEditorSettings* SplineSnappingEditorSettings = USplineSnappingEditorSettings::Get();
		const bool bUseSplineRotation = SplineSnappingEditorSettings->bRotationSnapEnabled;
		const bool bUseSplineScale = (SplineSnappingEditorSettings->ScaleSnapMode != ESplineScaleSnappingMode::IgoneSplineScale);
		const FVector RelativeOffset = SplineSnappingEditorSettings->RelativeOffset;
		const FQuat LocalRotationOffset = SplineSnappingEditorSettings->LocalRotationOffset.Quaternion();
		const bool bUseCustomSpacing = SplineSnappingEditorSettings->bUseCustomSpacing;
		const float MultiSelectSpacing = bUseCustomSpacing ? SplineSnappingEditorSettings->Spacing : (SelectedActors->Num() > 1 ? SplineLength / static_cast<float>(SelectedActors->Num()) : 0.0f);


		const float ClosestInputKey = SelectedSplineComp->FindInputKeyClosestToWorldLocation(ClosestLocation);
		const float ClosestDistance = GetDistanceAlongSplineAtSplineInputKey(ClosestInputKey, SelectedSplineComp);
		FVector  BestLocation = SelectedSplineComp->GetLocationAtSplineInputKey(ClosestInputKey, ESplineCoordinateSpace::World);
		FQuat BestRotation = SelectedSplineComp->GetQuaternionAtSplineInputKey(ClosestInputKey, ESplineCoordinateSpace::World);
		FVector BestScale(SplineSnappingEditorSettings->ScaleSnapMode == ESplineScaleSnappingMode::UseSplineScaleY ?
			SelectedSplineComp->GetScaleAtSplineInputKey(ClosestInputKey).Y : SelectedSplineComp->GetScaleAtSplineInputKey(ClosestInputKey).Z);

		FVector BestLocationWithOffset = BestLocation
			+ BestRotation.GetAxisX() * RelativeOffset.X
			+ BestRotation.GetAxisY() * RelativeOffset.Y
			+ BestRotation.GetAxisZ() * RelativeOffset.Z;


		float RunningIndex = 0.0f;
		// For each selected actor
		for (FSelectionIterator Iter(*SelectedActors); Iter; ++Iter)
		{
			if (AActor* SelectedActor = Cast<AActor>(*Iter))
			{
				if (SelectedSplineComp->GetOwner() != SelectedActor)
				{

					if (MultiSelectSpacing != 0.0f)
					{
						const float NewDistance = FMath::Fmod(ClosestDistance + MultiSelectSpacing*RunningIndex, SplineLength);
						BestLocation = SelectedSplineComp->GetLocationAtDistanceAlongSpline(NewDistance, ESplineCoordinateSpace::World);
						BestRotation = SelectedSplineComp->GetQuaternionAtDistanceAlongSpline(NewDistance, ESplineCoordinateSpace::World);
						BestScale = FVector(SplineSnappingEditorSettings->ScaleSnapMode == ESplineScaleSnappingMode::UseSplineScaleY ?
							SelectedSplineComp->GetScaleAtDistanceAlongSpline(NewDistance).Y : SelectedSplineComp->GetScaleAtDistanceAlongSpline(NewDistance).Z);

						BestLocationWithOffset = BestLocation
							+ BestRotation.GetAxisX() * RelativeOffset.X
							+ BestRotation.GetAxisY() * RelativeOffset.Y
							+ BestRotation.GetAxisZ() * RelativeOffset.Z;
					}

					SelectedActor->SetActorLocation(BestLocationWithOffset);

					if (bUseSplineRotation)
					{
						SelectedActor->SetActorRotation(BestRotation);
						SelectedActor->AddActorLocalRotation(LocalRotationOffset);
					}

					if (bUseSplineScale)
					{
						SelectedActor->SetActorScale3D(BestScale);
					}

					SelectedActor->PostEditChange();

					RunningIndex += 1.0f;
				}
			}
		}
	}
}

void FSplineSnappingToolEdMode::BeginTransaction(const FText& TransactionName)
{
	if (ScopedTransaction != nullptr)
	{
		EndTransaction(false);
	}

	if (ScopedTransaction == nullptr)
	{
		ScopedTransaction = new FScopedTransaction(TransactionName);
		
		for (FSelectionIterator Iter(*SelectedActors); Iter; ++Iter)
		{
			if (AActor* SelectedActor = Cast<AActor>(*Iter))
			{
				if (SelectedSplineComp->GetOwner() != SelectedActor)
				{
					SelectedActor->Modify();
				}
			}
		}

	}
}

void FSplineSnappingToolEdMode::CancelTransaction()
{
	if (ScopedTransaction != nullptr)
	{
		ScopedTransaction->Cancel();
		if (ScopedTransaction != nullptr)
		{
			delete ScopedTransaction;
			ScopedTransaction = nullptr;
		}
	}
}

void FSplineSnappingToolEdMode::EndTransaction(bool bNotifyChange /*= true*/)
{
	if (ScopedTransaction != nullptr)
	{
		delete ScopedTransaction;
		ScopedTransaction = nullptr;
		RefreshViewport();
	}

	if (bNotifyChange)
	{

		const USplineComponent* SplineComp = HasValidSpline() ? SelectedSplineComp : nullptr;

		for (FSelectionIterator Iter(*SelectedActors); Iter; ++Iter)
		{
			if (AActor* SelectedActor = Cast<AActor>(*Iter))
			{
				if (SplineComp != nullptr && SplineComp->GetOwner() == SelectedActor)
				{
					continue;
				}

				SelectedActor->PostEditChange();
			}
		}
	}
}

void FSplineSnappingToolEdMode::RefreshViewport()
{
	if (GEditor)
	{
		GEditor->RedrawLevelEditingViewports(false);
	}
}

void FSplineSnappingToolEdMode::OnEnableSelection()
{
	bCanSelectNewSpline = true;
	RefreshViewport();
}

bool FSplineSnappingToolEdMode::IsSelectionEnabled() const
{
	return bCanSelectNewSpline;
}

bool FSplineSnappingToolEdMode::CanClearSelection() const
{
	return (bCanSelectNewSpline || SelectedSplineComp != nullptr);
}

void FSplineSnappingToolEdMode::OnClearSelection()
{
	bCanSelectNewSpline = false;
	SelectedSplineComp = nullptr;
	RefreshViewport();
}

bool FSplineSnappingToolEdMode::HasValidSpline()
{
	if (IsValid(SelectedSplineComp) && SelectedSplineComp->IsUnreachable())
	{
		SelectedSplineComp = nullptr;
	}
	return (SelectedSplineComp != nullptr);
}

void FSplineSnappingToolEdMode::ResetSettingsToDefault()
{
	if (USplineSnappingEditorSettings* SplineSnappingEditorSettings = USplineSnappingEditorSettings::Get())
	{
		SplineSnappingEditorSettings->Reinit();
	}
}


bool FSplineSnappingToolEdMode::CanResetSettings() const
{
	if (const USplineSnappingEditorSettings* SplineSnappingEditorSettings = USplineSnappingEditorSettings::Get())
	{
		return !SplineSnappingEditorSettings->HasDefaultSettings();
	}
	return false;
}


void FSplineSnappingToolEdMode::SaveSettings()
{
	if (USplineSnappingEditorSettings* SplineSnappingEditorSettings = USplineSnappingEditorSettings::Get())
	{
		SplineSnappingEditorSettings->SaveConfig();
	}
}

bool FSplineSnappingToolEdMode::CanSaveSettings() const
{
	return true;
}

#undef LOCTEXT_NAMESPACE