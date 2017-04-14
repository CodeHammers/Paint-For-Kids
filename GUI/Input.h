#ifndef INPUT_H
#define INPUT_H

#include "..\DEFS.h"
#include "UI_Info.h" 
#include "..\CMUgraphicsLib\CMUgraphics.h"

class Output;
class Input		//The application manager should have a pointer to this class
{
private:
	int originalToolBarWidth = 60;
	int startingXForUpperMenu = 500;
	int ScreenEndX = 1500;
	int startingXforLeftMenu2ndCol = 1385;
	int startingXforLeftMenu1stCol = 1435;
	int leftMenuItemHeight = 50;
	int ScreenEndY = 800;
	int playModeItemHeight = 100;
	window *pWind;	//Pointer to the Graphics Window
public:
	Input(window *pW);		//Consturctor
	void GetPointClicked(int &x, int &y) const;//Get coordinate where user clicks
	string GetSrting(Output* pO) const;	 //Returns a string entered by the user

	ActionType GetUserAction() const; //Read the user click and map to an action

	~Input();
};

#endif