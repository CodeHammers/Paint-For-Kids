#pragma once

#include"Action.h"
#include"..\Figures\CFigure.h"
#include<set>

class SelectAction :public Action
{
private:
	Point P;   //to store the clicked point
	CFigure* ptr;  //pointer to the currently selected figure
	set<CFigure*>SelectedSoFar;  //set to store pointers to the currently selected figures

public:
	//constructor
	SelectAction(ApplicationManager* pApp);

	//Read action parameters
	virtual bool ReadActionParameters();

	//Execute action
	virtual void Execute();

	//A function to check whether a point is in the drawing area or not
	bool InDrawingArea(Point P) const;

	//A function to determine when to terminate selection
	bool TerminateSelection(Point P) const;

	//A function select a figure
	void Select(CFigure* ptr);

	//A function to unselect a figure
	void Unselect();
};