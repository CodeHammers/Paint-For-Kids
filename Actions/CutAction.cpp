#include"AddTriangleAction.h"

#include"..\Figures\CTriangle.h"

#include"..\ApplicationManager.h"

#include"..\GUI\Input.h"
#include"..\GUI\Output.h"
#include "CutAction.h"

CutAction::CutAction(ApplicationManager * pApp)
	:Action(pApp)
{
	CurrentDeleted = 0;
}

void CutAction::RemoveCutElementsFromTheOriginalList()
{

	/* This Fn Make The Pointer that points to the figure i selected = NULL but not delete it so far "" "" 
		The Mechanism of the few next lines is to make the pointer = NULL and shit it to the last of the FigList */
	int Indicator = 199;
	for (int i = 0; i < 200; ++i)
		if (FigList[i] != NULL && FigList[i]->IsPriority()) {
			FigList[i] = NULL; CurrentDeleted++;
			swap(FigList[i], FigList[Indicator--]);
		}
	/* Here ,, if we have a figure in the indx 10 and the elements from indx 1 to indx 9 are equal to null then I shift the element of indx 10 to the first 
	   of The FigList */
	Indicator = 0;
	for (int i = 0; i < 200; ++i)
		if (FigList[i] != NULL)
			swap(FigList[i], FigList[Indicator++]);
	pManager->UpdateFigCount(CurrentDeleted);
}

bool CutAction::ReadActionParameters()
{
	FigList = pManager->GetFigures(); 
	return true;
}

void CutAction::Execute()
{
	ReadActionParameters();
	pManager->CleanClipboard();
	for (int i = 0; i < 200; ++i)
		if (FigList[i] != NULL && FigList[i]->IsSelected()) {
			pManager->AddClipboard(FigList[i]);
			FigList[i]->SetPriority(true);
		}
	RemoveCutElementsFromTheOriginalList();
	Output* pOut = pManager->GetOutput();
	pOut->ClearDrawArea();
}
