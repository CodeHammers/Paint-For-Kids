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

	//Load function
	virtual void Load(ifstream &Infile);
};