#include "Action.h"
class ZoomAction : public Action
{
private:
	ActionType actType;
public:
	ZoomAction(ApplicationManager* pApp,ActionType ActType);

	virtual bool ReadActionParameters();
	virtual void Execute();
};