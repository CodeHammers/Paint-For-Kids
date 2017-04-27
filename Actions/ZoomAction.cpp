#include "ZoomAction.h"
#include "..\ApplicationManager.h"

bool ZoomAction::ReadActionParameters()
{
	return false;
}

ZoomAction::ZoomAction(ApplicationManager* appManager, ActionType actType) : Action(appManager)
{
	this->appManager = appManager;
	this->actType = actType;
}
/*	// ZOOM ITEMS // 
	ITM_ZOOM_IN_Clicked,
	ITM_ZOOM_OUT_Clicked,*/

void ZoomAction::Execute()
{
	if (actType == ITM_ZOOM_IN_Clicked) {
		if (!appManager->CheckValidityOfZoom(2)) {
			appManager->GetOutput()->PrintMessage("Woooooooow,That's is too much for me to handle ,kid");
			return;
		}

		appManager->GetOutput()->ChangeZoomLevel(2);
	}
	if (actType == ITM_ZOOM_OUT_Clicked) {
		if (!appManager->CheckValidityOfZoom(0.5)) {
			appManager->GetOutput()->PrintMessage("Woooooooow,That's is too much for me to handle ,kid");
			return;
		}
		appManager->GetOutput()->ChangeZoomLevel(0.5);
	}
}
