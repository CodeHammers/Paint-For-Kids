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
	virtual bool Encloses(Point P) ;

	virtual void Save(ofstream &OutFile);

	virtual void Load(ifstream &Infile);	//Load the figure parameters to the file

	virtual void PrintInfo(Output* pOut);

	Point GetCorner1();
	Point GetCorner2();
	//GfxInfo GetGfxInfo();
	//A function to get the area of the rectangle
	virtual int GetArea();
	virtual void SetPoints(Point s);

	//A function to decide whether a rectangle is valid to draw or not
	static bool ValidToDraw(Point P1, Point P2);
};

#endif