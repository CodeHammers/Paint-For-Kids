#include "Output.h"


Output::Output()
{
	/*Initialize user interface parameters*/
	UI.ZoomCenter.x = UI.width / 2;
	UI.ZoomCenter.y = UI.height / 2;
	UI.InterfaceMode = MODE_DRAW;
	UI.isFilled = false;
	UI.Zoom = 1;
	UI.DragState = false;
	/*Setting the dimensions of the application window*/
	UI.width = 1500; //Setting the width of the window.
	UI.height = 800; //Setting the height of the window.
	UI.wx = 5;  //Setting the starting position of the window.
	UI.wy = 5;   //Setting the ending position on the window.
	UI.Ratio = 1;  //intially no zoom

	/*Setting the dimensions of the toolbars right,up,left*/
	UI.StatusBarHeight = 80;      //Settting the height of the status bar.
	UI.MenuItemWidthLeft = 50;    //Setting the width of icons in the left menu.
	UI.MenuItemWidthUp = 50;     //Setting the width of icons in the upper menu.
	UI.MenuItemWidthRight = 50;   //Setting the width of icons in the right menu.
	UI.MenuItemHeight = 60; 

	//Drawing area dimensions 1380*660 with 5 pixels empty on all for sides
	//from x=55 ==> x=1435 , y=55 ==> y=715

	/*Setting the default colors for drawing and window background*/
	UI.DrawColor = BLUE;	//Setting the drawing color of figures.
	UI.FillColor = GREEN;	//Setting the filling color of the figures.
	UI.MsgColor = RED;		//Setting the color of the messages displayed on the status bar.

	if (UI.male) {
		UI.BkGrndColor = WHITE;	//Setting the background color.
		UI.HighlightColor = MAGENTA;	//Setting the highlighting color.
		UI.StatusBarColor = TURQUOISE;  //Setting the color of the status bar.
	}
	else {
		UI.BkGrndColor = LIGHTPINK;	//Setting the background color.
		UI.HighlightColor = LIGHTBLUE;	//Setting the highlighting color.
		UI.StatusBarColor = LIGHTBLUE;  //Setting the color of the status bar.
	}

	UI.PenWidth = 3;	//Setting the width of figures frames.

	/*Ceating the output window and setting the new name for the app*/
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	pWind->ChangeTitle("Paint for Kids - Drawing Mode");  //default mode, changes to play in the play mode

	/*Drawing the 2 menus for the application window*/
	CreateDrawToolBarUp(0,false,true);
	CreateDrawToolBarRight(false,true);

	/*Drawing the status bar in the application window*/
	CreateStatusBar();
}


Output::Output(int x)
{
	UI.InterfaceMode = MODE_DRAW;
	UI.isFilled = false;

	/*Setting the dimensions of the application window*/
	UI.width = 1500; //Setting the width of the window.
	UI.height = 800; //Setting the height of the window.
	UI.wx = 5;  //Setting the starting position of the window.
	UI.wy = 5;   //Setting the ending position on the window.
	UI.Ratio = 1;  //no resizing initially
	UI.Zoom = 1;   //no zooming initially
	UI.DragState = false;
	/*Setting the dimensions of the toolbars right,up,left*/
	UI.StatusBarHeight = 80;      //Settting the height of the status bar.
	UI.MenuItemWidthLeft = 50;    //Setting the width of icons in the left menu.
	UI.MenuItemWidthUp = 50;     //Setting the width of icons in the upper menu.
	UI.MenuItemWidthRight = 50;   //Setting the width of icons in the right menu.
	UI.MenuItemHeight = 60;       //setting the height of a menu item

	//Drawing area dimensions 1380*660 with 5 pixels empty on all for sides
	//from x=55 ==> x=1435 , y=55 ==> y=715

	/*Setting the default colors for drawing and window background*/
	UI.DrawColor = BLUE;	//Setting the drawing color of figures.
	UI.FillColor = GREEN;	//Setting the filling color of the figures.
	UI.MsgColor = RED;		//Setting the color of the messages displayed on the status bar.
	UI.BkGrndColor = WHITE;	//Setting the background color.
	UI.HighlightColor = MAGENTA;	//Setting the highlighting color.
	UI.StatusBarColor = TURQUOISE;  //Setting the color of the status bar.
	UI.PenWidth = 3;	//Setting the width of figures frames.

	/*Ceating the output window and setting the new name for the app*/
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	pWind->ChangeTitle("Paint for Kids - Drawing Mode");  //default mode, changes to play in the play mode

	string Mickey = "images\\MenuItems\\ICONS\\NewIcons\\Interface\\Mickey.jpg";
	string Miniee = "images\\MenuItems\\ICONS\\NewIcons\\Interface\\Miniee.jpg";
	pWind->DrawImage(Miniee,200,100,500,500);
	pWind->DrawImage(Mickey, 200+500, 100, 500, 500);
}


void Output::ChangeZoomLevel(double z) {
	if (z > 1)
		UI.Zoom += 0.25;
	else
		UI.Zoom -= 0.25;
	if (UI.Zoom <= 0)
		UI.Zoom = 1;
}


void Output::EditWindowSettings(color drawcolor, color fillcolor, color backgroundcolor)
{
	UI.DrawColor = drawcolor;
	UI.FillColor = fillcolor;
	UI.BkGrndColor = backgroundcolor;
	pWind->SetBrush(UI.BkGrndColor);
	pWind->SetPen(UI.BkGrndColor, 1);
	pWind->DrawRectangle(0, 0, UI.width, UI.height);
	UI.DrawColor = drawcolor;
	UI.FillColor = fillcolor;
	UI.BkGrndColor = backgroundcolor;
	pWind->SetPen(UI.DrawColor);
	pWind->SetBrush(UI.FillColor);
	CreateDrawToolBarUp(0, false,true);
	CreateDrawToolBarRight(false,true);
	CreateStatusBar();
	//pWind->DrawRectangle(0, 0, UI.width, UI.height);

}


void Output::ChangeBackgroundColor(color BackgroundColor)
{
	EditWindowSettings(UI.DrawColor, UI.FillColor, BackgroundColor);
}


void Output::ChangeDrawColor(color DrawColor)
{
	EditWindowSettings(DrawColor, UI.FillColor, UI.BkGrndColor);
}


