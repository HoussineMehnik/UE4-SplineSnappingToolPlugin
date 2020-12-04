// Copyright 2015 Elhoussine Mehnik (Mhousse1247). All Rights Reserved.
//******************* http://ue4resources.com/ *********************//

#pragma once

class FSplineSnappingToolStyle
{

private:
	static TSharedPtr< class FSlateStyleSet > StyleSet;

public:
	static void Initialize();
	static void Shutdown();
	static TSharedPtr< class ISlateStyle > Get();
	static FName GetStyleSetName();

private:
	static FString InContent(const FString& RelativePath, const ANSICHAR* Extension);
};