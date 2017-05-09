#include "CLine.h"
#include <fstream>
CLine::CLine(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	EndPoint1 = P1;
	EndPoint2 = P2;
}
void CLine::retrieveData() {
	EndPoint1 = Bundle[0];
	EndPoint2 = Bundle[1];
}
bool CLine::ValidAfterZoom() {
	Point P1 = EndPoint1; Point P2 = EndPoint2;
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
void CLine::ChopCoordniates()
{
	EndPoint1.x *= 0.5;
	EndPoint2.x *= 0.5;
}

void CLine::BundleData() {
	Bundle.push_back(EndPoint1);
	Bundle.push_back(EndPoint2);

}
void CLine::ChangeCord(Point p) {
	int difX = EndPoint1.x - p.x; int difY = EndPoint1.y - p.y;
	EndPoint1 = p;
	EndPoint2.x -= difX; EndPoint2.y -= difY;
}

void CLine::ChangeQuandrant(int Qx, int Qy) {
	int minY = min(EndPoint1.x, EndPoint2.y);
	int minX = min(EndPoint1.x, EndPoint2.x);
	EndPoint1.x += -minX + Qx;
	EndPoint2.x += -minX + Qx;
	EndPoint1.y += -minY + Qy;
	EndPoint2.y += -minY + Qy;
}
void CLine::Draw(Output* pOut) const
{
	if (Scrambled) {
		Point p1, p2;
		p1 = Bundle[0];
		p2 = Bundle[1];
		p1.x *= 0.5;
		p1.x += UI.width / 2;
		p2.x *= 0.5;
		p2.x += UI.width / 2;
		pOut->DrawLine(p1, p2, FigGfxInfo, false);
	}
	pOut->DrawLine(EndPoint1, EndPoint2, FigGfxInfo, Selected);
}
void CLine::Resize(double r) {
	Point P1 = EndPoint1; Point P2 = EndPoint2;
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
	EndPoint1 = P1; EndPoint2 = P2;
}

bool CLine::Encloses(Point P)
{
	Point ed1 = EndPoint1;
	Point ed2 = EndPoint2;
	if (Scrambled) {
		ed1 = Bundle[0];
		ed2 = Bundle[1];
		ed1.x *= 0.5;
		ed2.x *= 0.5;
		ed1.x += UI.width / 2;
		ed2.x += UI.width / 2;
	}
	int minx, maxx, miny, maxy;
	minx = min(ed1.x, ed2.x);
	maxx = max(ed1.x, ed2.x);
	miny = min(ed1.y, ed2.y);
	maxy = max(ed1.y, ed2.y);
	double dist = (ed2.y - ed1.y) * P.x - (ed2.x - ed1.x)*P.y + ed2.x * ed1.y - ed2.y * ed1.x;
	dist = abs(dist);
	dist = dist / (sqrt(pow(ed1.y - ed2.y, 2) + pow(ed1.x - ed2.x, 2)));
	double borderWidth = CFigure::FigGfxInfo.BorderWdth / 2;
	return (P.x >= minx && P.x <= maxx || P.y >= miny && P.y <= maxy) && borderWidth + 2 >= dist;
}

void CLine::Save(ofstream & OutFile)
{
	OutFile << "LINE" << "\t" <<ID << "\t" << EndPoint1.x << "\t" << EndPoint1.y << "\t"
		<< EndPoint2.x << "\t" << EndPoint2.y << "\t"<< (int)FigGfxInfo.DrawClr.ucRed
		<< "\t" << (int)FigGfxInfo.DrawClr.ucGreen << "\t" << (int)FigGfxInfo.DrawClr.ucBlue
		<< "\n";
}

void CLine::Load(ifstream &Infile)
{
	///Youe code goes here.
	int id;
	Infile >> id ;
	Infile >> EndPoint1.x >> EndPoint1.y >> EndPoint2.x >> EndPoint2.y;
	GfxInfo info;
	int DrawColor[3];
	Infile >> DrawColor[0] >> DrawColor[1] >> DrawColor[2];
	info.DrawClr = color(DrawColor[0], DrawColor[1], DrawColor[2]);
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

GfxInfo& CLine::GetGfxInfo()
{
	return FigGfxInfo;
}

Point CLine::GetTopCorner()
{
	if (EndPoint1.x <= EndPoint2.x&&EndPoint1.y <= EndPoint2.y)
		return EndPoint1;
	return EndPoint2;
}

CFigure* CLine::Clone()
{
	CFigure* Temp = new CLine(EndPoint1, EndPoint2, FigGfxInfo);
	return Temp;
}

bool CLine::TransferFigure(Point To, bool Check)
{
	if (!Check) {
		EndPoint1.x += To.x;	EndPoint1.y += To.y;
		EndPoint2.x += To.x;    EndPoint2.y += To.y;
		return true;
	}
	Point V1 = EndPoint1, V2 = EndPoint2;
	V1.x += To.x;   V1.y += To.y;
	V2.x += To.x;	V2.y += To.y;
	return ValidToDraw(V1, V2);
}

string CLine::GetName()
{
	return "Line";
}
