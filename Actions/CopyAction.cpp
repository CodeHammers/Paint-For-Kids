#include"CopyAction.h"

#include"..\Figures\CTriangle.h"
#include"..\Figures\CCircle.h"
#include"..\Figures\CLine.h"
#include"..\Figures\CRectangle.h"

#include"..\GUI\Input.h"
#include"..\GUI\Output.h"

CopyAction::CopyAction(ApplicationManager * pApp):Action(pApp)
{
}


bool CopyAction::ReadActionParameters()
{
	//get the selected figures count before taking any action
	Selected = pManager->GetSelectedFigCount();
	return (Selected > 0 ? true : false);
}


CFigure* CopyAction::CopyFigure(CFigure* ptr)
{
	//clones the current figure "makes an exact copy and returns it"
	CFigure* NewFigure = ptr->Clone();
	return NewFigure;
}


void CopyAction::Execute()
{
	//gets a pointer to the output class
	Output* pOut = pManager->GetOutput();

	if (ReadActionParameters()) {

		//if the clipboard contains previous copies, clear the clipboard
		if (pManager->GetClipboardSize() > 0)
			pManager->ClearClipboard();

		//calls a function to copy the figures and add them to the fig list
		pManager->CopyToClipboard(); 

		pOut->PrintMessage("Copy: Figures were copied successfully");
	}
	else {
		//the user attempt to copy figures, but he hasn't selected any
		pOut->PrintMessage("Copy: No figures were selected, select figures and then click copy");
		return;
	}
}