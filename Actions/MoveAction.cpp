#include "MoveAction.h"



bool MoveAction::ReadActionParameters()
{
	return false;
}

MoveAction::MoveAction(ApplicationManager * appmngr) : Action(appmngr)
{
}

void MoveAction::Execute(){	pManager->GetOutput()->PrintMessage("Drag Started");	while (!pManager->GetOutput()->EscapeClicked()) {	}	vector<CFigure*> figs = pManager->QuerySelectedForDrag();
	if (!pManager->GetSelectedFigCount()) {
		pManager->GetOutput()->PrintMessage("No Selected Figures Found");
		return;
	}	pair<Point, Point> Pr;	Pr = pManager->Drag();
}

pair<Point,Point> MoveAction::Drag(vector<CFigure*>figs)
{
	Point ref = pManager->GetTheTopFigureOfSelected();
	Output* pOut = pManager->GetOutput();
	for (int i = 0; i < figs.size(); i++) 	figs[i]->Drag(true);
	int iX, iY;
	UI.DragState = true;
	pOut->setBuffering(false);
	// Flush out the input queues before beginning
	pOut->FlushMouse();
	pOut->setBuffering(true);
	int RectULX = ref.x;
	int RectULY = ref.y;
	int RectWidth = 20;
	bool bDragging = false;
	iX = iY = 0;
	int iXOld = 0;
	int iYOld = 0;	Point d;
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
		Point p1;
		p1.x = RectULX;
		p1.y = RectULY;
		d = { ref.x - p1.x,ref.y - p1.y };
		d.x = -d.x; d.y = -d.y;
		for (int i = 0; i < figs.size(); i++) {
			Point po;
			figs[i]->SetStartingDragPoint(po);
			po = { po.x + d.x ,po.y + d.y };
			figs[i]->DrawDragged(pOut, po);
		}
		pOut->UpdateBuffer();
	}
	pOut->setBuffering(false);
	pManager->UpdateInterface();
	UI.DragState = false;
	for (int i = 0; i < figs.size(); i++) 	figs[i]->Drag(false);
	return make_pair(ref,d);
}