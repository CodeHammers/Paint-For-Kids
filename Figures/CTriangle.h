#pragma once
#include "CFigure.h"

class CTriangle : public CFigure
{
private:
	Point Vertex1, Vertex2, Vertex3;

public:
	//Constructor
	CTriangle(Point V1, Point V2, Point V3, GfxInfo FigureGfxInfo);

	//Draw function
	virtual void Draw(Output* pOut) const;

	//Encloses function
	virtual bool Encloses(Point P) ;

	//Function to the get the area of the triangle (used by encloses function)
	float GetArea(int x1, int y1, int x2, int y2, int x3, int y3) const;

	//Load function
	virtual void Load(ifstream &Infile);

	virtual void PrintInfo(Output* pOut);
};