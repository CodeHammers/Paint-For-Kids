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

#include <Windows.h>
#include <Mmsystem.h>

PlayAction::PlayAction(ApplicationManager* pApp) : Action(pApp)
{
	//gets pointer to input/output classes for frequent use
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
	//show the pick by fill color menu
	pOut->CreateDrawToolBarUp(3, false, false);
	//get user input "choice of color"
	subAction = pIn->GetUserAction();
	//hide the pick by color menu
	pOut->CreateDrawToolBarUp(3, true, false);
	//set the mode from "sub menu" back to "play mode"
	UI.InterfaceMode = MODE_PLAY;

	//set the fill color depending on user input
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
}


bool PlayAction::SetSubActionForFigureType()
{
	ActionType subAction;
	//show the pick by figure type menu
	pOut->CreateDrawToolBarUp(1, false, false);
	//get user action
	subAction = pIn->GetUserAction();
	//hide the pick by figure type menu
	pOut->CreateDrawToolBarUp(1, true, false);
	//set the mode from "sub menu" back to "play mode"
	UI.InterfaceMode = MODE_PLAY;

	//set the figure type depending on user input
	if (subAction == DRAW_CIRC) { FigureType = "Circule"; return true; }
	if (subAction == DRAW_TRI) { FigureType = "Triangle"; return true; }
	if (subAction == DRAW_RECT) { FigureType = "Rectangle";return true; }
	if (subAction == DRAW_LINE) { FigureType = "Line"; return true; }
	else return false;
}


bool PlayAction::SetSubActionForColoredFigures()
{
	//sets the parameters for the pick by color/type action
	return SetSubActionForFigureType() && SetSubActionForColor();
}


bool PlayAction::ReadActionParameters()
{
	//show games sub menu
	pOut->CreatePlayToolBar(1, false, false);   
	//get user action
	ActionType TypeOfGame = pIn->GetUserAction();  
	//Hide the menu
	pOut->CreatePlayToolBar(1, true, false);     
	
	switch (TypeOfGame)
	{
	case ITM_BY_TYPE_Clicked:
		if (SetSubActionForFigureType()) {    //set pick by type game parameters
			PlayFigTypeGame();                //play pick by type
			pManager->ReturnFromClipboard();  //restore the intial state of the fig list
		}
		break;

	case ITM_BY_FILLCOL_Clicked: 
		if (SetSubActionForColor()) {         //set pick by fill color game parameters
			PlayColorTypeGame();              //play pick by fill color
			pManager->ReturnFromClipboard();  //restore the intial state of the fig list
		}
		break;

	case ITM_BY_TYPE_AND_FILLCOL_Clicked:
		if (SetSubActionForColoredFigures()) {   //set pick by fill color and type game parameters
			PlayColoredFigureGame();             //play fill color and type
			pManager->ReturnFromClipboard();     //restore the intial state of the fig list
		}
		break;
	
	case ITM_BY_AREA_Clicked:
		UI.InterfaceMode = MODE_PLAY;        
		pManager->UpdateInterface();  ///malhash lazma
		PlayPickByArea();                    //play pick by figure area
		pManager->ReturnFromClipboard();     //restore the intial state of the fig list
		break;
	}
	return true;
}


void PlayAction::PlayFigTypeGame() { 
	int NumOfFigures = GetNumOfFigure();   //gets the number of desired figures 
	Point P; int Cnt = 0; int FailCnt = 0;  //variables to keep track of the user progress

	//if the user has no figures drawn at all or no figures of the desired type
	if (NumOfFigures == 0) {
		pOut->PrintMessage("No figures with the specified type");
		return;
	}

	//loop until the game is finished or the user aborts
	while (true) {
		pIn->GetPointClicked(P.x, P.y);  

		//gets the figure that encloses the clicked point
		CFigure*ptr = pManager->GetFigure(P.x, P.y);
		
		//check if the user wants to abort
		if (Abort(P)) {
			pOut->PrintMessage("Exiting From The Game .. Success");
			return;
		}
		
		//check if the user wants to exit the game
		if (ExitClicked(P)) {
			pOut->PrintMessage("Exiting From The Game .. Success");
			return;
		}
	
		//if the user clicked on an empty spot, wait for another click
		if (ptr == NULL) continue;
		
		//check the clicked figure
		else if (CheckFigureType(ptr)) {
			/*The following sequence of function calls make the selected figure disappear*/
			ptr->SetSelected(true);
			pManager->CutToClipboard(false);
			pManager->DeleteSelected(false); 
			pManager->UpdateInterface();

			//show the user his progress
			pOut->PrintMessage("Bravo.. Now you selected : " + to_string(++Cnt) + " out of :" + to_string(NumOfFigures));
			PlaySound(TEXT("Sounds/CorrectAnswer.wav"), NULL, SND_FILENAME);
		}

		else {
			//if the figure clicked the wrong figure
			pOut->PrintMessage("Pick And Hide: Wrong figure clicked");
			PlaySound(TEXT("Sounds/WrongAnswer.wav"), NULL, SND_FILENAME);
			FailCnt++;
		}

		if (Cnt == NumOfFigures) break;   //has the game ended?
	}

	//game ended, show user statistics
	pOut->PrintMessage("Pick And Hide: Good Job, Correct clicks: " + to_string(Cnt) + " , Wrong clicks: " + to_string(FailCnt));
	PlaySound(TEXT("Sounds/GameFinished.wav"), NULL, SND_FILENAME);
}


