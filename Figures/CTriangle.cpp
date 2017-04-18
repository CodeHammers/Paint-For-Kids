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


float CTriangle::GetArea(int x1, int y1, int x2, int y2, int x3, int y3) const
{
	return abs((x1*(y2 - y3) + x2*(y3 - y1) + x3*(y1 - y2)) / 2.0);
}

bool CTriangle::Encloses(Point P) const
{
	/* Calculate the area of V1V2V3 */
	float tot = GetArea(Vertex1.x, Vertex1.y, Vertex2.x, Vertex2.y, Vertex3.x, Vertex3.y);

	/* Calculate area of triangle PV2V3 */
	float A1 = GetArea(P.x, P.y, Vertex2.x, Vertex2.y, Vertex3.x, Vertex3.y);

	/* Calculate area of triangle PV1V3 */
	float A2 = GetArea(Vertex1.x, Vertex1.y, P.x, P.y, Vertex3.x, Vertex3.y);
	
	/* Calculate area of triangle PV1V2 */
	float A3 = GetArea(Vertex1.x, Vertex1.y, Vertex2.x, Vertex2.y, P.x, P.y);
	
	/* Check if sum of A1, A2 and A3 is same as A */
	return (tot == A1 + A2 + A3);
}

void CTriangle::Load(ifstream &Infile)
{
	///Your code goes here.
	;
}