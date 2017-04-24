#include"CopyAction.h"

#include"..\Figures\CTriangle.h"

#include"..\GUI\Input.h"
#include"..\GUI\Output.h"

CopyAction::CopyAction(ApplicationManager * pApp)
:Action(pApp)
{
}

bool CopyAction::ReadActionParameters()
{
	FigList = pManager->GetFigures();
	pManager->CleanClipboard();
	return true;
}

void CopyAction::Execute()
{
	ReadActionParameters();
	for (int i = 0; i < 200; ++i)
		if (FigList[i] != NULL && FigList[i]->IsSelected())
			pManager->AddClipboard(FigList[i]);
		else if (FigList[i] == NULL) return;
}
