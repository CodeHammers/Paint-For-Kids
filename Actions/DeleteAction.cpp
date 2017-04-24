#include "DeleteAction.h"

#include"..\GUI\Input.h"
#include"..\GUI\Output.h"

#include"..\ApplicationManager.h"

DeleteAction::DeleteAction(ApplicationManager *pApp)
:Action(pApp)
{
	CurrentDeleted = 0;
}

bool DeleteAction::ReadActionParameters()
{
	FigList = pManager->GetFigures();
	return true;
}

void DeleteAction::UpdateAfterDelete()
{
	ReadActionParameters();
	/* This Fn Make The Pointer that points to the figure i selected = NULL and delete it !!! 
	The Mechanism of the few next lines is to make the pointer = NULL and shit it to the last of the FigList */
	int Indicator = 199;
	for (int i = 0; i < 200; ++i)
		if (FigList[i] != NULL && FigList[i]->IsSelected()) {
			delete FigList[i];	FigList[i] = NULL; CurrentDeleted++;
			swap(FigList[i], FigList[Indicator--]);
		}
	/* Here ,, if we have a figure in the indx 10 and the elements from indx 1 to indx 9 are equal to null then I shift the element of indx 10 to the first
	of The FigList */
	Indicator = 0;
	for (int i = 0; i < 200; ++i)
		if (FigList[i] != NULL)
			swap(FigList[i], FigList[Indicator++]);
}


void DeleteAction::Execute()
{	
	Output* pOut = pManager->GetOutput();
	UpdateAfterDelete();
	pManager->UpdateFigCount(CurrentDeleted);
	pOut->ClearDrawArea();
}
