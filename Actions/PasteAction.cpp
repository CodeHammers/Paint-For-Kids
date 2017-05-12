#include "PasteAction.h"

#include "..\ApplicationManager.h"

#include"..\GUI\Input.h"
#include"..\GUI\Output.h"

#include "..\Figures\CRectangle.h"
#include "..\Figures\CCircle.h"
#include "..\Figures\CTriangle.h"
#include "..\Figures\Cline.h"

#include "SelectAction.h"


PasteAction::PasteAction(ApplicationManager * pApp):Action(pApp)
{
}


bool PasteAction::ReadActionParameters()
{
	//gets a pointer to the output/input classes
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//gets the number of the currently in the clipboard figures
	ToBePasted = pManager->GetClipboardSize();

	//if the clipboard is empty, do nothing
	if (ToBePasted == 0) {
		pOut->PrintMessage("Paste: The clipboard is empty, copy or cut some figures and then click paste");
		return false;
	}

	//if not, query the user for a destination point
	pOut->PrintMessage("Paste: Click to paste");

	//loop until a valid point is entered
	while (true) {
		pIn->GetPointClicked(P.x, P.y);

		//if the user wants to abort the action
		if (Abort(P))
			return false;

		//check whether the point is outside the drawing area
		if (!InDrawingArea(P))
			pOut->PrintMessage("Paste: You clicked outside the drawing area, click again");
		else
			return true;
	}
}

void PasteAction::Execute()
{
	//gets a pointer the output class
	Output* pOut = pManager->GetOutput();

	if (ReadActionParameters()) {
		//calls a function to calculate a reference point 
		Point ORIGIN = pManager->GetTheTopFigure();

		//set the reference point to use it for figures transitioning
		Point Transfer = { P.x - ORIGIN.x,P.y - ORIGIN.y };

		//calls a function to paste the figures and transfer them to the desired position
		pManager->AddPastedFigures(Transfer);
	}
	else
		return;
}

bool PasteAction::InDrawingArea(Point O)
{
	return (O.x >= 55 && O.x <= 1435 && O.y >= 60 && O.y <= 710);
}