// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

// QuestObjective will delegate actual objective handling to the appropriate handler
class CQuestObjectiveHandler
{
public:
	CQuestObjectiveHandler();
	virtual ~CQuestObjectiveHandler();
	virtual void RecieveGameEvent(class CGameEvent& event) = 0;
	inline bool IsObjectiveCompleted()const { return bObjectiveCompleted; }

protected:
	bool bObjectiveCompleted;
};

//==============================================
// This specialization handles tracking of area enter/leave objectives
class CQuestObjectiveHandlerArea : public CQuestObjectiveHandler
{
public:
	CQuestObjectiveHandlerArea(FName& inTargetAreaTag, bool inCompleteOnEnterArea);
	virtual void RecieveGameEvent(class CGameEvent& event) override;

private:
	FName _AreaTag;
	FName _BeginOverlapName;
	FName _EndOverlapName;
	bool bCompleteOnEnterArea;
};

//==============================================
// This specialization handles tracking of monsters killing objectives
class CQuestObjectiveHandlerMonsters : public CQuestObjectiveHandler
{
public:
	CQuestObjectiveHandlerMonsters();
	virtual void RecieveGameEvent(class CGameEvent& event) override;
};

//==============================================
// This specialization handles tracking of item collection objectives
class CQuestObjectiveHandlerItemCollection : public CQuestObjectiveHandler
{
public:
	CQuestObjectiveHandlerItemCollection();
	virtual void RecieveGameEvent(class CGameEvent& event) override;
};