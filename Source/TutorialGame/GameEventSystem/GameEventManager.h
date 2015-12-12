#pragma once

#include "GameEventHelpers.h"
#include <map>
#include <vector>
#include <algorithm>

class CGameEventManager
{
public:

	template<typename T>
	bool Register(T* pListener, FName eventName); // register to recieve events, example: suppose you want to listen to an event called 'some_event'. to do so: in your class constructor you will call this function [message manager ptr]->Register(this, TEXT("some_event"));

	template<typename T>
	bool Unregister(T* pListener, FName eventName);

	void SendEvent(CGameEvent& event); // send the event to the objects who registered interest

	void Reset(); // delete and clear everything

private:
	// you access the single instance of the event manager from the game instance
	friend class UUnnamedRPGGameInstance;
	CGameEventManager();
	~CGameEventManager();

	std::map<void*, CGameEventListenerHolder* > _EventListenersHolders;
	std::map< FName, std::vector< CGameEventListenerHolder* > > _ListenersMap;
};

//=====================================================================
template<typename T>
bool CGameEventManager::Register(T* pListener, FName eventName)
{
	if (pListener == nullptr)
		return false;

	CGameEventListenerHolder* pHolder = nullptr;
	if (_EventListenersHolders.count(pListener) != 0)
	{
		pHolder = _EventListenersHolders[pListener];
	}
	else
	{
		pHolder = new CTypedGameEventListener<T>(pListener);
		_EventListenersHolders[pListener] = pHolder;
	}

	std::vector< CGameEventListenerHolder* >& holdersRef = _ListenersMap[eventName]; // if event name wasn't added before, then the [] operator will add it and an empty vector will be returned
	if (std::find(holdersRef.begin(), holdersRef.end(), pHolder) != holdersRef.end())
	{
		// this guy is already listening to this message
		return false;
	}

	_ListenersMap[eventName].push_back(pHolder);
	return true;
}

//=====================================================================
template<typename T>
bool CGameEventManager::Unregister(T* pListener, FName eventName)
{
	if (pListener == nullptr)
		return false;

	if (_EventListenersHolders.count(pListener) == 0)
	{
		// no holder was ever created for this object, so it must be not listening to any event
		return false;
	}

	CGameEventListenerHolder* pHolder = _EventListenersHolders[pListener];
	std::vector< CGameEventListenerHolder* >& holdersRef = _ListenersMap[eventName];
	std::vector< CGameEventListenerHolder* >::iterator holderPos = std::find(holdersRef.begin(), holdersRef.end(), pHolder);
	if (holderPos == holdersRef.end())
	{
		// it is not in this event listener list
		return false;
	}

	holdersRef.erase(holderPos); // remove it
	return true;
}