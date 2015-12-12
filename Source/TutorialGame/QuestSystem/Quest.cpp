// Fill out your copyright notice in the Description page of Project Settings.

#include "UnnamedRPG.h"
#include "Quest.h"

UQuest::UQuest(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer), _CurrentObjectiveIndex(-1), _Status(EQuestStatus::NotStarted)
{
}

bool UQuest::Accept(class CGameEvent& event)
{
	if (GetStatus() == EQuestStatus::Finished)
	{
		return false; // since we already finished this quest
	}

	if (TriggerObjective.GetStatus() == EQuestStatus::NotStarted)
	{
		TriggerObjective.Init();
	}
	check(TriggerObjective.GetStatus() == EQuestStatus::InProgress);
	TriggerObjective.RecieveGameEvent(event);
	if (TriggerObjective.GetStatus() == EQuestStatus::Finished)
	{
		_Status = EQuestStatus::InProgress;
		check(ObjectiveList.Num() != 0);
		_CurrentObjectiveIndex = 0;
		ObjectiveList[_CurrentObjectiveIndex].Init();
		return true;
	}
	return false;
}

void UQuest::RecieveGameEvent(class CGameEvent& event)
{
	check(_Status == EQuestStatus::InProgress);
	FQuestObjective& CurrentObjective = ObjectiveList[_CurrentObjectiveIndex];
	CurrentObjective.RecieveGameEvent(event);
	if (CurrentObjective.GetStatus() == EQuestStatus::Finished)
	{
		MoveToNextObjective();
	}
}

void UQuest::MoveToNextObjective()
{
	_CurrentObjectiveIndex++;
	if (_CurrentObjectiveIndex == ObjectiveList.Num())
	{
		_Status = EQuestStatus::Finished;
		return;
	}

	/*else*/
	ObjectiveList[_CurrentObjectiveIndex].Init();
}




