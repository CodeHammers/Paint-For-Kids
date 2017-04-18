#include"AddCircleAction.h"

#include"..\Figures\CCircle.h"

#include"..\ApplicationManager.h"

#include"..\GUI\Input.h"
#include"..\GUI\Output.h"

AddCircleAction::AddCircleAction(ApplicationManager* pApp) :Action(pApp)
{
}

void AddCircleAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Circle: click to position the center");
	pIn->GetPointClicked(C.x,C.y);

	pOut->PrintMessage("New Circle: click the end point of the radius");
	pIn->GetPointClicked(E.x, E.y);

	//calculate the radius of the circle
	R = (int)sqrt(pow(C.x - E.x, 2) + pow(C.y - E.y, 2));

	CircGfxInfo.isFilled = false;	//default is not filled

	//get drawing, filling colors and pen width from the interface
	CircGfxInfo.DrawClr = pOut->getCrntDrawColor();
	CircGfxInfo.FillClr = pOut->getCrntFillColor();
	CircGfxInfo.BorderWdth = pOut->getCrntPenWidth();

	pOut->ClearStatusBar();
}


void AddCircleAction::Execute()
{
	//Read the action parameters
	ReadActionParameters();

	//Creat the corrosponding object
	CCircle* Circ = new CCircle(C, R, CircGfxInfo);

	//Save the circle in the figure list
	pManager->AddFigure(Circ);
}