#include "ApplicationManager.h"
#include "Actions\AddRectAction.h"


//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();
	
	FigCount = 0;
		
	//Create an array of figure pointers and set them to NULL		
	for(int i=0; i<MaxFigCount; i++)
		FigList[i] = NULL;	
}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
ActionType ApplicationManager::GetUserAction() const
{
	//Ask the input to get the action from the user.
	ActionType Type = pIn->GetUserAction(), ret;

	switch (Type) {

	case MODE_DRAW_SUB_MENU1_Clicked:   //figures
		pOut->CreateDrawToolBarUp(1, false);  //show sub menu
		ret = pIn->GetUserAction();  //get action(figure option)
		pOut->CreateDrawToolBarUp(1, true);  //hide sub menu
		return ret;

	case MODE_DRAW_SUB_MENU2_Clicked:  //pens
		pOut->CreateDrawToolBarUp(2, false);  //show sub menu
		ret = pIn->GetUserAction();  //get action(figure option)
		pOut->CreateDrawToolBarUp(2, true);  //hide sub menu
		return ret;

	case MODE_DRAW_SUB_MENU3_Clicked:
		pOut->CreateDrawToolBarUp(3, false);  //show sub menu
		ret = pIn->GetUserAction();  //get action(figure option)
		pOut->CreateDrawToolBarUp(3, true);  //hide sub menu
		return ret;

	case MODE_DRAW_SUB_MENU4_Clicked:
		pOut->CreateDrawToolBarUp(4, false);  //show sub menu
		ret = pIn->GetUserAction();  //get action(figure option)
		pOut->CreateDrawToolBarUp(4, true);  //hide sub menu
		return ret;

	case MODE_DRAW_SUB_MENU5_Clicked:
		pOut->CreateDrawToolBarUp(5, false);  //show sub menu
		ret = pIn->GetUserAction();  //get action(figure option)
		pOut->CreateDrawToolBarUp(5, true);  //hide sub menu
		return ret; 
	}
}
////////////////////////////////////////////////////////////////////////////////////
//Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType) 
{
	Action* pAct = NULL;
	
	//According to Action Type, create the corresponding action object
	switch (ActType)
	{
		
		case DRAW_RECT:
			pAct = new AddRectAction(this);
			break;

		case DRAW_LINE:
			///create AddLineAction here

			break;

		case EXIT:
			///create ExitAction here
			
			break;
		
		case STATUS:	//a click on the status bar ==> no action
			return;
	}
	
	//Execute the created action
	if(pAct != NULL)
	{
		pAct->Execute();//Execute
		delete pAct;	//Action is not needed any more ==> delete it
		pAct = NULL;
	}
}
//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//

//Add a figure to the list of figures
void ApplicationManager::AddFigure(CFigure* pFig)
{
	if(FigCount < MaxFigCount )
		FigList[FigCount++] = pFig;	
}
////////////////////////////////////////////////////////////////////////////////////
CFigure *ApplicationManager::GetFigure(int x, int y) const
{
	//If a figure is found return a pointer to it.
	//if this point (x,y) does not belong to any figure return NULL


	///Add your code here to search for a figure given a point x,y	

	return NULL;
}
//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{	
	for(int i=0; i<FigCount; i++)
		FigList[i]->Draw(pOut);		//Call Draw function (virtual member fn)
}
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the input
Input *ApplicationManager::GetInput() const
{	return pIn; }
//Return a pointer to the output
Output *ApplicationManager::GetOutput() const
{	return pOut; }
////////////////////////////////////////////////////////////////////////////////////
//Destructor
ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<FigCount; i++)
		delete FigList[i];
	delete pIn;
	delete pOut;
	
}
