#pragma once
#include"Action.h"
#include"..\ApplicationManager.h"
#include <vector>
#include "SelectAction.h"

#include<vector>

class PasteAction :public Action
{
private:
	int ToBePasted;
	Point P;
public:
	PasteAction(ApplicationManager* pApp);	
	virtual bool ReadActionParameters();
	virtual void Execute();	
	bool InDrawingArea(Point O);
};