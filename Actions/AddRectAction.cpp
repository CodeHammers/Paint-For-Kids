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
	while (true) {
		pIn->GetPointClicked(P1.x, P1.y);
		if (Abort(P1)) {
			pOut->ClearStatusBar();
			return false;
		}
		if (!InDrawingArea(P1))
			pOut->PrintMessage("New Rectangle: first corner point is out of the drawing area, click again");
		else
			break;
	}

	pOut->PrintMessage("New Rectangle: Click at second corner");
	while (true) {
		pIn->GetPointClicked(P2.x, P2.y);
		if (Abort(P2)) {
			pOut->ClearStatusBar();
			return false;
		}
		if (!InDrawingArea(P2))
			pOut->PrintMessage("New Rectangle: second corner point is out of the drawing area, click again");
		else
			break;
	}

	RectGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	RectGfxInfo.DrawClr = pOut->getCrntDrawColor();
	RectGfxInfo.FillClr = pOut->getCrntFillColor();
	RectGfxInfo.BorderWdth = pOut->getCrntPenWidth();

	pOut->ClearStatusBar();
	return true;
}

//Execute the action
void AddRectAction::Execute() 
{
	//This action needs to read some parameters first
	if (ReadActionParameters()) {

		//Create a rectangle with the parameters read from the user
		CRectangle *R = new CRectangle(P1, P2, RectGfxInfo);

		//Add the rectangle to the list of figures
		pManager->AddFigure(R);
	}
}

bool AddRectAction::InDrawingArea(Point P) const
{
	return (P.x >= 55 && P.x <= 1435 && P.y >= 60 && P.y <= 710);
}
