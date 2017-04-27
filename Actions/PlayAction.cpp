#include "PlayAction.h"

#include"..\ApplicationManager.h"

#include"../GUI/Input.h"
#include"../GUI/Output.h"

PlayAction::PlayAction(ApplicationManager* pApp) : Action(pApp)
{
}


bool PlayAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->ClearDrawArea();
	pOut->CreatePlayToolBar(0, false, true);

	ActionType Game = pIn->GetUserAction();

	if (Game == MODE_PLAY_SUB_MENU2_Clicked) {   //pick and hide

		pOut->CreatePlayToolBar(1, false, false);   //show games sub menu

		ActionType TypeOfGame = pIn->GetUserAction(); //See what game the baby wants to play :V
		pOut->CreatePlayToolBar(1, true, false);     //Hide the menu

		switch (TypeOfGame)
		{
		case ITM_BY_TYPE_Clicked:
			///code to call functions to do the logic
			break;

		case ITM_BY_FILLCOL_Clicked:
			///code to call functions to do the logic
			break;

		case ITM_BY_TYPE_AND_FILLCOL_Clicked:
			///code to call functions to do the logic
			break;

		case ITM_BY_AREA_Clicked:
			///code to call functions to do the logic
			break;
		}
	}

	else if (Game == MODE_PLAY_SUB_MENU1_Clicked) {  //scramble and find
		//Team kareem works here
	}
	
	return true;
}


void PlayAction::Execute()
{
	ReadActionParameters();
}