#pragma once
#include"..\ApplicationManager.h"
#include "Action.h"


class CutAction :public Action
{
private:
	int Selected; //stores the selected figures count

public:
	//constructor
	CutAction(ApplicationManager* pApp);

	//Reads action parameters
	virtual bool ReadActionParameters();

	//Execute action
	virtual void Execute();
};