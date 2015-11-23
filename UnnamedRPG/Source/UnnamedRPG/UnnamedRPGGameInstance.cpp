// Fill out your copyright notice in the Description page of Project Settings.

#include "UnnamedRPG.h"
#include "GameEventSystem/GameEventManager.h"
#include "QuestSystem/QuestManager.h"
#include "UnnamedRPGGameInstance.h"

void UUnnamedRPGGameInstance::Init()
{
	Super::Init();
	_GameEventManager = new CGameEventManager();
	_QuestManager = new CQuestManager(_GameEventManager);

	_QuestManager->GrabAllQuests();
}

void UUnnamedRPGGameInstance::Shutdown()
{
	Super::Shutdown();
	delete _QuestManager;
	delete _GameEventManager;
}




