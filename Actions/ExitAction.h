#pragma once

#include"Action.h"

class ExitAction : public Action
{
private:
	int FigCount;
public:
	/*A constructor function*/
	ExitAction(ApplicationManager* pApp);

	/*A function to read action parameters*/
	virtual bool ReadActionParameters();

	/*A function to execute the action*/
	virtual void Execute();
};