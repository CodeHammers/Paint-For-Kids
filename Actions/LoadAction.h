#pragma once
#include "Action.h"

class LoadAction :
	public Action
{
private:
	string filename;
	virtual bool ReadActionParameters();

public:
	LoadAction(ApplicationManager * pApp);
	//Reads File Name

	//Reads figures' Data and add appropiate objects to the FigList
	virtual void Execute();
	~LoadAction();
};