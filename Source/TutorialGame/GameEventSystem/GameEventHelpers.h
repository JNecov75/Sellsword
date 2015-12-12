#pragma once

#include "GameEvent.h"

class CGameEventListenerHolder
{
public:
	virtual ~CGameEventListenerHolder() {}
	virtual void PassEvent(CGameEvent& event) = 0;
};

template <typename T>
class CTypedGameEventListener : public CGameEventListenerHolder
{
public:
	CTypedGameEventListener(T* inGameEventListener);
	virtual void PassEvent(CGameEvent& event)override;

private:
	T* _GameEventListener;
};

//==================================================================
template <typename T>
CTypedGameEventListener<T>::CTypedGameEventListener(T* inGameEventListener)
	: _GameEventListener(inGameEventListener)
{
}

//==================================================================
template <typename T>
void CTypedGameEventListener<T>::PassEvent(CGameEvent& event)
{
	_GameEventListener->OnGameEvent(event); // This is a promise that anyone regsitered to listen to event will have this function (OnGameEvent) implemented.
}