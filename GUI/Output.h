#ifndef OUPTUT_H
#define OUPTUT_H
#include "Input.h"

class Output	//The application manager should have a pointer to this class
{
private:
	window* pWind;	//Pointer to the Graphics Window
public:
	/*A default constructor function*/
	Output();

	/*A non constructor function*/
	Output(int x);

	/*A function to chnage the zooming level*/
	void ChangeZoomLevel(double z);

	/*A function to edit the window settings*/
	void EditWindowSettings(color drawcolor, color fillcolor, color backgroundcolor);

	/*A function to change the application background*/
	void ChangeBackgroundColor(color BackgroundColor);

	/*A fcuntion to change the drawing color*/
	void ChangeDrawColor(color DrawColor);

	/*A function to change the fill color*/
	void ChangeFillColor(color FillColor);

	/*A function to change the border width*/
	void ChangeBorderWidth(int BW);

	/*A function to create a window*/
	window* CreateWind(int, int, int, int) const; 

	/*A fucntion to draw the upper toolbar*/
	void CreateDrawToolBarUp(int action, bool sub, bool show) const;	

	/*A function to draw the right toolbar*/
	void CreateDrawToolBarRight(bool collapse,bool show) const; 

	/*A function to create the play mode upper toolbar*/
	void CreatePlayToolBar(int action, bool collapse, bool stat) const; 

	/*A function to create the application status bar*/
	void CreateStatusBar() const;	

	/*A function to initiate the input class*/
	Input* CreateInput() const; 

	/*A function to clear the status bar*/
	void ClearStatusBar() const;

	/*A function to clear the drawing area*/
	void ClearDrawArea() const;	
								
	/*A function to draw a rectangle*/
	void DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected = false) const;  

	/*A function to draw a line*/
	void DrawLine(Point P1, Point P2, GfxInfo LineGfxInfo, bool selected = false) const;
	
	/*A function to draw a triangle*/
	void DrawTriangle(Point P1, Point P2, Point P3, GfxInfo TriangleGfxInfo, bool selected = false) const; 

	/*A function to draw a circle*/
	void DrawCircle(Point center, int radius, GfxInfo CircleGfxInfo, bool selected = false) const; //Draw a circle.

	buttonstate getButtonState(int & iX, int & iY);

	/*A function to zoom taking reference to a point*/
	void ZoomPoint(Point & p) const;

	/*A function to print a message on the status bar*/
	void PrintMessage(string msg) const;	

	/*A function to get the current drawing color*/
	color getCrntDrawColor() const;	

	/*A function to get the current fill color*/
	color getCrntFillColor() const;	

	/*A function to get the current pen width*/
	int getCrntPenWidth() const;	

	/*A function to clean the screen*/
	void CleanTheScreen();

	void setBuffering(bool state);

	void FlushMouse();

	bool EscapeClicked();

	bool EnterClicked();

	bool UpdateBuffer();


	/*Destructor function*/
	~Output();
};

#endif