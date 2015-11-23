#pragma once

#include "Quest.h"
#include "../GameEventSystem/GameEvent.h"
#include <vector>

class CQuestManager
{
public:

	void OnGameEvent(CGameEvent& event); // listen to game events so it can activate a quest if appropriate
	inline UQuest* GetActiveQuest()const { return _ActiveQuest; } // might be nullptr if no quest is currently active

private:
	friend class UUnnamedRPGGameInstance;
	CQuestManager(class CGameEventManager* inGameEventManager);
	~CQuestManager();
	void GrabAllQuests();

	std::vector<UQuest*> _QuestsList;
	UQuest* _ActiveQuest;
	class CGameEventManager* _GameEventManager;
};
