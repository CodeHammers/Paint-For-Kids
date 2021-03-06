#pragma once
#include "Action.h"
#include "../ApplicationManager.h"
class MoveAction :
	public Action
{
private:
	virtual bool ReadActionParameters();
public:
	MoveAction(ApplicationManager* appmngr);
	virtual void Execute();
	~MoveAction();
};

