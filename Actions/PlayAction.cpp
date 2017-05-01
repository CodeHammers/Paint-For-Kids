#include "PlayAction.h"

#include"..\ApplicationManager.h"

#include"..\Figures\CRectangle.h"
#include"..\Figures\CCircle.h"
#include"..\Figures\CLine.h"
#include"..\Figures\CTriangle.h"
#include "CopyAction.h"
#include "..\defs.h"


#include"../GUI/Input.h"
#include"../GUI/Output.h"

PlayAction::PlayAction(ApplicationManager* pApp) : Action(pApp)
{
	pIn = pManager->GetInput();
	pOut = pManager->GetOutput();
}


bool operator==(color a, color b)
{
	return ((a.ucBlue == b.ucBlue) && (a.ucGreen == b.ucGreen) && (a.ucRed == b.ucRed));
}


bool PlayAction::SetSubActionForColor()
{
	ActionType subAction;
	pOut->CreateDrawToolBarUp(3, false, false);
	subAction = pIn->GetUserAction();
	pOut->CreateDrawToolBarUp(3, true, false);
	UI.InterfaceMode = MODE_PLAY;

	if (subAction == ITM_BRUSHFILL_BLACK_Clicked)	{ FigureFillClr = BLACK    ; return true;}
	if (subAction == ITM_BRUSHFILL_YELLOW_Clicked)  { FigureFillClr = YELLOW   ; return true;}
	if (subAction == ITM_BRUSHFILL_BLUE_Clicked)	{ FigureFillClr = BLUE     ; return true;}
	if (subAction == ITM_BRUSHFILL_BROWN_Clicked)   { FigureFillClr = BROWN    ; return true;}
	if (subAction == ITM_BRUSHFILL_PINK_Clicked)    { FigureFillClr = PINK     ; return true;}
	if (subAction == ITM_BRUSHFILL_GREEN_Clicked)   { FigureFillClr = GREEN    ; return true;}
	if (subAction == ITM_BRUSHFILL_NILE_Clicked)    { FigureFillClr = LIGHTBLUE; return true;}
	if (subAction == ITM_BRUSHFILL_ORANGE_Clicked)  { FigureFillClr = ORANGE   ; return true;}
	if (subAction == ITM_BRUSHFILL_PURPLE_Clicked)  { FigureFillClr = PURPLE   ; return true;}
	if (subAction == ITM_BRUSHFILL_RED_Clicked)		{ FigureFillClr = RED      ; return true;}
	else return false;
	//pManager->UpdateInterface();
}


bool PlayAction::SetSubActionForFigureType()
{
	pOut->CreateDrawToolBarUp(1, false, false);
	ActionType  subAction = pIn->GetUserAction();
	pOut->CreateDrawToolBarUp(1, true, false);
	UI.InterfaceMode = MODE_PLAY;

	if (subAction == DRAW_CIRC) { FigureType = "Circule"; return true; }
	if (subAction == DRAW_TRI) { FigureType = "Triangle"; return true; }
	if (subAction == DRAW_RECT) { FigureType = "Rectangle";return true; }
	if (subAction == DRAW_LINE) { FigureType = "Line"; return true; }
	else return false;
	//pManager->UpdateInterface();
}


bool PlayAction::SetSubActionForColoredFigures()
{
	return SetSubActionForFigureType() && SetSubActionForColor();
}


bool PlayAction::ReadActionParameters()
{
	pOut->CreatePlayToolBar(1, false, false);   //show games sub menu

	ActionType TypeOfGame = pIn->GetUserAction();

	pOut->CreatePlayToolBar(1, true, false);     //Hide the menu

	switch (TypeOfGame)
	{
	case ITM_BY_TYPE_Clicked:
		if (SetSubActionForFigureType()) {
			PlayFigTypeGame();
			pManager->ReturnFromClipboard();
		}
		break;

	case ITM_BY_FILLCOL_Clicked:
		if (SetSubActionForColor()) {
			PlayColorTypeGame();
			pManager->ReturnFromClipboard();
		}
		break;

	case ITM_BY_TYPE_AND_FILLCOL_Clicked:
		if (SetSubActionForColoredFigures()) {
			PlayColoredFigureGame();
			pManager->ReturnFromClipboard();
		}
		break;
	
	case ITM_BY_AREA_Clicked:
		UI.InterfaceMode = MODE_PLAY;
		pManager->UpdateInterface();
		PlayPickByArea();
		pManager->ReturnFromClipboard();
		break;
	}
	return true;
}


