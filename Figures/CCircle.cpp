#include "CCircle.h"

CCircle::CCircle(Point P1, int r,GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Center = P1;
	Radius = r;
}


void CCircle::Draw(Output* pOut) const
{
	pOut->DrawCircle(Center, Radius, FigGfxInfo);
}


bool CCircle::Encloses(Point P) 
{
	float dist = pow(Center.x - P.x, 2) + pow(Center.y - P.y, 2);
	return dist <= Radius;
}

void CCircle::Load(ifstream &Infile)
{
	///Your code goes here.
	;
}