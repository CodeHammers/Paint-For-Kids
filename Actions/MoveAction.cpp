#include"MoveAction.h"

#include"../ApplicationManager.h"

MoveAction::MoveAction(ApplicationManager* pApp):Action(pApp)
{
}

bool MoveAction::ReadActionParameters()
{
	int Selected = pManager->GetSelectedFigCount();
	return (Selected > 0 ? true : false);
}
void MoveAction::Execute()
{
	if (ReadActionParameters()) {

	}
}