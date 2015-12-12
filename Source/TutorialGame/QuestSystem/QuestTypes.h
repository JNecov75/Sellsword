// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Core.h"
#include "QuestTypes.generated.h"

UENUM(BlueprintType)
enum class EQuestObjectiveTypes : uint8
{
	EnterArea UMETA(DisplayName = "Enter Area"),
	LeaveArea UMETA(DisplayName = "Leave Area"),
	KillMonster UMETA(DisplayName = "Kill A Monster"),
	CollectItem UMETA(DisplayName = "Collect An Item")
};

enum class EQuestStatus : uint8
{
	NotStarted, // The quest hasn't yet started
	InProgress, // The player is currently playing through this quest, it is teh active one
	Finished, // The quest was finished successfully
	Failed // The player failed in this quest
};
