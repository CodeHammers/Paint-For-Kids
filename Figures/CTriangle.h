#pragma once
#include "CFigure.h"

class CTriangle : public CFigure
{
private:
	Point Vertex1, Vertex2, Vertex3;  //Points to represent vertices of a triangle
	vector<Point> Bundle;    // A bundle to store original positional data

public:
	/*A Constructor function*/
	CTriangle(Point V1, Point V2, Point V3, GfxInfo FigureGfxInfo);

	/*A fucntion to restore figure's original data*/
	void retrieveData();

	virtual void SetStartingDragPoint(Point&);
	virtual bool CheckPosAfterDrag(Point p);


	/*A function to draw a triangle*/
	virtual void Draw(Output* pOut) const;
	virtual void DrawDragged(Output* pOut, Point p) const;
	/*A function to check whether a point is enclosed by a figure*/
	virtual bool Encloses(Point P) ;

	/*A function to chop the coordinates of a figure to fit in the left side of the screen*/
	virtual void ChopCoordniates();

	/*A function to create a bundle of the positional data of a figure*/
	void BundleData();

	/*A function to change the current quadrant of a figure*/
	void ChangeQuandrant(int Qx, int Qy);

	/*AFunction to the get the area of the triangle given its coordinates (used by encloses function)*/
	float Getarea(int x1, int y1, int x2, int y2, int x3, int y3) const;

	/*A function to change the coordinates of a figure*/
	void ChangeCord(Point p);

	/*A function to check the validity of a figure after zooming*/
	bool ValidAfterZoom();

	/*A function to resize a figure by a ratio*/
	void Resize(double r);

	/*A function to save a figure*/
	virtual void Save(ofstream &OutFile);

	/*A function to load figure's data*/
	virtual void Load(ifstream &Infile);

	/*A function to print the info a figure on the status bar*/
	virtual void PrintInfo(Output* pOut);

	/*A function to the get the first vertex of a triangle*/
	Point GetVertex1();

	/*A function to the get the second vertex of a triangle*/
	Point GetVertex2();

	/*A function to the get the third vertex of a triangle*/
	Point GetVertex3();

	/*A function to enforce points to a figure positional data*/
	virtual void SetPoints(Point s);

	/*A function to return the gfx info*/
	virtual GfxInfo& GetGfxInfo();

	/*A function to get the area of the triangle*/
	virtual int GetArea();

	/*A function to decide whether a triangle is valid to draw or not*/
	static bool ValidToDraw(Point P1, Point P2, Point P3);
	
	/*A function to the get the top corner of a figure*/
	virtual Point GetTopCorner();

	/*A function to make an exact clone of a figure*/
	virtual CFigure* Clone();

	/*A function to translate a figure to a new position*/
	virtual bool TransferFigure(Point To, bool Check = false);

	/*A function to get the name of a figure*/
	virtual string GetName();
};