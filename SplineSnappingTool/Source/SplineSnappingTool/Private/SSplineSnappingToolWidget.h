// Copyright 2015 Elhoussine Mehnik (Mhousse1247). All Rights Reserved.
//******************* http://ue4resources.com/ *********************//

#pragma once

#include "Widgets/SCompoundWidget.h"
#include "Widgets/DeclarativeSyntaxSupport.h"


class IDetailsView;
class FSplineSnappingToolEdMode;

class SSplineSnappingToolWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SSplineSnappingToolWidget) {}
	SLATE_END_ARGS()

		/** Slate widget construction */
		void Construct(const FArguments& InArgs, FSplineSnappingToolEdMode* InSplineSnappingMode);


protected:
	FSplineSnappingToolEdMode* SplineSnappingMode;
	TSharedPtr<SWidget> ToolkitWidget;
	TSharedPtr<IDetailsView> DetailsPanel;

private:

	void CreateSettingsDetailsView();
	TSharedPtr<SWidget> CreateToolButtonsWidget();
	TSharedPtr<SWidget> CreateSettingsBarWidget();
};