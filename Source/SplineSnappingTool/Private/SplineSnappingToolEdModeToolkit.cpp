//==========================================================================//
// Copyright Elhoussine Mehnik (ue4resources@gmail.com). All Rights Reserved.
//================== http://unrealengineresources.com/ =====================//


#include "SplineSnappingToolEdModeToolkit.h"
#include "SplineSnappingToolEdMode.h"
#include "Engine/Selection.h"
#include "Widgets/Input/SButton.h"
#include "Widgets/Text/STextBlock.h"
#include "EditorModeManager.h"
#include "PropertyEditorModule.h"
#include "IDetailsView.h"
#include "SplineSnappingEditorSettings.h"
#include "SSplineSnappingToolWidget.h"

#define LOCTEXT_NAMESPACE "FSplineSnappingToolEdModeToolkit"

FSplineSnappingToolEdModeToolkit::FSplineSnappingToolEdModeToolkit()
{
}

void FSplineSnappingToolEdModeToolkit::Init(const TSharedPtr<IToolkitHost>& InitToolkitHost)
{
	FSplineSnappingToolEdMode* SplineSnappingEditorMode = (FSplineSnappingToolEdMode*)(GetEditorMode());
	SAssignNew(ToolkitWidget, SSplineSnappingToolWidget, SplineSnappingEditorMode);
	FModeToolkit::Init(InitToolkitHost);
}

FName FSplineSnappingToolEdModeToolkit::GetToolkitFName() const
{
	return FName("SplineSnappingToolEdMode");
}

FText FSplineSnappingToolEdModeToolkit::GetBaseToolkitName() const
{
	return NSLOCTEXT("SplineSnappingToolEdModeToolkit", "DisplayName", "SplineSnappingToolEdMode Tool");
}

class FEdMode* FSplineSnappingToolEdModeToolkit::GetEditorMode() const
{
	return GLevelEditorModeTools().GetActiveMode(FSplineSnappingToolEdMode::EM_SplineSnappingToolEdModeId);
}

#undef LOCTEXT_NAMESPACE
