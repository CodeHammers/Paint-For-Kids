#include"CTriangle.h"
#include <fstream>

CTriangle::CTriangle(Point V1, Point V2, Point V3, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Vertex1 = V1;
	Vertex2 = V2;
	Vertex3 = V3;
}
void CTriangle::retrieveData() {
	Vertex1 = Bundle[0];
	Vertex2 = Bundle[1];
	Vertex3 = Bundle[2];
}
void CTriangle::Draw(Output* pOut) const
{
	if (Scrambled) {
		Point p1, p2,p3;
		p1 = Bundle[0];
		p2 = Bundle[1];
		p3 = Bundle[2];
		p1.x *= 0.5;
		p1.x += UI.width / 2;
		p2.x *= 0.5;
		p2.x += UI.width / 2;
		p3.x *= 0.5;
		p3.x += UI.width / 2;
		pOut->DrawTriangle(p1, p2,p3, FigGfxInfo, false);
	}
	pOut->DrawTriangle(Vertex1, Vertex2, Vertex3, FigGfxInfo, Selected);
}


float CTriangle::Getarea(int x1, int y1, int x2, int y2, int x3, int y3) const
{
	return abs((x1*(y2 - y3) + x2*(y3 - y1) + x3*(y1 - y2)) / 2.0);
}
bool CTriangle::ValidAfterZoom() {
	return true;
}
void CTriangle::Resize(double r) {

}
bool CTriangle::Encloses(Point P) 
{
	Point v1, v2, v3;
	v1 = Vertex1; v2 = Vertex2; v3 = Vertex3;
	if (Scrambled) {
		Vertex1 = Bundle[0];
		Vertex2 = Bundle[1];
		Vertex3 = Bundle[2];
		Vertex1.x *= 0.5;
		Vertex2.x *= 0.5;
		Vertex2.x *= 0.5;
		Vertex1.x += UI.width/2;
		Vertex2.x += UI.width/2;
		Vertex2.x += UI.width/2;
	}
	/* Calculate the area of V1V2V3 */
	float tot = Getarea(Vertex1.x, Vertex1.y, Vertex2.x, Vertex2.y, Vertex3.x, Vertex3.y);

	/* Calculate area of triangle PV2V3 */
	float A1 = Getarea(P.x, P.y, Vertex2.x, Vertex2.y, Vertex3.x, Vertex3.y);

	/* Calculate area of triangle PV1V3 */
	float A2 = Getarea(Vertex1.x, Vertex1.y, P.x, P.y, Vertex3.x, Vertex3.y);
	
	/* Calculate area of triangle PV1V2 */
	float A3 = Getarea(Vertex1.x, Vertex1.y, Vertex2.x, Vertex2.y, P.x, P.y);
	
	/* Check if sum of A1, A2 and A3 is same as A */
	Vertex1 = v1; Vertex2 = v2; Vertex3 = v3;
	return (tot == A1 + A2 + A3);
}

void CTriangle::ChopCoordniates()
{
	Vertex1.x *= 0.5;
	Vertex2.x *= 0.5;
	Vertex3.x *= 0.5;
}
void CTriangle::BundleData() {
	Bundle.push_back(Vertex1);
	Bundle.push_back(Vertex2);
	Bundle.push_back(Vertex3);

}
void CTriangle::ChangeQuandrant(int Qx,int Qy) {
	int minY = min(Vertex1.y, Vertex2.y, Vetex3.y);
	int minX = min(Vertex1.x, Vertex2.x, Vertext3.x);

	Vertex1.x += -minX +Qx;
	Vertex2.x += -minX +Qx;
	Vertex3.x += -minX + Qx;

	Vertex1.y += -minY + Qy;
	Vertex2.y += -minY + Qy;
	Vertex3.y += -minY + Qy;


}

