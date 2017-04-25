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
	CTriangle* T = dynamic_cast<CTriangle*>(ptr);
	if (T) {
		CTriangle* NewTriangle = new CTriangle(T->GetVertex1(), T->GetVertex2(), T->GetVertex3(), T->GetGfxInfo());
		NewTriangle->SetID(T->GetID());
		return NewTriangle;
	}

	CCircle* C = dynamic_cast<CCircle*>(ptr);
	if (C) {
		CCircle* NewCircle = new CCircle(C->GetCenter(), C->GetRadius(), C->GetGfxInfo());
		NewCircle->SetID(C->GetID());
		return NewCircle;
	}

	CLine* L = dynamic_cast<CLine*>(ptr);
	if (L) {
		CLine* NewLine = new CLine(L->GetEndPoint1(), L->GetEndPoint2(), L->GetGfxInfo());
		NewLine->SetID(L->GetID());
		return NewLine;
	}

	CRectangle* R = dynamic_cast<CRectangle*>(ptr);
	if (R) {
		CRectangle* NewRectangle = new CRectangle(R->GetCorner1(), R->GetCorner2(), R->GetGfxInfo());
		NewRectangle->SetID(R->GetID());
		return NewRectangle;
	}
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
