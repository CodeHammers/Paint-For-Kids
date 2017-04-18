#pragma once

#include"Action.h"

class SelectAction :public Action
{
private:
	Point P;

public:
	SelectAction(ApplicationManager* pApp);

	//Read action parameters
	virtual bool ReadActionParameters();

	//Execute action
	//virtual void Execute();
};