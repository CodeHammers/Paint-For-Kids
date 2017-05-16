#include "MoveAction.h"



bool MoveAction::ReadActionParameters()
{
	return false;
}

MoveAction::MoveAction(ApplicationManager * appmngr) : Action(appmngr)
{
}

void MoveAction::Execute(){	if (!pManager->GetFigCount()) {		pManager->GetOutput()->PrintMessage("No Selected Figures Found");		return;	}	pManager->GetOutput()->PrintMessage("Drag Started");	Point pupput;	pManager->GetInput()->GetPointClicked(pupput.x,pupput.y);	vector<CFigure*> figs = pManager->QuerySelectedForDrag();
	if (!pManager->GetSelectedFigCount()) {
		pManager->GetOutput()->PrintMessage("No Selected Figures Found");
		return;
	}	pair<Point, Point> Pr;	Pr = pManager->Drag();
}