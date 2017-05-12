#include "SendToAction.h"

#include"..\ApplicationManager.h"

#include"..\GUI\Input.h"
#include"..\GUI\Output.h"

SendToAction::SendToAction(int mode, ApplicationManager* pApp):Action(pApp)
{
	SendToMode = mode;
}

bool SendToAction::ReadActionParameters()
{
	//get the selected figures count before taking any action
	Selected = pManager->GetSelectedFigCount();
	return (Selected > 0 ? true : false);
}

void SendToAction::Execute()
{
	//gets a pointer to the output class
	Output* pOut = pManager->GetOutput();

	if (ReadActionParameters()) {
		pManager->SendSelectedTo(SendToMode);
	}
	else {
		//the user attempt to send figures, but he hasn't selected any
		pOut->PrintMessage("Send To: No selceted figures, select some figures then click again");
		return;
	}
}