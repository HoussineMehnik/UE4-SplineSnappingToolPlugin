//==========================================================================//
// Copyright Elhoussine Mehnik (ue4resources@gmail.com). All Rights Reserved.
//================== http://unrealengineresources.com/ =====================//

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "InputCoreTypes.h"
#include "SplineSnappingEditorSettings.generated.h"




UENUM()
enum class ESplineScaleSnappingMode : uint8
{
	IgoneSplineScale,
	UseSplineScaleY,
	UseSplineScaleZ
};

UENUM()
enum class EMousewheelRotationAxis: uint8
{
	None,
	X,
	Y,
	Z
};



UCLASS(config = EditorPerProjectUserSettings)
class SPLINESNAPPINGTOOL_API USplineSnappingEditorSettings : public UObject
{
	GENERATED_UCLASS_BODY()


public:

	static USplineSnappingEditorSettings * Get();

public:

	UPROPERTY(config, EditAnywhere, Category = "Snapping Settings")
		FVector RelativeOffset;


	UPROPERTY(config, EditAnywhere, Category = "Snapping Settings", meta = (InlineEditConditionToggle))
		bool bUseCustomSpacing;

	UPROPERTY(config, EditAnywhere, Category = "Snapping Settings", meta = (ClampMin = "0.0", UIMin = "0.0", EditCondition = "bUseCustomSpacing"))
		float Spacing;

	UPROPERTY(config, EditAnywhere, Category = "Snapping Settings", meta = (InlineEditConditionToggle))
		bool bRotationSnapEnabled;

	UPROPERTY(config, EditAnywhere, Category = "Snapping Settings", meta = (EditCondition = "bRotationSnapEnabled"))
		FRotator LocalRotationOffset;

	UPROPERTY(config, EditAnywhere, Category = "Snapping Settings")
		ESplineScaleSnappingMode ScaleSnapMode;


	UPROPERTY(config, EditAnywhere, Category = "Editor Settings", meta = (EditCondition = "bRotationSnapEnabled"))
		EMousewheelRotationAxis MousewheelRotationAxis;

	UPROPERTY(config, EditAnywhere, Category = "Editor Settings", meta = (ClampMin = "1.0", UIMin = "1.0", ClampMax = "180.0", UIMax = "180.0", EditCondition = "bRotationSnapEnabled"))
		float RotationSpeed;

	UPROPERTY(config, EditAnywhere, Category = "Editor Settings")
		FKey ModifierKey;

	UPROPERTY(config, EditAnywhere, meta = (HideAlphaChannel), Category = "Editor Settings")
		FColor SelectionColor;


public:
	void Reinit();
	bool HasDefaultSettings() const;
};
