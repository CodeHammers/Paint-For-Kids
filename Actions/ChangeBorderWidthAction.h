#pragma once
#pragma once
#include "Action.h"
class ChangeBorderWidthAction : public Action
{
private:
	ActionType ActType;
	int BorderWidth;
	virtual bool ReadActionParameters();

public:
	/*A constructor function*/
	ChangeBorderWidthAction(ApplicationManager* appManager, ActionType actType);

	/*A destructor function*/
	~ChangeBorderWidthAction();

	/*A function to execute action*/
	virtual void Execute();
};