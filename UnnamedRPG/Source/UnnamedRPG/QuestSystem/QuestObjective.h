// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Core.h"
#include "QuestTypes.h"
#include "QuestObjectiveHandler.h"
#include "QuestObjective.generated.h"

USTRUCT(BlueprintType)
struct FQuestObjective
{
	GENERATED_USTRUCT_BODY()

public:

	FQuestObjective();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		EQuestObjectiveTypes ObjectiveType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FName TargetTag;

	void Init();
	void RecieveGameEvent(class CGameEvent& event);
	inline EQuestStatus GetStatus()const { return _ObjectiveStatus; }

private:
	class CQuestObjectiveHandler* _Handler;
	EQuestStatus _ObjectiveStatus;
};