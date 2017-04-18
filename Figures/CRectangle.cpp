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
	return (P.x >= Corner1.x && P.x <= Corner2.x && P.y >= Corner1.y && P.y <= Corner2.y);
}

void CRectangle::Load(ifstream & Infile)
{
	int id,x,y;
	string DrawColor,FillColor;
	Infile >> id >> x >> y;
	Corner1.x = x; Corner1.y = y;
	Infile >> x >> y;
	Corner2.x = x; Corner2.y = y;
	GfxInfo info;
	Infile >> DrawColor;
	//Check for the color
	info.DrawClr = RED;
	Infile >> FillColor;
	if (FillColor == "NOFILL") {
		info.isFilled = false;
	}
	else {
		//check for the color
	}
	CFigure::FigGfxInfo = info;
}
