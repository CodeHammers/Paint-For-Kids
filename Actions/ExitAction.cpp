#include"ExitAction.h"

#include"..\ApplicationManager.h"

#include"..\GUI\Input.h"
#include"..\GUI\Output.h"

#include"..\Actions\SaveAction.h"

ExitAction::ExitAction(ApplicationManager* pApp) :Action(pApp)
{
}


bool ExitAction::ReadActionParameters()
{
	//get the current figures count before taking any action
	FigCount = pManager->GetFigCount();
	return (FigCount > 0 ? true : false);
}


void ExitAction::Execute()
{
	//gets a pointer to the output/input class
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	if (ReadActionParameters()) {
		pOut->PrintMessage("Exit Action: you might have some unsaved work, click to save to save it, or click anywhere to exit");
		
		ActionType Action = pIn->GetUserAction();
		if (Action == ITM_SAVEAS_Clicked) 
			pManager->ExecuteAction(Action);
	}
	pManager->Exit();
}