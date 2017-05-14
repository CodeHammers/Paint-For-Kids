#ifndef CRECT_H
#define CRECT_H

#include "CFigure.h"

class CRectangle : public CFigure
{
private:
	Point Corner1;	        //First corner of the rectangle
	Point Corner2;          //Second corner of the rectangle 
	vector<Point> Bundle;   //A bundle to store the original positional data

public:
	/*A constructor function*/
	CRectangle(Point , Point, GfxInfo FigureGfxInfo );

	/*A function to restore the original positional data*/
	void retrieveData();

	/*A function to draw a figure*/
	virtual void Draw(Output* pOut) const;

	/*A function to change coordinates of a figure*/
	void ChangeCord(Point p);

	/*A function to determine whether a point is inside a rectangle*/
	virtual bool Encloses(Point P) ;

	/*A function to chop the coordinates of a figure to fit on the left side of the screen*/
	virtual void ChopCoordniates();

	/*A function to create a bundle of the positional data*/
	void BundleData();

	/*A function to change the quadrant of a figure*/
	void ChangeQuandrant(int Qx, int Qy);

	/*A function to save a figute data*/
	virtual void Save(ofstream &OutFile);

	/*A function to load figure data*/
	virtual void Load(ifstream &Infile);	

	/*A function to print a figure info*/
	virtual void PrintInfo(Output* pOut);

	/*A fucntion to get the first corner of a rectangle*/
	Point GetCorner1();

	/*A function to get the second corner of a rectangle*/
	Point GetCorner2();
	
	/*A function to get the area of the rectangle*/
	virtual int GetArea();

	/*A function to enforce points to positional data*/
	virtual void SetPoints(Point s);

	/*A function to resize a figure*/
	void Resize(double r);

	/*A function to check the validity of a figure after zooming*/
	bool ValidAfterZoom();

	/*A function to return the gfx info of a figure*/
	virtual GfxInfo& GetGfxInfo();

	/*A function to get the top point of a figure*/
	virtual Point GetTopCorner();

	/*A function to decide whether a rectangle is valid to draw or not*/
	static bool ValidToDraw(Point P1, Point P2);

	/*A functiont to create an exact clone of figure*/
	virtual CFigure* Clone();

	/*A function to translate a figure's positions*/
	virtual bool TransferFigure(Point To, bool Check = false);

	/*A function to get the name of figure*/
	virtual string GetName();
};

#endif