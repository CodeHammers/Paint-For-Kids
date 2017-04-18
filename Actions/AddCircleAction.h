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
	virtual bool ReadActionParameters();

	//Execute the action
	virtual void Execute();

	//Function to handle edge cases
	bool InDrawingArea(Point P) const ;
};