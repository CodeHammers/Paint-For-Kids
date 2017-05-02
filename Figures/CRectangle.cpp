#include "CRectangle.h"
#include <string>
#include <fstream>

CRectangle::CRectangle(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
}

void CRectangle::retrieveData() {
	Corner1 = Bundle[0];
	Corner2 = Bundle[1];
}

void CRectangle::Draw(Output* pOut) const
{
	if (Scrambled) {
		Point p1, p2;
		p1 = Bundle[0];
		p2 = Bundle[1];
		p1.x *= 0.5;
		p1.x += UI.width / 2;
		p2.x *= 0.5;
		p2.x += UI.width / 2;
		pOut->DrawRect(p1, p2, FigGfxInfo, false);
	}
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawRect(Corner1, Corner2, FigGfxInfo, Selected);
}


bool CRectangle::Encloses(Point P) 
{
	Point ed1 = Corner1;
	Point ed2 = Corner2;
	if (Scrambled) {
		ed1 = Bundle[0];
		ed2 = Bundle[1];
		ed1.x *= 0.5;
		ed2.x *= 0.5;
		ed1.x += UI.width / 2;
		ed2.x += UI.width / 2;
	}
	/*	int minx, maxx, miny, maxy;
	minx = min(Corner1.x, Corner2.x);
	maxx = max(Corner1.x, Corner2.x);
	miny = min(Corner1.y, Corner2.y);
	maxy = max(Corner1.y, Corner2.y);

	return (P.x >= minx && P.x <= maxx && P.y >= miny && P.y <= maxy);*/
	int minx, maxx, miny, maxy;
	minx = min(ed1.x, ed2.x);
	maxx = max(ed1.x, ed2.x);
	miny = min(ed1.y, ed2.y);
	maxy = max(ed1.y, ed2.y);
	return (P.x >= minx && P.x <= maxx && P.y >= miny && P.y <= maxy); 
}

void CRectangle::ChopCoordniates()
{
	Corner1.x *= 0.5;
	Corner2.x *= 0.5;
}

void CRectangle::BundleData() {
	Bundle.push_back(Corner1);
	Bundle.push_back(Corner2);
}

void CRectangle::ChangeQuandrant(int Qx, int Qy) {
	int minY = min(Corner1.y, Corner2.y);
	int minX = min(Corner1.x, Corner2.x);

	Corner1.x += -minX + Qx;
	Corner2.x += -minX + Qx;

	Corner1.y += - minY + Qy;
	Corner2.y += -minY + Qy;

}
void CRectangle::Save(ofstream & OutFile)
{
	OutFile << "RECT" << "\t"<< ID << "\t";
	OutFile << Corner1.x << "\t" << Corner1.y << "\t";
	OutFile << Corner2.x << "\t" << Corner2.y << "\t";
	OutFile << (int)FigGfxInfo.DrawClr.ucRed << " " << (int)FigGfxInfo.DrawClr.ucGreen << " "
		<< (int)FigGfxInfo.DrawClr.ucBlue <<"\t";	
	if (FigGfxInfo.isFilled != true)
		OutFile << "-1 -1 -1";
	else
		OutFile << (int)FigGfxInfo.FillClr.ucRed << " " << (int)FigGfxInfo.FillClr.ucGreen << " "
		<< (int)FigGfxInfo.FillClr.ucBlue;
	OutFile << endl;
}

void CRectangle::Load(ifstream & Infile)
{
	int id;
	Infile >> id;
	Infile >> Corner1.x >> Corner1.y >> Corner2.x >> Corner2.y;
	GfxInfo info;
	int DrawColor[3], FillColor[3];

	Infile >> DrawColor[0] >> DrawColor[1] >> DrawColor[2];
	info.DrawClr = color(DrawColor[0], DrawColor[1], DrawColor[2]);
	Infile >> FillColor[0] >> FillColor[1] >> FillColor[2];
	if (FillColor[0] == -1) {
		info.isFilled = false;
		info.FillClr = WHITE;
	}
	else {
		info.isFilled = true;
		info.FillClr = color(FillColor[0], FillColor[1], FillColor[2]);
	}
	info.BorderWdth = 3;
	CFigure::ID = id;
	CFigure::FigGfxInfo = info;
}


