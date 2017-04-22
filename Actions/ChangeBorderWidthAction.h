#pragma once
#pragma once
#include "Action.h"
class ChangeBorderWidthAction :
	public Action
{
private:
	ActionType ActType;
	int BorderWidth;
	ApplicationManager* appManager;
	virtual bool ReadActionParameters();
public:
	ChangeBorderWidthAction(ApplicationManager* appManager, ActionType actType);
	~ChangeBorderWidthAction();
	virtual void Execute();

};