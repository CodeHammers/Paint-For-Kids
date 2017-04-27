#pragma once

#include"Action.h"

class PlayAction : public Action
{
private:



public:
	PlayAction(ApplicationManager* pApp);

	//Get action parameters function
	virtual bool ReadActionParameters();

	//Execute the action
	virtual void Execute();
};