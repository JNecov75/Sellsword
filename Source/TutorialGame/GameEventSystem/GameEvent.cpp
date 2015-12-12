
#include "UnnamedRPG.h"
#include "GameEvent.h"

//==============================================
CGameEvent::CGameEvent(FName inEventName, void* optionalEventData)
	: _EventName(inEventName), _EventData(optionalEventData)
{
}


//==============================================
CGameEvent::~CGameEvent()
{
}

//==============================================
