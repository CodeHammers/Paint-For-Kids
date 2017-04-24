#pragma once
#include"..\ApplicationManager.h"
#include "Action.h"

class CutAction :public Action
{
private:
	CFigure** FigList;
	int CurrentDeleted;
public:

	CutAction(ApplicationManager* pApp);
	void RemoveCutElementsFromTheOriginalList();
	virtual bool ReadActionParameters();
	virtual void Execute();
};