#pragma once

#include"Action.h"

class AddTriangleAction : public Action
{

private:
	Point P1, P2, P3;   //The 3 vertexes of the triangle
	GfxInfo TriangleGfxInfo;  //contains info about colors, borderwidth and similar info

public:
	//Constrcutor
	AddTriangleAction(ApplicationManager* pApp);

	//Read action parameters
	virtual bool ReadActionParameters();

	//Execute action
	virtual void Execute();
};