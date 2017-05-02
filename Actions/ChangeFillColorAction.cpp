#include "ChangeFillColor.h"
#include "..\ApplicationManager.h"

/*
ITM_BRUSHFILL_BLACK_Clicked,
ITM_BRUSHFILL_YELLOW_Clicked,
ITM_BRUSHFILL_BLUE_Clicked,
ITM_BRUSHFILL_BROWN_Clicked,
ITM_BRUSHFILL_PINK_Clicked,
ITM_BRUSHFILL_GREEN_Clicked,
ITM_BRUSHFILL_NILE_Clicked,
ITM_BRUSHFILL_ORANGE_Clicked,
ITM_BRUSHFILL_PURPLE_Clicked,
ITM_BRUSHFILL_RED_Clicked,
*/
bool ChangeFillColor::ReadActionParameters()
{
	switch (ActType)
	{
	case ITM_BRUSHFILL_BLACK_Clicked:
		DrawColor = BLACK;
		break;
	case ITM_BRUSHFILL_YELLOW_Clicked:
		DrawColor = YELLOW;
		break;
	case ITM_BRUSHFILL_BLUE_Clicked:
		DrawColor = BLUE;
		break;
	case ITM_BRUSHFILL_BROWN_Clicked:
		DrawColor = BROWN;
		break;
	case ITM_BRUSHFILL_PINK_Clicked:
		DrawColor = PINK;
		break;
	case ITM_BRUSHFILL_GREEN_Clicked:
		DrawColor = GREEN;
		break;
	case ITM_BRUSHFILL_NILE_Clicked://??!!
		DrawColor = LIGHTBLUE;
		break;
	case ITM_BRUSHFILL_ORANGE_Clicked:
		DrawColor = ORANGE;
		break;
	case ITM_BRUSHFILL_PURPLE_Clicked:
		DrawColor = PURPLE;
		break;
	case ITM_BRUSHFILL_RED_Clicked:
		DrawColor = RED;
		break;
	}
	return true;
}

ChangeFillColor::ChangeFillColor(ApplicationManager* appManager, ActionType actType) : Action(appManager)
{
	this->appManager = appManager;
	this->ActType = actType;
	ReadActionParameters();
}


void ChangeFillColor::Execute()
{
	pManager->ChangeFillClrForSelected(DrawColor);
	appManager->GetOutput()->ChangeFillColor(DrawColor);
}


ChangeFillColor::~ChangeFillColor()
{
}