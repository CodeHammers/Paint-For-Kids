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
	/*Constructor function*/
	Input(window *pW);

	/*A function to get the coordinates of a point clicked by the user*/
	void GetPointClicked(int &x, int &y) const;

	/*A function to get string from the user through keyboard*/
	string GetSrting(Output* pO) const;	 

	/*A function to get a click from the user and map it an on-screen icon*/
	ActionType GetUserAction() const; 

	/*A destructor function*/
	~Input();
};

#endif