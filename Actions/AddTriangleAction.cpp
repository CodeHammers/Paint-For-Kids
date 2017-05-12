#include"AddTriangleAction.h"

#include"..\Figures\CTriangle.h"

#include"..\ApplicationManager.h"

#include"..\GUI\Input.h"
#include"..\GUI\Output.h"


AddTriangleAction::AddTriangleAction(ApplicationManager* pApp) :Action(pApp)
{
}


bool AddTriangleAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Triangle: click to position vertex #1");

	//loop until a valid point is entered for vertex #1
	while (true) {
		pIn->GetPointClicked(P1.x, P1.y);

		//check if the user wants to abort the action
		if (Abort(P1)) {
			pOut->ClearStatusBar();
			return false;
		}

		//check whether the entered point is outside the drawing area
		if (!CTriangle::InDrawingArea(P1))
			pOut->PrintMessage("New Triangle: first vertex is out of the drawing area, click again");
		else
			break;
	}

	pOut->PrintMessage("New Triangle: click to position vertex #2");

	//loop until a valid point is entered for vertex #2
	while (true) {
		pIn->GetPointClicked(P2.x, P2.y);

		//check if the user wants to abort the action
		if (Abort(P2)) {
			pOut->ClearStatusBar();
			return false;
		}

		//check whether the entered point is outside the drawing area
		if (!CTriangle::InDrawingArea(P2))
			pOut->PrintMessage("New Triangle: second vertex is out of the drawing area, click again");
		else
			break;
	}

	pOut->PrintMessage("New Triangle: click to position vertex #3");

	//loop until a valid point is entered for vertex #3
	while (true) {
		pIn->GetPointClicked(P3.x, P3.y);

		//check if the user wants to abort the action
		if (Abort(P3)) {
			pOut->ClearStatusBar();
			return false;
		}

		//check whether the entered point is outside the drawing area
		if (!CTriangle::InDrawingArea(P3))
			pOut->PrintMessage("New Triangle: third vertex is out of the drawing area, click again");
		else
			break;
	}

	TriangleGfxInfo.isFilled = UI.isFilled;	//default is not filled

	//get drawing, filling colors and pen width from the interface
	TriangleGfxInfo.DrawClr = pOut->getCrntDrawColor();
	TriangleGfxInfo.FillClr = pOut->getCrntFillColor();
	TriangleGfxInfo.BorderWdth = pOut->getCrntPenWidth();

	pOut->ClearStatusBar();
	return true;
}


void AddTriangleAction::Execute()
{
	//Get action parameters
	if (ReadActionParameters()) {

		//Create the corrosponding object
		CTriangle* Triangle = new CTriangle(P1, P2, P3, TriangleGfxInfo);

		//Set the ID for the figure
		Triangle->SetID(pManager->GetFigCount() + 1);

		//Save the figure in the figure list
		pManager->AddFigure(Triangle);
	}
}