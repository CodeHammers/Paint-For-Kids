#include"AddTriangleAction.h"

#include"..\Figures\CTriangle.h"

#include"..\ApplicationManager.h"

#include"..\GUI\Input.h"
#include"..\GUI\Output.h"


AddTriangleAction::AddTriangleAction(ApplicationManager* pApp) :Action(pApp)
{
}


void AddTriangleAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Triangle: click to position vertex #1");
	pIn->GetPointClicked(P1.x, P1.y);

	pOut->PrintMessage("New Triangle: click to position vertex #2");
	pIn->GetPointClicked(P2.x, P2.y);

	pOut->PrintMessage("New Triangle: click to position vertex #3");
	pIn->GetPointClicked(P3.x, P3.y);

	TriangleGfxInfo.isFilled = false;	//default is not filled

	//get drawing, filling colors and pen width from the interface
	TriangleGfxInfo.DrawClr = pOut->getCrntDrawColor();
	TriangleGfxInfo.FillClr = pOut->getCrntFillColor();
	TriangleGfxInfo.BorderWdth = pOut->getCrntPenWidth();

	pOut->ClearStatusBar();
}


void AddTriangleAction::Execute()
{
	//Get action parameters
	ReadActionParameters();

	//Create the corrosponding object
	CTriangle* Triangle = new CTriangle(P1, P2, P3, TriangleGfxInfo);

	//Save the figure in the figure list
	pManager->AddFigure(Triangle);
}