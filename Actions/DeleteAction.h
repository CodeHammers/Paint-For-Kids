#pragma once
#include "SelectAction.h"

class DeleteAction : public Action
{
private:
	int Selected;

public:
	DeleteAction(ApplicationManager *pApp);
	virtual bool ReadActionParameters();
	virtual void Execute();
};