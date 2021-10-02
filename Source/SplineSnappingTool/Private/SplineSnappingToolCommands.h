//==========================================================================//
// Copyright Elhoussine Mehnik (ue4resources@gmail.com). All Rights Reserved.
//================== http://unrealengineresources.com/ =====================//

#pragma once

#include "CoreMinimal.h"
#include "Framework/Commands/Commands.h" 
#include "SplineSnappingToolStyle.h"

class FSplineSnappingToolCommands : public TCommands<FSplineSnappingToolCommands>
{
public:
	FSplineSnappingToolCommands()
		: TCommands<FSplineSnappingToolCommands>
		(	"SplineSnappingTool",
			NSLOCTEXT("Contexts", "SplineSnappingTool", "Spline Snapping Tool"),
			NAME_None,
			FSplineSnappingToolStyle::Get()->GetStyleSetName())
	{

	}

	virtual void RegisterCommands() override;

public:

	TSharedPtr<FUICommandInfo> SelectSpline;
	TSharedPtr<FUICommandInfo> ClearSelection;

	TSharedPtr<FUICommandInfo> ResetSettings;
	TSharedPtr<FUICommandInfo> SaveSettings;

};