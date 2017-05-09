#include"SelectAction.h"

#include"..\ApplicationManager.h"

#include"..\GUI\Input.h"
#include"..\GUI\Output.h"


SelectAction::SelectAction(ApplicationManager* pApp) :Action(pApp)
{
}

bool SelectAction::ReadActionParameters()
{

	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Click inside or on the border of a shape to select");
	while (true) {
		
		pIn->GetPointClicked(P.x, P.y);
		if (UI.Zoom == 0)
			UI.Zoom = 1;
		UI.ZoomCenter.x = UI.width / 2;
		UI.ZoomCenter.y = UI.height / 2;
		double z = UI.Zoom;
		UI.Zoom = 1 / UI.Zoom;
		P.x = UI.ZoomCenter.x - UI.Zoom*UI.ZoomCenter.x + UI.Zoom*P.x;
		P.y = UI.ZoomCenter.y - UI.Zoom*UI.ZoomCenter.y + UI.Zoom*P.y;
		UI.Zoom = z;
		/*If the user clicked the select button again, means he wants to
		terminate the selection process, so keep all the selected figures*/
		if (TerminateSelection(P)) {
			if(SelectedSoFar.size()>1)
				pOut->ClearStatusBar();
			return true;
		}


		/*If the user clicks outside the drawing area or clicks the abort 
		button, then the user wants to cancel the operation, unselect*/
		if (!InDrawingArea(P) || Abort(P)) {
			Unselect();
			pOut->ClearStatusBar();
			return false;
		}

		
		/*The user clicked inside the drawing area, so we have three possibilities
		[1] the user clicked in empty position on the drawing area so we unselect everything
		[2] the user clicked inside a non-selected figure so we select it
		[3] the user clicked inside a selected figure so we unselect it*/
		

		ptr = pManager->GetFigure(P.x, P.y); //see where the point
		
		/*[1] the user clicked at an empty spot*/
		if (ptr == NULL) {
			//Unselect();
			pOut->ClearStatusBar();
			return false;
		}
		else {
			Select(ptr);    //see the select function logic

			if(ptr->IsSelected())
				SelectedSoFar.insert(ptr);  //add this figure to the currently selected figures

			if (SelectedSoFar.size() == 1 && (*SelectedSoFar.begin())->IsSelected())
				(*SelectedSoFar.begin())->PrintInfo(pOut);
			else {
				string cnt = to_string(SelectedSoFar.size());
				pOut->PrintMessage("You have selected " + cnt + " figures so far");
			}
		}

		pManager->UpdateInterface();
	}
}


void SelectAction::Execute()
{
	ReadActionParameters();
}


bool SelectAction::InDrawingArea(Point P) const
{
	return (P.x >= 55 && P.x <= 1435 && P.y >= 60 && P.y <= 710);
}

bool SelectAction::TerminateSelection(Point P) const
{
	return (P.x >= 1450 && P.x <= 1500 && P.y >= 450 && P.y <= 500);
}


void SelectAction::Select(CFigure* ptr)
{
	if (!ptr->IsSelected()) {
		//ptr->ChngDrawClr(UI.HighlightColor);
		ptr->SetSelected(true);
	}
	else {
		//ptr->ChngDrawClr(UI.DrawColor);
		ptr->SetSelected(false);
		SelectedSoFar.erase(ptr);
	}
}

void SelectAction::Unselect()
{
	set<CFigure*>::iterator it = SelectedSoFar.begin();
	for (it; it != SelectedSoFar.end(); it++) {
		(*it)->SetSelected(false);
		//(*it)->ChngDrawClr(UI.DrawColor);
	}
	SelectedSoFar.clear();
}