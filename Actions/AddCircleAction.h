#pragma once

#include "Action.h"

class AddCircleAction : public Action
{

private:
	Point C;  //center point
	Point E;  //radius end point
	int R;    //radius (int) for simplicity
	GfxInfo CircGfxInfo;  //contains info about colors, borderwidth and similar info

public:
	//Constrcutor
	AddCircleAction(ApplicationManager* pApp);

	//Get action parameters function
	virtual bool ReadActionParameters();

	//Execute the action
	virtual void Execute();
};