void Output::ChangeFillColor(color FillColor)
{
	//EditWindowSettings(UI.DrawColor, FillColor, UI.BkGrndColor);
	UI.FillColor = FillColor;
	UI.isFilled = true;
	pWind->SetBrush(UI.FillColor);
}


void Output::ChangeBorderWidth(int bw)
{
	UI.PenWidth = bw;
	pWind->SetPen(UI.DrawColor,UI.PenWidth);
}


Input* Output::CreateInput() const
{
	Input* pIn = new Input(pWind);
	return pIn;
}

//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window* Output::CreateWind(int w, int h, int x, int y) const
{
	window* pW = new window(w, h, x, y);
	pW->SetBrush(UI.BkGrndColor);
	pW->SetPen(UI.BkGrndColor, 1);
	pW->DrawRectangle(0, 0, w, h);  //Background.
	return pW;
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateStatusBar() const
{
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearStatusBar() const
{
	//Clear Status bar by drawing a filled white rectangle
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateDrawToolBarRight(bool collapse, bool show) const
{
	UI.InterfaceMode = MODE_DRAW;  //Setting the current mode.

	/*Adding two parallel icons for zooming in and out*/;
	string zoomControls[CounterZoom];
	if (UI.male) {
		zoomControls[ITM_ZOOM_IN] = "images\\MenuItems\\ICONS\\TOOLS\\ZOOM_IN.jpg";
		zoomControls[ITM_ZOOM_OUT] = "images\\MenuItems\\ICONS\\TOOLS\\ZOOM_OUT.jpg";
	}
	else {
		zoomControls[ITM_ZOOM_IN] = "images\\MenuItems\\ICONS\\NewIcons\\Tools\\ZOOM_IN.jpg";
		zoomControls[ITM_ZOOM_OUT] = "images\\MenuItems\\ICONS\\NewIcons\\Tools\\ZOOM_OUT.jpg";
	}
	pWind->DrawImage(zoomControls[ITM_ZOOM_IN], 1435, 13 * UI.MenuItemWidthRight+45, 25, 25);
	pWind->DrawImage(zoomControls[ITM_ZOOM_OUT], 1460, 13 * UI.MenuItemWidthRight+45, 25, 25);


	/*Loading the icons for the left toolbar.*/
	string MenuItemImages[DRAW_ITM_COUNT_LEFT];
	if (UI.male) {
		MenuItemImages[ITM_COLLAPSERIGHT] = "images\\MenuItems\\ICONS\\TOOLS\\ABORT.jpg";
		MenuItemImages[ITM_LOAD] = "images\\MenuItems\\ICONS\\TOOLS\\LOAD.jpg";
		MenuItemImages[ITM_MOVE] = "images\\MenuItems\\ICONS\\TOOLS\\MOVE.jpg";
		MenuItemImages[ITM_SELECT] = "images\\MenuItems\\ICONS\\TOOLS\\SELECT.jpg";
		MenuItemImages[ITM_RESIZE] = "images\\MenuItems\\ICONS\\TOOLS\\RESIZE1.jpg";
		MenuItemImages[ITM_COPY] = "images\\MenuItems\\ICONS\\TOOLS\\COPY.jpg";
		MenuItemImages[ITM_CUT] = "images\\MenuItems\\ICONS\\TOOLS\\CUT.jpg";
		MenuItemImages[ITM_PASTE] = "images\\MenuItems\\ICONS\\TOOLS\\PASTE.jpg";
		MenuItemImages[ITM_REDO] = "images\\MenuItems\\ICONS\\TOOLS\\SendFront_White.jpg";
		MenuItemImages[ITM_UNDO] = "images\\MenuItems\\ICONS\\TOOLS\\SendBack_White.jpg";
		MenuItemImages[ITM_DELETE] = "images\\MenuItems\\ICONS\\TOOLS\\DELETE.jpg";
		MenuItemImages[ITM_SAVE] = "images\\MenuItems\\ICONS\\TOOLS\\Story_Mode_White.jpg";
		MenuItemImages[ITM_SAVEAS] = "images\\MenuItems\\ICONS\\TOOLS\\SAVEAS.jpg";
		MenuItemImages[ITM_EXIT] = "images\\MenuItems\\ICONS\\TOOLS\\EXIT.jpg";
	}
	else {
		MenuItemImages[ITM_COLLAPSERIGHT] = "images\\MenuItems\\ICONS\\NewIcons\\Tools\\Abort.jpg";
		MenuItemImages[ITM_LOAD] = "images\\MenuItems\\ICONS\\NewIcons\\Tools\\LOAD.jpg";
		MenuItemImages[ITM_MOVE] = "images\\MenuItems\\ICONS\\NewIcons\\Tools\\MOVE.jpg";
		MenuItemImages[ITM_SELECT] = "images\\MenuItems\\ICONS\\NewIcons\\Tools\\SELECT.jpg";
		MenuItemImages[ITM_RESIZE] = "images\\MenuItems\\ICONS\\NewIcons\\Tools\\RESIZE.jpg";
		MenuItemImages[ITM_COPY] = "images\\MenuItems\\ICONS\\NewIcons\\Tools\\COPY.jpg";
		MenuItemImages[ITM_CUT] = "images\\MenuItems\\ICONS\\NewIcons\\Tools\\CUT.jpg";
		MenuItemImages[ITM_PASTE] = "images\\MenuItems\\ICONS\\NewIcons\\Tools\\PASTE.jpg";
		MenuItemImages[ITM_REDO] = "images\\MenuItems\\ICONS\\NewIcons\\Tools\\SendFront.jpg";
		MenuItemImages[ITM_UNDO] = "images\\MenuItems\\ICONS\\NewIcons\\Tools\\SendBack.jpg";
		MenuItemImages[ITM_DELETE] = "images\\MenuItems\\ICONS\\NewIcons\\Tools\\DELETE.jpg";
		MenuItemImages[ITM_SAVE] = "images\\MenuItems\\ICONS\\NewIcons\\Tools\\StoryMode.jpg";
		MenuItemImages[ITM_SAVEAS] = "images\\MenuItems\\ICONS\\NewIcons\\Tools\\SAVEAS.jpg";
		MenuItemImages[ITM_EXIT] = "images\\MenuItems\\ICONS\\NewIcons\\Tools\\EXIT.jpg";
	}
	pWind->DrawImage(MenuItemImages[ITM_COLLAPSERIGHT], 1437, 13 * UI.MenuItemWidthLeft, 45, 45);
	pWind->DrawImage(MenuItemImages[ITM_EXIT], 1437, 0, UI.MenuItemWidthLeft, UI.MenuItemWidthLeft);

	if (show) {
		for (int i = 1; i < DRAW_ITM_COUNT_LEFT - 2; i++) {
			pWind->DrawImage(MenuItemImages[i], 1435, i * 50, UI.MenuItemWidthLeft, UI.MenuItemWidthLeft);
		}
		return;
	}

	int sign, start;
	if (!collapse) {
		sign = -1;
		start = 1500;
	}
	else {
		sign = 1;
		start = 1435;
	}

	for (int j = 0; j <= 63; j++) {
		for (int i = 1; i < DRAW_ITM_COUNT_LEFT - 2; i++){
			pWind->DrawImage(MenuItemImages[i],start+sign*j, i * 50, UI.MenuItemWidthLeft, UI.MenuItemWidthLeft);
			if (collapse) {
				pWind->SetBrush(UI.BkGrndColor);
				pWind->SetPen(UI.BkGrndColor, 1);
				pWind->DrawRectangle(start, 50, start + sign*j, 600);
			}
		}
	}
}


/*This function is responsible of drawing the upper toolber and all its sub menus*/
void Output::CreateDrawToolBarUp(int action, bool collapse,bool show) const
{
	//Action tells this function what to do
	// 0: draw normal menu, other numbers it draws the corresponding sub menus 
	if (action == 0) {
		UI.InterfaceMode = MODE_DRAW;   //Setting the current mode.

		//clear the area where the menu is going to be drawn
		pWind->SetBrush(UI.BkGrndColor);
		pWind->SetPen(UI.BkGrndColor, 1);
		pWind->DrawRectangle(50, 0, 1200, 50);
		//drawing the play mode icon
	string PlayModeIcon;
		if (UI.male)
			PlayModeIcon = "images\\MenuItems\\ICONS\\JOYSTICK.jpg";
		else
			PlayModeIcon = "images\\MenuItems\\ICONS\\NewIcons\\Tools\\JOYSTICK2.jpg";

		pWind->DrawImage(PlayModeIcon, 0, 0, 50, 50);

		//Loading the icons for the main upper menu.
		string MenuItemImages[DRAW_LEFT_MENU_ITEMS_COUNT];
		if (UI.male) {
			MenuItemImages[ITM_FIGURE] = "images\\MenuItems\\ICONS\\TOOLS\\FIGURE.jpg";
			MenuItemImages[ITM_PEN] = "images\\MenuItems\\ICONS\\Pencils\\BLACK.jpg";
			MenuItemImages[ITM_BRUSH] = "images\\MenuItems\\ICONS\\Brushes\\GREEN.jpg";
			MenuItemImages[ITM_BCKGCOLOR] = "images\\MenuItems\\ICONS\\BkGROUND\\WHITE.jpg";
			MenuItemImages[STROKWIDTH] = "images\\MenuItems\\ICONS\\BORDERWIDTH\\GROUP.jpg";
		}
		else {
			MenuItemImages[ITM_FIGURE] = "images\\MenuItems\\ICONS\\NewIcons\\Tools\\FIGURE.jpg";
			MenuItemImages[ITM_PEN] = "images\\MenuItems\\ICONS\\NewIcons\\Pencils\\WHITE.jpg";
			MenuItemImages[ITM_BRUSH] = "images\\MenuItems\\ICONS\\NewIcons\\Brushes\\WHITE.jpg";
			MenuItemImages[ITM_BCKGCOLOR] = "images\\MenuItems\\ICONS\\NewIcons\\Bkground Color\\WHITE.jpg";
			MenuItemImages[STROKWIDTH] = "images\\MenuItems\\ICONS\\NewIcons\\BorderWidth\\GROUP.jpg";
		}
		if (show) {
			for (int i = 0; i < DRAW_LEFT_MENU_ITEMS_COUNT; i++) {
				pWind->DrawImage(MenuItemImages[i], (11 + i)*UI.MenuItemWidthUp, 0, UI.MenuItemWidthUp, UI.MenuItemWidthUp);
			}
				return;
		}

		int sign, start;
		if (!collapse) {
			sign = 1;
			start = -50;
		}
		else {
			sign = -1;
			start = 0;
		}

		for (int j = 0; j <= 50; j++) {
			//Drawing the upper toolbar, 11 is a shifting factor to start drawing near the middle of the screen
			for (int i = 0; i < DRAW_LEFT_MENU_ITEMS_COUNT; i++) {
				pWind->DrawImage(MenuItemImages[i], (11 + i)*UI.MenuItemWidthUp, start + sign*j, UI.MenuItemWidthUp, UI.MenuItemWidthUp);
				if (collapse) {
					pWind->SetBrush(UI.BkGrndColor);
					pWind->SetPen(UI.BkGrndColor, 1);
					pWind->DrawRectangle((11 + i)*UI.MenuItemWidthUp, UI.MenuItemWidthUp -j, 5*UI.MenuItemWidthUp , 2*UI.MenuItemWidthUp -j);
				}
			}
		}
	}


	else if (action == 1) {
		string MenuItemImages[FigurelistIcons_Count];
		if (UI.male) {
			MenuItemImages[ITM_CIRCLE] = "images\\MenuItems\\ICONS\\CIRCULE.jpg";
			MenuItemImages[ITM_RECTANGLE] = "images\\MenuItems\\ICONS\\RECTANGLE.jpg";
			MenuItemImages[ITM_TRIANGLE] = "images\\MenuItems\\ICONS\\TRIANGLE.jpg";
			MenuItemImages[ITM_LINE] = "images\\MenuItems\\ICONS\\LINE.jpg";
		}
		else {
			MenuItemImages[ITM_CIRCLE] = "images\\MenuItems\\ICONS\\NewIcons\\Tools\\CIRCULE.jpg";
			MenuItemImages[ITM_RECTANGLE] = "images\\MenuItems\\ICONS\\NewIcons\\Tools\\RECTANGLE.jpg";
			MenuItemImages[ITM_TRIANGLE] = "images\\MenuItems\\ICONS\\NewIcons\\Tools\\TRIANGLE.jpg";
			MenuItemImages[ITM_LINE] = "images\\MenuItems\\ICONS\\NewIcons\\Tools\\LINE.jpg";
		}

		int sign, start;
		if (!collapse)		{
			UI.InterfaceMode = MODE_DRAW_SUB_MENU1;
			sign = 1;
			start = -50;
		}
		else {
			UI.InterfaceMode = MODE_DRAW;
			sign = -1;
			start = 0;
		}
		for (int j = 0; j <= 50; ++j) {
			for (int i = 0; i < FigurelistIcons_Count; ++i)
				pWind->DrawImage(MenuItemImages[i], start + sign*j, (i + 4)*UI.MenuItemWidthLeft, UI.MenuItemWidthLeft, UI.MenuItemWidthLeft);
			if (collapse) {
				pWind->SetBrush(UI.BkGrndColor);
				pWind->SetPen(UI.BkGrndColor, 1);
				pWind->DrawRectangle(UI.MenuItemWidthLeft, 4 * UI.MenuItemWidthLeft, UI.MenuItemWidthLeft - j, (FigurelistIcons_Count + 4)*UI.MenuItemWidthLeft);
			}
		}
	}
	
	else if (action == 2) {

		//Loading icons for the second sub menu (the pen sub menu)
		string MenuItemImages[DRAW_ITEM_COUNT_RIGHTPEN];
		if (UI.male) {
			MenuItemImages[ITM_PEN1] = "images\\MenuItems\\ICONS\\Pencils\\BLACK.jpg";
			MenuItemImages[ITM_PEN2] = "images\\MenuItems\\ICONS\\Pencils\\YELLOW.jpg";
			MenuItemImages[ITM_PEN3] = "images\\MenuItems\\ICONS\\Pencils\\BLUE.jpg";
			MenuItemImages[ITM_PEN4] = "images\\MenuItems\\ICONS\\Pencils\\BROWN.jpg";
			MenuItemImages[ITM_PEN5] = "images\\MenuItems\\ICONS\\Pencils\\PINK.jpg";
			MenuItemImages[ITM_PEN6] = "images\\MenuItems\\ICONS\\Pencils\\GREEN.jpg";
			MenuItemImages[ITM_PEN7] = "images\\MenuItems\\ICONS\\Pencils\\NILE.jpg";
			MenuItemImages[ITM_PEN8] = "images\\MenuItems\\ICONS\\Pencils\\ORANGE.jpg";
			MenuItemImages[ITM_PEN9] = "images\\MenuItems\\ICONS\\Pencils\\PURPLE.jpg";
			MenuItemImages[ITM_PEN10] = "images\\MenuItems\\ICONS\\Pencils\\RED.jpg";
		}
		else {
			MenuItemImages[ITM_PEN1] = "images\\MenuItems\\ICONS\\NewIcons\\Pencils\\BLACK.jpg";
			MenuItemImages[ITM_PEN2] = "images\\MenuItems\\ICONS\\NewIcons\\Pencils\\YELLOW.jpg";
			MenuItemImages[ITM_PEN3] = "images\\MenuItems\\ICONS\\NewIcons\\Pencils\\BLUE.jpg";
			MenuItemImages[ITM_PEN4] = "images\\MenuItems\\ICONS\\NewIcons\\Pencils\\BROWN.jpg";
			MenuItemImages[ITM_PEN5] = "images\\MenuItems\\ICONS\\NewIcons\\Pencils\\PINK.jpg";
			MenuItemImages[ITM_PEN6] = "images\\MenuItems\\ICONS\\NewIcons\\Pencils\\GREEN.jpg";
			MenuItemImages[ITM_PEN7] = "images\\MenuItems\\ICONS\\NewIcons\\Pencils\\NILE.jpg";
			MenuItemImages[ITM_PEN8] = "images\\MenuItems\\ICONS\\NewIcons\\Pencils\\ORANGE.jpg";
			MenuItemImages[ITM_PEN9] = "images\\MenuItems\\ICONS\\NewIcons\\Pencils\\PURPLE.jpg";
			MenuItemImages[ITM_PEN10] = "images\\MenuItems\\ICONS\\NewIcons\\Pencils\\RED.jpg";
		}

		//The following logic tells the loop whether to draw a menu moving into the screen
		//Or collapsing outta the screen
		int sign, start;
		if (!collapse) {   //not collapse means moving into the screen
			UI.InterfaceMode = MODE_DRAW_SUB_MENU2;
			sign = 1;
			start = -50;
		}
		else {            //collapse means moving outta the screen
			UI.InterfaceMode = MODE_DRAW;
			sign = -1;
			start = 0;
		}
		
		/*The following loop does a double job depending on the values of start and
		sign, for one set of values it draws a menu moving into the screen, offering a selection
		of pens to the user, and for the other set of values it collapses the menu out of the screen*/
		//the number 50 in the j counter is the FPS in which the menu motion is done

		for (int j = 0; j <= 50; j++) { //note: i+2 is the shifting ratio
			for (int i = 0; i < DRAW_ITEM_COUNT_RIGHTPEN ; i++) { // 1 here is the intializer of enum 
				pWind->DrawImage(MenuItemImages[i], start+sign*j, (i + 2) * UI.MenuItemWidthLeft,
					UI.MenuItemWidthLeft, UI.MenuItemWidthLeft);
				if (collapse) {
					pWind->SetBrush(UI.BkGrndColor);
					pWind->SetPen(UI.BkGrndColor, 1);
					pWind->DrawRectangle(UI.MenuItemWidthLeft, 2 * UI.MenuItemWidthLeft,
					       UI.MenuItemWidthLeft - j, (DRAW_ITEM_COUNT_RIGHTPEN + 2)* UI.MenuItemWidthLeft);
				}
			}
		}
	}

	else if (action == 3) {
		
		//Loading icons for the third sub menu(Brush sub menu)
		string MenuItemImages[DRAW_ITEM_COUNT_RIGHTBRUSHFILL]; 
		if (UI.male) {
			MenuItemImages[ITM_BRUSHFILL1] = "images\\MenuItems\\ICONS\\Brushes\\BLACK.jpg";
			MenuItemImages[ITM_BRUSHFILL2] = "images\\MenuItems\\ICONS\\Brushes\\YELLOW.jpg";
			MenuItemImages[ITM_BRUSHFILL3] = "images\\MenuItems\\ICONS\\Brushes\\BLUE.jpg";
			MenuItemImages[ITM_BRUSHFILL4] = "images\\MenuItems\\ICONS\\Brushes\\BROWN.jpg";
			MenuItemImages[ITM_BRUSHFILL5] = "images\\MenuItems\\ICONS\\Brushes\\PINK.jpg";
			MenuItemImages[ITM_BRUSHFILL6] = "images\\MenuItems\\ICONS\\Brushes\\GREEN.jpg";
			MenuItemImages[ITM_BRUSHFILL7] = "images\\MenuItems\\ICONS\\Brushes\\NILE.jpg";
			MenuItemImages[ITM_BRUSHFILL8] = "images\\MenuItems\\ICONS\\Brushes\\ORANGE.jpg";
			MenuItemImages[ITM_BRUSHFILL9] = "images\\MenuItems\\ICONS\\Brushes\\PURPLE.jpg";
			MenuItemImages[ITM_BRUSHFILL10] = "images\\MenuItems\\ICONS\\Brushes\\RED.jpg";
		}
		else {
			MenuItemImages[ITM_BRUSHFILL1] = "images\\MenuItems\\ICONS\\NewIcons\\Brushes\\BLACK.jpg";
			MenuItemImages[ITM_BRUSHFILL2] = "images\\MenuItems\\ICONS\\NewIcons\\Brushes\\YELLOW.jpg";
			MenuItemImages[ITM_BRUSHFILL3] = "images\\MenuItems\\ICONS\\NewIcons\\Brushes\\BLUE.jpg";
			MenuItemImages[ITM_BRUSHFILL4] = "images\\MenuItems\\ICONS\\NewIcons\\Brushes\\BROWN.jpg";
			MenuItemImages[ITM_BRUSHFILL5] = "images\\MenuItems\\ICONS\\NewIcons\\Brushes\\PINK.jpg";
			MenuItemImages[ITM_BRUSHFILL6] = "images\\MenuItems\\ICONS\\NewIcons\\Brushes\\GREEN.jpg";
			MenuItemImages[ITM_BRUSHFILL7] = "images\\MenuItems\\ICONS\\NewIcons\\Brushes\\NILE.jpg";
			MenuItemImages[ITM_BRUSHFILL8] = "images\\MenuItems\\ICONS\\NewIcons\\Brushes\\ORANGE.jpg";
			MenuItemImages[ITM_BRUSHFILL9] = "images\\MenuItems\\ICONS\\NewIcons\\Brushes\\PURPLE.jpg";
			MenuItemImages[ITM_BRUSHFILL10] = "images\\MenuItems\\ICONS\\NewIcons\\Brushes\\RED.jpg";
		}
		int sign, start;
		if (!collapse) {   //not collapse means moving into the screen
			UI.InterfaceMode = MODE_DRAW_SUB_MENU3;
			sign = 1;
			start = -50;
		}
		else {            //collapse means moving outta the screen
			UI.InterfaceMode = MODE_DRAW;
			sign = -1;
			start = 0;
		}

		/*The following loop does a double job depending on the values of start and
		sign, for one set of values it draws a menu moving into the screen, offering a selection
		of pens to the user, and for the other set of values it collapses the menu out of the screen*/
		//the number 50 in the j counter is the FPS in which the menu motion is done

		for (int j = 0; j <= 50; j++) { //note: i+2 is the shifting ratio
			for (int i = 0; i < DRAW_ITEM_COUNT_RIGHTBRUSHFILL; i++) { // 1 here is the intializer of enum 
				pWind->DrawImage(MenuItemImages[i], start + sign*j, (i + 2) * UI.MenuItemWidthLeft, UI.MenuItemWidthLeft, UI.MenuItemWidthLeft);
				if (collapse) {
					pWind->SetBrush(UI.BkGrndColor);
					pWind->SetPen(UI.BkGrndColor, 1);
					pWind->DrawRectangle(UI.MenuItemWidthLeft, 2 * UI.MenuItemWidthLeft, UI.MenuItemWidthLeft - j, (DRAW_ITEM_COUNT_RIGHTBRUSHFILL + 2)* UI.MenuItemWidthLeft);
				}
			}
		}
	}

	else if (action == 4) {
		
		//Loading icons for the forth sub menu (background color options)
		string MenuItemImages[BKCG_COLOR_COUNT];
		if (UI.male) {
			MenuItemImages[ITM_BCKG_WHITE] = "images\\MenuItems\\ICONS\\BkGROUND\\WHITE.jpg";
			MenuItemImages[ITM_BCKG_YELLOW] = "images\\MenuItems\\ICONS\\BkGROUND\\YELLOW.jpg";
			MenuItemImages[ITM_BCKG_BLUE] = "images\\MenuItems\\ICONS\\BkGROUND\\BLUE.jpg";
			MenuItemImages[ITM_BCKG_BROWN] = "images\\MenuItems\\ICONS\\BkGROUND\\BROWN.jpg";
			MenuItemImages[ITM_BCKG_PINK] = "images\\MenuItems\\ICONS\\BkGROUND\\PINK.jpg";
			MenuItemImages[ITM_BCKG_GREEN] = "images\\MenuItems\\ICONS\\BkGROUND\\GREEN.jpg";
			MenuItemImages[ITM_BCKG_NILE] = "images\\MenuItems\\ICONS\\BkGROUND\\NILE.jpg";
			MenuItemImages[ITM_BCKG_ORANE] = "images\\MenuItems\\ICONS\\BkGROUND\\ORANGE.jpg";
			MenuItemImages[ITM_BCKG_PURPLE] = "images\\MenuItems\\ICONS\\BkGROUND\\PURPLE.jpg";
			MenuItemImages[ITM_BCKG_RED] = "images\\MenuItems\\ICONS\\BkGROUND\\RED.jpg";
		}
		else {
			MenuItemImages[ITM_BCKG_WHITE] = "images\\MenuItems\\ICONS\\NewIcons\\Bkground Color\\WHITE.jpg";
			MenuItemImages[ITM_BCKG_YELLOW] = "images\\MenuItems\\ICONS\\NewIcons\\Bkground Color\\YELLOW.jpg";
			MenuItemImages[ITM_BCKG_BLUE] = "images\\MenuItems\\ICONS\\NewIcons\\Bkground Color\\BLUE.jpg";
			MenuItemImages[ITM_BCKG_BROWN] = "images\\MenuItems\\ICONS\\NewIcons\\Bkground Color\\BROWN.jpg";
			MenuItemImages[ITM_BCKG_PINK] = "images\\MenuItems\\ICONS\\NewIcons\\Bkground Color\\PINK.jpg";
			MenuItemImages[ITM_BCKG_GREEN] = "images\\MenuItems\\ICONS\\NewIcons\\Bkground Color\\GREEN.jpg";
			MenuItemImages[ITM_BCKG_NILE] = "images\\MenuItems\\ICONS\\NewIcons\\Bkground Color\\NILE.jpg";
			MenuItemImages[ITM_BCKG_ORANE] = "images\\MenuItems\\ICONS\\NewIcons\\Bkground Color\\ORANGE.jpg";
			MenuItemImages[ITM_BCKG_PURPLE] = "images\\MenuItems\\ICONS\\NewIcons\\Bkground Color\\PURPLE.jpg";
			MenuItemImages[ITM_BCKG_RED] = "images\\MenuItems\\ICONS\\NewIcons\\Bkground Color\\RED.jpg";
		}
		int sign, start;
		if (!collapse) {   //not collapse means moving into the screen
			UI.InterfaceMode = MODE_DRAW_SUB_MENU4;
			sign = 1;
			start = -50;
		}
		else {            //collapse means moving outta the screen
			UI.InterfaceMode = MODE_DRAW;
			sign = -1;
			start = 0;
		}

		/*The following loop does a double job depending on the values of start and
		sign, for one set of values it draws a menu moving into the screen, offering a selection
		of pens to the user, and for the other set of values it collapses the menu out of the screen*/
		//the number 50 in the j counter is the FPS in which the menu motion is done

		for (int j = 0; j <= 50; j++) { //note: i+2 is the shifting ratio
			for (int i = 0; i < BKCG_COLOR_COUNT; i++) { // 1 here is the intializer of enum 
				pWind->DrawImage(MenuItemImages[i], start + sign*j, (i + 2) * UI.MenuItemWidthLeft, UI.MenuItemWidthLeft, UI.MenuItemWidthLeft);
				if (collapse) {
					pWind->SetBrush(UI.BkGrndColor);
					pWind->SetPen(UI.BkGrndColor, 1);
					pWind->DrawRectangle(UI.MenuItemWidthLeft, 2 * UI.MenuItemWidthLeft, UI.MenuItemWidthLeft - j, (BKCG_COLOR_COUNT + 2)* UI.MenuItemWidthLeft);
				}
			}
		}
	}

	else if(action == 5) {

		//Loading icons for the fifth sub menu (border width options)
		string MenuItemImages[BORDER_WIDTH_COUNT];
		if (UI.male) {
			MenuItemImages[ITM_BORDERWIDTH1] = "images\\MenuItems\\ICONS\\BORDERWIDTH\\1.jpg";
			MenuItemImages[ITM_BORDERWIDTH2] = "images\\MenuItems\\ICONS\\BORDERWIDTH\\2.jpg";
			MenuItemImages[ITM_BORDERWIDTH3] = "images\\MenuItems\\ICONS\\BORDERWIDTH\\3.jpg";
			MenuItemImages[ITM_BORDERWIDTH4] = "images\\MenuItems\\ICONS\\BORDERWIDTH\\4.jpg";
		}
		else {
			MenuItemImages[ITM_BORDERWIDTH1] = "images\\MenuItems\\ICONS\\NewIcons\\BorderWidth\\1.jpg";
			MenuItemImages[ITM_BORDERWIDTH2] = "images\\MenuItems\\ICONS\\NewIcons\\BorderWidth\\2.jpg";
			MenuItemImages[ITM_BORDERWIDTH3] = "images\\MenuItems\\ICONS\\NewIcons\\BorderWidth\\3.jpg";
			MenuItemImages[ITM_BORDERWIDTH4] = "images\\MenuItems\\ICONS\\NewIcons\\BorderWidth\\4.jpg";
		}
		int sign, start;
		if (!collapse) {   //not collapse means moving into the screen
			UI.InterfaceMode = MODE_DRAW_SUB_MENU5;
			sign = 1;
			start = -50;
		}
		else {            //collapse means moving outta the screen
			UI.InterfaceMode = MODE_DRAW;
			sign = -1;
			start = 0;
		}

		/*The following loop does a double job depending on the values of start and
		sign, for one set of values it draws a menu moving into the screen, offering a selection
		of pens to the user, and for the other set of values it collapses the menu out of the screen*/
		//the number 50 in the j counter is the FPS in which the menu motion is done

		for (int j = 0; j <= 50; j++) { //note: i+2 is the shifting ratio
			for (int i = 0; i < BORDER_WIDTH_COUNT; i++) { // 1 here is the intializer of enum 
				pWind->DrawImage(MenuItemImages[i], start + sign*j, (i + 4) * UI.MenuItemWidthLeft, UI.MenuItemWidthLeft, UI.MenuItemWidthLeft);
				if (collapse) {
					pWind->SetBrush(UI.BkGrndColor);
					pWind->SetPen(UI.BkGrndColor, 1);
					pWind->DrawRectangle(UI.MenuItemWidthLeft, 4 * UI.MenuItemWidthLeft, UI.MenuItemWidthLeft - j, (BKCG_COLOR_COUNT + 4)* UI.MenuItemWidthLeft);
				}
			}
		}
	}

	else {
		//Loading icons for the fifth sub menu (border width options)
		string MenuItemImages[RESIZE_CONTROLS_COUNT];
		if (UI.male) {
			MenuItemImages[ITM_RESIZE25] = "images\\MenuItems\\ICONS\\RESIZE\\25.jpg";
			MenuItemImages[ITM_RESIZE50] = "images\\MenuItems\\ICONS\\RESIZE\\50.jpg";
			MenuItemImages[ITM_RESIZE200] = "images\\MenuItems\\ICONS\\RESIZE\\200.jpg";
			MenuItemImages[ITM_RESIZE400] = "images\\MenuItems\\ICONS\\RESIZE\\400.jpg";
		}
		else {
			MenuItemImages[ITM_RESIZE25] = "images\\MenuItems\\ICONS\\NewIcons\\Tools\\25.jpg";
			MenuItemImages[ITM_RESIZE50] = "images\\MenuItems\\ICONS\\NewIcons\\Tools\\50.jpg";
			MenuItemImages[ITM_RESIZE200] = "images\\MenuItems\\ICONS\\NewIcons\\Tools\\200.jpg";
			MenuItemImages[ITM_RESIZE400] = "images\\MenuItems\\ICONS\\NewIcons\\Tools\\400.jpg";
		}
		int sign, start;
		if (!collapse) {   //not collapse means moving into the screen
			UI.InterfaceMode = MODE_DRAW_SUB_MENU6;
			sign = 1;
			start = -50;
		}
		else {            //collapse means moving outta the screen
			UI.InterfaceMode = MODE_DRAW;
			sign = -1;
			start = 0;
		}

		/*The following loop does a double job depending on the values of start and
		sign, for one set of values it draws a menu moving into the screen, offering a selection
		of pens to the user, and for the other set of values it collapses the menu out of the screen*/
		//the number 50 in the j counter is the FPS in which the menu motion is done

		for (int j = 0; j <= 50; j++) { //note: i+2 is the shifting ratio
			for (int i = 0; i < RESIZE_CONTROLS_COUNT; i++) { // 1 here is the intializer of enum 
				pWind->DrawImage(MenuItemImages[i], start + sign*j, (i + 4) * UI.MenuItemWidthLeft, UI.MenuItemWidthLeft, UI.MenuItemWidthLeft);
				if (collapse) {
					pWind->SetBrush(UI.BkGrndColor);
					pWind->SetPen(UI.BkGrndColor, 1);
					pWind->DrawRectangle(UI.MenuItemWidthLeft, 4 * UI.MenuItemWidthLeft, UI.MenuItemWidthLeft - j, (RESIZE_CONTROLS_COUNT + 4)* UI.MenuItemWidthLeft);
				}
			}
		}
	}
}

//////////////////////////////////////////////////////////////////////////////////////////

void Output::CreatePlayToolBar(int action, bool collapse, bool stat) const
{
	if (action == 0) {
		if (stat) 
		{
			UI.Zoom = 1;
			CreateDrawToolBarUp(0, true, false);
			CreateDrawToolBarRight(true, false);
		}

		string MenuItemImages[PLAY_ITM_COUNT];
		if (UI.male) {
			MenuItemImages[ITM_SCRAMBLEAndFind] = "images\\MenuItems\\ICONS\\TOOLS\\SCRAMBLE1.jpg";
			MenuItemImages[ITM_PickAndHide] = "images\\MenuItems\\ICONS\\TOOLS\\PickAndHide.jpg";
			MenuItemImages[ITEM_TODRAW] = "images\\MenuItems\\ICONS\\TOOLS\\TODRAW1.jpg";
		}
		else {
			MenuItemImages[ITM_SCRAMBLEAndFind] = "images\\MenuItems\\ICONS\\NewIcons\\Tools\\Scramble_Red.jpg";
			MenuItemImages[ITM_PickAndHide] = "images\\MenuItems\\ICONS\\NewIcons\\Tools\\PickAndHide.jpg";
			MenuItemImages[ITEM_TODRAW] = "images\\MenuItems\\ICONS\\NewIcons\\Tools\\TODRAW2.jpg";
		}
		int sign, start;
		if (!collapse) {
			sign = 1;
			start = -50;
		}
		else {
			sign = -1;
			start = 0;
		}

		for (int j = 0; j <= 50; j++) {
			//Drawing the upper toolbar, 11 is a shifting factor to start drawing near the middle of the screen
			for (int i = 0; i < PLAY_ITM_COUNT - 1; i++) {
				pWind->DrawImage(MenuItemImages[i], (13 + i)*UI.MenuItemWidthUp, start + sign*j, UI.MenuItemWidthUp, UI.MenuItemWidthUp);
				if (collapse) {
					pWind->SetBrush(UI.BkGrndColor);
					pWind->SetPen(UI.BkGrndColor, 1);
					pWind->DrawRectangle((13 + i)*UI.MenuItemWidthUp, UI.MenuItemWidthUp - j, 2 * UI.MenuItemWidthUp, 2 * UI.MenuItemWidthUp - j);
				}
			}
		}
		pWind->DrawImage(MenuItemImages[2], 0, 0, UI.MenuItemWidthUp, UI.MenuItemWidthUp);
		//CreateDrawToolBarRight(false, false);
		UI.InterfaceMode = MODE_PLAY;
	}
	else {
		string MenuItemImages[Pick_And_Hide_Menu_Count];
		if (UI.male) {
			MenuItemImages[ITM_BY_TYPE] = "images\\MenuItems\\ICONS\\TOOLS\\ByShape.jpg";       //add the icons you created!!
			MenuItemImages[ITM_BY_FILLCOL] = "images\\MenuItems\\ICONS\\TOOLS\\ByColor.jpg";
			MenuItemImages[ITM_BY_TYPE_AND_FILLCOL] = "images\\MenuItems\\ICONS\\TOOLS\\ByColorShpae.jpg";
			MenuItemImages[ITM_BY_AREA] = "images\\MenuItems\\ICONS\\TOOLS\\BySize.jpg";
		}
		else {
			MenuItemImages[ITM_BY_TYPE] = "images\\MenuItems\\ICONS\\NewIcons\\Tools\\ByFigure.jpg";       //add the icons you created!!
			MenuItemImages[ITM_BY_FILLCOL] = "images\\MenuItems\\ICONS\\NewIcons\\Tools\\ByColor.jpg";
			MenuItemImages[ITM_BY_TYPE_AND_FILLCOL] = "images\\MenuItems\\ICONS\\NewIcons\\Tools\\ByColoredFigure.jpg";
			MenuItemImages[ITM_BY_AREA] = "images\\MenuItems\\ICONS\\NewIcons\\Tools\\ByArea.jpg";
		}
		int sign, start;
		if (!collapse) {
			UI.InterfaceMode = MODE_PLAY_SUB_MENU2;
			sign = 1;
			start = -50;
		}
		else {
			UI.InterfaceMode = MODE_PLAY;
			sign = -1;
			start = 0;
		}

		for (int j = 0; j <= 50; ++j) {
			for (int i = 0; i < Pick_And_Hide_Menu_Count; ++i)
				pWind->DrawImage(MenuItemImages[i], start + sign*j, (i + 4)*UI.MenuItemWidthLeft, UI.MenuItemWidthLeft, UI.MenuItemWidthLeft);
			if (collapse) {
				pWind->SetBrush(UI.BkGrndColor);
				pWind->SetPen(UI.BkGrndColor, 1);
				pWind->DrawRectangle(UI.MenuItemWidthLeft, 4 * UI.MenuItemWidthLeft, UI.MenuItemWidthLeft - j, (FigurelistIcons_Count + 4)*UI.MenuItemWidthLeft);
			}
		}
	}
}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::ClearDrawArea() const
{
	pWind->SetPen(UI.BkGrndColor, 1);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(0, 50, UI.width - 65, UI.height - UI.StatusBarHeight);
	//I changed the clear function to only clear the area enclosed by all 4 toolbars
}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::PrintMessage(string msg) const	//Prints a message on status bar
{
	ClearStatusBar();	//First clear the status bar

	pWind->SetPen(UI.MsgColor, 50);
	pWind->SetFont(20, BOLD, BY_NAME, "Arial");
	pWind->DrawString(10, UI.height - (int)(UI.StatusBarHeight / 1.5), msg);
}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntDrawColor() const	//get current drawing color
{
	return UI.DrawColor;
}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntFillColor() const	//get current filling color
{
	return UI.FillColor;
}
//////////////////////////////////////////////////////////////////////////////////////////

int Output::getCrntPenWidth() const		//get current pen width
{
	return UI.PenWidth;
}

void Output::CleanTheScreen()
{
	pWind->SetPen(UI.BkGrndColor, 1);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(0, 0, 1500, 800);
	//I changed the clear function to only clear the area enclosed by all 4 toolbars
}

//======================================================================================//
//								Figures Drawing Functions								//
//======================================================================================//

void Output::DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected) const
{
	color DrawingClr; //RectGfxInfo.isFilled = true;

	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = RectGfxInfo.DrawClr;

	int bw = RectGfxInfo.BorderWdth + (UI.Zoom - 1) / 0.25;
	if (bw <= 0)
		bw = 1;
	pWind->SetPen(DrawingClr, bw);	//Set Drawing color & width
	
	drawstyle style;
	if (RectGfxInfo.isFilled)  
	{
		style = FILLED;
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else
		style = FRAME;
	
	int Dist = abs(P1.y -P2.y);
	Point P1s = P1; Point P2s = P2;

	ZoomPoint(P1);
	ZoomPoint(P2);
	pWind->DrawRectangle(P1.x, P1.y, P2.x, P2.y, style);

	P1 = P1s; P2 = P2s;

}


void Output::ZoomPoint(Point &P1) const{
	if (UI.Zoom == 0)
		UI.Zoom = 1;

	UI.ZoomCenter.x = UI.width / 2;
	UI.ZoomCenter.y = UI.height / 2;

	P1.x = UI.ZoomCenter.x - UI.Zoom*UI.ZoomCenter.x + UI.Zoom*P1.x;
	P1.y = UI.ZoomCenter.y - UI.Zoom*UI.ZoomCenter.y + UI.Zoom*P1.y;
}


void Output::DrawLine(Point P1, Point P2, GfxInfo LineGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = LineGfxInfo.DrawClr;
	int bw = LineGfxInfo.BorderWdth + (UI.Zoom - 1 )/ 0.25;
	if (bw <= 0)
		bw = 1;
	pWind->SetPen(DrawingClr, bw);	//Set Drawing color & width
	Point P1s = P1; Point P2s = P2;

	
	ZoomPoint(P1);
	ZoomPoint(P2);

	pWind->DrawLine(P1.x, P1.y, P2.x, P2.y, FRAME);
	P1 = P1s; P2 = P2s;

}


void Output::DrawTriangle(Point P1, Point P2, Point P3, GfxInfo TriangleGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = TriangleGfxInfo.DrawClr;
	int bw = TriangleGfxInfo.BorderWdth + (UI.Zoom - 1) / 0.25;
	if (bw <= 0)
		bw = 1;
	pWind->SetPen(DrawingClr, bw);

	drawstyle style;
	if (TriangleGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(TriangleGfxInfo.FillClr);
	}
	else
		style = FRAME;
	Point P1s = P1; Point P2s = P2; Point P3s = P3;
	ZoomPoint(P1); ZoomPoint(P2); ZoomPoint(P3);
	pWind->DrawTriangle(P1.x, P1.y, P2.x, P2.y, P3.x, P3.y, style);
	P1 = P1s; P2 = P2s; P3 = P3s;
}


void Output::DrawCircle(Point center, int radius, GfxInfo CircleGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = CircleGfxInfo.DrawClr;
	int bw = CircleGfxInfo.BorderWdth + (UI.Zoom - 1) / 0.25;
	
	if (bw <= 0)
		bw = 1;
	pWind->SetPen(DrawingClr, bw);

	drawstyle style;
	if (CircleGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(CircleGfxInfo.FillClr);
	}
	else
		style = FRAME;
	Point c = center;
	ZoomPoint(center);
	pWind->DrawCircle(center.x, center.y, radius*UI.Zoom, style);
	center = c;
}

buttonstate Output::getButtonState(int &iX, int &iY) {
	return  pWind->GetButtonState(LEFT_BUTTON, iX, iY);
}

void Output::setBuffering(bool state) {
	pWind->SetBuffering(state);
}

void Output::FlushMouse() {
	pWind->FlushMouseQueue();
	//pWind->FlushKeyQueue();
}

bool Output::EscapeClicked() {
	char cKeyData;
	return pWind->GetKeyPress(cKeyData) == ESCAPE;
}

bool Output::EnterClicked() {
	char cKeyData;
	return pWind->GetKeyPress(cKeyData) == FUNCTION;
}
bool Output::UpdateBuffer() {
	pWind->UpdateBuffer();
	return true;
}




//////////////////////////////////////////////////////////////////////////////////////////
Output::~Output()
{
	delete pWind;
}