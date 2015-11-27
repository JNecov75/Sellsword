#pragma once

#include "NameTypes.h"

class CGameEvent
{
public:
	CGameEvent(FName eventName, void* optionalEventData = nullptr);
	~CGameEvent();

	inline FName GetName() const { return _EventName; }
	inline void SetData(void* d) { _EventData = d; }
	inline void* GetData()const { return _EventData; }

private:
	FName _EventName;
	void* _EventData;
};