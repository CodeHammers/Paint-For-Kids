#include"StoryAction.h"

#include"..\GUI\Input.h"
#include"..\GUI\Output.h"

#include"../ApplicationManager.h"

#include <Windows.h>
#include <Mmsystem.h>


StoryAction::StoryAction(ApplicationManager* pApp) :Action(pApp)
{
}


bool StoryAction::ReadActionParameters()
{
	pManager->ExecuteAction(ITM_LOAD_Clicked);
	return true;
}


void StoryAction::Execute()
{
	ReadActionParameters();

	pManager->UpdateInterface();

	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	while (true) {
		pIn->GetPointClicked(P.x, P.y);

		if (Abort(P)) 
			return;
		
		CFigure* ptr = pManager->GetFigure(P.x, P.y);

		if (ptr == NULL) 
			pOut->PrintMessage("Story Mode: you clicked an empty spot, click again");
		
		else {
			string name = ptr->GetName();

			if (name == "Circule") {
				pOut->PrintMessage("Story Mode: you clicked a Circle");
				PlaySound(TEXT("Sounds/Circle.wav"), NULL, SND_FILENAME);
			}
			else if (name == "Line") {
				pOut->PrintMessage("Story Mode: you clicked a Line");
				PlaySound(TEXT("Sounds/Line.wav"), NULL, SND_FILENAME);
			}
			else if (name == "Rectangle") {
				pOut->PrintMessage("Story Mode: you clicked a Rectangle");
				PlaySound(TEXT("Sounds/Rectangle.wav"), NULL, SND_FILENAME);
			}
			else {
				pOut->PrintMessage("Story Mode: you clicked a Triangle");
				PlaySound(TEXT("Sounds/Triangle.wav"), NULL, SND_FILENAME);
			}
		}
	}
}