void CRectangle::PrintInfo(Output* pOut)
{
	string x = "(" + to_string(Corner1.x) + "," + to_string(Corner1.y) + ")";
	string y = "(" + to_string(Corner2.x) + "," + to_string(Corner2.y) + ")";
	string A = to_string(GetArea());

	pOut->PrintMessage("Rectangle: Corner1= " + x + " , Corner2= " + y+ " , Area= "+A);
}

Point CRectangle::GetCorner1()
{
	return Corner1;
}

Point CRectangle::GetCorner2()
{
	return Corner2;
}

//GfxInfo CRectangle::GetGfxInfo()
//{
//	return FigGfxInfo;
//}

int CRectangle::GetArea()
{
	Point Aux = { Corner2.x,Corner1.y };

	return (int)(sqrt(pow(Corner1.x - Aux.x, 2) + pow(Corner1.y - Aux.y, 2))*
		sqrt(pow(Corner2.x - Aux.x, 2) + pow(Corner2.y - Aux.y, 2)));
}

void CRectangle::SetPoints(Point s)
{
	Corner1.x += s.x;
	Corner1.y += s.y;
	Corner2.x += s.x;
	Corner2.y += s.y;
}

void CRectangle::Resize(double r) {
	Point P1 = Corner1; Point P2 = Corner2;
	int Dist = abs(P1.y - P2.y);
	int increment = Dist * UI.Ratio - Dist;
	if (P1.y > P2.y) {
		P1.y += increment / 2; P2.y -= increment / 2;
	}
	else {
		P2.y += increment / 2; P1.y -= increment / 2;
	}
	Dist = abs(P1.x - P2.x);
	increment = Dist * UI.Ratio - Dist;
	if (P1.x > P2.x) {
		P1.x += increment / 2; P2.x -= increment / 2;

	}
	else {
		P2.x += increment / 2; P1.x -= increment / 2;
	}
	Corner1 = P1; Corner2 = P2;
}
bool CRectangle::ValidAfterZoom() {
	Point P1 = Corner1; Point P2 = Corner2;
	int Dist = abs(P1.y - P2.y);
	int increment = Dist * UI.Ratio - Dist;
	if (P1.y > P2.y) {
		P1.y += increment / 2; P2.y -= increment / 2;
	}
	else {
		P2.y += increment / 2; P1.y -= increment / 2;
	}
	Dist = abs(P1.x - P2.x);
	increment = Dist * UI.Ratio - Dist;
	if (P1.x > P2.x) {
		P1.x += increment / 2; P2.x -= increment / 2;

	}
	else {
		P2.x += increment / 2; P1.x -= increment / 2;
	}
	return ValidToDraw(P1, P2);
}
GfxInfo& CRectangle::GetGfxInfo()
{
	return FigGfxInfo;
}
bool CRectangle::ValidToDraw(Point P1, Point P2)
{
	return InDrawingArea(P1) && InDrawingArea(P2);
}

Point CRectangle::GetTopCorner()
{
	if (Corner1.x <= Corner2.x&&Corner1.y <= Corner2.y)
		return Corner1;
	return Corner2;
}
bool CRectangle::TransferFigure(Point To, bool Check)
{
	if (!Check) {
		Corner1.x += To.x;	Corner1.y += To.y;
		Corner2.x += To.x;  Corner2.y += To.y;
		return true;
	}
	Point V1 = Corner1, V2 = Corner2;
	V1.x += To.x;   V1.y += To.y;
	V2.x += To.x;	V2.y += To.y;
	return ValidToDraw(V1, V2);
}