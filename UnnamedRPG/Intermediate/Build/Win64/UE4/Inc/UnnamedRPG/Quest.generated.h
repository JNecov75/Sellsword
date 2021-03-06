// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	C++ class header boilerplate exported from UnrealHeaderTool.
	This is automatically generated by the tools.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectBase.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef UNNAMEDRPG_Quest_generated_h
#error "Quest.generated.h already included, missing '#pragma once' in Quest.h"
#endif
#define UNNAMEDRPG_Quest_generated_h

#define UnnamedRPG_Source_UnnamedRPG_QuestSystem_Quest_h_16_RPC_WRAPPERS
#define UnnamedRPG_Source_UnnamedRPG_QuestSystem_Quest_h_16_RPC_WRAPPERS_NO_PURE_DECLS
#define UnnamedRPG_Source_UnnamedRPG_QuestSystem_Quest_h_16_INCLASS_NO_PURE_DECLS \
	private: \
	static void StaticRegisterNativesUQuest(); \
	friend UNNAMEDRPG_API class UClass* Z_Construct_UClass_UQuest(); \
	public: \
	DECLARE_CLASS(UQuest, UObject, COMPILED_IN_FLAGS(0), 0, UnnamedRPG, NO_API) \
	DECLARE_SERIALIZER(UQuest) \
	/** Indicates whether the class is compiled into the engine */    enum {IsIntrinsic=COMPILED_IN_INTRINSIC}; \
	virtual UObject* _getUObject() const { return const_cast<UQuest*>(this); }


#define UnnamedRPG_Source_UnnamedRPG_QuestSystem_Quest_h_16_INCLASS \
	private: \
	static void StaticRegisterNativesUQuest(); \
	friend UNNAMEDRPG_API class UClass* Z_Construct_UClass_UQuest(); \
	public: \
	DECLARE_CLASS(UQuest, UObject, COMPILED_IN_FLAGS(0), 0, UnnamedRPG, NO_API) \
	DECLARE_SERIALIZER(UQuest) \
	/** Indicates whether the class is compiled into the engine */    enum {IsIntrinsic=COMPILED_IN_INTRINSIC}; \
	virtual UObject* _getUObject() const { return const_cast<UQuest*>(this); }


#define UnnamedRPG_Source_UnnamedRPG_QuestSystem_Quest_h_16_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UQuest(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UQuest) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UQuest); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UQuest); \
private: \
	/** Private copy-constructor, should never be used */ \
	NO_API UQuest(const UQuest& InCopy); \
public:


#define UnnamedRPG_Source_UnnamedRPG_QuestSystem_Quest_h_16_ENHANCED_CONSTRUCTORS \
private: \
	/** Private copy-constructor, should never be used */ \
	NO_API UQuest(const UQuest& InCopy); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UQuest); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UQuest); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UQuest)


#define UnnamedRPG_Source_UnnamedRPG_QuestSystem_Quest_h_13_PROLOG
#define UnnamedRPG_Source_UnnamedRPG_QuestSystem_Quest_h_16_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	UnnamedRPG_Source_UnnamedRPG_QuestSystem_Quest_h_16_RPC_WRAPPERS \
	UnnamedRPG_Source_UnnamedRPG_QuestSystem_Quest_h_16_INCLASS \
	UnnamedRPG_Source_UnnamedRPG_QuestSystem_Quest_h_16_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define UnnamedRPG_Source_UnnamedRPG_QuestSystem_Quest_h_16_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	UnnamedRPG_Source_UnnamedRPG_QuestSystem_Quest_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
	UnnamedRPG_Source_UnnamedRPG_QuestSystem_Quest_h_16_INCLASS_NO_PURE_DECLS \
	UnnamedRPG_Source_UnnamedRPG_QuestSystem_Quest_h_16_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID UnnamedRPG_Source_UnnamedRPG_QuestSystem_Quest_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
