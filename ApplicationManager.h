#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "DEFS.h"

#include "Figures\CFigure.h"

#include "GUI\input.h"
#include "GUI\output.h"

#include<fstream>
#include<vector>

//Main class that manages everything in the application.
class ApplicationManager
{
	enum { MaxFigCount = 200 };	//Max no of figures

private:
	int FigCount;		//Actual number of figures
	//int SelectedFigs;   //Actual number of currently selected figures
	//CFigure* FigList[MaxFigCount];	//List of all figures (Array of pointers)
	vector<CFigure*>FigList;
	//CFigure* CurrentlySelected[MaxFigCount]; //list of the currently selected figures
	//Pointers to Input and Output classes
	Input *pIn;
	Output *pOut;
	vector<CFigure*>Clipboard;
	int ClipboardCount;

	bool IsFillMenu(ActionType ActType) const;
	bool IsBackgroundMenu(ActionType ActType) const;

	bool IsPenMenu(ActionType ActType) const;

public:	
	ApplicationManager(); 
	~ApplicationManager();
	void nullifyFigList();
	// -- Action-Related Functions
	//Reads the input command from the user and returns the corresponding action type
	ActionType GetUserAction() const;
	void ExecuteAction(ActionType) ; //Creates an action and executes it
	//void AddClipboard(CFigure* pFig);
	// -- Figures Management Functions
	void AddFigure(CFigure* pFig); //Adds a new figure to the FigList
	CFigure* GetFigure(int x, int y) const; //Search for a figure given a point inside the figure
	void DeleteSelected(bool flag);
	//vector<CFigure*> GetSelected();
	//void UpdateFigCount(int Selected_Deleted);
	void ClearClipboard();
	int GetClipboardSize();
	// -- Interface Management Functions
	Input *GetInput() const; //Return pointer to the input
	Output *GetOutput() const; //Return pointer to the output
	void UpdateInterface() const;	//Redraws all the drawing window
	// -- where in the hell does this go functions
	void SaveAll(ofstream &OutFile); // location for 
	int GetFigCount();
	int GetSelectedFigCount();
	void MoveSelectedToClipboard(bool unselect);
	void CopyToClipboard();
};

#endif