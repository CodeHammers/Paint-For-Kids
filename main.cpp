#include "ApplicationManager.h"
#include "Actions\LoadAction.h"
#include "Actions\PlayAction.h"
string PlayAction::FigureType = "";
color  PlayAction::FigureFillClr = WHITE;
int main()
{

	ActionType ActType;
	//Create an object of ApplicationManager
	ApplicationManager AppManager;
	
	do
	{		
		//Read user action
		ActType = AppManager.GetUserAction();

		//Exexute the action
		AppManager.ExecuteAction(ActType);

		//Update the interface
		AppManager.UpdateInterface();	

	}while(ActType != EXIT);

	return 0;
}