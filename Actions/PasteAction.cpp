#include "PasteAction.h"
#include"..\GUI\Input.h"
#include"..\GUI\Output.h"
#include "..\Figures\CRectangle.h"
#include "..\Figures\CCircle.h"
#include "..\Figures\CTriangle.h"
#include "..\Figures\Cline.h"
#include "SelectAction.h"
#include "..\ApplicationManager.h"
PasteAction::PasteAction(ApplicationManager * pApp)
	:Action(pApp)
{
	for (int i = 0; i < 100; ++i)
		Temp[i] = NULL;
	Actual_CountTemp = 0;
}

void PasteAction::AddTemp(CFigure* pFig)
{
	Temp[Actual_CountTemp++] = pFig;
}

bool PasteAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();	
	Input* pIn = pManager->GetInput();

	FigList = pManager->GetFigures();
	Clipboard = pManager->GetFigures(true);
	OriginPoint = GetTheOrigin();
	pOut->PrintMessage("please Click On an Appropriate point");
	pIn->GetPointClicked(TransitionPoint.x, TransitionPoint.y);
	
	if (Abort(TransitionPoint))
		return false;
	if (!InDrawingArea(TransitionPoint))
		return false;
	
	pOut->ClearStatusBar();
	return true;
}

void PasteAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	GfxInfo Info;
	Info.BorderWdth = 3;
	Info.DrawClr = pOut->getCrntDrawColor();
	Info.isFilled = false;
	if (ReadActionParameters()) {
		for (int i = 0; i < 200; ++i) {
			if (Clipboard[i] == NULL)
				break;
			CTriangle * ptr = dynamic_cast<CTriangle *>(Clipboard[i]);
			if (ptr) {
				if (InDrawingArea(ptr->GetFirstVertex()) && InDrawingArea(ptr->GetSecondVertex()) && InDrawingArea(ptr->GetThirdVertex())) {
					CTriangle * NewShape = new CTriangle(ptr->GetFirstVertex(), ptr->GetSecondVertex(), ptr->GetThirdVertex(), Info);
					AddTemp(NewShape);
				}
				continue;
			}
			CCircle * ptr2 = dynamic_cast<CCircle *>(Clipboard[i]);
			if (ptr2) {
				Point C = ptr2->GetFirstVertex(); int R = ptr2->GetRadius();
				if ((InDrawingArea({ C.x + R,C.y }) && InDrawingArea({ C.x - R,C.y }) && InDrawingArea({ C.x,C.y + R }) && InDrawingArea({ C.x,C.y - R }))) {
					CCircle * NewShape = new CCircle(C, R, Info);
					AddTemp(NewShape);
				}
				continue;
			}
			CLine * ptr3 = dynamic_cast<CLine *>(Clipboard[i]);
			if (ptr3) {
				if (InDrawingArea(ptr3->GetFirstVertex()) && InDrawingArea(ptr3->GetSecondVertex())) {
					CLine * NewShape = new CLine(ptr3->GetFirstVertex(), ptr3->GetSecondVertex(), Info);
					AddTemp(NewShape);
				}
				continue;
			}
			CRectangle * ptr4= dynamic_cast<CRectangle *>(Clipboard[i]);
			if (ptr4) {
				if (InDrawingArea(ptr4->GetFirstVertex()) && InDrawingArea(ptr4->GetSecondVertex())) {
					CRectangle * NewShape = new CRectangle(ptr4->GetFirstVertex(), ptr4->GetSecondVertex(), Info);
					AddTemp(NewShape);
				}
				continue;
			}
		}
		TransitionFigures();
		AddtoFigList();
	}
}

Point PasteAction::GetTheOrigin()
{
	Point P = { 2000,2000 };
	for (int i = 0; i < 100; ++i)
		if (Clipboard[i] != NULL)
			if (Clipboard[i]->GetFirstVertex().y < P.y)
				P = Clipboard[i]->GetFirstVertex();
	return P;
}

bool PasteAction::InDrawingArea(Point P) const
{
	return (P.x >= 55 && P.x <= 1435 && P.y >= 60 && P.y <= 710);
}

void PasteAction::TransitionFigures()
{
	int A = TransitionPoint.x - OriginPoint.x;
	int B = TransitionPoint.y - OriginPoint.y;
	Point P{ A,B };

	for (int i = 0; i < 200; ++i) {
		if (Temp[i] == NULL)
			return;
		Temp[i]->SetPoints(P);
	}
}

void PasteAction::AddtoFigList()
{
	for (int i = 0; i < Actual_CountTemp; ++i)
		pManager->AddFigure(Temp[i]);
}
