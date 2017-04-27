#include "CCircle.h"
#include <sstream>
#include <fstream>

CCircle::CCircle(Point P1, int r,GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Center = P1;
	Radius = r;
}


void CCircle::Draw(Output* pOut) const
{
	pOut->DrawCircle(Center, Radius, FigGfxInfo);
}

bool CCircle::ValidAfterZoom() {
	return ValidToDraw(Center, Radius*UI.Ratio);
}
void CCircle::Save(ofstream & OutFile)
{
	OutFile << ID << "\t";
	OutFile << Center.x << "\t" << Center.y << "\t";
	OutFile<< Radius << (int)FigGfxInfo.DrawClr.ucBlue << " " 
		<< (int)FigGfxInfo.DrawClr.ucGreen<< " " << (int)FigGfxInfo.DrawClr.ucRed << "\t";
	if (FigGfxInfo.isFilled != true)
		OutFile << "NOFILL";
	else
		OutFile << (int)FigGfxInfo.FillClr.ucBlue << " " << (int)FigGfxInfo.FillClr.ucGreen << " "
		<< (int)FigGfxInfo.FillClr.ucRed;
	OutFile << endl;
}


bool CCircle::Encloses(Point P) 
{
	float dist = pow(Center.x - P.x, 2) + pow(Center.y - P.y, 2);
	return dist <= Radius*Radius;
}

void CCircle::Load(ifstream &Infile)
{
	///Your code goes here.
	int id;
	string DrawColor, FillColor;
	Infile >> id ;
	Infile >> Center.x >> Center.y >> Radius;
	GfxInfo info;
	Infile >> DrawColor;
	info.DrawClr = GetColor(DrawColor);
	Infile >> FillColor;
	if (FillColor == "NOFILL") {
		info.isFilled = false;
		info.FillClr = WHITE;
	}
	else {
		info.isFilled = true;
		info.FillClr = GetColor(FillColor);
	}
	info.BorderWdth = 3;
	CFigure::ID = id;
	CFigure::FigGfxInfo = info; ;
}

void CCircle::PrintInfo(Output* pOut) 
{
	string rs = to_string(Radius);
	string c = "(" + to_string(Center.x) + "," + to_string(Center.y) + ")";
	string A = to_string(GetArea());
	pOut->PrintMessage("Circle: radius = " + rs + ", Center = " + c+ ", Area = "+A);
}

Point CCircle::GetCenter()
{
	return Center;
}

//GfxInfo CCircle::GetGfxInfo()
//{
//	return FigGfxInfo;
//}

int CCircle::GetArea()
{
	return (int)3.14*Radius*Radius;
}

void CCircle::SetPoints(Point s)
{
	Center.x += s.x;
	Center.y += s.y;
}

int CCircle::GetRadius()
{
	return Radius;
}

bool CCircle::ValidToDraw(Point C, int R)
{
	return (InDrawingArea({ C.x + R,C.y }) && InDrawingArea({ C.x - R,C.y }) && 
		   InDrawingArea({ C.x,C.y + R }) && InDrawingArea({ C.x,C.y - R }));
}

void CCircle::TransferFigure(Point To)
{
	;
}