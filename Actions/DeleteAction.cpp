#include "DeleteAction.h"

#include"..\GUI\Input.h"
#include"..\GUI\Output.h"

#include"..\ApplicationManager.h"


DeleteAction::DeleteAction(ApplicationManager *pApp):Action(pApp)
{
}


bool DeleteAction::ReadActionParameters()
{
	//get the selected figures count before taking any action
	Selected = pManager->GetSelectedFigCount();
	return (Selected > 0 ?  true :  false);
}

void DeleteAction::Execute()
{	
	//gets a pointer to the output class
	Output* pOut = pManager->GetOutput();

	if (ReadActionParameters()) {
		//clean the drawing the area "delete figure effective immediately"
		pOut->ClearDrawArea();

		pOut->PrintMessage("Delete: Successfully deleted selected figures");

		//calls delete selected with a true flag to perform deep deletion 
		pManager->DeleteSelected(true);
	}
	else {
		//the user attempt to delete figures, but he hasn't selected any
		pOut->PrintMessage("Delete: No figures was selected, select figures before clicking delete, kiddo!");
		return;
	}
}