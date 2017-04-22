#pragma once
#include "CFigure.h"

class CLine : public CFigure
{
private:
	Point EndPoint1;    //line's end points
	Point EndPoint2;
public:
	//Constrcutor
	CLine(Point P1, Point P2, GfxInfo FigureGfxInfo);

	//Draw function
	virtual void Draw(Output* pOut) const;

	//A function to tell whether a point belongs to a line
	virtual bool Encloses(Point P) ;

	//Load the figure parameters to the file
	virtual void Load(ifstream &Infile);	

	virtual void PrintInfo(Output* pOut);

	//A function to get the length of the line
	virtual int GetArea();

	//A function to decide whether a line is valid to draw or not
	static bool ValidToDraw(Point P1, Point P2);
};