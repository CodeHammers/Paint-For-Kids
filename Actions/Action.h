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

	//A function to abort any action while it's undergoing
	bool Abort(Point P) {
		return (P.x >= 1437 && P.x <= 1500 && P.y >= 13*50 && P.y <= 800-80-25);
	}
	
};

#endif