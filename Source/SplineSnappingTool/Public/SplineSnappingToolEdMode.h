//==========================================================================//
// Copyright Elhoussine Mehnik (ue4resources@gmail.com). All Rights Reserved.
//================== http://unrealengineresources.com/ =====================//

#pragma once

#include "CoreMinimal.h"
#include "EdMode.h"


class USplineComponent;
class USelection;
class FScopedTransaction;
class FUICommandList;

class FSplineSnappingToolEdMode : public FEdMode
{
public:
	const static FEditorModeID EM_SplineSnappingToolEdModeId;
public:
	FSplineSnappingToolEdMode();
	virtual ~FSplineSnappingToolEdMode();

	// FEdMode interface
	virtual void Initialize() override;
	virtual void Enter() override;
	virtual void Exit() override;
	virtual void Render(const FSceneView* View, FViewport* Viewport, FPrimitiveDrawInterface* PDI);
	virtual bool HandleClick(FEditorViewportClient* InViewportClient, HHitProxy* HitProxy, const FViewportClick& Click);
	virtual bool InputKey(FEditorViewportClient* ViewportClient, FViewport* Viewport, FKey Key, EInputEvent Event) override;
	virtual bool InputAxis(FEditorViewportClient* InViewportClient, FViewport* Viewport, int32 ControllerId, FKey Key, float Delta, float DeltaTime) override;
	virtual bool MouseMove(FEditorViewportClient* ViewportClient, FViewport* Viewport, int32 x, int32 y) override;
	virtual bool LostFocus(FEditorViewportClient* ViewportClient, FViewport* Viewport) override;
	virtual bool IsSelectionAllowed(AActor* InActor, bool bInSelection) const override;
	virtual EAxisList::Type GetWidgetAxisToDraw(UE::Widget::EWidgetMode InWidgetMode) const override;
	virtual bool GetCursor(EMouseCursor::Type& OutCursor) const override;
	virtual void Tick(FEditorViewportClient* ViewportClient, float DeltaTime) override;
	bool UsesToolkits() const override;
	// End of FEdMode interface


public:

	TSharedPtr<FUICommandList> GetUICommandList();

protected:

	void RegisterCommands();
	void UnregisterCommands();
	void SnapSelectedActorsToSpline(FEditorViewportClient* ViewportClient);
	void BeginTransaction(const FText& TransactionName);
	void CancelTransaction();
	void EndTransaction(bool bNotifyChange = true);
	void RefreshViewport();

	void OnEnableSelection();
	bool IsSelectionEnabled() const;

	bool CanClearSelection() const;
	void OnClearSelection();

	bool HasValidSpline();

	void ResetSettingsToDefault();
	bool CanResetSettings() const;

	void SaveSettings();
	bool CanSaveSettings() const;

private:

	TSharedPtr<FUICommandList> SplineSnappingUICommandList;
	FScopedTransaction* ScopedTransaction;
	const USplineComponent* SelectedSplineComp;
	USelection* SelectedActors;
	bool bSnapEnabled;
	bool bSplineHovered;
	bool bCanSelectNewSpline;
	bool bMouseDragging;
};


