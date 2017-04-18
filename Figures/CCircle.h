#pragma once

#include "CFigure.h"

class CCircle : public CFigure
{

private:
	Point Center;
	int Radius;

public:
	//Constructor
	CCircle(Point P1, int r,GfxInfo FigureGfxInfo);

	//Draw function
	virtual void Draw(Output* pOut) const;

	//Load the figure parameters to the file
	virtual void Load(ifstream &Infile);

	//A function tell tell with the point P is inside the circle
	virtual bool Encloses(Point P) const;
};