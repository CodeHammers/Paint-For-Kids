#pragma once
#include "Actions\Action.h"

class LoadAction :
	public Action
{
private:
	string filename;
public:
	LoadAction(ApplicationManager * pApp);
	//Reads File Name
	virtual void ReadActionParameters();

	//Reads figures' Data and add appropiate objects to the FigList
	virtual void Execute();
	~LoadAction();
};