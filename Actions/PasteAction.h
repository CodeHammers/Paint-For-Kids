#pragma once
#include"Action.h"
#include"..\ApplicationManager.h"
#include <vector>
#include "SelectAction.h"
class PasteAction :public Action
{
private:
	CFigure**Clipboard;
	Point OriginPoint;
	Point TransitionPoint;
	CFigure**FigList;
	CFigure*Temp[100];
	int Actual_CountTemp;

	void AddTemp(CFigure* pFig);
	void AddtoFigList();
	Point GetTheOrigin();
	bool InDrawingArea(Point P) const;
	void TransitionFigures();
public:
	PasteAction(ApplicationManager* pApp);	
	virtual bool ReadActionParameters();
	virtual void Execute();	
};