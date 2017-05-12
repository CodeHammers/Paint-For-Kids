#pragma once
#include"Action.h"
#include"..\ApplicationManager.h"
#include <vector>

class CopyAction : public Action
{
private:
	int Selected;   //stores the selected figures count
public:
	//constructor
	CopyAction(ApplicationManager* pApp);

	//static function to perform cloning for any desired figure
	static CFigure* CopyFigure(CFigure* ptr);

	//Read action parameters
	virtual bool ReadActionParameters();

	//Excute action
	virtual void Execute();
};