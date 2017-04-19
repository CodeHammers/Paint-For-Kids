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
	int id, x, y;
	string DrawColor, FillColor;
	Infile >> id >> x >> y;
	Infile >> Corner1.x >> Corner1.y >> Corner2.x >> Corner2.y;
	GfxInfo info;
	Infile >> DrawColor;
	//Check for the color
	info.DrawClr = GetColor(DrawColor);
	Infile >> FillColor;
	if (FillColor == "NOFILL") {
		info.isFilled = false;
	}
	else {
		info.isFilled = true;
		info.FillClr = GetColor(FillColor);
	}
	CFigure::FigGfxInfo = info;
}
