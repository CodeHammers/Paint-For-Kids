#ifndef CFIGURE_H
#define CFIGURE_H
#include <vector>

#include "..\defs.h"
#include "..\GUI\Output.h"

//Base class for all figures
class CFigure
{
protected:
	int ID;		//Each figure has an ID
	bool Selected;	//true if the figure is selected.
	GfxInfo FigGfxInfo;	//Figure graphis info
	bool HighPriority = false;
	bool Scrambled = false;
	/// Add more parameters if needed.

public:
	CFigure(GfxInfo FigureGfxInfo);
	void ScrambleFigure();
	bool ScrambledFigure();
	void disableScramble();
	virtual void retrieveData()=0;
	virtual void Resize(double ratio) = 0;
	void SetSelected(bool s);	//select/unselect the figure
	bool IsSelected() const;	//check whether fig is selected
	static color GetColor(string color);
	virtual void Draw(Output* pOut) const  = 0 ;		//Draw the figure
	void SetPriority(bool s);	//select/unselect the figure
	bool IsPriority() const;	//check whether fig is selected
	void ChngDrawClr(color Dclr);	//changes the figure's drawing color
	void ChngFillClr(color Fclr);	//changes the figure's filling color
	void SetID(int id);
	virtual bool ValidAfterZoom()=0;
	virtual void ChopCoordniates()=0;
	virtual void ChangeQuandrant(int Qx,int Qy)=0;
	virtual void BundleData()=0;
	///The following functions should be supported by the figure class
	///It should be overridden by each inherited figure

	///Decide the parameters that you should pass to each function	
	virtual void PrintInfo(Output* pOut) = 0;

	virtual int GetArea() = 0;
	//virtual void Rotate() = 0;	//Rotate the figure
	//virtual void Resize() = 0;	//Resize the figure
	//virtual void Move() = 0;		//Move the figure

	virtual bool Encloses(Point P) = 0;

	virtual void SetPoints(Point x) = 0;

	virtual void Save(ofstream &OutFile) = 0;	//Save the figure parameters to the file
	virtual void Load(ifstream &Infile) = 0;	//Load the figure parameters to the file
	virtual Point GetTopCorner() = 0;
	virtual bool TransferFigure(Point To, bool Check = false) = 0;
	//virtual void PrintInfo(Output* pOut) = 0;	//print all figure info on the status bar
	
	static bool InDrawingArea(Point P);
	virtual GfxInfo& GetGfxInfo() = 0;
	int GetID();
};

#endif