#include "ChangeBckgrndColor.h"
#include "..\ApplicationManager.h"

/*	
	ITM_BCKG_WHITE_Clicked,
	ITM_BCKG_BLUE_Clicked,
	ITM_BCKG_RED_Clicked,
	ITM_BCKG_BROWN_Clicked,
	ITM_BCKG_PINK_Clicked,
	ITM_BCKG_NILE_Clicked,
	ITM_BCKG_YELLOW_Clicked,
	ITM_BCKG_ORANE_Clicked,
	ITM_BCKG_PURPLE_Clicked,
	ITM_BCKG_GREEN_Clicked
*/
bool ChangeBckgrndColor::ReadActionParameters()
{
		switch (ActType)
		{
		case ITM_BCKG_WHITE_Clicked:
			BackgroundColor = WHITE;
			break;
		case ITM_BCKG_BLUE_Clicked:
			BackgroundColor = BLUE;
			break;
		case ITM_BCKG_RED_Clicked:
			BackgroundColor = RED;
			break;
		case ITM_BCKG_PINK_Clicked:
			BackgroundColor = PINK;
			break;
		case ITM_BCKG_BROWN_Clicked:
			BackgroundColor = BROWN;
			break;
		case ITM_BCKG_NILE_Clicked:
			BackgroundColor = PURPLE;//DONT KNOW WHAT IS THIS
			break;
		case ITM_BCKG_YELLOW_Clicked:
			BackgroundColor = YELLOW;
			break;
		case ITM_BCKG_ORANE_Clicked:
			BackgroundColor = ORANGE;
			break;
		case ITM_BCKG_PURPLE_Clicked:
			BackgroundColor = PURPLE;
			break;
		case ITM_BCKG_GREEN_Clicked:
			BackgroundColor = GREEN;
			break;
		}
	return true;
}

ChangeBckgrndColor::ChangeBckgrndColor(ApplicationManager* appManager,ActionType actType) : Action(appManager)
{
	this->ActType = actType;
	ReadActionParameters();
}


void ChangeBckgrndColor::Execute()
{
	
	pManager->GetOutput()->ChangeBackgroundColor(BackgroundColor);

}

ChangeBckgrndColor::~ChangeBckgrndColor()
{
}