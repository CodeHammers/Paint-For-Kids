#include "ApplicationManager.h"
#include "Actions\AddRectAction.h"
#include "Actions\AddLineAction.h"
#include "Actions\AddCircleAction.h"
#include "Actions\AddTriangleAction.h"
#include "Actions\SelectAction.h"
#include "Actions\LoadAction.h"
#include "Actions\ChangeBckgrndColor.h"
#include "Actions\ChangeDrawColorAction.h"
#include "Actions\ChangeFillColor.h"
#include "Actions\ChangeBorderWidthAction.h"
#include "Actions\SaveAction.h"
#include "Actions\DeleteAction.h"
#include "Actions\CopyAction.h"
#include "Actions\CutAction.h"
#include "Actions\PasteAction.h"
#include "Actions\ZoomAction.h"
#include "Actions\PlayAction.h"
#include "Actions\ResizeAction.h"
#include "Actions\ScrambleAction.h"
#include <time.h>       /* time */

//Constructor

ApplicationManager::ApplicationManager()
{

	//Interface Here//

	//Create Input and output
	pOut = new Output(5);
	pIn = pOut->CreateInput();
	Point P;
	while (true) {
		pIn->GetPointClicked(P.x, P.y);
		if (P.x >= 200 && P.x <= 700) {
			UI.male = false;
			break;
		}
		else if (P.x >= 700 && P.x <= 700 + 500) {
			UI.male = true;
			break;
		}
	}
	UI.InterfaceMode = MODE_DRAW;
	if (UI.male) {
		UI.BkGrndColor = WHITE;	//Setting the background color.
		UI.HighlightColor = MAGENTA;	//Setting the highlighting color.
		UI.StatusBarColor = TURQUOISE;  //Setting the color of the status bar.
	}
	else {
		UI.BkGrndColor = LIGHTPINK;	//Setting the background color.
		UI.HighlightColor = WHITE;	//Setting the highlighting color.
		UI.StatusBarColor = LIGHTBLUE;  //Setting the color of the status bar.
	}
	UI.PenWidth = 3;	//Setting the width of figures frames.
	pOut->CleanTheScreen();
	pOut->CreateDrawToolBarUp(0, false, true);
	pOut->CreateDrawToolBarRight(false, true);

	/*Drawing the status bar in the application window*/
	pOut->CreateStatusBar();
	ClipboardMode = 1;
}

void ApplicationManager::ScaleAll() {
	for (unsigned int i = 0; i < FigList.size(); i++) {
		FigList[i]->Resize(0.5);
		FigList[i]->ChopCoordniates();
	}
}
void ApplicationManager::RollBackChanges() {
	for (unsigned int i = 0; i < FigList.size(); i++) {
		FigList[i]->Resize(2);
		FigList[i]->disableScramble();
		FigList[i]->retrieveData();
		FigList[i]->SetSelected(false);
	}
}

void ApplicationManager::nullifyFigList() {
	FigList.clear();
	/*
	while (FigCount--) {
		delete FigList[FigCount];
		FigList[FigCount] = NULL;
	}
	++FigCount;
	*/
}
bool ApplicationManager::SelectFigureToScramble(int idx) {
	CFigure* fig = FigList[idx];
	fig->SetSelected(true);
	return true;
}
void ApplicationManager::ClearSelections() {
	for (unsigned int i = 0; i < FigList.size(); i++) {
		FigList[i]->SetSelected(false);
	}
}
bool ApplicationManager::CheckValidityOfZoom(double r) {
	UI.Ratio *= r;
	for (int i = 0; i < FigList.size(); i++) {
		if (!FigList[i]->ValidAfterZoom()) {
			UI.Ratio /= r;
			return false;
		}
	}
	UI.Ratio /= r;
	return true;
}

void ApplicationManager::BundleFiguresData() {
	for (unsigned int i = 0; i < FigList.size(); i++) {
		FigList[i]->ScrambleFigure();
		FigList[i]->BundleData();
	}
}

