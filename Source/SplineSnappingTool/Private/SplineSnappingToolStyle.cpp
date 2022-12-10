//==========================================================================//
// Copyright Elhoussine Mehnik (ue4resources@gmail.com). All Rights Reserved.
//================== http://unrealengineresources.com/ =====================//


#include "SplineSnappingToolStyle.h"
#include "Interfaces/IPluginManager.h"
#include "Styling/SlateStyleRegistry.h"
#include "SlateOptMacros.h"
#include "Styling/SlateTypes.h"
#include "EditorStyleSet.h"


#define IMAGE_BRUSH( RelativePath, ... ) FSlateImageBrush( FSplineSnappingToolStyle::InContent( RelativePath, ".png" ), __VA_ARGS__ )


FString FSplineSnappingToolStyle::InContent(const FString& RelativePath, const ANSICHAR* Extension)
{
	static FString IconsDir = IPluginManager::Get().FindPlugin(TEXT("SplineSnappingTool"))->GetContentDir() / TEXT("Icons");
	return (IconsDir / RelativePath) + Extension;
}

TSharedPtr< FSlateStyleSet > FSplineSnappingToolStyle::StyleSet = NULL;
TSharedPtr< class ISlateStyle > FSplineSnappingToolStyle::Get() { return StyleSet; }


FName FSplineSnappingToolStyle::GetAppStyleSetName()
{
	return StyleSet->GetStyleSetName();
}


BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION

void FSplineSnappingToolStyle::Initialize()
{

	// Const icon
	const FVector2D Icon16x16(16.0f, 16.f);
	const FVector2D Icon40x40(40.f, 40.f);
	const FVector2D Icon128x128(128.f, 128.f);

	// Only register once
	if (StyleSet.IsValid())
	{
		return;
	}

	// Style Set Allocation
	StyleSet = MakeShareable(new FSlateStyleSet("SplineSnappingToolStyle"));
	FString ContentDir = IPluginManager::Get().FindPlugin(TEXT("SplineSnappingTool"))->GetContentDir();
	StyleSet->SetContentRoot(ContentDir);

	// Mode Icons
	StyleSet->Set(TEXT("SplineSnappingToolMode"), new IMAGE_BRUSH("icon_Snap_40x", Icon40x40));
	StyleSet->Set(TEXT("SplineSnappingToolMode.Small"), new IMAGE_BRUSH("icon_Snap_40x", Icon16x16));


	// Button Icons
	StyleSet->Set(TEXT("SplineSnappingTool.SelectSpline"), new IMAGE_BRUSH("icon_Select_40x", Icon40x40));
	StyleSet->Set(TEXT("SplineSnappingTool.SelectSpline.Small"), new IMAGE_BRUSH("icon_Select_40x", Icon16x16));

	StyleSet->Set(TEXT("SplineSnappingTool.ClearSelection"), new IMAGE_BRUSH("icon_Clear_40x", Icon40x40));
	StyleSet->Set(TEXT("SplineSnappingTool.ClearSelection.Small"), new IMAGE_BRUSH("icon_Clear_40x", Icon16x16));

	StyleSet->Set(TEXT("SplineSnappingTool.ResetSettings"), new IMAGE_BRUSH("icon_resettodefault_32x", Icon40x40));
	StyleSet->Set(TEXT("SplineSnappingTool.ResetSettings.Small"), new IMAGE_BRUSH("icon_resettodefault_32x", Icon16x16));

	StyleSet->Set(TEXT("SplineSnappingTool.SaveSettings"), new IMAGE_BRUSH("icon_save_40x", Icon40x40));
	StyleSet->Set(TEXT("SplineSnappingTool.SaveSettings.Small"), new IMAGE_BRUSH("icon_save_40x", Icon16x16));

	// Register Style Set
	FSlateStyleRegistry::RegisterSlateStyle(*StyleSet.Get());
};

END_SLATE_FUNCTION_BUILD_OPTIMIZATION

#undef IMAGE_BRUSH


void FSplineSnappingToolStyle::Shutdown()
{
	if (StyleSet.IsValid())
	{
		FSlateStyleRegistry::UnRegisterSlateStyle(*StyleSet.Get());
		ensure(StyleSet.IsUnique());
		StyleSet.Reset();
	}
}

