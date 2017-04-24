#pragma once
#include"Action.h"
#include"..\ApplicationManager.h"
#include <vector>
class CopyAction : public Action
{
private:
	CFigure** FigList;
public:
	CopyAction(ApplicationManager* pApp);
	virtual bool ReadActionParameters();
	virtual void Execute();
};