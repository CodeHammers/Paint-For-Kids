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
	Point P= pManager->DragObj(fig);
	fig->CheckPosAfterDrag(P);

}


MoveAction::~MoveAction()
{
}
