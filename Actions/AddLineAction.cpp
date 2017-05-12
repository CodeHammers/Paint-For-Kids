#include "AddLineAction.h"

#include "..\Figures\Cline.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddLineAction::AddLineAction(ApplicationManager* pApp) :Action(pApp)
{
}


bool AddLineAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Line: click the first end point");

	//loop until a valid end point 1 is entered 
	while (true) {
		pIn->GetPointClicked(P1.x, P1.y);

		//check if the user wants to abort the action
		if (Abort(P1)) {
			pOut->ClearStatusBar();
			return false;
		}

		//check whether the point clicked is outside the drawing area
		if (!CLine::InDrawingArea(P1))
			pOut->PrintMessage("New Line: first end point is out of the drawing area, click again");
		else
			break;
	}

	pOut->PrintMessage("New Line: click the second end point");

	//loop until a valid end point 2 is entered 
	while (true) {
		pIn->GetPointClicked(P2.x, P2.y);

		//check if the user wants to abort the action
		if (Abort(P2)) {
			pOut->ClearStatusBar();
			return false;
		}

		//check whether the point clicked is outside the drawing area
		if (!CLine::InDrawingArea(P2))
			pOut->PrintMessage("New Line: second end point is out of the drawing area, click again");
		else
			break;
	}

	LineGfxInfo.isFilled = false;	//default is not filled

	//get drawing, filling colors and pen width from the interface
	LineGfxInfo.DrawClr = pOut->getCrntDrawColor();
	LineGfxInfo.FillClr = pOut->getCrntFillColor();
	LineGfxInfo.BorderWdth = pOut->getCrntPenWidth();

	pOut->ClearStatusBar();
	return true;
}


void AddLineAction::Execute()
{
	//Read the action parameter from the user
	if (ReadActionParameters()) {

		//Create the corrosponding object
		CLine* L = new CLine(P1, P2, LineGfxInfo);

		//Set the ID for the figure
		L->SetID(pManager->GetFigCount() + 1);

		//Save the Line in the figure list
		pManager->AddFigure(L);
	}
}