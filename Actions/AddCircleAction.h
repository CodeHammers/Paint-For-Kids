#pragma once

#include "Action.h"

class AddCircleAction : public Action
{

private:
	Point C, E;
	int R;
	GfxInfo CircGfxInfo;

public:
	//Constrcutor
	AddCircleAction(ApplicationManager* pApp);

	//Get action parameters function
	virtual void ReadActionParameters();

	//Execute the action
	virtual void Execute();

};
