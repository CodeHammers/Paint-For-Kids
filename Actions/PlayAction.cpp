#include "PlayAction.h"

#include"..\ApplicationManager.h"

#include"..\Figures\CRectangle.h"
#include"..\Figures\CCircle.h"
#include"..\Figures\CLine.h"
#include"..\Figures\CTriangle.h"


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

		ActionType subAction,subAction2;

		switch (TypeOfGame)
		{
		case ITM_BY_TYPE_Clicked:
			pOut->CreateDrawToolBarUp(1, false, false);
			subAction = pIn->GetUserAction();
			pOut->CreateDrawToolBarUp(1, true, false);
			UI.InterfaceMode = MODE_PLAY;
			///code to call functions to do the logic
			break;

		case ITM_BY_FILLCOL_Clicked:
			pOut->CreateDrawToolBarUp(3, false, false);
			subAction = pIn->GetUserAction();
			pOut->CreateDrawToolBarUp(3, true, false);
			UI.InterfaceMode = MODE_PLAY;
			///code to call functions to do the logic
			break;

		case ITM_BY_TYPE_AND_FILLCOL_Clicked:
			//choose type
			pOut->CreateDrawToolBarUp(1, false, false);
			subAction = pIn->GetUserAction();
			pOut->CreateDrawToolBarUp(1, true, false);
			//choose fill color
			pOut->CreateDrawToolBarUp(3, false, false);
			subAction2 = pIn->GetUserAction();
			pOut->CreateDrawToolBarUp(3, true, false);
			UI.InterfaceMode = MODE_PLAY;
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

bool PlayAction::CheckFigureType(CFigure* ptr)
{
	CTriangle* T = dynamic_cast<CTriangle*>(ptr);
	if (T)
		return FigureType == "Triangle";

	CCircle* C = dynamic_cast<CCircle*>(ptr);
	if (C)
		return FigureType == "Circle";

	CLine* L = dynamic_cast<CLine*>(ptr);
	if (L)
		return FigureType == "Line";

	CRectangle* R = dynamic_cast<CRectangle*>(ptr);
	if (R)
		return FigureType == "Rectangle";
	return false;
}


bool PlayAction::CheckFigureDrawClr(CFigure* ptr)
{
	color c = (ptr->GetGfxInfo()).DrawClr;
	//return ((ptr->GetGfxInfo()).DrawClr == FigureDrawClr);
	return (c.ucBlue == FigureDrawClr.ucBlue) && (c.ucGreen == FigureDrawClr.ucGreen)
		&& (c.ucRed == FigureDrawClr.ucRed);
}


bool PlayAction::CheckFigureFillClr(CFigure* ptr)
{
	//return ((ptr->GetGfxInfo()).FillClr == FigureFillClr);
	color c = (ptr->GetGfxInfo()).FillClr;
	return (c.ucBlue == FigureFillClr.ucBlue) && (c.ucGreen == FigureFillClr.ucGreen)
		&& (c.ucRed == FigureFillClr.ucRed);
}


void PlayAction::CalcAndQueueAreas()
{
	FigureAreas = pManager->GetFigureAreas();
}

void PlayAction::Execute()
{
	ReadActionParameters();
}