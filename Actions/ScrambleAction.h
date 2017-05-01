#pragma once
#include "Action.h"
class ScrambleAction :
	public Action
{
public:
	int WrongAnswers = 0;
	int RightAnswers = 0;
	ScrambleAction(ApplicationManager * app);
	//Get action parameters function
	virtual bool ReadActionParameters();

	//Execute the action
	virtual void Execute();
	void LetsStartTheGaaaame();
	~ScrambleAction();
};

