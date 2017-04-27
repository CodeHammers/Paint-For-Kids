#include "PasteAction.h"
#include"..\GUI\Input.h"
#include"..\GUI\Output.h"
#include "..\Figures\CRectangle.h"
#include "..\Figures\CCircle.h"
#include "..\Figures\CTriangle.h"
#include "..\Figures\Cline.h"
#include "SelectAction.h"
#include "..\ApplicationManager.h"


PasteAction::PasteAction(ApplicationManager * pApp):Action(pApp)
{
}


bool PasteAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	ToBePasted = pManager->GetClipboardSize();
	if (ToBePasted == 0) {
		pOut->PrintMessage("Paste: The clipboard is empty, copy or cut some figures and then click paste");
		return false;
	}

	pOut->PrintMessage("Paste: Click to paste");

	while (true) {
		pIn->GetPointClicked(P.x, P.y);

		if (Abort(P))
			return false;

		if (!InDrawingArea(P))
			pOut->PrintMessage("Paste: You clicked outside the drawing area, click again");
		else
			return true;
	}
}

void PasteAction::Execute()
{
	Output* pOut = pManager->GetOutput();

	if (ReadActionParameters()) {
		Point ORIGIN = pManager->GetTheTopFigure();
		Point Transfer = { P.x - ORIGIN.x,P.y - ORIGIN.y };
		pManager->AddPastedFigures(Transfer);
	}
	else
		return;
}

bool PasteAction::InDrawingArea(Point O)
{
	return (O.x >= 55 && O.x <= 1435 && O.y >= 60 && O.y <= 710);
}