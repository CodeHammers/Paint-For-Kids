#pragma once
#include "CFigure.h"

class CTriangle : public CFigure
{
private:
	Point Vertex1, Vertex2, Vertex3;
	vector<Point> Bundle;

public:
	//Constructor
	CTriangle(Point V1, Point V2, Point V3, GfxInfo FigureGfxInfo);

	void retrieveData();

	//Draw function
	virtual void Draw(Output* pOut) const;

	//Encloses function
	virtual bool Encloses(Point P) ;
	virtual void ChopCoordniates();

	void BundleData();

	void ChangeQuandrant(int Qx, int Qy);

	//Function to the get the area of the triangle (used by encloses function)
	float Getarea(int x1, int y1, int x2, int y2, int x3, int y3) const;

	bool ValidAfterZoom();

	void Resize(double r);

	//Save function
	virtual void Save(ofstream &OutFile);

	//Load function
	virtual void Load(ifstream &Infile);

	virtual void PrintInfo(Output* pOut);

	Point GetVertex1();
	Point GetVertex2();
	Point GetVertex3();
	//GfxInfo GetGfxInfo();
	virtual void SetPoints(Point s);
	virtual GfxInfo GetGfxInfo();
	//A function to get the area of the triangle
	virtual int GetArea();

	//A function to decide whether a triangle is valid to draw or not
	static bool ValidToDraw(Point P1, Point P2, Point P3);
	virtual Point GetTopCorner();
	virtual bool TransferFigure(Point To, bool Check = false);
};