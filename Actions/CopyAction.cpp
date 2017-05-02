#include"CopyAction.h"

#include"..\Figures\CTriangle.h"
#include"..\Figures\CCircle.h"
#include"..\Figures\CLine.h"
#include"..\Figures\CRectangle.h"

#include"..\GUI\Input.h"
#include"..\GUI\Output.h"

CopyAction::CopyAction(ApplicationManager * pApp)
:Action(pApp)
{
}


bool CopyAction::ReadActionParameters()
{
	Selected = pManager->GetSelectedFigCount();
	return (Selected > 0 ? true : false);
}


CFigure* CopyAction::CopyFigure(CFigure* ptr)
{
	CFigure* NewFigure = ptr->Clone();
	return NewFigure;
}

void CopyAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	if (ReadActionParameters()) {

		if (pManager->GetClipboardSize() > 0)
			pManager->ClearClipboard();

		pManager->CopyToClipboard();
		pOut->PrintMessage("Copy: Figures were copied successfully");
	}
	else {
		pOut->PrintMessage("Copy: No figures were selected, select figures and then click copy");
		return;
	}
}
