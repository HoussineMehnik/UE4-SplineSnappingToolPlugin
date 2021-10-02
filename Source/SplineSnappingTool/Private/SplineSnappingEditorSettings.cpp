//==========================================================================//
// Copyright Elhoussine Mehnik (ue4resources@gmail.com). All Rights Reserved.
//================== http://unrealengineresources.com/ =====================//

#include "SplineSnappingEditorSettings.h"


USplineSnappingEditorSettings::USplineSnappingEditorSettings(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	Reinit();
}

USplineSnappingEditorSettings * USplineSnappingEditorSettings::Get()
{
	static USplineSnappingEditorSettings* SplineSnappingEditorSettings = nullptr;

	if (SplineSnappingEditorSettings == nullptr)
	{
		SplineSnappingEditorSettings = GetMutableDefault<USplineSnappingEditorSettings>();
	}

	return SplineSnappingEditorSettings;
}


bool USplineSnappingEditorSettings::HasDefaultSettings() const
{
	return RelativeOffset == FVector::ZeroVector
		&& bUseCustomSpacing == false
		&& Spacing != 0.0f
		&& LocalRotationOffset == FRotator::ZeroRotator
		&& ModifierKey == EKeys::LeftShift
		&& bRotationSnapEnabled == true
		&& MousewheelRotationAxis == EMousewheelRotationAxis::None
		&& RotationSpeed == 360.0f
		&& ScaleSnapMode == ESplineScaleSnappingMode::IgoneSplineScale
		&& SelectionColor == FColor(255, 128, 0);
}

void USplineSnappingEditorSettings::Reinit()
{
	RelativeOffset = FVector(0.0f);
	bUseCustomSpacing = false;
	Spacing = 0.0f;
	LocalRotationOffset = FRotator(0.0f);
	ModifierKey = EKeys::LeftShift;
	bRotationSnapEnabled = true;
	MousewheelRotationAxis = EMousewheelRotationAxis::None;
	RotationSpeed = 360.0f;
	ScaleSnapMode = ESplineScaleSnappingMode::IgoneSplineScale;
	SelectionColor = FColor(255, 128, 0);
}
