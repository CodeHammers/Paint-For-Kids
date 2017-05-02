#pragma once
#include "Action.h"
class ChangeBckgrndColor :
	public Action
{
private:
	ActionType ActType;
	color BackgroundColor;
	ApplicationManager* appManager;
	virtual bool ReadActionParameters();
public:
	ChangeBckgrndColor(ApplicationManager* appManager,ActionType actType);
	~ChangeBckgrndColor();
	virtual void Execute();
};

