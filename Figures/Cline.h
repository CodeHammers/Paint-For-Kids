#pragma once
#include "CFigure.h"

class CLine : public CFigure
{
private:
	Point EndPoint1;         //line's end point 1
	Point EndPoint2;         //line's end point 1
	vector<Point> Bundle;    //line's original, positional data bundle

public:
	/*Constrcutor*/
	CLine(Point P1, Point P2, GfxInfo FigureGfxInfo);

	/*A function to restore figure's original positional data*/
	void retrieveData();

	/*A function to check the validity of a figure after zooming*/
	bool ValidAfterZoom();

	/*A function to chop the coordinates of a figure by half to fit in the left side of the screen*/
	virtual void ChopCoordniates();

	/*A function create a bundle of a figure's positional data*/
	void BundleData();

	/*A function to change coordinates of a figure*/
	void ChangeCord(Point p);

	/*A function to change the quadrant of a figure*/
	void ChangeQuandrant(int Qx, int Qy);

	/*A function to draw a figure*/
	virtual void Draw(Output* pOut) const;

	/*A function to resize a figure by a ratio*/
	void Resize(double r);

	/*A function to tell whether a point belongs to a line*/
	virtual bool Encloses(Point P) ;

	/*A function to save the figure parameters to the file*/
	virtual void Save(ofstream &OutFile);

	/*Load the figure parameters to the file*/
	virtual void Load(ifstream &Infile);	

	/*A function to print a figure's data*/
	virtual void PrintInfo(Output* pOut);

	/*A function to get the first point*/
	Point GetEndPoint1();

	/*A function to get the second point*/
	Point GetEndPoint2();

	/*A function to get the length of the line*/
	virtual int GetArea();

	/*A function to enforce values of points*/
	virtual void SetPoints(Point x);

	/*A function to decide whether a line is valid to draw or not*/
	static bool ValidToDraw(Point P1, Point P2);
	
	/*A function to return the gfx info of a figure*/
	virtual GfxInfo& GetGfxInfo();
	
	/*A function to get the top point of a figure*/
	virtual Point GetTopCorner();

	/*A function to clone and make an exact copy of a figure*/
	virtual CFigure* Clone();

	/*A function to translate a figure to a new position*/
	virtual bool TransferFigure(Point To, bool Check = false);

	/*A function to return the name of a figure*/
	virtual string GetName();
};