void PlayAction:: PlayFigTypeGame() { 
	int NumOfFigures = GetNumOfFigure(); 
	Point P; int Cnt = 0; int FailCnt = 0;

	if (NumOfFigures == 0) {
		pOut->PrintMessage("No figures with the specified type");
		return;
	}

	while (true) {
		pIn->GetPointClicked(P.x, P.y);
		CFigure*ptr = pManager->GetFigure(P.x, P.y);
		
		if (Abort(P)) {
			pOut->PrintMessage("Exiting From The Game .. Success");
			return;
		}
		
		if (ExitClicked(P)) {
			pOut->PrintMessage("Exiting From The Game .. Success");
			return;
		}
	

		if (ptr == NULL) continue;
		//Add if exit clicked and fix abort ya mo2men ya 3el2

		else if (CheckFigureType(ptr)) {
			ptr->SetSelected(true);
			pManager->CutToClipboard(false);
			pManager->DeleteSelected(false); 
			pManager->UpdateInterface();
			pOut->PrintMessage("Bravo.. Now you selected : " + to_string(++Cnt) + " out of :" + to_string(NumOfFigures));
		}

		else {
			pOut->PrintMessage("Pick And Hide: Wrong figure clicked");
			FailCnt++;
		}

		if (Cnt == NumOfFigures) break;
	}

	pOut->PrintMessage("Pick And Hide: Good Job, Correct clicks: " + to_string(Cnt) + " , Wrong clicks: " + to_string(FailCnt));
}


void PlayAction::PlayColorTypeGame()
{
	int NumOfFigures = GetNumOfColorfulFigures();
	Point P; int Cnt = 0; int FailCnt = 0;

	if (NumOfFigures == 0) {
		pOut->PrintMessage("No figures with the specified color");
		return;
	}

	while (true){
		pIn->GetPointClicked(P.x, P.y);
		CFigure*ptr = pManager->GetFigure(P.x, P.y);

		if (Abort(P)) {
			pOut->PrintMessage("Loading :: EXITING FROM THE GAME");
			return;
		}

		if (ExitClicked(P)) {
			pOut->PrintMessage("Loading :: EXITING FROM THE GAME");
			return;
		}

		if (ptr == NULL) continue;
	
		else if (CheckColorType(ptr)) {
			ptr->SetSelected(true);
			pManager->CutToClipboard(false);
			pManager->DeleteSelected(false);
			pManager->UpdateInterface();
			pOut->PrintMessage("Bravo.. Now you selected : " + to_string(++Cnt) + " From :" + to_string(NumOfFigures));
			
		}

		else {
			pOut->PrintMessage("Pick And Hide: Wrong figure clicked");
			FailCnt++;
		}

		if (Cnt == NumOfFigures) break;
	}

	pOut->PrintMessage("Pick And Hide: Good Job, Correct clicks: " + to_string(Cnt) + " , Wrong clicks: " + to_string(FailCnt));
}


