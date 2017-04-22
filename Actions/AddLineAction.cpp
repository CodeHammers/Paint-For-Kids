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
	while (true) {
		pIn->GetPointClicked(P1.x, P1.y);
		if (Abort(P1)) {
			pOut->ClearStatusBar();
			return false;
		}
		if (!CLine::InDrawingArea(P1))
			pOut->PrintMessage("New Line: first end point is out of the drawing area, click again");
		else
			break;
	}

	pOut->PrintMessage("New Line: click the second end point");
	while (true) {
		pIn->GetPointClicked(P2.x, P2.y);
		if (Abort(P2)) {
			pOut->ClearStatusBar();
			return false;
		}
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

		//Save the Line in the figure list
		pManager->AddFigure(L);
	}
}