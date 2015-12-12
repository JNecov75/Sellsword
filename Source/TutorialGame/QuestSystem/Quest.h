// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Object.h"
#include "QuestTypes.h"
#include "QuestObjective.h"
#include "Quest.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class UNNAMEDRPG_API UQuest : public UObject
{
	GENERATED_BODY()
	
public:

	UQuest(const FObjectInitializer& ObjectInitializer);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (DisplayName = "Quest Trigger"))
		FQuestObjective TriggerObjective;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (DisplayName = "Objectives List"))
		TArray<FQuestObjective> ObjectiveList;

	inline EQuestStatus GetStatus() const { return _Status; } // get the current status of this quest

	bool Accept(class CGameEvent& event); // accepting means the quest will become the active one, this will only be called if there is currently no active quest in progress.
	void RecieveGameEvent(class CGameEvent& event); // This will be called for every game event once this is the active quest

private:
	void MoveToNextObjective();
	int32 _CurrentObjectiveIndex;
	EQuestStatus _Status;
};
