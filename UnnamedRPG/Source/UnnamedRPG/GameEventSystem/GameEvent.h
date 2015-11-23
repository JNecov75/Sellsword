#pragma once

#include "NameTypes.h"
#include <map>

//============================================================
// Internal use
class CVariantValue
{
public:
	virtual ~CVariantValue();
};

template <typename T>
class CTypedVariantValue : public CVariantValue
{
public:
	CTypedVariantValue(T& inValue) : Value(inValue) {}
	T Value;
};

//============================================================
// Game event class. Events are identified by thier name and they can conatin any number of parameters sent with them. Treat as a value class.
// When passing event parameters, please no r-value (i.e., DO NOT write evnt.AddParameter(TEXT("CoolParameterNameButNotCoolValue"), 132.5); 
// instead: float CoolValue = 132.5; evnt.AddParameter(TEXT("CoolParameterName"), CoolValue); This is needed to help the compiler in type deduction.
class CGameEvent
{
public:
	CGameEvent(FName eventName);
	~CGameEvent();

	inline FName GetName() const { return _EventName; }

	template <typename T>
	bool AddParameter(FName parameterName, T& inParameterValue);

	template <typename T>
	bool GetParameter(FName parameterName, T& outParameterValue);

private:
	FName _EventName;
	std::map< FName, CVariantValue* > _Parameters;
};

//============================================================
template <typename T>
bool CGameEvent::AddParameter(FName parameterName, T& inParameterValue)
{
	if (_Parameters.count(parameterName) != 0)
	{
		check(0 && "parameter is already there");
		return false;
	}

	CVariantValue* pValue = new CTypedVariantValue<T>(inParameterValue);
	_Parameters[parameterName] = pValue;
	return true;
}


template <typename T>
bool CGameEvent::GetParameter(FName parameterName, T& outParameterValue)
{
	if (_Parameters.count(parameterName) == 0)
	{
		check(0 && "parameter is not there");
		return false;
	}

	CTypedVariantValue<T>* pValue =  0; // dynamic_cast<CTypedVariantValue<T>*>(_Parameters[parameterName]);
	if (!pValue)
	{
		check(0 && "the requested output value type doesn't match the stored type");
		return false;
	}

	outParameterValue = pValue->Value;
	return true;
}