void ApplicationManager::RearrangeFigures() {
	int areaQuadrantsX[4];
	int areaQuadrantsY[4];
	areaQuadrantsX[0] = 70; areaQuadrantsY[0] = 70;
	areaQuadrantsX[1] = UI.width/4; areaQuadrantsY[1] = 70;
	areaQuadrantsX[2] = 70; areaQuadrantsY[2] = UI.height/2;
	areaQuadrantsX[3] = UI.width/4; areaQuadrantsY[3] = UI.height/2;
	int index = 0;
	srand(time(NULL));
	for (unsigned int i = 0; i < FigList.size(); i++) {
	/*	FigList[i]->ChangeQuandrant(areaQuadrantsX[index], areaQuadrantsY[index]);
		index++;
		index = index % 4;
		int maxAttemps=0;*/
		Point p; p.x = rand() % (UI.width / 2 - 70) + 70; p.y = rand() % (UI.height / 2 - 70) + 70;p.x += UI.width / 2;
		FigList[i]->ChangeCord(p);
		while (!FigList[i] ->ValidAfterZoom()) {
			p; p.x = rand() % (UI.width / 2 - 70) + 70; p.y = rand() % (UI.height / 2 - 70) + 70; p.x += UI.width / 2;
			FigList[i]->ChangeCord(p);
			//FigList[i]->ChangeQuandrant(areaQuadrantsX[index], areaQuadrantsY[index]);
			//index++;
			//index = index % 4;
			
		}
		p.x -= UI.width/2;
		FigList[i]->ChangeCord(p);
	}
}

bool ApplicationManager::IsFillMenu(ActionType ActType) const
{
	switch (ActType)
	{
	case ITM_BRUSHFILL_BLACK_Clicked:
		return true;
	case ITM_BRUSHFILL_BLUE_Clicked:
		return true;
	case ITM_BRUSHFILL_BROWN_Clicked:
		return true;
	case ITM_BRUSHFILL_GREEN_Clicked:
		return true;
	case ITM_BRUSHFILL_ORANGE_Clicked:
		return true;
	case ITM_BRUSHFILL_PINK_Clicked:
		return true;
	case ITM_BRUSHFILL_YELLOW_Clicked:
		return true;
	case ITM_BRUSHFILL_NILE_Clicked:
		return true;
	case ITM_BRUSHFILL_PURPLE_Clicked:
		return true;
	case ITM_BRUSHFILL_RED_Clicked:
		return true;
	}
	return false;
}
bool ApplicationManager::IsBackgroundMenu(ActionType ActType) const
{
	switch (ActType)
	{
	case ITM_BCKG_WHITE_Clicked:
		return true;
	case ITM_BCKG_BLUE_Clicked:
		return true;
	case ITM_BCKG_RED_Clicked:
		return true;
	case ITM_BCKG_PINK_Clicked:
		return true;
	case ITM_BCKG_BROWN_Clicked:
		return true;
	case ITM_BCKG_NILE_Clicked:
		return true;
	case ITM_BCKG_YELLOW_Clicked:
		return true;
	case ITM_BCKG_ORANE_Clicked:
		return true;
	case ITM_BCKG_PURPLE_Clicked:
		return true;
	case ITM_BCKG_GREEN_Clicked:
		return true;
	}
	return false;
}

