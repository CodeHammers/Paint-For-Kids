#include "LoadAction.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

#include "..\Figures\CRectangle.h"

#include <fstream>

LoadAction::LoadAction(ApplicationManager * pApp) : Action(pApp)
{
}

void LoadAction::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	filename = pIn->GetSrting(NULL);
}


void LoadAction::Execute()
{
	ReadActionParameters();
	ifstream Infile(filename);
	string DrawColor, FillColor, BackgroundColor ,FigType;
	int NumOfFigs;
	for (int i = 0; i < NumOfFigs; i++) {
		if (FigType == "RECT") {
			GfxInfo emptyGFX;
			Point emptyP;
			CRectangle* rec = new CRectangle(emptyP, emptyP, emptyGFX);
			rec->Load(Infile);
		}
		if (FigType == "TRIANG") {

		}
		if (FigType == "CRICLE") {

		}
		if (FigType == "LINE") {

		}
	}

}

LoadAction::~LoadAction()
{
}