void PlayAction::PlayColorTypeGame()
{
	int NumOfFigures = GetNumOfColorfulFigures(); //gets the number of desired figures 
	Point P; int Cnt = 0; int FailCnt = 0;  //variables to keep track of the user progress

	//if the user has no figures drawn at all or no figures of the desired type
	if (NumOfFigures == 0) {
		pOut->PrintMessage("No figures with the specified color");
		return;
	}

	//loop until the game is finished or the user aborts
	while (true){
		pIn->GetPointClicked(P.x, P.y);

		//gets the figure that encloses the clicked point
		CFigure*ptr = pManager->GetFigure(P.x, P.y);

		//check if the user wants to abort
		if (Abort(P)) {
			pOut->PrintMessage("Loading :: EXITING FROM THE GAME");
			return;
		}

		//check if the user wants to exit the game
		if (ExitClicked(P)) {
			pOut->PrintMessage("Loading :: EXITING FROM THE GAME");
			return;
		}

		//if the user clicked on an empty spot, wait for another click
		if (ptr == NULL) continue;
	
		//check the clicked figure
		else if (CheckColorType(ptr)) {
			/*The following sequence of function calls make the selected figure disappear*/
			ptr->SetSelected(true);
			pManager->CutToClipboard(false);
			pManager->DeleteSelected(false);
			pManager->UpdateInterface();

			//show the user his progress
			pOut->PrintMessage("Bravo.. Now you selected : " + to_string(++Cnt) + " From :" + to_string(NumOfFigures));
			PlaySound(TEXT("Sounds/CorrectAnswer.wav"), NULL, SND_FILENAME);
		}

		else {
			//if the figure clicked the wrong figure
			pOut->PrintMessage("Pick And Hide: Wrong figure clicked");
			PlaySound(TEXT("Sounds/WrongAnswer.wav"), NULL, SND_FILENAME);
			FailCnt++;
		}

		if (Cnt == NumOfFigures) break;   //has the game ended?
	}

	//game ended, show user statistics
	pOut->PrintMessage("Pick And Hide: Good Job, Correct clicks: " + to_string(Cnt) + " , Wrong clicks: " + to_string(FailCnt));
	PlaySound(TEXT("Sounds/GameFinished.wav"), NULL, SND_FILENAME);
}


void PlayAction::PlayColoredFigureGame()
{
	int NumOfColoredFigures = pManager->GetNumOfColoredFigures(); //gets the number of desired figures 
	Point P; int Cnt = 0; int FailCnt = 0;  //variables to keep track of the user progress

	//if the user has no figures drawn at all or no figures of the desired type
	if (NumOfColoredFigures == 0) {
		pOut->PrintMessage("No figures with the specified color/type");
		return;
	}

	//loop until the game is finished or the user aborts
	while (true) {
		pIn->GetPointClicked(P.x, P.y);

		//gets the figure that encloses the clicked point
		CFigure*ptr = pManager->GetFigure(P.x, P.y);
		
		//check if the user wants to abort
		if (Abort(P)) {
			pOut->PrintMessage("Exiting From The Game .. Success");
			return;
		}

		//check if the user wants to exit the game
		if (ExitClicked(P)) {
			pOut->PrintMessage("Exiting From The Game .. Success");
			return;
		}

		//if the user clicked on an empty spot, wait for another click
		if (ptr == NULL) continue;

		//check the clicked figure
		else if (CheckColoredFigures(ptr)) {
			/*The following sequence of function calls make the selected figure disappear*/
			ptr->SetSelected(true);
			pManager->CutToClipboard(false);
			pManager->DeleteSelected(false);
			pManager->UpdateInterface();

			//show the user his progress
			pOut->PrintMessage("Bravo.. Now you selected : " + to_string(++Cnt) + " Out of :" + to_string(NumOfColoredFigures));
			PlaySound(TEXT("Sounds/CorrectAnswer.wav"), NULL, SND_FILENAME);
		}

		else {
			//if the figure clicked the wrong figure
			pOut->PrintMessage("Pick And Hide: Wrong figure clicked");
			PlaySound(TEXT("Sounds/WrongAnswer.wav"), NULL, SND_FILENAME);
			FailCnt++;
		}

		if (NumOfColoredFigures == Cnt) break;  //has the game ended?
	}
	//game ended, show user statistics
	pOut->PrintMessage("Pick And Hide: Good Job, Correct clicks: "+to_string(Cnt)+" , Wrong clicks: "+to_string(FailCnt));
	PlaySound(TEXT("Sounds/GameFinished.wav"), NULL, SND_FILENAME);
}

