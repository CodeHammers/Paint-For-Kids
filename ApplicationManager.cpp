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
#include "Actions\SendToAction.h"
#include "Actions\ExitAction.h"
#include "Actions\MoveAction.h"
#include "Actions\StoryAction.h"

#include <time.h> /* time */


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


//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//

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

	switch (ActType)
	{
		case ITM_MOVE_Clicked:
			pAct = new MoveAction(this);
			break;

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

		case ITM_LOAD_Clicked:
			pAct = new LoadAction(this);
			break;
		
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

		case ITM_UNDO_Clicked:
			pAct = new SendToAction(1,this);
			break;

		case ITM_REDO_Clicked:
			pAct = new SendToAction(2, this);
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

		case ITM_SAVE_Clicked:
			pAct = new StoryAction(this);
			break;

		case STATUS:	//a click on the status bar ==> no action
			return;

		case EXIT:
			pAct = new ExitAction(this);
			break;
	}
	
	//Execute the created action
	if(pAct != NULL)
	{
		pAct->Execute();//Execute
		delete pAct;	//Action is not needed any more ==> delete it
		pAct = NULL;
	}
}

//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//

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

	random_shuffle(FigList.begin(), FigList.end());
	srand(time(NULL));

	for (unsigned int i = 0; i < FigList.size(); i++) {

		Point p; p.x = rand() % (UI.width / 2 - 70) + 70; p.y = rand() % (UI.height / 2 - 70) + 70; p.x += UI.width / 2;
		FigList[i]->ChangeCord(p);
		int tries = 0;
		while (!FigList[i]->ValidAfterZoom()) {
			p.x = rand() % (UI.width / 2 - 140) + 140; p.y = rand() % (UI.height / 2 - 70) + 70; p.x += UI.width / 2;
			FigList[i]->ChangeCord(p);
			tries++;
			if (tries > 30) {
				FigList[i]->Resize(0.75);
			}
		}

		p.x -= UI.width / 2;
		if (p.x < 80)
			p.x += 80;
		FigList[i]->ChangeCord(p);

	}
}

void ApplicationManager::Exit()     
{
	for (int i = 0; i < FigList.size(); i++)
		delete FigList[i];
	delete pOut; delete pIn;
	pIn = NULL; pOut = NULL;
	FigList.clear();
}


void ApplicationManager::AddFigure(CFigure* pFig)
{
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
			FigList[i]->SetSelected(false); //new addition
			if (flag) delete FigList[i];
			FigList.erase(FigList.begin() + i);
			i--;
		}
	}
}


bool ApplicationManager::ResizeSelectedFigures(double ratio) {
	double temp = UI.Ratio;
	UI.Ratio = ratio;

	int num = 0;

	for (int i = 0; i < FigList.size(); i++) {
		if (FigList[i]->IsSelected()) {
			if (FigList[i]->ValidAfterZoom())
				FigList[i]->Resize(ratio);
			else {
				string s = "Cannot Resize " + num;
				pOut->PrintMessage(s + " Figures");
			}
		}
	}
	UI.Ratio = temp;
	return FigList.size();
}


