#pragma once
#include "Action.h"


class ChangeBckgrndColor : public Action
{
private:
	ActionType ActType;  //represents the action type
	color BackgroundColor;  //to store the background color
	virtual bool ReadActionParameters();

public:
	/*A constructor function*/
	ChangeBckgrndColor(ApplicationManager* appManager,ActionType actType);

	/*A destrcutor function*/
	~ChangeBckgrndColor();

	/*A function to execute action*/
	virtual void Execute();
};