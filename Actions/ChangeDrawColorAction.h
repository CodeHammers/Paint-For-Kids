#pragma once
#include "Action.h"
class ChangeDrawColorAction :
	public Action
{
private:
	ActionType ActType;
	color DrawColor;
	ApplicationManager* appManager;
	virtual bool ReadActionParameters();
public:
	ChangeDrawColorAction(ApplicationManager* appManager, ActionType actType);
	~ChangeDrawColorAction();
	virtual void Execute();

};