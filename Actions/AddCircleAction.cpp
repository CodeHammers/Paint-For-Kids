#include"AddCircleAction.h"

#include"..\Figures\CCircle.h"

#include"..\ApplicationManager.h"

#include"..\GUI\Input.h"
#include"..\GUI\Output.h"

AddCircleAction::AddCircleAction(ApplicationManager* pApp) :Action(pApp)
{
}

bool AddCircleAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	
	while (true) {
		pOut->PrintMessage("New Circle: click to position the center");
		while (true) {
			pIn->GetPointClicked(C.x, C.y);
			if (Abort(C)) {
				pOut->ClearStatusBar();
				return false;
			}
			if (!InDrawingArea(C))
				pOut->PrintMessage("New Circle: center is out of the drawing area, click again");
			else
				break;
		}

		pOut->PrintMessage("New Circle: click the end point of the radius");
		while (true) {
			pIn->GetPointClicked(E.x, E.y);
			if (Abort(E)) {
				pOut->ClearStatusBar();
				return false;
			}
			if (!InDrawingArea(E))
				pOut->PrintMessage("New Circle: radius end point is out of the drawing area, click again");
			else
				break;
		}

		//calculate the radius of the circle
		R = (int)sqrt(pow(C.x - E.x, 2) + pow(C.y - E.y, 2));

		if (!(InDrawingArea({ C.x + R,C.y }) && InDrawingArea({ C.x - R,C.y }) && InDrawingArea({ C.x,C.y + R }) && InDrawingArea({ C.x,C.y - R }))) {
			pOut->PrintMessage("New Circle: circle's dimensions are too large to fit, click to try again or abort");
			pIn->GetPointClicked(C.x, C.y);
			if (Abort(C)) {
				pOut->ClearStatusBar();
				return false;
			}
		}
		else
			break;
	}

	CircGfxInfo.isFilled = false;	//default is not filled

	//get drawing, filling colors and pen width from the interface
	CircGfxInfo.DrawClr = pOut->getCrntDrawColor();
	CircGfxInfo.FillClr = pOut->getCrntFillColor();
	CircGfxInfo.BorderWdth = pOut->getCrntPenWidth();

	pOut->ClearStatusBar();
	return true;
}


void AddCircleAction::Execute()
{
	//Read the action parameters
	if (ReadActionParameters()) {

		//Creat the corrosponding object
		CCircle* Circ = new CCircle(C, R, CircGfxInfo);

		//Save the circle in the figure list
		pManager->AddFigure(Circ);
	}
}

bool AddCircleAction::InDrawingArea(Point P) const
{
	return (P.x >= 55 && P.x <= 1435 && P.y >= 60 && P.y <= 710);	  
}