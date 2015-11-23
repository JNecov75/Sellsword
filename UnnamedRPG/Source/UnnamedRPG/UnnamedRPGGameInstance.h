// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/GameInstance.h"
#include "UnnamedRPGGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class UNNAMEDRPG_API UUnnamedRPGGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:
	virtual void Init() override;
	virtual void Shutdown() override;

	inline class CGameEventManager* GetGameEventManager()const{ return _GameEventManager; }


private:
	class CGameEventManager* _GameEventManager;
	class CQuestManager* _QuestManager;
};
