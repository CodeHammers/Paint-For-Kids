#ifndef CFIGURE_H
#define CFIGURE_H
#include <vector>

#include "..\defs.h"
#include "..\GUI\Output.h"

//Base class for all figures
class CFigure
{
protected:
	int ID;		                   //Each figure has an ID
	bool Selected;	               //true if the figure is selected.
	GfxInfo FigGfxInfo;	           //Figure graphis info
	bool Scrambled = false;        //determines if the figure is randomly drawn, intially false
	bool Dragged = false;

public:
	/*Contructor function*/
	CFigure(GfxInfo FigureGfxInfo);

	/*A function to set the scrambles flag*/
	void ScrambleFigure();

	/*A function to check whether a figure is randomaly drawn*/
	bool ScrambledFigure();

	/*A function to disable the scrambling mode for figures*/
	void disableScramble();

	/*A virtual function to restore figure's original positional data*/
	virtual void retrieveData()=0;

	/*A virtual function to resize a figure by a specified ratio*/
	virtual void Resize(double ratio) = 0;

	/*A function to set the selected flag for a figure*/
	void SetSelected(bool s);	

	/*A function to check whether a figure is selected*/
	bool IsSelected() const;	

	/*A static function that returns a figure's color*/
	static color GetColor(string color);

	/*A pure virtual function to draw a figure*/
	virtual void Draw(Output* pOut) const  = 0 ;		
	virtual void DrawDragged(Output* pOut,Point p) const = 0;
	/*A function to change figure's drawing color*/
	void ChngDrawClr(color Dclr);	

	/*A function to change figure's fill color*/
	void ChngFillClr(color Fclr);	

	/*A function to set the figure's ID*/
	void SetID(int id);

	/*Virtual function to check the validity of a figure position after zooming*/
	virtual bool ValidAfterZoom()=0;

	/*A fucntion to resize the figure size by half to fit in the left side of the screen*/
	virtual void ChopCoordniates()=0;

	/*A function to change figure's quadrant*/
	virtual void ChangeQuandrant(int Qx,int Qy)=0;

	/*A function to create a bundle of a figure's positional data*/
	virtual void BundleData()=0;

	/*A function to change a figure's coordinates*/
	virtual void ChangeCord(Point p)=0;

	/*A function to print a figure's info*/
	virtual void PrintInfo(Output* pOut) = 0;

	/*A function to calculate the area of a figure*/
	virtual int GetArea() = 0;

	/*A function to check whether a point P is encompassed by a figure*/
	virtual bool Encloses(Point P) = 0;

	/*A function to enforce points to positional data*/
	virtual void SetPoints(Point x) = 0;

	/*A function to save and write figure's data to an exeternal file*/
	virtual void Save(ofstream &OutFile) = 0;	

	/*A function to load and read figure's data from an external file*/
	virtual void Load(ifstream &Infile) = 0;	

	/*A function to return the top point of a figure*/
	virtual Point GetTopCorner() = 0;

	/*A function to translate a figure and move it to another position*/
	virtual bool TransferFigure(Point To, bool Check = false) = 0;

	/*A function to create and exact copy of a figure*/
	virtual CFigure* Clone() = 0;

	/*A static function to check whether a point is inside the drawing area*/
	static bool InDrawingArea(Point P);

	/*A function to return gfx of a figure*/
	virtual GfxInfo& GetGfxInfo() = 0;

	/*A function to return a figure's ID*/
	int GetID();
	void Drag(bool);
	/*A function to return a figure's name*/
	virtual string GetName() = 0;

	//virtual void Rotate() = 0;	//Rotate the figure
	//virtual void Resize() = 0;	//Resize the figure
	//virtual void Move() = 0;		//Move the figure
};

#endif