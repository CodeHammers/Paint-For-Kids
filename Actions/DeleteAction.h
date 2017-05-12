#pragma once
#include "SelectAction.h"

class DeleteAction : public Action
{
private:
	int Selected;  //stores the selected figures count

public:
	//constructor
	DeleteAction(ApplicationManager *pApp);

	//Read Action parameters
	virtual bool ReadActionParameters();

	//Execute action
	virtual void Execute();
};