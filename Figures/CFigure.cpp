#include "CFigure.h"

color CFigure::GetColor(string DrawColor)
{
	if (DrawColor == "RED") {
		return  RED;
	}
	if (DrawColor == "GREEN") {
		return  GREEN;
	}
	if (DrawColor == "BLUE") {
		return  BLUE;
	}
	if (DrawColor == "BROWN") {
		return  BROWN;
	}
	if (DrawColor == "BLACK") {
		return BLACK;
	}
	if (DrawColor == "ORANGE") {
		return  ORANGE;
	}
	if (DrawColor == "PURPLE") {
		return  PURPLE;
	}
	if (DrawColor == "YELLOW") {
		return  YELLOW;
	}
	if (DrawColor == "NILE") {
		return PURPLE;
	}
	return NULL;
}

void CFigure::SetPriority(bool s)
{
	HighPriority = s;
}


int CFigure::GetID()
{
	return ID;
}

bool CFigure::IsPriority() const
{
	return HighPriority;
}

void CFigure::SetID(int id)
{
	ID = id;
}

CFigure::CFigure(GfxInfo FigureGfxInfo)
{ 
	FigGfxInfo = FigureGfxInfo;	//Default status is non-filled.
	Selected = false;
}

void CFigure::ScrambleFigure()
{
	Scrambled = true;
}

bool CFigure::ScrambledFigure()
{
	return Scrambled;
}

void CFigure::disableScramble()
{
	Scrambled = false;
}

void CFigure::SetSelected(bool s)
{	Selected = s; }

bool CFigure::IsSelected() const
{	return Selected; }

void CFigure::ChngDrawClr(color Dclr)
{	FigGfxInfo.DrawClr = Dclr; }

void CFigure::ChngFillClr(color Fclr)
{	
	FigGfxInfo.isFilled = true;
	FigGfxInfo.FillClr = Fclr; 
}

bool CFigure::InDrawingArea(Point P) 
{
	return (P.x >= 55 && P.x <= 1435 && P.y >= 60 && P.y <= 710);
}