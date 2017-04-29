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

	bool ValidAfterZoom();
	virtual void ChopCoordniates();

	//Draw function
	virtual void Draw(Output* pOut) const;

	void Resize(double r);

	//A function to tell whether a point belongs to a line
	virtual bool Encloses(Point P) ;

	//Save the figure parameters to the file
	virtual void Save(ofstream &OutFile);

	//Load the figure parameters to the file
	virtual void Load(ifstream &Infile);	

	virtual void PrintInfo(Output* pOut);

	Point GetEndPoint1();
	Point GetEndPoint2();
	//GfxInfo GetGfxInfo();
	//A function to get the length of the line
	virtual int GetArea();
	virtual void SetPoints(Point x);
	//A function to decide whether a line is valid to draw or not
	static bool ValidToDraw(Point P1, Point P2);
	virtual GfxInfo GetGfxInfo();
	virtual Point GetTopCorner();
	virtual bool TransferFigure(Point To, bool Check = false);
};