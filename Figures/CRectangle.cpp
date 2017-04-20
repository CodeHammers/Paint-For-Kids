#include "CRectangle.h"
#include <string>
#include <fstream>

CRectangle::CRectangle(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
}
	

void CRectangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawRect(Corner1, Corner2, FigGfxInfo, Selected);
}


bool CRectangle::Encloses(Point P) 
{
	int minx, maxx, miny, maxy;
	minx = min(Corner1.x, Corner2.x);
	maxx = max(Corner1.x, Corner2.x);
	miny = min(Corner1.y, Corner2.y);
	maxy = max(Corner1.y, Corner2.y);

	return (P.x >= minx && P.x <= maxx && P.y >= miny && P.y <= maxy);
}

void CRectangle::Load(ifstream & Infile)
{
	int id;
	string DrawColor, FillColor;
	Infile >> id;
	Infile >> Corner1.x >> Corner1.y >> Corner2.x >> Corner2.y;
	GfxInfo info;
	Infile >> DrawColor;
	//Check for the color
	info.DrawClr = GetColor(DrawColor);
	Infile >> FillColor;
	if (FillColor == "NOFILL") {
		info.isFilled = false;
		info.FillClr = WHITE;
	}
	else {
		info.isFilled = true;
		info.FillClr = GetColor(FillColor);
	}
	info.BorderWdth = 3;
	CFigure::ID = id;
	CFigure::FigGfxInfo = info;
}


void CRectangle::PrintInfo(Output* pOut)
{
	string x = "(" + to_string(Corner1.x) + "," + to_string(Corner1.y) + ")";
	string y = "(" + to_string(Corner2.x) + "," + to_string(Corner2.y) + ")";
	string A = to_string(GetArea());

	pOut->PrintMessage("Rectangle: Corner1= " + x + " , Corner2= " + y+ " , Area= "+A);
}


int CRectangle::GetArea()
{
	Point Aux = { Corner2.x,Corner1.y };

	return (int)(sqrt(pow(Corner1.x - Aux.x, 2) + pow(Corner1.y - Aux.y, 2))*
		sqrt(pow(Corner2.x - Aux.x, 2) + pow(Corner2.y - Aux.y, 2)));
}