void ApplicationManager::SendSelectedTo(int mode)
{
	//mode = 1 ==> send to front
	//mode = 2 ==> send to back
	vector<CFigure*> tmp;
	for (int i = 0; i < FigList.size(); i++) {
		if (FigList[i]->IsSelected()) {
			FigList[i]->SetSelected(false);
			tmp.push_back(FigList[i]);
			FigList.erase(FigList.begin() + i);
			i--;
		}
	}
	if (mode == 1) {
		for (int i = tmp.size() - 1; i >= 0; i--) {
			FigList.insert(FigList.begin(), tmp[i]);
		}
	}
	else {
		for (int i = 0; i < tmp.size(); i++) {
			FigList.push_back(tmp[i]);
		}
	}
	tmp.clear();
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


Point ApplicationManager::GetTheTopFigure()
{
	Point P = { 2000,2000 };
	for (int i = 0; i < Clipboard.size(); ++i)
		if (Clipboard[i]->GetTopCorner().x <= P.x && Clipboard[i]->GetTopCorner().y <= P.y)
			P = Clipboard[i]->GetTopCorner();
	return P;
}


vector<CFigure*> ApplicationManager::QuerySelectedForDrag() {
	vector<CFigure*> SelectedFigs;
	for (unsigned int i = 0; i < FigList.size(); ++i) {
		if (FigList[i]->IsSelected())
			SelectedFigs.push_back(FigList[i]);
	}
	return SelectedFigs;
}

pair<Point, Point> ApplicationManager::Drag()
{	vector<CFigure*>figs = QuerySelectedForDrag();
	Point ref = GetTheTopFigureOfSelected();
	Output* pOut = GetOutput();

	for (int i = 0; i < figs.size(); i++) 	figs[i]->Drag(true);

	int iX, iY;
	UI.DragState = true;
	pOut->setBuffering(false);

	// Flush out the input queues before beginning
	pOut->FlushMouse();
	pOut->setBuffering(true);
	int RectULX = ref.x;
	int RectULY = ref.y;
	int RectWidth = 20;
	bool bDragging = false;
	iX = iY = 0;
	int iXOld = 0;
	int iYOld = 0;	Point d;

	// Loop until there escape is pressed
	while (!pOut->EscapeClicked())
	{
		UpdateInterface();
		GfxInfo gf; gf.isFilled = true; gf.FillClr = YELLOW; gf.DrawClr = YELLOW; gf.BorderWdth = 5;
		pOut->DrawCircle({ RectULX ,RectULY }, 30, gf, false);
		// Dragging voodoo
		if (bDragging == false) {
			if (pOut->getButtonState(iX, iY) == BUTTON_DOWN) {
				int dist = (iX - RectULX)*(iX - RectULX) + (iY - RectULY)*(iY - RectULY);
				dist = sqrt(dist);
				if (dist <= 30) {
					bDragging = true;
					iXOld = iX; iYOld = iY;
				}
		/*		if (((iX > RectULX) && (iX < (RectULX + RectWidth))) && ((iY > RectULY) && (iY < (RectULY + RectWidth)))) {
					bDragging = true;
					iXOld = iX; iYOld = iY;
				}*/
			}
		}
		else {
			if (pOut->getButtonState(iX, iY) == BUTTON_UP) {
				bDragging = false;
			}
			else {
				if (iX != iXOld) {
					RectULX = RectULX + (iX - iXOld);
					iXOld = iX;
				}
				if (iY != iYOld) {
					RectULY = RectULY + (iY - iYOld);
					iYOld = iY;
				}
			}
		}

		Point p1;
		p1.x = RectULX;
		p1.y = RectULY;
		d = { ref.x - p1.x,ref.y - p1.y };
		d.x = -d.x; d.y = -d.y;

		for (int i = 0; i < figs.size(); i++) {
			Point po;
			figs[i]->SetStartingDragPoint(po);
			po = { po.x + d.x ,po.y + d.y };
			figs[i]->DrawDragged(pOut, po);
		}

		pOut->UpdateBuffer();
	}

	pOut->setBuffering(false);
	UpdateInterface();
	UI.DragState = false;

	for (int i = 0; i < figs.size(); i++) 	figs[i]->Drag(false);

	CheckValidityOfDrag(figs, make_pair(ref, d));

	return make_pair(ref, d);
}


void ApplicationManager::CheckValidityOfDrag(vector<CFigure*> figs, pair<Point, Point> Pr) {	Point ref = Pr.first;
	Point d = Pr.second;

	for (int i = 0; i < figs.size(); i++) {
		Point po;
		figs[i]->SetStartingDragPoint(po);
		po = { po.x + d.x ,po.y + d.y };		if (!figs[i]->CheckPosAfterDrag(po)) {			for (int j = i; j >= 0; j--)				figs[j]->retrieveData();			break;		}
	}
}


Point ApplicationManager::GetTheTopFigureOfSelected()
{
	Point P = { 2000,2000 };

	for (unsigned int i = 0; i < FigList.size(); ++i)
		if (FigList[i]->GetTopCorner().x <= P.x && FigList[i]->GetTopCorner().y <= P.y&&FigList[i]->IsSelected())
			P = FigList[i]->GetTopCorner();
	
	return P;
}


CFigure* ApplicationManager::GetFigure(int x, int y) const
{
	for (int i = FigList.size() - 1; i >= 0; i--) {
		if (FigList[i]->Encloses({ x,y }))  //if the point is in the figure
			return FigList[i];
	}
	return NULL;
}


//==================================================================================//
//						Clipboard Management Functions								//
//==================================================================================//


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


void ApplicationManager::ReturnFromClipboard()
{
	for (int i = 0; i < Clipboard.size(); ++i) {
		Clipboard[i]->SetSelected(false); FigList.push_back(Clipboard[i]);
	}
	ClipboardMode = 0;	ClearClipboard();
}


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


//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{
	if (pOut == NULL)
		return;
	if (UI.Zoom != 1&&UI.Zoom !=0||UI.DragState ) {
		pOut->CleanTheScreen();
		for (int i = 0; i < FigList.size(); i++) {
			FigList[i]->Draw(pOut);		//Call Draw function (virtual member fn)
		}
		pOut->CreateDrawToolBarUp(0, false, true);
		pOut->CreateDrawToolBarRight(false, true);
		pOut->CreateStatusBar();
	}
	else {
		GetOutput()->ClearDrawArea();
		for (int i = 0; i < FigList.size(); i++) {
			FigList[i]->Draw(pOut);		//Call Draw function (virtual member fn)
		}
	}
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