bool ApplicationManager::IsPenMenu(ActionType ActType) const
{
	switch (ActType)
	{
	case ITM_BRUSH_BLACK_Clicked:
		return true;
	case ITM_BRUSH_YELLOW_Clicked:
		return true;
	case ITM_BRUSH3_BLUE_Clicked:
		return true;
	case ITM_BRUSH_BROWN_Clicked:
		return true;
	case ITM_BRUSH_PINK_Clicked:
		return true;
	case ITM_BRUSH_GREEN_Clicked:
		return true;
	case ITM_BRUSH_NILE_Clicked:
		return true;
	case ITM_BRUSH_ORANGE_Clicked:
		return true;
	case ITM_BRUSH_PURPLE_Clicked:
		return true;
	case ITM_BRUSH_RED_Clicked:
		return true;
	}
	return false;
}
//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
ActionType ApplicationManager::GetUserAction() const
{
	/*We get the user actions, we define two main types of actions,
	(1) a simple action, that's an action taken directly from an on-screen icon
	(2) a nested action, that's an action taken from a sub menu
	-for action number 1, we simple return the action type to the main
	-for action number 2, we do the following: 
	   [1] show the sub menu
	   [2] wait for the user to click an icon from the sub menu
	   [3] hide th sub menu(that includes a click in the sub menu or outside it)
	   [4] return the selected action to the main function*/

	//Ask the input to get the action from the user.
	ActionType Type = pIn->GetUserAction(), ret;
	switch (Type) {
    
	case MODE_DRAW_SUB_MENU1_Clicked:   //figures
		pOut->CreateDrawToolBarUp(1, false,false);  //show sub menu
		ret = pIn->GetUserAction();  //get action(figure option)
		pOut->CreateDrawToolBarUp(1, true, false);  //hide sub menu
		return ret;

	case MODE_DRAW_SUB_MENU2_Clicked:  //pens
		pOut->CreateDrawToolBarUp(2, false, false);  //show sub menu
		ret = pIn->GetUserAction();  //get action(pen option)
		pOut->CreateDrawToolBarUp(2, true, false);  //hide sub menu
		return ret;

	case MODE_DRAW_SUB_MENU3_Clicked: //brushes
		pOut->CreateDrawToolBarUp(3, false, false);  //show sub menu
		ret = pIn->GetUserAction();  //get action(brushes option)
		pOut->CreateDrawToolBarUp(3, true, false);  //hide sub menu
		return ret;

	case MODE_DRAW_SUB_MENU4_Clicked:  //background colors
		pOut->CreateDrawToolBarUp(4, false, false);  //show sub menu
		ret = pIn->GetUserAction();  //get action(background colors option)
		pOut->CreateDrawToolBarUp(4, true, false);  //hide sub menu
		return ret;

	case MODE_DRAW_SUB_MENU5_Clicked:  //border width
		pOut->CreateDrawToolBarUp(5, false, false);  //show sub menu
		ret = pIn->GetUserAction();  //get action(border width option)
		pOut->CreateDrawToolBarUp(5, true, false);  //hide sub menu
		return ret; 

	case ITM_RESIZE_Clicked:  //resize options
		pOut->CreateDrawToolBarUp(6, false, false);  //show sub menu
		ret = pIn->GetUserAction();  //get action(resize option)
		pOut->CreateDrawToolBarUp(6, true, false);  //hide sub menu
		return ret;
	
	}

	return Type;  //if not a sub menu action, return it directly.
}
////////////////////////////////////////////////////////////////////////////////////
//Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType)
{
	Action* pAct = NULL;

	//According to Action Type, create the corresponding action object
	if (IsBackgroundMenu(ActType)) {
		pAct = new ChangeBckgrndColor(this, ActType);
	}
	if (IsPenMenu(ActType)) {
		pAct = new ChangeDrawColorAction(this, ActType);
	}
	if (IsFillMenu(ActType)) {
		pAct = new ChangeFillColor(this,ActType);
	}

	/*	ITM_RESIZE25_Clicked,
	ITM_RESIZE50_Clicked,
	ITM_RESIZE200_Clicked,
	ITM_RESIZE400_Clicked,*/
	switch (ActType)
	{
		case ITM_RESIZE25_Clicked:
			pAct = new ResizeAction(this, ITM_RESIZE25_Clicked);
			break;
		case ITM_RESIZE50_Clicked:
			pAct = new ResizeAction(this, ITM_RESIZE50_Clicked);
			break;
		case ITM_RESIZE200_Clicked:
			pAct = new ResizeAction(this, ITM_RESIZE200_Clicked);
			break;
		case ITM_RESIZE400_Clicked:
			pAct = new ResizeAction(this, ITM_RESIZE400_Clicked);
			break;
		case ITM_ZOOM_IN_Clicked:
			pAct = new ZoomAction(this, ActType);
			break;
		case ITM_ZOOM_OUT_Clicked:
			pAct = new ZoomAction(this, ActType);
			break;
		// Border Action Start
		case ITM_BORDERWIDTH1_Clicked :
			pAct = new ChangeBorderWidthAction(this,ActType);
			break;
		case ITM_BORDERWIDTH2_Clicked:
			pAct = new ChangeBorderWidthAction(this, ActType);
			break;
		case ITM_BORDERWIDTH3_Clicked:
			pAct = new ChangeBorderWidthAction(this, ActType);
			break;
		case ITM_BORDERWIDTH4_Clicked:
			pAct = new ChangeBorderWidthAction(this, ActType);
			break;
		//Border Action End
		case ITM_LOAD_Clicked:
			pAct = new LoadAction(this);
			break;
		//ironically ,this is the Scramble action :C
		case MODE_PLAY_SUB_MENU1_Clicked:
			pAct = new ScrambleAction(this);
			break;
		case DRAW_RECT:
			pAct = new AddRectAction(this);
			break;

		case DRAW_LINE:
			pAct = new AddLineAction(this);
			break;

		case DRAW_CIRC:
			pAct = new AddCircleAction(this);
			break;

		case DRAW_TRI:
			pAct = new AddTriangleAction(this);
			break;

		case ITM_SELECT_Clicked:
			pAct = new SelectAction(this);
			break;

		case ITM_SAVEAS_Clicked:
			pAct = new SaveAction(this);
			break;

		case EXIT:
			///create ExitAction here
			
			break;

		case ITM_DELETE_Clicked:
			pAct = new DeleteAction(this);
			break;

		case ITM_COPY_Clicked:
			pAct = new CopyAction(this);
			break;

		case ITM_CUT_Clicked:
			pAct = new CutAction(this);
			break;

		case ITM_PASTE_Clicked:
			pAct = new PasteAction(this);
			break;

		case TO_DRAW:
			pOut->CreatePlayToolBar(0, true,false);
			pOut->CreateDrawToolBarUp(0, false, false);
			pOut->CreateDrawToolBarRight(false, false);
			UI.InterfaceMode = MODE_DRAW;
			break;

		case TO_PLAY:
			pOut->CreatePlayToolBar(0, false, true);
			ManageSelection(false);
			ClearClipboard();
			break;

		case MODE_PLAY_SUB_MENU2_Clicked:
			pAct = new PlayAction(this);
			break;

		case STATUS:	//a click on the status bar ==> no action
			return;
	}
	
	//Execute the created action
	if(pAct != NULL)
	{
		pAct->Execute();//Execute
		delete pAct;	//Action is not needed any more ==> delete it
		pAct = NULL;
	}
}
//void ApplicationManager::AddClipboard(CFigure * pFig)
//{
//	Clipboard.push_back(pFig);
//}
//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//

