#include "LoadAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "..\Figures\CRectangle.h"
#include "..\Figures\CTriangle.h"
#include "..\Figures\CCircle.h"
#include "..\Figures\CLine.h"
#include <fstream>

LoadAction::LoadAction(ApplicationManager * pApp) : Action(pApp)
{
}

bool LoadAction::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	filename = pIn->GetSrting(NULL);
	return true;
}


void LoadAction::Execute()
{
	ReadActionParameters();
	//should ask to save current work if any before clearing
	pManager->GetOutput()->ClearDrawArea();
	ifstream Infile(filename);
	string DrawColor, FillColor, BackgroundColor, FigType;
	Infile >> DrawColor >> FillColor >> BackgroundColor;
	color drawcolor = CFigure::GetColor(DrawColor);
	color fillcolor = CFigure::GetColor(FillColor);
	color bckgcolor = CFigure::GetColor(BackgroundColor);
	pManager->GetOutput()->EditWindowSettings(drawcolor, fillcolor, bckgcolor);
	int NumOfFigs;
	for (int i = 0; i < NumOfFigs; i++) {
		GfxInfo emptyGFX;
		Point emptyP;
		if (FigType == "RECT") {
			CRectangle* rec = new CRectangle(emptyP, emptyP, emptyGFX);
			rec->Load(Infile);
			pManager->AddFigure(rec);
		}
		if (FigType == "TRIANG") {
			CTriangle* trig = new CTriangle(emptyP, emptyP, emptyP, emptyGFX);
			trig->Load(Infile);
			pManager->AddFigure(trig);
		}
		if (FigType == "CRICLE") {
			CCircle* circ = new CCircle(emptyP, 0, emptyGFX);
			circ->Load(Infile);
			pManager->AddFigure(circ);
		}
		if (FigType == "LINE") {
			CLine * line = new CLine(emptyP, emptyP, emptyGFX);
			line->Load(Infile);
			pManager->AddFigure(line);
		}
	}

}

LoadAction::~LoadAction()
{
}