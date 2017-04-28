#pragma once

#include"Action.h"
#include"..\Figures\CFigure.h"
#include<queue>

class PlayAction : public Action
{
private:
	string FigureType;
	color FigureDrawClr;
	color FigureFillClr;
	priority_queue<int>FigureAreas;

public:
	PlayAction(ApplicationManager* pApp);

	//Get action parameters function
	virtual bool ReadActionParameters();

	//Execute the action
	virtual void Execute();

	//A function to check the figure type
	bool CheckFigureType(CFigure* ptr);

	//A function to check the figure draw color
	bool CheckFigureDrawClr(CFigure* ptr);

	//A function to check the figure fill color
	bool CheckFigureFillClr(CFigure* ptr);

	//A function to claculate and queue figure areas
	void CalcAndQueueAreas();
};