#include "LoadAction.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

#include "..\Figures\CRectangle.h"
#include "..\Figures\CTriangle.h"
#include "..\Figures\CCircle.h"
#include "..\Figures\CLine.h"

#include "SaveAction.h"

#include <fstream>
#include <iostream>


LoadAction::LoadAction(ApplicationManager * pApp) : Action(pApp)
{
}

bool LoadAction::ReadActionParameters()
{
	if (pManager->GetFigCount()) {
		pManager->GetOutput()->PrintMessage("Your Current Graph will be lost if you proceed , click save icon to save or click anywhere else to proceed");
		ActionType ac = pManager->GetUserAction();
		if (ac == ITM_SAVE_Clicked) {
			Action* action = new SaveAction(pManager);
			action->Execute();
		}
	}
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
	int DrawColor[3], FillColor[3] ,bckgrndColor[3];

	Infile >> DrawColor[0] >> DrawColor[1] >> DrawColor[2];
	Infile >> FillColor[0] >> FillColor[1] >> FillColor[2];
	Infile >> bckgrndColor[0] >> bckgrndColor[1] >> bckgrndColor[2];

	string  FigType;
	color drawcolor = color(DrawColor[0],DrawColor[1],DrawColor[2]);
	color fillcolor = color(FillColor[0], FillColor[1], FillColor[2]);
	color bckgcolor = color(bckgrndColor[0], bckgrndColor[1], bckgrndColor[2]);
	pManager->nullifyFigList();
	pManager->GetOutput()->ClearDrawArea();
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
}

LoadAction::~LoadAction()
{
}