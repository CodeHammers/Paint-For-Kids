#pragma once
#include "Action.h"


class ChangeBckgrndColor : public Action
{
private:
	ActionType ActType;  //represents the action type
	color BackgroundColor;  //to store the background color
	ApplicationManager* appManager;  
	virtual bool ReadActionParameters();
public:
	ChangeBckgrndColor(ApplicationManager* appManager,ActionType actType);
	~ChangeBckgrndColor();
	virtual void Execute();
};

