#include"SelectAction.h"

#include"..\ApplicationManager.h"

#include"..\GUI\Input.h"
#include"..\GUI\Output.h"


SelectAction::SelectAction(ApplicationManager* pApp) :Action(pApp)
{
}

bool SelectAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Click inside or on the border of a shape to select");
	pIn->GetPointClicked(P.x, P.y);



}