void CTriangle::Save(ofstream & OutFile)
{
	OutFile << "TRIANG"  <<"\t" << ID <<"\t";
	OutFile << Vertex1.x << "\t" << Vertex1.y << "\t";
	OutFile << Vertex2.x << "\t" << Vertex2.y << "\t";
	OutFile << Vertex3.x << "\t" << Vertex3.y << "\t";
	OutFile << (int)FigGfxInfo.DrawClr.ucRed << " " << (int)FigGfxInfo.DrawClr.ucGreen << " "
		<< (int)FigGfxInfo.DrawClr.ucBlue << "\t";
	if (FigGfxInfo.isFilled != true)
		OutFile << "-1 -1 -1";
	else
		OutFile << (int)FigGfxInfo.FillClr.ucRed << " " << (int)FigGfxInfo.FillClr.ucGreen << " "
		<< (int)FigGfxInfo.FillClr.ucBlue;
	OutFile << endl;
}

void CTriangle::Load(ifstream &Infile)
{
	///Your code goes here.
	int id;
	Infile >> id;
	Infile >> Vertex1.x >> Vertex1.y >> Vertex2.x >> Vertex2.y >> Vertex3.x >> Vertex3.y;
	GfxInfo info;
	int DrawColor[3], FillColor[3];

	Infile >> DrawColor[0] >> DrawColor[1] >> DrawColor[2];
	info.DrawClr = color(DrawColor[0], DrawColor[1], DrawColor[2]);
	Infile >> FillColor[0]>>FillColor[1]>>FillColor[2];
	if (FillColor[0] == -1) {
		info.isFilled = false;
		info.FillClr = WHITE;
	}
	else {
		info.isFilled = true;
		info.FillClr = color(FillColor[0], FillColor[1],FillColor[2]);
	}
	info.BorderWdth = 3;
	CFigure::ID = id;
	CFigure::FigGfxInfo = info;
}

void CTriangle::PrintInfo(Output* pOut)
{
	string x = "(" + to_string(Vertex1.x) + "," + to_string(Vertex1.y) + ")";
	string y = "(" + to_string(Vertex2.x) + "," + to_string(Vertex2.y) + ")";
	string z = "(" + to_string(Vertex3.x) + "," + to_string(Vertex3.y) + ")";
	string A = to_string(GetArea());

	pOut->PrintMessage("Triangle: Vertex1 = " + x + " , Vertex2 = " + y + " , Vertex3 = "+z+ " , Area = "+A);
}

Point CTriangle::GetVertex1()
{
	return Vertex1;
}

Point CTriangle::GetVertex2()
{
	return Vertex2;
}

Point CTriangle::GetVertex3()
{
	return Vertex3;
}

//GfxInfo CTriangle::GetGfxInfo()
//{
//	return FigGfxInfo;
//}

void CTriangle::SetPoints(Point s)
{
	Vertex1.x += s.x;
	Vertex1.y += s.y;
	Vertex2.x += s.x;
	Vertex2.y += s.y;
	Vertex3.x += s.x;
	Vertex3.y += s.y;
}

GfxInfo CTriangle::GetGfxInfo()
{
	return FigGfxInfo;
}

int CTriangle::GetArea()
{
	return (int)Getarea(Vertex1.x, Vertex1.y, Vertex2.x, Vertex2.y, Vertex3.x, Vertex3.y);
}

bool CTriangle::ValidToDraw(Point P1, Point P2, Point P3)
{
	return InDrawingArea(P1) && InDrawingArea(P2) && InDrawingArea(P3);
}


Point CTriangle::GetTopCorner()
{
	if (Vertex1.x <= Vertex2.x && Vertex1.x <= Vertex3.x && Vertex1.y <= Vertex2.y && Vertex1.y <= Vertex3.y)
		return Vertex1;
	else if (Vertex2.x <= Vertex1.x&&Vertex2.x <= Vertex3.x&&Vertex2.y <= Vertex1.y&&Vertex2.y <= Vertex3.x)
		return Vertex2;
	return Vertex3;
}
bool CTriangle::TransferFigure(Point To, bool Check)
{
	if (!Check) {
		Vertex1.x += To.x;  Vertex1.y += To.y;
		Vertex2.x += To.x;	Vertex2.y += To.y;
		Vertex3.x += To.x;	Vertex3.y += To.y;
		return true;
	}
	Point V1 = Vertex1, V2 = Vertex2, V3 = Vertex3;
	V1.x += To.x;   V1.y += To.y;
	V2.x += To.x;	V2.y += To.y;
	V3.x += To.x;	V3.y += To.y;
	return ValidToDraw(V1, V2, V3);
}