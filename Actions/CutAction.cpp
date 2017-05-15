#include"AddTriangleAction.h"

#include"..\Figures\CTriangle.h"

#include"..\ApplicationManager.h"

#include"..\GUI\Input.h"
#include"..\GUI\Output.h"
#include "CutAction.h"

#include <Windows.h>
#include <Mmsystem.h>

CutAction::CutAction(ApplicationManager * pApp) : Action(pApp)
{
}


bool CutAction::ReadActionParameters()
{
	//get the selected figures count before taking any action
	Selected = pManager->GetSelectedFigCount();
	return (Selected > 0 ? true : false);
}

void CutAction::Execute()
{
	//gets a pointer to the output class
	Output* pOut = pManager->GetOutput();

	if (ReadActionParameters()) {

		//if the clipboard contains previous cuts, clear the clipboard
		if (pManager->GetClipboardSize() > 0)
			pManager->ClearClipboard();

		//Calls cut to clipboard with a false flag to avoid unselecting figures
		pManager->CutToClipboard(false);

		//calls a function to delete the selected figures with a false flag to perfrom shallow delete
		pManager->DeleteSelected(false);

		pOut->PrintMessage("Cut: Figures were cut successfully");
		pOut->ClearDrawArea();
	}
	else {
		//the user attempt to cut figures, but he hasn't selected any
		pOut->PrintMessage("Cut: No selceted figures, select some figures then click cut");
		PlaySound(TEXT("Sounds/Error.wav"), NULL, SND_FILENAME);
		return;
	}
}