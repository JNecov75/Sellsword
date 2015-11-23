
#include "UnnamedRPG.h"
#include "GameEvent.h"

CVariantValue::~CVariantValue()
{
}

//==============================================
CGameEvent::CGameEvent(FName inEventName) : _EventName(inEventName)
{
}


//==============================================
CGameEvent::~CGameEvent()
{
	for (std::map< FName, CVariantValue* >::iterator iter = _Parameters.begin(), endIter = _Parameters.end();
		iter != endIter; ++iter)
	{
		delete (iter->second);
	}
	_Parameters.clear();
}

//==============================================
