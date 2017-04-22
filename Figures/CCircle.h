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
	virtual bool Encloses(Point P);

	//A function to print a figure info
	virtual void PrintInfo(Output* pOut);

	//A function to get the area of the circle
	virtual int GetArea();

	//A function to decide whether a circle is valid to draw or not
	static bool ValidToDraw(Point C, int R);
};