//Add a figure to the list of figures
void ApplicationManager::AddFigure(CFigure* pFig)
{
	if(FigCount < MaxFigCount )
		FigList.push_back(pFig);	
}

int ApplicationManager::GetFigCount() { return FigList.size(); }

void ApplicationManager::ManageSelection(bool s)
{
	for (int i = 0; i < FigList.size(); i++)
		FigList[i]->SetSelected(s);
}

void ApplicationManager::ChangeDrwClrForSelected(const color& Color)
{
	for (int i = 0; i < FigList.size(); ++i)
		if (FigList[i]->IsSelected()) {
			FigList[i]->GetGfxInfo().DrawClr = Color;
			FigList[i]->SetSelected(false);
		}
}

void ApplicationManager::ChangeFillClrForSelected(const color & Color)
{
	for (int i = 0; i < FigList.size(); ++i)
		if (FigList[i]->IsSelected()) {
			FigList[i]->GetGfxInfo().FillClr = Color;
			FigList[i]->SetSelected(false);
			FigList[i]->GetGfxInfo().isFilled = true;
		}
}

void ApplicationManager::ChangeBorderWidthForSelected(const int & BorderWidth)
{
	for (int i = 0; i < FigList.size(); ++i)
		if (FigList[i]->IsSelected()) {
			FigList[i]->GetGfxInfo().BorderWdth = BorderWidth;
			FigList[i]->SetSelected(false);
		}
}

int ApplicationManager::GetSelectedFigCount()
{
	int cnt = 0;
	for (int i = 0; i < FigList.size(); i++) {
		if (FigList[i]->IsSelected())
			cnt++;
	}
	return cnt;
}

void ApplicationManager::DeleteSelected(bool flag)
{
	for (int i = 0; i < FigList.size(); i++) {
		if (FigList[i]->IsSelected()) {
			if(flag) delete FigList[i];
			FigList.erase(FigList.begin() + i);
			i--;
		}
	}
}

void ApplicationManager::CutToClipboard(bool unselect)
{
	for (int i = 0; i < FigList.size(); i++) {
		if (FigList[i]->IsSelected()) {
			if (unselect) 
				FigList[i]->SetSelected(false);
			Clipboard.push_back(FigList[i]);
		}
	}
}

void ApplicationManager::CopyToClipboard()
{
	for (int i = 0; i < FigList.size(); i++) {
		if (FigList[i]->IsSelected()) {
			FigList[i]->SetSelected(false);
			CFigure* ptr = CopyAction::CopyFigure(FigList[i]);
			Clipboard.push_back(ptr);
		}
	}
}

