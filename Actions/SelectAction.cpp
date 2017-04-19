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
	
	while (true) {
		pOut->PrintMessage("Click inside or on the border of a shape to select");
		pIn->GetPointClicked(P.x, P.y);

		/*If the user clicked the select button again, means he wants to
		terminate the selection process, so keep all the selected figures*/
		if (TerminateSelection(P)) {
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
		
		//if(ptr!=NULL) SelectedSoFar.push_back(ptr); //add this figure to the currently selected figures

		/*[1] the user clicked at an empty spot*/
		if (ptr == NULL) {
			Unselect();
			pOut->ClearStatusBar();
			return false;
		}
		else {
			SelectedSoFar.push_back(ptr);  //add this figure to the currently selected figures
			Select(ptr);    //see the select function logic
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
		ptr->ChngDrawClr(UI.HighlightColor);
		ptr->SetSelected(true);
	}
	else {
		ptr->ChngDrawClr(UI.DrawColor);
		ptr->SetSelected(false);
	}
}

void SelectAction::Unselect()
{
	for (int i = 0; i < SelectedSoFar.size(); i++) {
		SelectedSoFar[i]->ChngDrawClr(UI.DrawColor);
		SelectedSoFar[i]->SetSelected(false);
	}
}

