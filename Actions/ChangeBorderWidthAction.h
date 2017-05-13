#pragma once
#pragma once
#include "Action.h"
class ChangeBorderWidthAction :
	public Action
{
private:
	ActionType ActType;
	int BorderWidth;
	virtual bool ReadActionParameters();
public:
	ChangeBorderWidthAction(ApplicationManager* appManager, ActionType actType);
	~ChangeBorderWidthAction();
	virtual void Execute();
};