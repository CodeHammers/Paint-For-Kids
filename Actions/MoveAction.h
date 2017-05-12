#pragma once
#include"Action.h"

class MoveAction : public Action
{
private:

public:
	MoveAction(ApplicationManager* pApp);
	virtual bool ReadActionParameters();
	virtual void Execute();
};