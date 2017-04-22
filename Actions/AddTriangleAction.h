#pragma once

#include"Action.h"

class AddTriangleAction : public Action
{

private:
	Point P1, P2, P3;
	GfxInfo TriangleGfxInfo;

public:
	//Constrcutor
	AddTriangleAction(ApplicationManager* pApp);

	//Read action parameters
	virtual bool ReadActionParameters();

	//Execute action
	virtual void Execute();
};