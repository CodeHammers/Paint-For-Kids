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


CFigure::CFigure(GfxInfo FigureGfxInfo)
{ 
	FigGfxInfo = FigureGfxInfo;	//Default status is non-filled.
	Selected = false;
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