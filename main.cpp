#include "ApplicationManager.h"
#include "Actions\LoadAction.h"
#include "Actions\PlayAction.h"
#include "Figures\CCircle.h"
string PlayAction::FigureType = "";
color  PlayAction::FigureFillClr = WHITE;
int main()
{

	ActionType ActType;
	ApplicationManager AppManager;
	//Point p,p2,p3; p.x = 100, p.y = 100;
	//p2.x = p.x + 50; p2.y = p.y;
	//p3.x = p.x; p2.y = p.y + 50;
	//GfxInfo gf; gf.isFilled=false; gf.BorderWdth = 4; gf.DrawClr = BLACK;

	/*CCircle* c = new CCircle(p,20,gf);
	AppManager.AddFigure(c);*/

	int count = 0;
	do
	{		
		//Read user action
		ActType = AppManager.GetUserAction();

		//Exexute the action
		AppManager.ExecuteAction(ActType);

		//Update the interface
		AppManager.UpdateInterface();	
	/*	if (!count) {
			AppManager.DragObj(c);
			count++;
		}*/


	}while(ActType != EXIT);

	return 0;
}