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


bool CLine::Encloses(Point P) 
{
	float dist1 = pow(EndPoint1.x - P.x, 2) + pow(EndPoint1.y - P.y, 2);
	float dist2 = pow(EndPoint2.x - P.x, 2) + pow(EndPoint2.y - P.y, 2);
	float tot= pow(EndPoint1.x - EndPoint2.x, 2) + pow(EndPoint1.y - EndPoint2.y, 2);

	return tot == dist1 + dist2 + 2*dist1*dist2;
}

void CLine::Load(ifstream &Infile)
{
	///Youe code goes here.
	;
}