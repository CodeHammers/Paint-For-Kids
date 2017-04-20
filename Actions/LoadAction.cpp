#include "LoadAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "..\Figures\CRectangle.h"
#include "..\Figures\CTriangle.h"
#include "..\Figures\CCircle.h"
#include "..\Figures\CLine.h"
#include <fstream>
#include <iostream>
LoadAction::LoadAction(ApplicationManager * pApp) : Action(pApp)
{
}

bool LoadAction::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	pManager->GetOutput()->PrintMessage("specify the name of the file you want to load from ");
	filename = pIn->GetSrting(pManager->GetOutput());
	return true;
}


void LoadAction::Execute()
{
	ReadActionParameters();
	//should ask to save current work if any before clearing
	ifstream Infile;
	Infile.open("Saved//"+filename+".txt", ios::in);
	//Infile.open("input.txt", ios::in);
	/*
	if (!Infile) {
		std::cout << "leh ba2a";
	}
	*/
	string DrawColor, FillColor, BackgroundColor, FigType;
	Infile >> DrawColor >> FillColor >> BackgroundColor;
	color drawcolor = CFigure::GetColor(DrawColor);
	color fillcolor = CFigure::GetColor(FillColor);
	color bckgcolor = CFigure::GetColor(BackgroundColor);
	pManager->nullifyFigList();
	pManager->GetOutput()->EditWindowSettings(drawcolor, fillcolor, bckgcolor);
	int NumOfFigs; Infile >> NumOfFigs;
	for (int i = 0; i < NumOfFigs; i++) {
		GfxInfo emptyGFX = GfxInfo();
		Infile >> FigType;
		Point emptyP= Point();
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
		if (FigType == "CIRCLE") {
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
	pManager->UpdateInterface();

}

LoadAction::~LoadAction()
{
}