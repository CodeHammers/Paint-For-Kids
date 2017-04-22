#include"CTriangle.h"
#include <fstream>

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


float CTriangle::Getarea(int x1, int y1, int x2, int y2, int x3, int y3) const
{
	return abs((x1*(y2 - y3) + x2*(y3 - y1) + x3*(y1 - y2)) / 2.0);
}

bool CTriangle::Encloses(Point P) 
{
	/* Calculate the area of V1V2V3 */
	float tot = Getarea(Vertex1.x, Vertex1.y, Vertex2.x, Vertex2.y, Vertex3.x, Vertex3.y);

	/* Calculate area of triangle PV2V3 */
	float A1 = Getarea(P.x, P.y, Vertex2.x, Vertex2.y, Vertex3.x, Vertex3.y);

	/* Calculate area of triangle PV1V3 */
	float A2 = Getarea(Vertex1.x, Vertex1.y, P.x, P.y, Vertex3.x, Vertex3.y);
	
	/* Calculate area of triangle PV1V2 */
	float A3 = Getarea(Vertex1.x, Vertex1.y, Vertex2.x, Vertex2.y, P.x, P.y);
	
	/* Check if sum of A1, A2 and A3 is same as A */
	return (tot == A1 + A2 + A3);
}

void CTriangle::Load(ifstream &Infile)
{
	///Your code goes here.
	int id;
	string DrawColor, FillColor;
	Infile >> id;
	Infile >> Vertex1.x >> Vertex1.y >> Vertex2.x >> Vertex2.y >> Vertex3.x >> Vertex3.y;
	GfxInfo info;
	Infile >> DrawColor;
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

void CTriangle::PrintInfo(Output* pOut)
{
	string x = "(" + to_string(Vertex1.x) + "," + to_string(Vertex1.y) + ")";
	string y = "(" + to_string(Vertex2.x) + "," + to_string(Vertex2.y) + ")";
	string z = "(" + to_string(Vertex3.x) + "," + to_string(Vertex3.y) + ")";
	string A = to_string(GetArea());

	pOut->PrintMessage("Triangle: Vertex1 = " + x + " , Vertex2 = " + y + " , Vertex3 = "+z+ " , Area = "+A);
}

int CTriangle::GetArea()
{
	return (int)Getarea(Vertex1.x, Vertex1.y, Vertex2.x, Vertex2.y, Vertex3.x, Vertex3.y);
}

bool CTriangle::ValidToDraw(Point P1, Point P2, Point P3)
{
	return InDrawingArea(P1) && InDrawingArea(P2) && InDrawingArea(P3);
}