#pragma once

#include"Action.h"
#include"../Figures/CFigure.h"
#include<vector>

class SendToAction : public Action
{
private:
	int SendToMode;   //determines the send to mode (back/front)
	int Selected;     //keeps count of the number of selected figures
public:
	//constructor
	SendToAction(int mode, ApplicationManager* pApp);

	//Get action parameters function
	virtual bool ReadActionParameters();

	//Execute the action
	virtual void Execute();
};