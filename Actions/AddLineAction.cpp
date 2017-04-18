#include "AddLineAction.h"

#include "..\Figures\Cline.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddLineAction::AddLineAction(ApplicationManager* pApp) :Action(pApp)
{
}


void AddLineAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Line: click the first end point");
	pIn->GetPointClicked(P1.x,P1.y);

	pOut->PrintMessage("New Line: click the second end point");
	pIn->GetPointClicked(P2.x, P2.y);

	LineGfxInfo.isFilled = false;	//default is not filled

	//get drawing, filling colors and pen width from the interface
	LineGfxInfo.DrawClr = pOut->getCrntDrawColor();
	LineGfxInfo.FillClr = pOut->getCrntFillColor();
	LineGfxInfo.BorderWdth = pOut->getCrntPenWidth();

	pOut->ClearStatusBar();
}


void AddLineAction::Execute()
{
	//Read the action parameter from the user
	ReadActionParameters();

	//Create the corrosponding object
	CLine* L = new CLine(P1, P2, LineGfxInfo);

	//Save the Line in the figure list
	pManager->AddFigure(L);
}