// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SplineSnappingTool/Public/SplineSnappingEditorSettings.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSplineSnappingEditorSettings() {}
// Cross Module References
	SPLINESNAPPINGTOOL_API UEnum* Z_Construct_UEnum_SplineSnappingTool_EMousewheelRotationAxis();
	UPackage* Z_Construct_UPackage__Script_SplineSnappingTool();
	SPLINESNAPPINGTOOL_API UEnum* Z_Construct_UEnum_SplineSnappingTool_ESplineScaleSnappingMode();
	SPLINESNAPPINGTOOL_API UClass* Z_Construct_UClass_USplineSnappingEditorSettings_NoRegister();
	SPLINESNAPPINGTOOL_API UClass* Z_Construct_UClass_USplineSnappingEditorSettings();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FRotator();
	INPUTCORE_API UScriptStruct* Z_Construct_UScriptStruct_FKey();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FColor();
// End Cross Module References
	static UEnum* EMousewheelRotationAxis_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_SplineSnappingTool_EMousewheelRotationAxis, Z_Construct_UPackage__Script_SplineSnappingTool(), TEXT("EMousewheelRotationAxis"));
		}
		return Singleton;
	}
	template<> SPLINESNAPPINGTOOL_API UEnum* StaticEnum<EMousewheelRotationAxis>()
	{
		return EMousewheelRotationAxis_StaticEnum();
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_EMousewheelRotationAxis(EMousewheelRotationAxis_StaticEnum, TEXT("/Script/SplineSnappingTool"), TEXT("EMousewheelRotationAxis"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_SplineSnappingTool_EMousewheelRotationAxis_Hash() { return 828454987U; }
	UEnum* Z_Construct_UEnum_SplineSnappingTool_EMousewheelRotationAxis()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_SplineSnappingTool();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("EMousewheelRotationAxis"), 0, Get_Z_Construct_UEnum_SplineSnappingTool_EMousewheelRotationAxis_Hash(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "EMousewheelRotationAxis::None", (int64)EMousewheelRotationAxis::None },
				{ "EMousewheelRotationAxis::X", (int64)EMousewheelRotationAxis::X },
				{ "EMousewheelRotationAxis::Y", (int64)EMousewheelRotationAxis::Y },
				{ "EMousewheelRotationAxis::Z", (int64)EMousewheelRotationAxis::Z },
			};
#if WITH_METADATA
			const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "ModuleRelativePath", "Public/SplineSnappingEditorSettings.h" },
				{ "None.Name", "EMousewheelRotationAxis::None" },
				{ "X.Name", "EMousewheelRotationAxis::X" },
				{ "Y.Name", "EMousewheelRotationAxis::Y" },
				{ "Z.Name", "EMousewheelRotationAxis::Z" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_SplineSnappingTool,
				nullptr,
				"EMousewheelRotationAxis",
				"EMousewheelRotationAxis",
				Enumerators,
				UE_ARRAY_COUNT(Enumerators),
				RF_Public|RF_Transient|RF_MarkAsNative,
				EEnumFlags::None,
				UE4CodeGen_Private::EDynamicType::NotDynamic,
				(uint8)UEnum::ECppForm::EnumClass,
				METADATA_PARAMS(Enum_MetaDataParams, UE_ARRAY_COUNT(Enum_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUEnum(ReturnEnum, EnumParams);
		}
		return ReturnEnum;
	}
	static UEnum* ESplineScaleSnappingMode_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_SplineSnappingTool_ESplineScaleSnappingMode, Z_Construct_UPackage__Script_SplineSnappingTool(), TEXT("ESplineScaleSnappingMode"));
		}
		return Singleton;
	}
	template<> SPLINESNAPPINGTOOL_API UEnum* StaticEnum<ESplineScaleSnappingMode>()
	{
		return ESplineScaleSnappingMode_StaticEnum();
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_ESplineScaleSnappingMode(ESplineScaleSnappingMode_StaticEnum, TEXT("/Script/SplineSnappingTool"), TEXT("ESplineScaleSnappingMode"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_SplineSnappingTool_ESplineScaleSnappingMode_Hash() { return 2022086339U; }
	UEnum* Z_Construct_UEnum_SplineSnappingTool_ESplineScaleSnappingMode()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_SplineSnappingTool();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("ESplineScaleSnappingMode"), 0, Get_Z_Construct_UEnum_SplineSnappingTool_ESplineScaleSnappingMode_Hash(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "ESplineScaleSnappingMode::IgoneSplineScale", (int64)ESplineScaleSnappingMode::IgoneSplineScale },
				{ "ESplineScaleSnappingMode::UseSplineScaleY", (int64)ESplineScaleSnappingMode::UseSplineScaleY },
				{ "ESplineScaleSnappingMode::UseSplineScaleZ", (int64)ESplineScaleSnappingMode::UseSplineScaleZ },
			};
#if WITH_METADATA
			const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "IgoneSplineScale.Name", "ESplineScaleSnappingMode::IgoneSplineScale" },
				{ "ModuleRelativePath", "Public/SplineSnappingEditorSettings.h" },
				{ "UseSplineScaleY.Name", "ESplineScaleSnappingMode::UseSplineScaleY" },
				{ "UseSplineScaleZ.Name", "ESplineScaleSnappingMode::UseSplineScaleZ" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_SplineSnappingTool,
				nullptr,
				"ESplineScaleSnappingMode",
				"ESplineScaleSnappingMode",
				Enumerators,
				UE_ARRAY_COUNT(Enumerators),
				RF_Public|RF_Transient|RF_MarkAsNative,
				EEnumFlags::None,
				UE4CodeGen_Private::EDynamicType::NotDynamic,
				(uint8)UEnum::ECppForm::EnumClass,
				METADATA_PARAMS(Enum_MetaDataParams, UE_ARRAY_COUNT(Enum_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUEnum(ReturnEnum, EnumParams);
		}
		return ReturnEnum;
	}
	void USplineSnappingEditorSettings::StaticRegisterNativesUSplineSnappingEditorSettings()
	{
	}
	UClass* Z_Construct_UClass_USplineSnappingEditorSettings_NoRegister()
	{
		return USplineSnappingEditorSettings::StaticClass();
	}
	struct Z_Construct_UClass_USplineSnappingEditorSettings_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_RelativeOffset_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_RelativeOffset;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bUseCustomSpacing_MetaData[];
#endif
		static void NewProp_bUseCustomSpacing_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bUseCustomSpacing;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Spacing_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Spacing;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bRotationSnapEnabled_MetaData[];
#endif
		static void NewProp_bRotationSnapEnabled_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bRotationSnapEnabled;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_LocalRotationOffset_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_LocalRotationOffset;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_ScaleSnapMode_Underlying;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ScaleSnapMode_MetaData[];
#endif
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_ScaleSnapMode;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_MousewheelRotationAxis_Underlying;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MousewheelRotationAxis_MetaData[];
#endif
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_MousewheelRotationAxis;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_RotationSpeed_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_RotationSpeed;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ModifierKey_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ModifierKey;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SelectionColor_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_SelectionColor;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_USplineSnappingEditorSettings_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_SplineSnappingTool,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USplineSnappingEditorSettings_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "SplineSnappingEditorSettings.h" },
		{ "ModuleRelativePath", "Public/SplineSnappingEditorSettings.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USplineSnappingEditorSettings_Statics::NewProp_RelativeOffset_MetaData[] = {
		{ "Category", "Snapping Settings" },
		{ "ModuleRelativePath", "Public/SplineSnappingEditorSettings.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_USplineSnappingEditorSettings_Statics::NewProp_RelativeOffset = { "RelativeOffset", nullptr, (EPropertyFlags)0x0010000000004001, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(USplineSnappingEditorSettings, RelativeOffset), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UClass_USplineSnappingEditorSettings_Statics::NewProp_RelativeOffset_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USplineSnappingEditorSettings_Statics::NewProp_RelativeOffset_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USplineSnappingEditorSettings_Statics::NewProp_bUseCustomSpacing_MetaData[] = {
		{ "Category", "Snapping Settings" },
		{ "InlineEditConditionToggle", "" },
		{ "ModuleRelativePath", "Public/SplineSnappingEditorSettings.h" },
	};
#endif
	void Z_Construct_UClass_USplineSnappingEditorSettings_Statics::NewProp_bUseCustomSpacing_SetBit(void* Obj)
	{
		((USplineSnappingEditorSettings*)Obj)->bUseCustomSpacing = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_USplineSnappingEditorSettings_Statics::NewProp_bUseCustomSpacing = { "bUseCustomSpacing", nullptr, (EPropertyFlags)0x0010000000004001, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(USplineSnappingEditorSettings), &Z_Construct_UClass_USplineSnappingEditorSettings_Statics::NewProp_bUseCustomSpacing_SetBit, METADATA_PARAMS(Z_Construct_UClass_USplineSnappingEditorSettings_Statics::NewProp_bUseCustomSpacing_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USplineSnappingEditorSettings_Statics::NewProp_bUseCustomSpacing_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USplineSnappingEditorSettings_Statics::NewProp_Spacing_MetaData[] = {
		{ "Category", "Snapping Settings" },
		{ "ClampMin", "0.0" },
		{ "EditCondition", "bUseCustomSpacing" },
		{ "ModuleRelativePath", "Public/SplineSnappingEditorSettings.h" },
		{ "UIMin", "0.0" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_USplineSnappingEditorSettings_Statics::NewProp_Spacing = { "Spacing", nullptr, (EPropertyFlags)0x0010000000004001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(USplineSnappingEditorSettings, Spacing), METADATA_PARAMS(Z_Construct_UClass_USplineSnappingEditorSettings_Statics::NewProp_Spacing_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USplineSnappingEditorSettings_Statics::NewProp_Spacing_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USplineSnappingEditorSettings_Statics::NewProp_bRotationSnapEnabled_MetaData[] = {
		{ "Category", "Snapping Settings" },
		{ "InlineEditConditionToggle", "" },
		{ "ModuleRelativePath", "Public/SplineSnappingEditorSettings.h" },
	};
#endif
	void Z_Construct_UClass_USplineSnappingEditorSettings_Statics::NewProp_bRotationSnapEnabled_SetBit(void* Obj)
	{
		((USplineSnappingEditorSettings*)Obj)->bRotationSnapEnabled = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_USplineSnappingEditorSettings_Statics::NewProp_bRotationSnapEnabled = { "bRotationSnapEnabled", nullptr, (EPropertyFlags)0x0010000000004001, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(USplineSnappingEditorSettings), &Z_Construct_UClass_USplineSnappingEditorSettings_Statics::NewProp_bRotationSnapEnabled_SetBit, METADATA_PARAMS(Z_Construct_UClass_USplineSnappingEditorSettings_Statics::NewProp_bRotationSnapEnabled_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USplineSnappingEditorSettings_Statics::NewProp_bRotationSnapEnabled_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USplineSnappingEditorSettings_Statics::NewProp_LocalRotationOffset_MetaData[] = {
		{ "Category", "Snapping Settings" },
		{ "EditCondition", "bRotationSnapEnabled" },
		{ "ModuleRelativePath", "Public/SplineSnappingEditorSettings.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_USplineSnappingEditorSettings_Statics::NewProp_LocalRotationOffset = { "LocalRotationOffset", nullptr, (EPropertyFlags)0x0010000000004001, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(USplineSnappingEditorSettings, LocalRotationOffset), Z_Construct_UScriptStruct_FRotator, METADATA_PARAMS(Z_Construct_UClass_USplineSnappingEditorSettings_Statics::NewProp_LocalRotationOffset_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USplineSnappingEditorSettings_Statics::NewProp_LocalRotationOffset_MetaData)) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UClass_USplineSnappingEditorSettings_Statics::NewProp_ScaleSnapMode_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USplineSnappingEditorSettings_Statics::NewProp_ScaleSnapMode_MetaData[] = {
		{ "Category", "Snapping Settings" },
		{ "ModuleRelativePath", "Public/SplineSnappingEditorSettings.h" },
	};
#endif
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UClass_USplineSnappingEditorSettings_Statics::NewProp_ScaleSnapMode = { "ScaleSnapMode", nullptr, (EPropertyFlags)0x0010000000004001, UE4CodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(USplineSnappingEditorSettings, ScaleSnapMode), Z_Construct_UEnum_SplineSnappingTool_ESplineScaleSnappingMode, METADATA_PARAMS(Z_Construct_UClass_USplineSnappingEditorSettings_Statics::NewProp_ScaleSnapMode_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USplineSnappingEditorSettings_Statics::NewProp_ScaleSnapMode_MetaData)) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UClass_USplineSnappingEditorSettings_Statics::NewProp_MousewheelRotationAxis_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USplineSnappingEditorSettings_Statics::NewProp_MousewheelRotationAxis_MetaData[] = {
		{ "Category", "Editor Settings" },
		{ "EditCondition", "bRotationSnapEnabled" },
		{ "ModuleRelativePath", "Public/SplineSnappingEditorSettings.h" },
	};
#endif
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UClass_USplineSnappingEditorSettings_Statics::NewProp_MousewheelRotationAxis = { "MousewheelRotationAxis", nullptr, (EPropertyFlags)0x0010000000004001, UE4CodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(USplineSnappingEditorSettings, MousewheelRotationAxis), Z_Construct_UEnum_SplineSnappingTool_EMousewheelRotationAxis, METADATA_PARAMS(Z_Construct_UClass_USplineSnappingEditorSettings_Statics::NewProp_MousewheelRotationAxis_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USplineSnappingEditorSettings_Statics::NewProp_MousewheelRotationAxis_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USplineSnappingEditorSettings_Statics::NewProp_RotationSpeed_MetaData[] = {
		{ "Category", "Editor Settings" },
		{ "ClampMax", "180.0" },
		{ "ClampMin", "1.0" },
		{ "EditCondition", "bRotationSnapEnabled" },
		{ "ModuleRelativePath", "Public/SplineSnappingEditorSettings.h" },
		{ "UIMax", "180.0" },
		{ "UIMin", "1.0" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_USplineSnappingEditorSettings_Statics::NewProp_RotationSpeed = { "RotationSpeed", nullptr, (EPropertyFlags)0x0010000000004001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(USplineSnappingEditorSettings, RotationSpeed), METADATA_PARAMS(Z_Construct_UClass_USplineSnappingEditorSettings_Statics::NewProp_RotationSpeed_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USplineSnappingEditorSettings_Statics::NewProp_RotationSpeed_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USplineSnappingEditorSettings_Statics::NewProp_ModifierKey_MetaData[] = {
		{ "Category", "Editor Settings" },
		{ "ModuleRelativePath", "Public/SplineSnappingEditorSettings.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_USplineSnappingEditorSettings_Statics::NewProp_ModifierKey = { "ModifierKey", nullptr, (EPropertyFlags)0x0010000000004001, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(USplineSnappingEditorSettings, ModifierKey), Z_Construct_UScriptStruct_FKey, METADATA_PARAMS(Z_Construct_UClass_USplineSnappingEditorSettings_Statics::NewProp_ModifierKey_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USplineSnappingEditorSettings_Statics::NewProp_ModifierKey_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USplineSnappingEditorSettings_Statics::NewProp_SelectionColor_MetaData[] = {
		{ "Category", "Editor Settings" },
		{ "HideAlphaChannel", "" },
		{ "ModuleRelativePath", "Public/SplineSnappingEditorSettings.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_USplineSnappingEditorSettings_Statics::NewProp_SelectionColor = { "SelectionColor", nullptr, (EPropertyFlags)0x0010000000004001, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(USplineSnappingEditorSettings, SelectionColor), Z_Construct_UScriptStruct_FColor, METADATA_PARAMS(Z_Construct_UClass_USplineSnappingEditorSettings_Statics::NewProp_SelectionColor_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USplineSnappingEditorSettings_Statics::NewProp_SelectionColor_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_USplineSnappingEditorSettings_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USplineSnappingEditorSettings_Statics::NewProp_RelativeOffset,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USplineSnappingEditorSettings_Statics::NewProp_bUseCustomSpacing,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USplineSnappingEditorSettings_Statics::NewProp_Spacing,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USplineSnappingEditorSettings_Statics::NewProp_bRotationSnapEnabled,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USplineSnappingEditorSettings_Statics::NewProp_LocalRotationOffset,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USplineSnappingEditorSettings_Statics::NewProp_ScaleSnapMode_Underlying,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USplineSnappingEditorSettings_Statics::NewProp_ScaleSnapMode,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USplineSnappingEditorSettings_Statics::NewProp_MousewheelRotationAxis_Underlying,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USplineSnappingEditorSettings_Statics::NewProp_MousewheelRotationAxis,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USplineSnappingEditorSettings_Statics::NewProp_RotationSpeed,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USplineSnappingEditorSettings_Statics::NewProp_ModifierKey,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USplineSnappingEditorSettings_Statics::NewProp_SelectionColor,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_USplineSnappingEditorSettings_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<USplineSnappingEditorSettings>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_USplineSnappingEditorSettings_Statics::ClassParams = {
		&USplineSnappingEditorSettings::StaticClass,
		"EditorPerProjectUserSettings",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_USplineSnappingEditorSettings_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_USplineSnappingEditorSettings_Statics::PropPointers),
		0,
		0x001000A4u,
		METADATA_PARAMS(Z_Construct_UClass_USplineSnappingEditorSettings_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_USplineSnappingEditorSettings_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_USplineSnappingEditorSettings()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_USplineSnappingEditorSettings_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(USplineSnappingEditorSettings, 3290808470);
	template<> SPLINESNAPPINGTOOL_API UClass* StaticClass<USplineSnappingEditorSettings>()
	{
		return USplineSnappingEditorSettings::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_USplineSnappingEditorSettings(Z_Construct_UClass_USplineSnappingEditorSettings, &USplineSnappingEditorSettings::StaticClass, TEXT("/Script/SplineSnappingTool"), TEXT("USplineSnappingEditorSettings"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(USplineSnappingEditorSettings);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
