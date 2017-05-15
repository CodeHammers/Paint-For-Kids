#pragma once

#include "CFigure.h"

class CCircle:public CFigure
{
private:
	Point Center;   //circle's center
	int Radius;     //circle's center
	pair<Point, int> Bundle;  //used for changing position data

public:
	//Constructor
	CCircle(Point P1, int r,GfxInfo FigureGfxInfo);
	virtual void SetStartingDragPoint(Point&) ;
	//A function to retrieve figure's original data
	void retrieveData();

	//A function to draw a figure
	virtual void Draw(Output* pOut) const;
	virtual void DrawDragged(Output* pOut, Point p) const;
	virtual void CheckPosAfterDrag(Point p) ;
	//A function to chage figure's coordinates
	virtual void ChopCoordniates();

	//A function to check validity after zooming
	bool ValidAfterZoom();

	//A function to change the figure's quadrant
	void ChangeQuandrant(int Qx, int Qy);

	//A function to change the circle's center
	void ChangeCord(Point p);

	//A function to create the data bundle
	void BundleData();

	//Save the figure parameters to the file
	virtual void Save(ofstream &OutFile);

	//Load the figure parameters to the file
	virtual void Load(ifstream &Infile);

	//A function tell tell with the point P is inside the circle
	virtual bool Encloses(Point P);

	//A function to print a figure info
	virtual void PrintInfo(Output* pOut);

	//A function that returns the circle's center
	Point GetCenter();

	//A function to get the area of the circle
	virtual int GetArea();

	//A function to set points 
	virtual void SetPoints(Point x);

	//A function that returns the radius
	int GetRadius();
	
	//A function to decide whether a circle is valid to draw or not
	static bool ValidToDraw(Point C, int R);

	//A function to resize graph
	void Resize(double r);

	//A function the get the top corner
	virtual Point GetTopCorner();

	//A function create a clone of a figure
	virtual CFigure* Clone();

	//Function to translate current position to a destination
	virtual bool TransferFigure(Point To, bool Check = false);

	//A function that returns the gfx info
	virtual GfxInfo& GetGfxInfo();

	//A function that returns the figure name
	virtual string GetName();
};