#ifndef CRECT_H
#define CRECT_H

#include "CFigure.h"

class CRectangle : public CFigure
{
private:
	Point Corner1;	
	Point Corner2;
public:
	CRectangle(Point , Point, GfxInfo FigureGfxInfo );
	virtual void Draw(Output* pOut) const;

	//A function to determine whether a point is inside a rectangle
	virtual bool Encloses(Point P) const;

	virtual void Load(ifstream &Infile);	//Load the figure parameters to the file
};

#endif