#ifndef ACTION_H
#define ACTION_H

#include "..\DefS.h"

class ApplicationManager; //forward class declaration


//Base class for all possible actions
class Action
{
protected:
	ApplicationManager *pManager;	//Actions needs AppMngr to do their job

public:

	Action(ApplicationManager *pApp) { pManager = pApp; }	//constructor

	//Reads parameters required for action to execute (code depends on action type)
	virtual bool ReadActionParameters() =0;
	
	//Execute action (code depends on action type)
	virtual void Execute() =0;

	//To undo this action (code depends on action type)
	//virtual void Undo()=0;

	//To redo this action (code depends on action type)
	//virtual void Redo()=0;

	bool Abort(Point P) {
		return (P.x >= 1385 && P.x <= 1500 && P.y >= 0 && P.y <= 50);
	}
	
};

#endif