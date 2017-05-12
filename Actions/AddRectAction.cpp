#include "AddRectAction.h"
#include "..\Figures\CRectangle.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddRectAction::AddRectAction(ApplicationManager * pApp):Action(pApp)
{}


bool AddRectAction::ReadActionParameters()
{	
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Rectangle: Click at first corner");

	//loop until a valid point for corner 1 is entered
	while (true) {
		pIn->GetPointClicked(P1.x, P1.y);

		//check if the user wants to abort the action
		if (Abort(P1)) {
			pOut->ClearStatusBar();
			return false;
		}

		//check whether the entered point is outside the drawing area
		if (!CRectangle::InDrawingArea(P1))
			pOut->PrintMessage("New Rectangle: first corner point is out of the drawing area, click again");
		else
			break;
	}

	pOut->PrintMessage("New Rectangle: Click at second corner");

	//loop until a valid point for corner 1 is entered
	while (true) {
		pIn->GetPointClicked(P2.x, P2.y);

		//check if the user wants to abort the action
		if (Abort(P2)) {
			pOut->ClearStatusBar();
			return false;
		}

		//check whether the entered point is outside the drawing area
		if (!CRectangle::InDrawingArea(P2))
			pOut->PrintMessage("New Rectangle: second corner point is out of the drawing area, click again");
		else
			break;
	}

	RectGfxInfo.isFilled = UI.isFilled;	//default is not filled

	//get drawing, filling colors and pen width from the interface
	RectGfxInfo.DrawClr = pOut->getCrntDrawColor();
	RectGfxInfo.FillClr = pOut->getCrntFillColor();
	RectGfxInfo.BorderWdth = pOut->getCrntPenWidth();

	pOut->ClearStatusBar();
	return true;
}


void AddRectAction::Execute() 
{
	//This action needs to read some parameters first
	if (ReadActionParameters()) {
		//Create a rectangle with the parameters read from the user
		CRectangle *R = new CRectangle(P1, P2, RectGfxInfo);

		//Set the ID for the figure
		R->SetID(pManager->GetFigCount() + 1);

		//Add the rectangle to the list of figures
		pManager->AddFigure(R);
	}
}