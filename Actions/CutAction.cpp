#include"AddTriangleAction.h"

#include"..\Figures\CTriangle.h"

#include"..\ApplicationManager.h"

#include"..\GUI\Input.h"
#include"..\GUI\Output.h"
#include "CutAction.h"

CutAction::CutAction(ApplicationManager * pApp) : Action(pApp)
{
}

bool CutAction::ReadActionParameters()
{
	Selected = pManager->GetSelectedFigCount();
	return (Selected > 0 ? true : false);
}

void CutAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	if (ReadActionParameters()) {

		if (pManager->GetClipboardSize() > 0)
			pManager->ClearClipboard();

		pManager->MoveSelectedToClipboard(false);
		pManager->DeleteSelected(false);
		pManager->MoveSelectedToClipboard(true);
		pOut->PrintMessage("Cut: Figures were cut successfully");
		pOut->ClearDrawArea();
	}
	else {
		pOut->PrintMessage("Cut: No selceted figures, select some figures then click cut");
		return;
	}
}