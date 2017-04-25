#pragma once
#include"..\ApplicationManager.h"
#include "Action.h"


class CutAction :public Action
{
private:
	int Selected;

public:

	CutAction(ApplicationManager* pApp);
	virtual bool ReadActionParameters();
	virtual void Execute();
};