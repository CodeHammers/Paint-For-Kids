#pragma once

#include"Action.h"

class StoryAction : public Action
{
private:
	Point P;

public:
	/*A constructor function*/
	StoryAction(ApplicationManager* pApp);

	/*Read action parameters*/
	virtual bool ReadActionParameters();

	/*Excute action*/
	virtual void Execute();
};