// Fill out your copyright notice in the Description page of Project Settings.

#include "UnnamedRPG.h"
#include "QuestObjective.h"

FQuestObjective::FQuestObjective() : _Handler(nullptr), _ObjectiveStatus(EQuestStatus::NotStarted)
{
}

void FQuestObjective::Init()
{
	if (ObjectiveType == EQuestObjectiveTypes::EnterArea
		|| ObjectiveType == EQuestObjectiveTypes::LeaveArea)
	{
		_Handler = new CQuestObjectiveHandlerArea(TargetTag, ObjectiveType == EQuestObjectiveTypes::EnterArea);
	}

	_ObjectiveStatus = EQuestStatus::InProgress;
}

void FQuestObjective::RecieveGameEvent(class CGameEvent& event)
{
	check(_Handler && "It seems you haven't called Init");
	_Handler->RecieveGameEvent(event);
	if (_Handler->IsObjectiveCompleted())
	{
		_ObjectiveStatus = EQuestStatus::Finished;
		delete _Handler; // we don't need it anymore
		_Handler = nullptr;
	}
}

