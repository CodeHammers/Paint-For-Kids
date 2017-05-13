#pragma once

#include"Action.h"
#include"..\Figures\CFigure.h"
#include<queue>

class PlayAction : public Action
{
private:
	
	static color FigureFillClr; //stores the pick figure fill color
	priority_queue<int>FigureAreas;  //queue and store areas of all figures
	Input* pIn; Output* pOut;  //pointers to input/output classes
	static string FigureType;  //string to store the figure type

public:
	//constructor
	PlayAction(ApplicationManager* pApp);

	//Get action parameters function
	virtual bool ReadActionParameters();
	
	//Execute the action
	virtual void Execute();
	                            
	//sets the pick by color action paramters
	bool SetSubActionForColor();
	
	//sets the pick by figure type action paramters
	bool SetSubActionForFigureType();

	//sets the pick by figure type and fill color action paramters
	bool SetSubActionForColoredFigures();

	//A function to check the figure type
	static bool CheckFigureType(CFigure* ptr);

	//A function to check the figure color
	static bool CheckColorType(CFigure* ptr);

	//A function to check colored figures
	static bool CheckColoredFigures(CFigure* ptr);

	//A function to claculate and queue figure areas
	void CalcAndQueueAreas();

	//A function to simulate pick by area 
	void PlayPickByArea();

	//A function simulate pick by type and color 
	void PlayColorTypeGame();

	//A function to simulate pick by fill color
	void PlayColoredFigureGame();

	//A function simulate pick by type 
	void PlayFigTypeGame();

	//A function to get the number of spcified-color filled figures
	int GetNumOfColorfulFigures();

	//A function to the get the number of figures based on their type
	int GetNumOfFigure();

	//A function to tell whether the figure with the corrct area was clicked or not
	bool CorrectArea(CFigure* ptr);

	//A function to determine whether the use wants to exit or not
	bool ExitClicked(Point P);

};