void PlayAction::PlayColoredFigureGame()
{
	int NumOfColoredFigures = pManager->GetNumOfColoredFigures();
	Point P; int Cnt = 0; int FailCnt = 0;

	if (NumOfColoredFigures == 0) {
		pOut->PrintMessage("No figures with the specified color/type");
		return;
	}

	while (true) {
		pIn->GetPointClicked(P.x, P.y);
		CFigure*ptr = pManager->GetFigure(P.x, P.y);
		
		if (Abort(P)) {
			pOut->PrintMessage("Exiting From The Game .. Success");
			return;
		}

		if (ExitClicked(P)) {
			pOut->PrintMessage("Exiting From The Game .. Success");
			return;
		}

		if (ptr == NULL) continue;

		else if (CheckColoredFigures(ptr)) {
			ptr->SetSelected(true);
			pManager->CutToClipboard(false);
			pManager->DeleteSelected(false);
			pManager->UpdateInterface();

			pOut->PrintMessage("Bravo.. Now you selected : " + to_string(++Cnt) + " Out of :" + to_string(NumOfColoredFigures));
		}

		else {
			pOut->PrintMessage("Pick And Hide: Wrong figure clicked");
			FailCnt++;
		}

		if (NumOfColoredFigures == Cnt) break;
	}
	pOut->PrintMessage("Pick And Hide: Good Job, Correct clicks: "+to_string(Cnt)+" , Wrong clicks: "+to_string(FailCnt));
}

void PlayAction::PlayPickByArea()
{
	int NumOfFigures = pManager->GetFigCount();
	Point P; int Cnt = 0; int FailCnt = 0;

	if (NumOfFigures == 0) {
		pOut->PrintMessage("You haven't drawn any figures yet, kiddo!");
		return;
	}

	CalcAndQueueAreas();

	while (FigureAreas.size()) {
		pIn->GetPointClicked(P.x, P.y);
		CFigure*ptr = pManager->GetFigure(P.x, P.y);
	
		if (Abort(P)) {
			pOut->PrintMessage("Exiting From The Game .. Success");
			return;
		}

		if (ExitClicked(P)) {
			pOut->PrintMessage("Exiting From The Game .. Success");
			return;
		}
		if (ptr == NULL) continue;

		else if (CorrectArea(ptr)) {
			FigureAreas.pop();
			ptr->SetSelected(true);
			pManager->CutToClipboard(false);
			pManager->DeleteSelected(false);
			pManager->UpdateInterface();

			pOut->PrintMessage("Bravo.. Now you selected : " + to_string(++Cnt) + " Out of :" + to_string(NumOfFigures));
		}

		else {
			pOut->PrintMessage("Pick And Hide: Wrong figure clicked");
			FailCnt++;
		}
	}
	pOut->PrintMessage("Pick And Hide: Good Job, Correct clicks: " + to_string(Cnt) + " , Wrong clicks: " + to_string(FailCnt));
}


bool PlayAction::CorrectArea(CFigure* ptr)
{
	return (ptr->GetArea() == FigureAreas.top());
}

bool PlayAction::ExitClicked(Point P)
{
	if (P.x >= 1435 && P.x <= 1500 && P.y >= 0 && P.y <= 50)
		return true;
	return false;
}


int PlayAction::GetNumOfFigure() {
	return pManager->GetNumOfFigType();
}


int PlayAction::GetNumOfColorfulFigures()
{
	return pManager->GetNumOfColorfulFig();
}


bool PlayAction::CheckFigureType(CFigure* ptr)
{
	CTriangle* T = dynamic_cast<CTriangle*>(ptr);
	if (T)
		return FigureType == "Triangle";

	CCircle* C = dynamic_cast<CCircle*>(ptr);
	if (C)
		return FigureType == "Circule";

	CLine* L = dynamic_cast<CLine*>(ptr);
	if (L)
		return FigureType == "Line";

	CRectangle* R = dynamic_cast<CRectangle*>(ptr);
	if (R)
		return FigureType == "Rectangle";
	return false;
}


bool PlayAction::CheckColoredFigures(CFigure* ptr)
{
	return CheckFigureType(ptr) && CheckColorType(ptr);
}


bool PlayAction::CheckColorType(CFigure* ptr)
{
	if (ptr == NULL) return false;
	return (ptr->GetGfxInfo().isFilled  && ptr->GetGfxInfo().FillClr == FigureFillClr);
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