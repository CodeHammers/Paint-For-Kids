#include "ChangeDrawColorAction.h"
#include "..\ApplicationManager.h"

/*
ITM_BRUSH_BLACK_Clicked,
ITM_BRUSH_YELLOW_Clicked,
ITM_BRUSH3_BLUE_Clicked,
ITM_BRUSH_BROWN_Clicked,
ITM_BRUSH_PINK_Clicked,
ITM_BRUSH_GREEN_Clicked,
ITM_BRUSH_NILE_Clicked,
ITM_BRUSH_ORANGE_Clicked,
ITM_BRUSH_PURPLE_Clicked,
ITM_BRUSH_RED_Clicked,
ITM_COLLAPSELEFT_Clicked,
*/
bool ChangeDrawColorAction::ReadActionParameters()
{
	switch (ActType)
	{
	case ITM_BRUSH_BLACK_Clicked:
		DrawColor = BLACK;
		break;
	case ITM_BRUSH_YELLOW_Clicked:
		DrawColor = YELLOW;
		break;
	case ITM_BRUSH3_BLUE_Clicked:
		DrawColor = BLUE;
		break;
	case ITM_BRUSH_BROWN_Clicked:
		DrawColor = BROWN;
		break;
	case ITM_BRUSH_PINK_Clicked:
		DrawColor = PINK;
		break;
	case ITM_BRUSH_GREEN_Clicked:
		DrawColor = GREEN;
		break;
	case ITM_BRUSH_NILE_Clicked://??!!
		DrawColor = LIGHTBLUE;
		break;
	case ITM_BRUSH_ORANGE_Clicked:
		DrawColor = ORANGE;
		break;
	case ITM_BRUSH_PURPLE_Clicked:
		DrawColor = PURPLE;
		break;
	case ITM_BRUSH_RED_Clicked:
		DrawColor = RED;
		break;
	}
	return true;
}

ChangeDrawColorAction::ChangeDrawColorAction(ApplicationManager* appManager, ActionType actType) : Action(appManager)
{
	this->appManager = appManager;
	this->ActType = actType;
	ReadActionParameters();
}


void ChangeDrawColorAction::Execute()
{
	pManager->ChangeDrwClrForSelected(DrawColor);
	appManager->GetOutput()->ChangeDrawColor(DrawColor);
}

ChangeDrawColorAction::~ChangeDrawColorAction()
{
}