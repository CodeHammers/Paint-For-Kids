#include "ZoomAction.h"
#include "..\ApplicationManager.h"

bool ZoomAction::ReadActionParameters()
{
	return false;
}

ZoomAction::ZoomAction(ApplicationManager* appManager, ActionType actType) : Action(appManager)
{
	this->actType = actType;
}
/*	// ZOOM ITEMS // 
	ITM_ZOOM_IN_Clicked,
	ITM_ZOOM_OUT_Clicked,*/

void ZoomAction::Execute()
{
	if (actType == ITM_ZOOM_IN_Clicked) {
		pManager->GetOutput()->ChangeZoomLevel(2);
	}
	if (actType == ITM_ZOOM_OUT_Clicked) {
		pManager->GetOutput()->ChangeZoomLevel(0.5);
	}
}
