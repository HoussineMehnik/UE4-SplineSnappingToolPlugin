//==========================================================================//
// Copyright Elhoussine Mehnik (ue4resources@gmail.com). All Rights Reserved.
//================== http://unrealengineresources.com/ =====================//

#include "SplineSnappingToolCommands.h"

#define LOCTEXT_NAMESPACE "SplineSnappingToolCommands"

void FSplineSnappingToolCommands::RegisterCommands()
{
	UI_COMMAND(SelectSpline, "Select Spline", "Select New Spline Component", EUserInterfaceActionType::RadioButton, FInputChord(EKeys::S));
	UI_COMMAND(ClearSelection, "Clear Selection", "Clear Selected Spline Or Exit Selection Mode", EUserInterfaceActionType::Button, FInputChord(EKeys::Escape));

	UI_COMMAND(ResetSettings, "Reset Settings", "Reset Settings To Default", EUserInterfaceActionType::Button, FInputChord());
	UI_COMMAND(SaveSettings, "Save Settings", "Save Settings", EUserInterfaceActionType::Button, FInputChord());


}

#undef LOCTEXT_NAMESPACE