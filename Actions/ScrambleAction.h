#pragma once
#include "Action.h"
class ScrambleAction :
	public Action
{
public:
	ScrambleAction(ApplicationManager * app);
	//Get action parameters function
	virtual bool ReadActionParameters();

	//Execute the action
	virtual void Execute();
	~ScrambleAction();
};

