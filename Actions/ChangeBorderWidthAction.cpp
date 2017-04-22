#include "ChangeBorderWidthAction.h"
#include "..\ApplicationManager.h"
/*	ITM_BORDERWIDTH1_Clicked,
	ITM_BORDERWIDTH2_Clicked,
	ITM_BORDERWIDTH3_Clicked,
	ITM_BORDERWIDTH4_Clicked,*/

bool ChangeBorderWidthAction::ReadActionParameters()
{
	switch (ActType)
	{
	case ITM_BORDERWIDTH1_Clicked:
		BorderWidth = 4;
		break;
	case ITM_BORDERWIDTH2_Clicked:
		BorderWidth = 8;
		break;
	case ITM_BORDERWIDTH3_Clicked:
		BorderWidth = 12;
		break;
	case ITM_BORDERWIDTH4_Clicked:
		BorderWidth = 16;
		break;
	}
	return true;
}

ChangeBorderWidthAction::ChangeBorderWidthAction(ApplicationManager* appManager, ActionType actType) : Action(appManager)
{
	this->appManager = appManager;
	this->ActType = actType;
	ReadActionParameters();
}


void ChangeBorderWidthAction::Execute()
{
	appManager->GetOutput()->ChangeBorderWidth(BorderWidth);

}

ChangeBorderWidthAction::~ChangeBorderWidthAction()
{
}