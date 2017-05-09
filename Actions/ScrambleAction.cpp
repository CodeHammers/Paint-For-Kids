#include "ScrambleAction.h"
#include"..\ApplicationManager.h"


ScrambleAction::ScrambleAction(ApplicationManager * appmanager) : Action(appmanager)
{
}

bool ScrambleAction::ReadActionParameters()
{
	return false;
}


void ScrambleAction::Execute()
{
	pManager->BundleFiguresData();
	pManager->ScaleAll();
	pManager->RearrangeFigures();
	StartGame();
}

void ScrambleAction::StartGame() {
	int size = pManager->GetFigCount();
	while (size--) {
		pManager->SelectFigureToScramble(size);
		pManager->UpdateInterface();
		Point p;
		while (pManager->GetInput()->GetPointClicked(p.x,p.y),true) {
			if (Abort(p)) {
				pManager->GetOutput()->PrintMessage("Exiting From The Game .. Success");
				pManager->GetOutput()->ClearDrawArea();
				pManager->ReturnFromClipboard();
				pManager->RollBackChanges();
				return;
			}
	
			if (restart(p)) {
				pManager->RearrangeFigures();
				pManager->GetOutput()->PrintMessage("Restarting  The Game .. Success");
				pManager->GetOutput()->ClearDrawArea();
				RightAnswers = 0; WrongAnswers = 0;
				pManager->ReturnFromClipboard();
				pManager->ClearSelections();
				StartGame();
				return;
			}
			CFigure * fig = pManager->GetFigure(p.x, p.y);
			if (!fig)
				continue;
			if (!fig->IsSelected()) {
				WrongAnswers++;
				pManager->GetOutput()->PrintMessage("You MADE IT ! ....... to the wrong answer :V");
			}
			else {
				RightAnswers++;
				pManager->GetOutput()->PrintMessage("And That one was .... ...  .. .      Right! ;)");
				pManager->CutToClipboard(false);
				pManager->DeleteSelected(false);
				pManager->UpdateInterface();

				break;
			}
		}
	}
	int total = RightAnswers + WrongAnswers;
	pManager->GetOutput()->PrintMessage( "YOu got "+to_string( RightAnswers) + " out of " + to_string(total)+" Attemps" );
	pManager->ReturnFromClipboard();
	pManager->GetOutput()->ClearDrawArea();
	pManager->RollBackChanges();

}
bool ScrambleAction::restart(Point p) {
	int x = p.x;  int y = p.y;
	if (x >= 13 * 50 && x <= 15 * 50 && y >= 0 && y <= 50) 
		if (x < 14 * 50)
			return true;
	return false;
}

ScrambleAction::~ScrambleAction()
{
}
