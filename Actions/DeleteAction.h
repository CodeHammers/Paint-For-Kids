#pragma once
#include "SelectAction.h"
#include <vector>
class DeleteAction : public Action
{
private:
	int CurrentDeleted;
	CFigure** FigList;
public:
	DeleteAction(ApplicationManager *pApp);
	virtual bool ReadActionParameters();
	void UpdateAfterDelete();
	virtual void Execute();
};