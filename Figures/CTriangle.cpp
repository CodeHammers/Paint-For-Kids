#include"CTriangle.h"


CTriangle::CTriangle(Point V1, Point V2, Point V3, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Vertex1 = V1;
	Vertex2 = V2;
	Vertex3 = V3;
}


void CTriangle::Draw(Output* pOut) const
{
	pOut->DrawTriangle(Vertex1, Vertex2, Vertex3, FigGfxInfo);
}


void CTriangle::Load(ifstream &Infile)
{
	///Your code goes here.
	;
}