void PlayAction::PlayPickByArea()
{
	int NumOfFigures = pManager->GetFigCount();  //gets the number of desired figures 
	Point P; int Cnt = 0; int FailCnt = 0;  //variables to keep track of the user progress

	//if the user has no figures drawn at all or no figures of the desired type
	if (NumOfFigures == 0) {
		pOut->PrintMessage("You haven't drawn any figures yet, kiddo!");
		return;
	}

	//calls a function to calculate and queue up figures with respect to their areas in an ascending order
	CalcAndQueueAreas();

	//loop until the game is finished or the user aborts
	while (FigureAreas.size()) {
		pIn->GetPointClicked(P.x, P.y);

		//gets the figure that encloses the clicked point
		CFigure*ptr = pManager->GetFigure(P.x, P.y);
	
		//check if the user wants to abort
		if (Abort(P)) {
			pOut->PrintMessage("Exiting From The Game .. Success");
			return;
		}

		//check if the user wants to exit the game
		if (ExitClicked(P)) {
			pOut->PrintMessage("Exiting From The Game .. Success");
			return;
		}

		//if the user clicked on an empty spot, wait for another click
		if (ptr == NULL) continue;

		//check the clicked figure
		else if (CorrectArea(ptr)) {
			/*The following sequence of function calls make the selected figure disappear*/
			FigureAreas.pop();
			ptr->SetSelected(true);
			pManager->CutToClipboard(false);
			pManager->DeleteSelected(false);
			pManager->UpdateInterface();

			//show the user his progress
			pOut->PrintMessage("Bravo.. Now you selected : " + to_string(++Cnt) + " Out of :" + to_string(NumOfFigures));
			PlaySound(TEXT("Sounds/CorrectAnswer.wav"), NULL, SND_FILENAME);
		}

		else {
			//if the figure clicked the wrong figure
			pOut->PrintMessage("Pick And Hide: Wrong figure clicked");
			PlaySound(TEXT("Sounds/WrongAnswer.wav"), NULL, SND_FILENAME);
			FailCnt++;
		}
	}
	//game ended, show user statistics
	pOut->PrintMessage("Pick And Hide: Good Job, Correct clicks: " + to_string(Cnt) + " , Wrong clicks: " + to_string(FailCnt));
	PlaySound(TEXT("Sounds/GameFinished.wav"), NULL, SND_FILENAME);
}


bool PlayAction::CorrectArea(CFigure* ptr)
{
	/*Check if the clicked figure's area matches the area on the top of the heap "the smallest"*/
	return (ptr->GetArea() == FigureAreas.top());
}


bool PlayAction::ExitClicked(Point P)
{
	//checks if the user clicked the exit icon
	if (P.x >= 1435 && P.x <= 1500 && P.y >= 0 && P.y <= 50)
		return true;
	return false;
}


int PlayAction::GetNumOfFigure() {
	//gets the number of figures under pre-spcified conditions (fig type)
	return pManager->GetNumOfFigType();
}


int PlayAction::GetNumOfColorfulFigures()
{
	//gets the number of figures under pre-spcified conditions (colored figures)
	return pManager->GetNumOfColorfulFig();
}


bool PlayAction::CheckFigureType(CFigure* ptr)
{
	//function to check the figure type
	string MyName = ptr->GetName();
	return (FigureType == MyName);
}


bool PlayAction::CheckColoredFigures(CFigure* ptr)
{
	//check a figure under type/fill color conditions
	return CheckFigureType(ptr) && CheckColorType(ptr);
}


bool PlayAction::CheckColorType(CFigure* ptr)
{
	if (ptr == NULL) return false;
	return (ptr->GetGfxInfo().isFilled  && ptr->GetGfxInfo().FillClr == FigureFillClr);
}


void PlayAction::CalcAndQueueAreas()
{
	//calculates and queues figure areas
	FigureAreas = pManager->GetFigureAreas();
}

void PlayAction::Execute()
{
	ReadActionParameters();
}