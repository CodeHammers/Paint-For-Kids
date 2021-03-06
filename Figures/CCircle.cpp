#include "CCircle.h"

#include <sstream>
#include <fstream>

CCircle::CCircle(Point P1, int r,GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Center = P1;
	Radius = r;
}

void CCircle::SetStartingDragPoint(Point &p)
{
	p = Center;
}


void CCircle::retrieveData() {
	//creates a bundle for figure's data to be used for retrieving original info
	Radius = Bundle.second;
	Center = Bundle.first;
}


void CCircle::Draw(Output* pOut) const
{
	if (Dragged)
		return;
	//checks of we are drawing the circle at a random position "scramble and find game" or
	//just drawing it as a draw action
	if (Scrambled) {

		Point C = Bundle.first;
		C.x *= 0.5;
		C.x += UI.width/2;
		pOut->DrawCircle(C ,Radius,FigGfxInfo,false);
	}

	pOut->DrawCircle(Center, Radius, FigGfxInfo, Selected);
}

void CCircle::DrawDragged(Output * pOut, Point p) const
{
	pOut->DrawCircle(p, Radius, FigGfxInfo, Selected);
}

bool CCircle::CheckPosAfterDrag(Point p)
{
	BundleData();
	Center = p;
	if (!ValidToDraw(p, Radius)) {
		retrieveData();
		return false;
	}

	return true;
}


void CCircle::ChopCoordniates()
{
	Center.x *= 0.5;   //resize the circle to fit in the left side of the screen
}


bool CCircle::ValidAfterZoom() {
	//checks for validty after zooming
	return ValidToDraw(Center, Radius*UI.Ratio);
}


void CCircle::ChangeQuandrant(int Qx, int Qy) {
	//changes the current quadrant the circle is located at
	Center.x = Qx + Radius;
	Center.y = Qy + Radius;
}


void CCircle::ChangeCord(Point p) {
	Center = p;
}


void CCircle::BundleData() {
	Bundle = make_pair(Center,Radius);  //creates a pair of the bundled data
}


void CCircle::Save(ofstream & OutFile)
{
	//saves the figure according to the format specified in the doc.
	OutFile << "CIRCLE" << "\t"  << ID << "\t";
	OutFile << Center.x << "\t" << Center.y << "\t";
	OutFile<< Radius << "\t"<< (int)FigGfxInfo.DrawClr.ucRed << " " 
		<< (int)FigGfxInfo.DrawClr.ucGreen<< " " << (int)FigGfxInfo.DrawClr.ucBlue << "\t";
	if (FigGfxInfo.isFilled != true)
		OutFile << "  -1 -1 -1" << " \t" << FigGfxInfo.BorderWdth;
	else
		OutFile << (int)FigGfxInfo.FillClr.ucRed << " " << (int)FigGfxInfo.FillClr.ucGreen << " "
		<< (int)FigGfxInfo.FillClr.ucBlue<<" \t"<< FigGfxInfo.BorderWdth;
	OutFile << endl;
}


bool CCircle::Encloses(Point P) 
{
	//function to whether a point is enclosed within the circle
	if (Scrambled) {
		float dist = pow(Bundle.first.x *0.5 +UI.width/2- P.x, 2) + pow(Bundle.first.y - P.y, 2);
		return dist <= Radius*Radius;
	}
	float dist = pow(Center.x - P.x, 2) + pow(Center.y - P.y, 2);
	return dist <= Radius*Radius;
}


void CCircle::Load(ifstream &Infile)
{
	//function to load circle from a .txt file
	int id;
	Infile >> id ;
	Infile >> Center.x >> Center.y >> Radius;
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
	Infile>> info.BorderWdth;
	CFigure::ID = id;
	CFigure::FigGfxInfo = info; ;
}


void CCircle::PrintInfo(Output* pOut) 
{
	//prints the circle's info
	string rs = to_string(Radius);
	string c = "(" + to_string(Center.x) + "," + to_string(Center.y) + ")";
	string A = to_string(GetArea());
	pOut->PrintMessage("Circle: radius = " + rs + ", Center = " + c+ ", Area = "+A);
}


Point CCircle::GetCenter()
{
	return Center;
}


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
	//checks if the circle is valid to be drawn
	return (InDrawingArea({ C.x + R,C.y }) && InDrawingArea({ C.x - R,C.y }) && 
		   InDrawingArea({ C.x,C.y + R }) && InDrawingArea({ C.x,C.y - R }));
}


void CCircle::Resize(double r) {
	Radius = r*Radius;  //resize circle by specified ratio
}


Point CCircle::GetTopCorner()
{
	return Center;
}


CFigure* CCircle::Clone()
{
	//creates an exact copy of the current object
	CFigure* Temp = new CCircle(Center, Radius, FigGfxInfo);
	return Temp;
}


bool CCircle::TransferFigure(Point To, bool Check)
{
	//transfers the figure's coordinates to translate to a new destination
	if (!Check) {
		Center.x += To.x; Center.y += To.y;
		return true;
	}
	Point V = Center;
	V.x += To.x; V.y += To.y;
	return ValidToDraw(V, Radius);
}


GfxInfo& CCircle::GetGfxInfo()
{
	return FigGfxInfo;
}


string CCircle::GetName()
{
	return "Circule";
}