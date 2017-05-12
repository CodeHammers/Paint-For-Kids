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
		
		//loop until a valid center point is entered
		while (true) {
			pIn->GetPointClicked(C.x, C.y);

			//check if the user wants to cancel the action
			if (Abort(C)) {
				pOut->ClearStatusBar();
				return false;
			}

			//if the user clicks outside the drawing area, discard the current point and ask again
			if (!CCircle::InDrawingArea(C))
				pOut->PrintMessage("New Circle: center is out of the drawing area, click again");
			else
				break;
		}

		pOut->PrintMessage("New Circle: click the end point of the radius");

		//loop until a valid radius end point is entered
		while (true) {
			pIn->GetPointClicked(E.x, E.y);

			//check if the user wants to cancel the action
			if (Abort(E)) {
				pOut->ClearStatusBar();
				return false;
			}

			//if the user clicks outside the drawing area, discard the current point and ask again
			if (!CCircle::InDrawingArea(E))
				pOut->PrintMessage("New Circle: radius end point is out of the drawing area, click again");
			else
				break;
		}

		//calculate the radius of the circle
		R = (int)sqrt(pow(C.x - E.x, 2) + pow(C.y - E.y, 2));

		//check if the dimensions of the circle would fully fit in the drawing area
		//if it's not valid, click again to resart the drawing process or abort the action
		if (!CCircle::ValidToDraw(C,R)) {
			pOut->PrintMessage("New Circle: circle's dimensions are too large to fit, click to try again or abort");
			pIn->GetPointClicked(C.x, C.y);

			//if the user decided to abort the action
			if (Abort(C)) {
				pOut->ClearStatusBar();
				return false;
			}
		}
		else
			break;
	}

	CircGfxInfo.isFilled = UI.isFilled;	//default is not filled

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

		//Set the ID for the figure
		Circ->SetID(pManager->GetFigCount() + 1);

		//Save the circle in the figure list
		pManager->AddFigure(Circ);
	}
}