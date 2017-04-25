#pragma once
#include"Action.h"
#include"..\ApplicationManager.h"
#include <vector>

class CopyAction : public Action
{
private:
	int Selected;
public:
	CopyAction(ApplicationManager* pApp);
	static CFigure* CopyFigure(CFigure* ptr);
	virtual bool ReadActionParameters();
	virtual void Execute();
};