#include "DeleteAction.h"

#include"..\GUI\Input.h"
#include"..\GUI\Output.h"

#include"..\ApplicationManager.h"

DeleteAction::DeleteAction(ApplicationManager *pApp):Action(pApp)
{
}

bool DeleteAction::ReadActionParameters()
{
	Selected = pManager->GetSelectedFigCount();
	return (Selected > 0 ?  true :  false);
}

void DeleteAction::Execute()
{	
	Output* pOut = pManager->GetOutput();
	if (ReadActionParameters()) {
		pOut->ClearDrawArea();
		pOut->PrintMessage("Delete: Successfully deleted selected figures");
		pManager->DeleteSelected(true);
	}
	else {
		pOut->PrintMessage("Delete: No figures was selected, select figures before clicking delete, kiddo!");
		return;
	}
}