void ApplicationManager::AddPastedFigures(Point P)
{
	if (ClipboardMode > 1) {

		vector<CFigure*>temp(Clipboard.size());
		for (int i = 0; i < Clipboard.size(); i++)
			temp[i] = Clipboard[i];

		Clipboard.clear();
		for (int i = 0; i < temp.size(); i++) {
			CFigure* ptr = CopyAction::CopyFigure(temp[i]);
			Clipboard.push_back(ptr);
		}
	}
	bool found = true;
	for (int i = 0; i < Clipboard.size(); ++i)
		if (!Clipboard[i]->TransferFigure(P, true)) {
			found = false;	break;
		}
	for (int i = 0; i < Clipboard.size(); i++) {
		if (found) {
			Clipboard[i]->TransferFigure(P);
			AddFigure(Clipboard[i]);
			ClipboardMode++;
		}
		else {
			pOut->PrintMessage("Paste: Can't paste all/some figures taking reference to the Clicker point");
			break;
		}
	}
}
void ApplicationManager::ResizeSelectedFigures(double ratio) {
	double temp = UI.Ratio;
	UI.Ratio = ratio;
	if (FigList.empty())
		return;
	for (int i = 0; i < FigList.size(); i++) {
		if (FigList[i]->IsSelected()) {
			FigList[i]->Resize(ratio);
		}
	}
	UI.Ratio = temp;
}

priority_queue<int> ApplicationManager::GetFigureAreas()
{
	priority_queue<int>Areas;
	for (int i = 0; i < FigList.size(); i++) {
		Areas.push(FigList[i]->GetArea());
	}
	return Areas;
}

int ApplicationManager::GetNumOfFigType()
{
	int cnt = 0;
	for (int i = 0; i < FigList.size(); ++i)
		if (PlayAction::CheckFigureType(FigList[i]))
			cnt++;
	return cnt;
}

int ApplicationManager::GetNumOfColorfulFig()
{
	int cnt = 0;
	for (int i = 0; i < FigList.size(); ++i)
		if (PlayAction::CheckColorType(FigList[i]))
			cnt++;
	return cnt;
}

int ApplicationManager::GetNumOfColoredFigures()
{
	int cnt = 0;
	for (int i = 0; i < FigList.size(); ++i)
		if (PlayAction::CheckColoredFigures(FigList[i]))
			cnt++;
	return cnt;
}

void ApplicationManager::ReturnFromClipboard()
{
	for (int i = 0; i < Clipboard.size(); ++i) {
		Clipboard[i]->SetSelected(false); FigList.push_back(Clipboard[i]);
	}
	ClipboardMode = 0;	ClearClipboard();
}

Point ApplicationManager::GetTheTopFigure()
{
	Point P = { 2000,2000 };
	for (int i = 0; i < Clipboard.size(); ++i)
		if (Clipboard[i]->GetTopCorner().x <= P.x && Clipboard[i]->GetTopCorner().y <= P.y)
			P = Clipboard[i]->GetTopCorner();
	return P;
}

////////////////////////////////////////////////////////////////////////////////////
CFigure* ApplicationManager::GetFigure(int x, int y) const
{
	for (int i = FigList.size() -1; i>=0; i--) {
		if (FigList[i]->Encloses({ x,y }))  //if the point is in the figure
			return FigList[i];
	}
	return NULL;
}

//vector<CFigure*> ApplicationManager::GetSelected()
//{
//	vector<CFigure*> selected;
//	for (int i = 0; i < FigList.size(); i++) {
//		if (FigList[i]->IsSelected())
//			selected.push_back(FigList[i]);
//	}
//	return selected;
//}


//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{
	if (UI.Zoom != 1) {
		pOut->CleanTheScreen();
		pOut->CreateDrawToolBarUp(0, false, true);
		pOut->CreateDrawToolBarRight(false, true);
		pOut->CreateStatusBar();
	}
	GetOutput()->ClearDrawArea();
	for (int i = 0; i < FigList.size(); i++) {
		FigList[i]->Draw(pOut);		//Call Draw function (virtual member fn)
	
	}
}

//void ApplicationManager::UpdateFigCount(int Selected_Deleted)
//{
//	FigCount -= Selected_Deleted;
//}

void ApplicationManager::ClearClipboard()
{
	if (ClipboardMode == 1) {
		for (int i = 0; i < Clipboard.size(); i++)
			delete Clipboard[i];
	}
	Clipboard.clear();
}

int ApplicationManager::GetClipboardSize()
{
	return Clipboard.size();
}

void ApplicationManager::SaveAll(ofstream &OutFile)
{
	OutFile << FigList.size() << endl;
	for (int i = 0; i < FigList.size(); i++)
		FigList[i]->Save(OutFile);
}
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the input
Input *ApplicationManager::GetInput() const
{	return pIn; }

//Return a pointer to the output
Output *ApplicationManager::GetOutput() const
{	return pOut; }
////////////////////////////////////////////////////////////////////////////////////
//Destructor
ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<FigList.size(); i++)
		delete FigList[i];
	delete pIn;
	delete pOut;
}