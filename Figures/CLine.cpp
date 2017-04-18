#include "CLine.h"

CLine::CLine(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	EndPoint1 = P1;
	EndPoint2 = P2;
}


void CLine::Draw(Output* pOut) const
{
	pOut->DrawLine(EndPoint1, EndPoint2, FigGfxInfo, Selected);
}

void CLine::Load(ifstream &Infile)
{
	///Youe code goes here.
	;
}