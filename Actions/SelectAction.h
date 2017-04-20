#pragma once

#include"Action.h"
#include"..\Figures\CFigure.h"
#include<set>

class SelectAction :public Action
{
private:
	Point P;
	CFigure* ptr;
	set<CFigure*>SelectedSoFar;

public:
	SelectAction(ApplicationManager* pApp);

	//Read action parameters
	virtual bool ReadActionParameters();

	//Execute action
	virtual void Execute();

	//A function to check whether a point is in the drawing area or not
	bool InDrawingArea(Point P) const;

	bool TerminateSelection(Point P) const;

	void Select(CFigure* ptr);
	void Unselect();
};