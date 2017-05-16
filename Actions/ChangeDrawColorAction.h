#pragma once
#include "Action.h"

class ChangeDrawColorAction : public Action
{
private:
	ActionType ActType;
	color DrawColor;
	virtual bool ReadActionParameters();

public:
	/*A constructor function*/
	ChangeDrawColorAction(ApplicationManager* appManager, ActionType actType);

	/*A destructor function*/
	~ChangeDrawColorAction();

	/*A function to execute action*/
	virtual void Execute();
};