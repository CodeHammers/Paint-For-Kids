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
	pManager->ScaleAll();
}

ScrambleAction::~ScrambleAction()
{
}
