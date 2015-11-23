// Fill out your copyright notice in the Description page of Project Settings.

#include "UnnamedRPG.h"
#include "QuestObjective.h"
#include "../GameEventSystem/GameEvent.h"

//=========================================
CQuestObjectiveHandler::CQuestObjectiveHandler() : bObjectiveCompleted(false)
{
}

CQuestObjectiveHandler::~CQuestObjectiveHandler()
{
}

//=========================================
CQuestObjectiveHandlerArea::CQuestObjectiveHandlerArea(FName& inTargetAreaTag, bool inCompleteOnEnterArea) 
	: _AreaTag(inTargetAreaTag), bCompleteOnEnterArea(inCompleteOnEnterArea)
{
	_BeginOverlapName = FName(TEXT("PlayerBeginOverlap"));
	_EndOverlapName = FName(TEXT("PlayerEndOverlap"));
}

void CQuestObjectiveHandlerArea::RecieveGameEvent(class CGameEvent& event)
{
	if (bCompleteOnEnterArea && event.GetName() == _BeginOverlapName)
	{
		AActor* OtherActor = nullptr;
		event.GetParameter(TEXT("OtherActor"), OtherActor);
		if (OtherActor->ActorHasTag(_AreaTag))
		{
			bObjectiveCompleted = true;
			return;
		}
	}


	else if (!bCompleteOnEnterArea && event.GetName() == _EndOverlapName)
	{
		AActor* OtherActor = nullptr;
		event.GetParameter(TEXT("OtherActor"), OtherActor);
		if (OtherActor->ActorHasTag(_AreaTag))
		{
			bObjectiveCompleted = true;
			return;
		}
	}
}

//=========================================



