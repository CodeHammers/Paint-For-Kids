#pragma once
#include "Action.h"
class ChangeFillColor :
	public Action
{
private:
	ActionType ActType;
	color DrawColor;
	virtual bool ReadActionParameters();
public:
	ChangeFillColor(ApplicationManager* appManager, ActionType actType);
	~ChangeFillColor();
	virtual void Execute();
};