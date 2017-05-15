#include "MoveAction.h"



bool MoveAction::ReadActionParameters()
{
	return false;
}

MoveAction::MoveAction(ApplicationManager * appmngr) : Action(appmngr)
{
}

void MoveAction::Execute()
{
	pManager->GetOutput()->PrintMessage("Choose figure you want to move");
	Point p;
	pManager->GetInput()->GetPointClicked(p.x, p.y);
	CFigure *fig= pManager->GetFigure(p.x,p.y);
	if (fig == NULL)
		return;
	Point P= Drag(fig);
	fig->CheckPosAfterDrag(P);

}

Point MoveAction::Drag(CFigure * fig)
{
	Output* pOut = pManager->GetOutput();
	fig->Drag(true);
	int iX, iY;
	UI.DragState = true;
	pOut->setBuffering(false);
	char cKeyData;
	// Flush out the input queues before beginning
	pOut->FlushMouse();
	pOut->setBuffering(true);
	Point pp;
	fig->SetStartingDragPoint(pp);
	int RectULX = pp.x;
	int RectULY = pp.y;
	int RectWidth = 20;
	bool bDragging = false;
	iX = iY = 0;
	int iXOld = 0;
	int iYOld = 0;
	// Loop until there escape is pressed
	while (!pOut->EscapeClicked())
	{
		pManager->UpdateInterface();
		// Dragging voodoo
		if (bDragging == false) {
			if (pOut->getButtonState(iX, iY) == BUTTON_DOWN) {
				if (((iX > RectULX) && (iX < (RectULX + RectWidth))) && ((iY > RectULY) && (iY < (RectULY + RectWidth)))) {
					bDragging = true;
					iXOld = iX; iYOld = iY;
				}
			}
		}
		else {
			if (pOut->getButtonState(iX, iY) == BUTTON_UP) {
				bDragging = false;
			}
			else {
				if (iX != iXOld) {
					RectULX = RectULX + (iX - iXOld);
					iXOld = iX;
				}
				if (iY != iYOld) {
					RectULY = RectULY + (iY - iYOld);
					iYOld = iY;
				}
			}
		}
		Point p1, p2;
		p1.x = RectULX;
		p1.y = RectULY;
		p2.x = RectULX + RectWidth;
		p2.y = RectULY + RectWidth;
		GfxInfo gf; gf.isFilled = false; gf.BorderWdth = 3; gf.DrawClr = BLACK;
		pp = p1;
		fig->DrawDragged(pOut, p1);
		pOut->UpdateBuffer();
	}
	pOut->setBuffering(false);
	pManager->UpdateInterface();
	UI.DragState = false;
	fig->Drag(false);
	return pp;
}


MoveAction::~MoveAction()
{

}
