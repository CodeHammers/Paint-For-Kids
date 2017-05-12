#pragma once

#include "Action.h"

class AddLineAction : public Action
{
private:
	Point P1, P2;  //line's end points
	GfxInfo LineGfxInfo;  //contains info about colors, borderwidth and similar info
public:
	//constructor
	AddLineAction(ApplicationManager* pApp);

	//read parameter for the actions
	bool virtual ReadActionParameters();

	//function to execute the action
	void virtual Execute();
};
