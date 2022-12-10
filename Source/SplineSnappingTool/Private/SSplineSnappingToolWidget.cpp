//==========================================================================//
// Copyright Elhoussine Mehnik (ue4resources@gmail.com). All Rights Reserved.
//================== http://unrealengineresources.com/ =====================//

#include "SSplineSnappingToolWidget.h"
#include "PropertyEditorModule.h"
#include "Modules/ModuleManager.h"
#include "Framework/MultiBox/MultiBoxBuilder.h"
#include "Framework/Application/SlateApplication.h"
#include "Widgets/Layout/SBorder.h"
#include "Widgets/SBoxPanel.h"
#include "Widgets/Layout/SScrollBox.h"
#include "Widgets/Layout/SBox.h"
#include "Widgets/Layout/SScaleBox.h"
#include "PropertyCustomizationHelpers.h"
#include "Widgets/Input/SButton.h"
#include "EditorFontGlyphs.h"
#include "Widgets/Images/SImage.h"

#include "SplineSnappingEditorSettings.h"
#include "SplineSnappingToolEdMode.h"
#include "SplineSnappingToolCommands.h"


#define LOCTEXT_NAMESPACE "SplineSnappingToolWidget"


void SSplineSnappingToolWidget::Construct(const FArguments& InArgs, FSplineSnappingToolEdMode* InSplineSnappingMode)
{
	SplineSnappingMode = InSplineSnappingMode;
	CreateSettingsDetailsView();

	ChildSlot
		[
			SNew(SScrollBox)
			+ SScrollBox::Slot()
				[
					SNew(SVerticalBox)
					+ SVerticalBox::Slot()
					.AutoHeight()
						[
							SNew(SBorder)
							.BorderImage(FAppStyle::GetBrush("ToolPanel.DarkGroupBorder"))
								[
									SNew(SVerticalBox)
									+SVerticalBox::Slot()
									.Padding(FMargin(0.f, 4.f))
									.AutoHeight()
										[
											SNew(SBorder)
											.BorderImage(FAppStyle::GetBrush("ToolPanel.DarkGroupBorder"))
											.HAlign(HAlign_Fill)
											.VAlign(VAlign_Fill)
												[
													SNew(SBorder)
													.BorderImage(FAppStyle::GetBrush("ToolPanel.DarkGroupBorder"))
													.HAlign(HAlign_Left)
													.VAlign(VAlign_Center)
														[
															SNew(SHorizontalBox)
															.Clipping(EWidgetClipping::ClipToBounds)
															+ SHorizontalBox::Slot()
															.VAlign(VAlign_Center)
															.Padding(3.f)
															.AutoWidth()
																[
																	SNew(STextBlock)
																	.TextStyle(FAppStyle::Get(), "ContentBrowser.TopBar.Font")
																	.Font( FAppStyle::Get().GetFontStyle( "FontAwesome.10" ) )
																	//.Text( FEditorFontGlyphs::Arrow_Down)
																]
															+ SHorizontalBox::Slot()
															.VAlign(VAlign_Center)
															.Padding(3.f)
															.AutoWidth()
																[
																	SNew(STextBlock)
																	.TextStyle(FAppStyle::Get(), "ContentBrowser.TopBar.Font")
																		.Text(LOCTEXT("SplineSnappingTool_Name", "Spline Snapping Tool"))
																]
														]

												]
											]

								
											+ SVerticalBox::Slot()
												.AutoHeight()
												[
													SNew(SBorder)
													.BorderImage(FAppStyle::GetBrush("ToolPanel.GroupBorder"))
													.HAlign(HAlign_Center)
													.VAlign(VAlign_Fill)
													.Padding(FMargin(2.f))
														[
															CreateToolButtonsWidget()->AsShared()
														]
												]

											+ SVerticalBox::Slot()
												.AutoHeight()
												[
													SNew(SBorder)
													.BorderImage(FAppStyle::GetBrush("ToolPanel.GroupBorder"))
														[
															DetailsPanel->AsShared()
														]
												]
											+ SVerticalBox::Slot()
												.AutoHeight()
												.HAlign(HAlign_Right)
												.Padding(FMargin(8.f, 8.f))
												[
													CreateSettingsBarWidget().ToSharedRef()
												]
										]
								]
						]
				];

											
}





void SSplineSnappingToolWidget::CreateSettingsDetailsView()
{
	FPropertyEditorModule& PropertyEditorModule = FModuleManager::LoadModuleChecked<FPropertyEditorModule>("PropertyEditor");
	FDetailsViewArgs DetailsViewArgs;
	DetailsViewArgs.bUpdatesFromSelection = false;
	DetailsViewArgs.bLockable = false;
	DetailsViewArgs.bAllowSearch = false;
	DetailsViewArgs.NameAreaSettings = FDetailsViewArgs::HideNameArea;
	DetailsViewArgs.bHideSelectionTip = true;

	DetailsPanel = PropertyEditorModule.CreateDetailView(DetailsViewArgs);

	USplineSnappingEditorSettings* SplineSnappingEditorSettings = USplineSnappingEditorSettings::Get();
	DetailsPanel->SetObject(SplineSnappingEditorSettings);
}

TSharedPtr<SWidget> SSplineSnappingToolWidget::CreateToolButtonsWidget()
{
	FToolBarBuilder ToolBar(SplineSnappingMode->GetUICommandList(), FMultiBoxCustomization::None);
	ToolBar.SetLabelVisibility(EVisibility::Collapsed);


	ToolBar.AddToolBarButton(FSplineSnappingToolCommands::Get().SelectSpline);
	ToolBar.AddSeparator();
	ToolBar.AddToolBarButton(FSplineSnappingToolCommands::Get().ClearSelection);

	return ToolBar.MakeWidget();
}
TSharedPtr<SWidget> SSplineSnappingToolWidget::CreateSettingsBarWidget()
{
	FToolBarBuilder Toolbar(SplineSnappingMode->GetUICommandList(), FMultiBoxCustomization::None);
	Toolbar.SetLabelVisibility(EVisibility::Collapsed);
	Toolbar.AddToolBarButton(FSplineSnappingToolCommands::Get().ResetSettings);
	Toolbar.AddSeparator();
	Toolbar.AddToolBarButton(FSplineSnappingToolCommands::Get().SaveSettings);


	return
		SNew(SHorizontalBox)
			+ SHorizontalBox::Slot()
			[
				SNew(SOverlay)
				+ SOverlay::Slot()
				[
					SNew(SBorder)
					.HAlign(HAlign_Center)
					.Padding(0)
					.BorderImage(FAppStyle::GetBrush("NoBorder"))
					.IsEnabled(FSlateApplication::Get().GetNormalExecutionAttribute())
					[
						Toolbar.MakeWidget()
					]
				]
			];
}



#undef LOCTEXT_NAMESPACE 