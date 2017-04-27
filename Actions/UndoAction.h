#pragma once
#include "Action.h"

class UndoAction :public Action
{
public:
	UndoAction(ApplicationManager* pApp);

	//Read action parameters
	virtual bool ReadActionParameters();

	//Execute action
	virtual void Execute();

};