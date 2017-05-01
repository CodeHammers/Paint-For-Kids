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
	LetsStartTheGaaaame();
}

void ScrambleAction::LetsStartTheGaaaame() {
	int size = pManager->GetFigCount();
	while (size--) {
		pManager->SelectFigureToScramble();
		pManager->UpdateInterface();
		Point p;
		while (pManager->GetInput()->GetPointClicked(p.x,p.y),true) {
			CFigure * fig = pManager->GetFigure(p.x, p.y);
			if (!fig)
				continue;
			if (!fig->IsSelected()) {
				WrongAnswers++;
				pManager->GetOutput()->PrintMessage("You MADE IT ! ....... to the wrong answer :V");
			}
			else {
				RightAnswers++;
				fig->SetSelected(false);
				pManager->GetOutput()->PrintMessage("And That one was .... ...  .. .      Right! ;)");
				break;
			}
		}
	}
	int total = RightAnswers + WrongAnswers;
	pManager->GetOutput()->PrintMessage( "YOu got "+to_string( RightAnswers) + " out of " + to_string(total)+" Attemps" );
}

ScrambleAction::~ScrambleAction()
{
}
