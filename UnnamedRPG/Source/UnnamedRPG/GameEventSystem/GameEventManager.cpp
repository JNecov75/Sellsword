#include "UnnamedRPG.h"
#include "GameEventManager.h"

CGameEventManager::CGameEventManager()
{
}

CGameEventManager::~CGameEventManager()
{
	Reset();
}

void CGameEventManager::SendEvent(CGameEvent& event)
{
	FName eventName = event.GetName();
	if (_ListenersMap.count(eventName) == 0)
	{
		// nobody is listenening to this event!
		return;
	}

	std::vector< CGameEventListenerHolder* >& listenersHolders = _ListenersMap[eventName];
	for (size_t i = 0, count = listenersHolders.size(); i < count; i++)
	{
		listenersHolders[i]->PassEvent(event);
	}
}

void CGameEventManager::Reset()
{
	for (std::map<void*, CGameEventListenerHolder* >::iterator iter = _EventListenersHolders.begin(), endIter = _EventListenersHolders.end();
		iter != endIter; ++iter)
	{
		delete (iter->second);
	}
	_EventListenersHolders.clear();
	_ListenersMap.clear();
}