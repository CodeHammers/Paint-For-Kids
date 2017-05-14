#include "ResizeAction.h"
#include "..\ApplicationManager.h"


/*	ITM_RESIZE25_Clicked,
	ITM_RESIZE50_Clicked,
	ITM_RESIZE200_Clicked,
	ITM_RESIZE400_Clicked,*/
ResizeAction::ResizeAction(ApplicationManager* appmanager,ActionType at) : Action(appmanager)
{
	appManager = appManager;
	actType = at;
}

bool ResizeAction::ReadActionParameters()
{
	switch (actType) {
	case ITM_RESIZE25_Clicked:
		ratio = 0.25;
		break;
	case ITM_RESIZE50_Clicked:
		ratio = 0.5;
		break;
	case ITM_RESIZE200_Clicked:
		ratio = 2;
		break;
	case ITM_RESIZE400_Clicked:
		ratio = 4;
		break;
	}
	return false;
}

void ResizeAction::Execute()
{
	ReadActionParameters();
	if (!pManager->ResizeSelectedFigures(ratio))
		pManager->GetOutput()->PrintMessage("Cannot find any selected figure to resize ");
}


ResizeAction::~ResizeAction()
{
}
