#pragma once
#include"Action.h"
#include"..\ApplicationManager.h"
#include <vector>
#include "SelectAction.h"

#include<vector>

class PasteAction :public Action
{
private:
	int ToBePasted;  //stores the selected figures count
	Point P;   //stores the point to which we will paste
public:
	//constructor
	PasteAction(ApplicationManager* pApp);	

	//read action parameters
	virtual bool ReadActionParameters();

	//execute action
	virtual void Execute();	

	//A function to check if the given point is inside the drawing area
	bool InDrawingArea(Point O);
};