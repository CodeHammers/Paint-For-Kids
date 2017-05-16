#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "DEFS.h"

#include "Figures\CFigure.h"

#include "GUI\input.h"
#include "GUI\output.h"

#include "Figures\CFigure.h"

#include<fstream>
#include<vector>
#include<queue>

//Main class that manages everything in the application.
class ApplicationManager
{
	enum { MaxFigCount = 200 };	//Max no of figures

private:

	int FigCount;		//Actual number of figures
	vector<CFigure*>FigList;  //vector that holds the figure list
	
	//Pointers to Input and Output classes
	Input *pIn;
	Output *pOut;

	int ClipboardMode;            //status of the clipboard
	vector<CFigure*>Clipboard;    //clipboard
	vector<CFigure**>List;        ///eh dah?
	int ClipboardCount;           ///why?

	/*A private function to tell whether an action is a fill menu action*/
	bool IsFillMenu(ActionType ActType) const;

	/*A private function to tell whether an action is a background menu action*/
	bool IsBackgroundMenu(ActionType ActType) const;

	/*A private function to tell whether an action is a pen menu action*/
	bool IsPenMenu(ActionType ActType) const;

public:	

	/*Constructor function*/
	ApplicationManager();

	///---FIGURE MANAGMENT FUNCTIONS.	

	/*A function to change the drawing color for all currently selected figures*/
	void ChangeDrwClrForSelected(const color& Color);

	/*A function to change the fill color for all currently selected figures*/
	void ChangeFillClrForSelected(const color& Color);

	/*A function to change the border width for all currently selected figures*/
	void ChangeBorderWidthForSelected(const int& BorderWidth);

	/*A function to send a figure to the back or the front of another*/
	void SendSelectedTo(int mode);

	/*A function to scale all figures by a specified ratio*/
	void ScaleAll();

	/*A function to roll back changes made to figure's positional data*/
	void RollBackChanges();

	/*A function to select the figures to be scrambled*/
	bool SelectFigureToScramble(int idx);

	/*A function to unselect all figures*/
	void ClearSelections();

	/*A function to the validity of figures drawing after zoom*/
	bool CheckValidityOfZoom(double r);

	/*A function to bundle the figure positional data*/
	void BundleFiguresData();

	/*A function to rearrange figures*/
	void RearrangeFigures();

	/*A function to resize selected figures*/
	bool ResizeSelectedFigures(double ratio);

	/*A function to get the most top point in the fig list*/
	Point GetTheTopFigure();

	/*A function to grab figures to be dragged*/
	vector<CFigure*> QuerySelectedForDrag();

	/*A function to calculate and queue areas of all figures*/
	priority_queue<int>GetFigureAreas();

	/*A function to get the number of figures specified by type*/
	int GetNumOfFigType();

	/*A function to get the number of figures specified by fill color*/
	int GetNumOfColorfulFig();

	/*A function to return what's in the clipboard*/
	void ReturnFromClipboard();

	/*A function to get the number of figures specified by both type and fill color*/
	int GetNumOfColoredFigures();

	/*A function to manage selection, select all or unselect all*/
	void ManageSelection(bool s);

	/*A function to orchestrate the dragging action*/
	pair<Point, Point> Drag();

	/*A function to check the validity of drag*/
	void CheckValidityOfDrag(vector<CFigure*> figs, pair<Point, Point> Pr);

	/*A function to get the top point of all selected figures*/
	Point GetTheTopFigureOfSelected();

	/*A function to search the figure list for a figure that encloses a given point*/
	CFigure* GetFigure(int x, int y) const;

	/*A function to add a figure to the figure list*/
	void AddFigure(CFigure* pFig);

	/*A function to save all figures fromt a .txt file*/
	void SaveAll(ofstream &OutFile);

	/*A function to return the figure count*/
	int GetFigCount();

	/*A function to return the selected figures count*/
	int GetSelectedFigCount();

	///---------------------------------------------------------------------------------


	///--- OPERATION MANAGMENT FUNCTIONS

	/*A function to get the user action and map it to the corresponding action*/
	ActionType GetUserAction() const;

	/*A function to call the ploymorphic execute function in figures*/
	void ExecuteAction(ActionType) ; 
	
	///--------------------------------------------------------------------------------


	///---CLIPBOARD MANAGMENT FUNCTIONS

	/*A function to delete selected figure, flag specifies the bahavior (shallow or deep deletion)*/
	void DeleteSelected(bool flag);
	
	/*A function to clear the clipboard*/
	void ClearClipboard();

	/*A function to return the clipboard size*/
	int GetClipboardSize();

	/*A function to cut figures to the clipboard*/
	void CutToClipboard(bool unselect);

	/*A function to copy figure to the clipboard*/
	void CopyToClipboard();

	/*A function to add pasted figures to the fig list*/
	void AddPastedFigures(Point P);
	
	///--------------------------------------------------------------------------------


	///---INTERFACE MANAGEMENT FUNCTIONS

	/*A function to return a pointer to the input class*/
	Input *GetInput() const; 

	/*A function to return a pointer to the output class*/
	Output *GetOutput() const; 

	/*A function to update the interface by redrawing figures and menus*/
	void UpdateInterface() const;	

	///---------------------------------------------------------------------------

	
	///TERMINATION CLEAN UP FUNCTIONS
	
	/*A function to clear only entries from the fig list vector*/
	void nullifyFigList();
	
	/*A function to clean up before exiting*/
	void Exit();

	/*A destructor function*/
	~ApplicationManager();
};

#endif