#include "CLine.h"
#include <fstream>
CLine::CLine(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	EndPoint1 = P1;
	EndPoint2 = P2;
}


void CLine::Draw(Output* pOut) const
{
	pOut->DrawLine(EndPoint1, EndPoint2, FigGfxInfo, Selected);
}


bool CLine::Encloses(Point P) 
{
	/*float dist1 = pow(EndPoint1.x - P.x, 2) + pow(EndPoint1.y - P.y, 2);
	float dist2 = pow(EndPoint2.x - P.x, 2) + pow(EndPoint2.y - P.y, 2);
	float tot= pow(EndPoint1.x - EndPoint2.x, 2) + pow(EndPoint1.y - EndPoint2.y, 2);

	double d = abs(tot - (dist1 + dist2 + 2 * sqrt(dist1)*sqrt(dist2)));

	return (abs(tot-(dist1 + dist2 + 2*sqrt(dist1)*sqrt(dist2)))<=FigGfxInfo.BorderWdth);*/

	int minx, maxx, miny, maxy;
	minx = min(EndPoint1.x, EndPoint2.x);
	maxx = max(EndPoint1.x, EndPoint2.x);
	miny = min(EndPoint1.y, EndPoint2.y);
	maxy = max(EndPoint1.y, EndPoint2.y);

	return (P.x >= minx && P.x <= maxx && P.y >= miny && P.y <=maxy);
}

void CLine::Save(ofstream & OutFile)
{
	OutFile << ID << "\t" << EndPoint1.x << "\t" << EndPoint1.y << "\t"
		<< EndPoint2.x << "\t" << EndPoint2.y << "\t"<< (int)FigGfxInfo.DrawClr.ucBlue
		<< "\t" << (int)FigGfxInfo.DrawClr.ucGreen << "\t" << (int)FigGfxInfo.DrawClr.ucRed
		<< "\n";
}

void CLine::Load(ifstream &Infile)
{
	///Youe code goes here.
	int id;
	string DrawColor;
	Infile >> id ;
	Infile >> EndPoint1.x >> EndPoint1.y >> EndPoint2.x >> EndPoint2.y;
	GfxInfo info;
	Infile >> DrawColor;
	//Check for the color
	info.DrawClr = GetColor(DrawColor);
	info.BorderWdth = 3;
	CFigure::ID = id;
	CFigure::FigGfxInfo = info;
}

void CLine::PrintInfo(Output* pOut)
{
	string x = "(" + to_string(EndPoint1.x) + "," + to_string(EndPoint1.y) + ")";
	string y = "(" + to_string(EndPoint2.x) + "," + to_string(EndPoint2.y) + ")";
	string l = to_string(GetArea());
	pOut->PrintMessage("Line: EndPoint1= "+x+" , EndPoint2= "+y+ " , Length= "+l);
}

Point CLine::GetEndPoint1()
{
	return EndPoint1;
}

Point CLine::GetEndPoint2()
{
	return EndPoint2;
}

//GfxInfo CLine::GetGfxInfo()
//{
//	return FigGfxInfo;
//}

int CLine::GetArea()
{
	return (int)sqrt(pow(EndPoint1.x - EndPoint2.x, 2) + pow(EndPoint1.y - EndPoint2.y, 2));
}

void CLine::SetPoints(Point s)
{
	EndPoint1.x += s.x;
	EndPoint1.y += s.y;
	EndPoint2.x += s.x;
	EndPoint2.y += s.y;
}

bool CLine::ValidToDraw(Point P1, Point P2)
{
	return InDrawingArea(P1) && InDrawingArea(P2);
}

void CLine::TransferFigure(Point To)
{
	;
}