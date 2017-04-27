#include "Action.h"
class ZoomAction : public Action
{
private:
	ActionType actType;
	ApplicationManager * appManager;
public:
	ZoomAction(ApplicationManager* pApp,ActionType ActType);

	virtual bool ReadActionParameters();
	virtual void Execute();
};