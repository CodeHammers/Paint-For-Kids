#include "PickAndHide.h"

#include"..\ApplicationManager.h"

#include"..\Figures\CRectangle.h"
#include"..\Figures\CCircle.h"
#include"..\Figures\CLine.h"
#include"..\Figures\CTriangle.h"
#include "CopyAction.h"
#include "..\defs.h"


#include"../GUI/Input.h"
#include"../GUI/Output.h"

PickAndHide::PickAndHide(ApplicationManager* pApp) : Action(pApp)
{
	pIn = pManager->GetInput();
	pOut = pManager->GetOutput();
}


bool operator==(color a, color b)
{
	return ((a.ucBlue == b.ucBlue) && (a.ucGreen == b.ucGreen) && (a.ucRed == b.ucRed));
}


void PickAndHide::SetSubActionForColor()
{
	ActionType subAction;
	pOut->CreateDrawToolBarUp(3, false, false);
	subAction = pIn->GetUserAction();
	if (subAction == ITM_BRUSHFILL_BLACK_Clicked)	{ FigureFillClr = BLACK    ; }
	if (subAction == ITM_BRUSHFILL_YELLOW_Clicked)  { FigureFillClr = YELLOW   ; }
	if (subAction == ITM_BRUSHFILL_BLUE_Clicked)	{ FigureFillClr = BLUE     ; }
	if (subAction == ITM_BRUSHFILL_BROWN_Clicked)   { FigureFillClr = BROWN    ; }
	if (subAction == ITM_BRUSHFILL_PINK_Clicked)    { FigureFillClr = PINK     ; }
	if (subAction == ITM_BRUSHFILL_GREEN_Clicked)   { FigureFillClr = GREEN    ; }
	if (subAction == ITM_BRUSHFILL_NILE_Clicked)    { FigureFillClr = LIGHTBLUE; }
	if (subAction == ITM_BRUSHFILL_ORANGE_Clicked)  { FigureFillClr = ORANGE   ; }
	if (subAction == ITM_BRUSHFILL_PURPLE_Clicked)  { FigureFillClr = PURPLE   ; }
	if (subAction == ITM_BRUSHFILL_RED_Clicked)		{ FigureFillClr = RED      ; }
	pOut->CreateDrawToolBarUp(3, true, false);

	UI.InterfaceMode = MODE_PLAY;

	//pManager->UpdateInterface();
}


void PickAndHide::SetSubActionForFigureType()
{
	pOut->CreateDrawToolBarUp(1, false, false);
	ActionType  subAction = pIn->GetUserAction();
	pOut->CreateDrawToolBarUp(1, true, false);
	if (subAction == DRAW_CIRC) { FigureType = "Circule"  ;	}
	if (subAction == DRAW_TRI)  { FigureType = "Triangle" ;	}
	if (subAction == DRAW_RECT) { FigureType = "Rectangle"; }
	if (subAction == DRAW_LINE) { FigureType = "Line"     ;	}
	UI.InterfaceMode = MODE_PLAY;

	//pManager->UpdateInterface();
}


void PickAndHide::SetSubActionForColoredFigures()
{
	SetSubActionForFigureType();
	SetSubActionForColor();
}


bool PickAndHide::ReadActionParameters()
{
	pOut->CreatePlayToolBar(1, false, false);   //show games sub menu

	ActionType TypeOfGame = pIn->GetUserAction();
		
	pOut->CreatePlayToolBar(1, true, false);     //Hide the menu

	switch (TypeOfGame)
	{
	case ITM_BY_TYPE_Clicked:
		SetSubActionForFigureType();
		PlayFigTypeGame();
		pManager->ReturnFromClipboard();
		break;

	case ITM_BY_FILLCOL_Clicked:
		SetSubActionForColor();
		PlayColorTypeGame();
		pManager->ReturnFromClipboard();
		break;

	case ITM_BY_TYPE_AND_FILLCOL_Clicked:
		SetSubActionForColoredFigures();
		PlayColoredFigureGame();
		pManager->ReturnFromClipboard();
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

/*pOut->CreatePlayToolBar(0, true, false);
pOut->CreateDrawToolBarUp(0, false, false);
pOut->CreateDrawToolBarRight(false, false);*/

void PickAndHide:: PlayFigTypeGame() {
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


void PickAndHide::PlayColorTypeGame()
{
	int NumOfFigures = GetNumOfColorfulFigures();
	Point P; int Cnt = 0; int FailCnt = 0;

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


void PickAndHide::PlayColoredFigureGame()
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

void PickAndHide::PlayPickByArea()
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


bool PickAndHide::CorrectArea(CFigure* ptr)
{
	return (ptr->GetArea() == FigureAreas.top());
}

bool PickAndHide::ExitClicked(Point P)
{
	if (P.x >= 1435 && P.x <= 1500 && P.y >= 0 && P.y <= 50)
		return true;
	return false;
}


int PickAndHide::GetNumOfFigure() {
	return pManager->GetNumOfFigType();
}


int PickAndHide::GetNumOfColorfulFigures()
{
	return pManager->GetNumOfColorfulFig();
}


bool PickAndHide::CheckFigureType(CFigure* ptr)
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


bool PickAndHide::CheckColoredFigures(CFigure* ptr)
{
	return CheckFigureType(ptr) && CheckColorType(ptr);
}


bool PickAndHide::CheckColorType(CFigure* ptr)
{
	if (ptr == NULL) return false;
	return (ptr->GetGfxInfo().isFilled  && ptr->GetGfxInfo().FillClr == FigureFillClr);
}


bool PickAndHide::CheckFigureDrawClr(CFigure* ptr)
{
	color c = (ptr->GetGfxInfo()).DrawClr;
	//return ((ptr->GetGfxInfo()).DrawClr == FigureDrawClr);
	return (c.ucBlue == FigureDrawClr.ucBlue) && (c.ucGreen == FigureDrawClr.ucGreen)
		&& (c.ucRed == FigureDrawClr.ucRed);
}


bool PickAndHide::CheckFigureFillClr(CFigure* ptr)
{
	//return ((ptr->GetGfxInfo()).FillClr == FigureFillClr);
	color c = (ptr->GetGfxInfo()).FillClr;
	return (c.ucBlue == FigureFillClr.ucBlue) && (c.ucGreen == FigureFillClr.ucGreen)
		&& (c.ucRed == FigureFillClr.ucRed);
}


void PickAndHide::CalcAndQueueAreas()
{
	FigureAreas = pManager->GetFigureAreas();
}

void PickAndHide::Execute()
{
	ReadActionParameters();
}