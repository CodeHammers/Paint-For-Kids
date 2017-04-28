#pragma once
#include "Action.h"
class ResizeAction :
	public Action
{
private:
	double ratio = 1;
	ActionType actType;
	ApplicationManager* appManager;
public:
	ResizeAction(ApplicationManager* appmanager,ActionType);
	virtual bool ReadActionParameters();
	virtual void Execute();
	~ResizeAction();
};

