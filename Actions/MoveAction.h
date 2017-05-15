#pragma once
#include "C:\Paint-For-Kids\Actions\Action.h"
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

