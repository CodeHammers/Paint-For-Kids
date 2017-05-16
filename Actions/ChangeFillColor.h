#pragma once
#include "Action.h"

class ChangeFillColor : public Action
{
private:
	ActionType ActType;
	color DrawColor;
	virtual bool ReadActionParameters();

public:
	/*A constructor function*/
	ChangeFillColor(ApplicationManager* appManager, ActionType actType);

	/*A destructor function*/
	~ChangeFillColor();

	/*A function to execute action*/
	virtual void Execute();
};