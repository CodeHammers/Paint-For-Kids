#ifndef OUPTUT_H
#define OUPTUT_H
#include "Input.h"

class Output	//The application manager should have a pointer to this class
{
private:
	window* pWind;	//Pointer to the Graphics Window
public:
	Output();
	void EditWindowSettings(color drawcolor, color fillcolor, color backgroundcolor);
	void ChangeBackgroundColor(color BackgroundColor);
	window* CreateWind(int, int, int, int) const; //creates the application window
	void CreateDrawToolBarUp(int action, bool sub) const;	//creates Draw mode upper toolbar 
	void CreateDrawToolBarRight(bool collapse) const;//creates Draw mode right toolbar 
	void CreatePlayToolBar() const;	//creates Play mode toolbar & menu
	void CreateStatusBar() const;	//create the status bar

	Input* CreateInput() const; //creates a pointer to the Input object	
	void ClearStatusBar() const;	//Clears the status bar
	void ClearDrawArea() const;	//Clears the drawing area

								// -- Figures Drawing functions
	void DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected = false) const;  //Draw a rectangle
	void DrawLine(Point P1, Point P2, GfxInfo LineGfxInfo, bool selected = false) const;  //Draw a Line
	void DrawTriangle(Point P1, Point P2, Point P3, GfxInfo TriangleGfxInfo, bool selected = false) const; //Draw a triangle
	void DrawCircle(Point center, int radius, GfxInfo CircleGfxInfo, bool selected = false) const; //Draw a circle.

	void PrintMessage(string msg) const;	//Print a message on Status bar

	color getCrntDrawColor() const;	//get current drwawing color
	color getCrntFillColor() const;	//get current filling color
	int getCrntPenWidth() const;		//get current pen width

	~Output();
};

#endif