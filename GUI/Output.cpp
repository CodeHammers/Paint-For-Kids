#include "Output.h"


Output::Output()
{
	/*Initialize user interface parameters*/
	UI.InterfaceMode = MODE_DRAW;

	/*Setting the dimensions of the application window*/
	UI.width = 1500; //Setting the width of the window.
	UI.height = 800; //Setting the height of the window.
	UI.wx = 5;  //Setting the starting position of the window.
	UI.wy = 5;   //Setting the ending position on the window.

	/*Setting the dimensions of the toolbars right,up,left*/
	UI.StatusBarHeight = 80;      //Settting the height of the status bar.
	UI.MenuItemWidthLeft = 50;    //Setting the width of icons in the left menu.
	UI.MenuItemWidthUp = 50;     //Setting the width of icons in the upper menu.
	UI.MenuItemWidthRight = 50;   //Setting the width of icons in the right menu.
	UI.MenuItemHeight = 60;      

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

	/*Drawing the 2 menus for the application window*/
	CreateDrawToolBarUp(0,false);
	CreateDrawToolBarRight(false);

	/*Drawing the status bar in the application window*/
	CreateStatusBar();
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
void Output::CreateDrawToolBarRight(bool collapse) const
{
	UI.InterfaceMode = MODE_DRAW;  //Setting the current mode.

	/*Adding two parallel icons for zooming in and out*/;
	string zoomControls[CounterZoom];
	zoomControls[ITM_ZOOM_IN] = "images\\MenuItems\\ICONS\\TOOLS\\ZOOMIN.jpg";
	zoomControls[ITM_ZOOM_OUT] = "images\\MenuItems\\ICONS\\TOOLS\\ZOOMOUT.jpg";
	pWind->DrawImage(zoomControls[ITM_ZOOM_IN], 1385, 13 * UI.MenuItemWidthRight, UI.MenuItemWidthRight, UI.MenuItemWidthRight);
	pWind->DrawImage(zoomControls[ITM_ZOOM_OUT], 1435, 13 * UI.MenuItemWidthRight, UI.MenuItemWidthRight, UI.MenuItemWidthRight);


	/*Loading the icons for the left toolbar.*/
	string MenuItemImages[DRAW_ITM_COUNT_LEFT];
	MenuItemImages[ITM_COLLAPSERIGHT] = "images\\MenuItems\\ICONS\\TOOLS\\COLLAPSE.jpg";
	MenuItemImages[ITM_LOAD] = "images\\MenuItems\\ICONS\\TOOLS\\LOAD.jpg";
	MenuItemImages[ITM_MOVE] = "images\\MenuItems\\ICONS\\TOOLS\\MOVE.jpg";
	MenuItemImages[ITM_SELECT] = "images\\MenuItems\\ICONS\\TOOLS\\SELECT.jpg";
	MenuItemImages[ITM_RESIZE] = "images\\MenuItems\\ICONS\\TOOLS\\RESIZE1.jpg";
	MenuItemImages[ITM_COPY] = "images\\MenuItems\\ICONS\\TOOLS\\COPY.jpg";
	MenuItemImages[ITM_CUT] = "images\\MenuItems\\ICONS\\TOOLS\\CUT.jpg";
	MenuItemImages[ITM_PASTE] = "images\\MenuItems\\ICONS\\TOOLS\\PASTE.jpg";
	MenuItemImages[ITM_REDO] = "images\\MenuItems\\ICONS\\TOOLS\\REDO11.jpg";
	MenuItemImages[ITM_UNDO] = "images\\MenuItems\\ICONS\\TOOLS\\UNDO11.jpg";
	MenuItemImages[ITM_DELETE] = "images\\MenuItems\\ICONS\\TOOLS\\DELETE.jpg";
	MenuItemImages[ITM_SAVE] = "images\\MenuItems\\ICONS\\TOOLS\\SAVE.jpg";
	MenuItemImages[ITM_SAVEAS] = "images\\MenuItems\\ICONS\\TOOLS\\SAVEAS.jpg";
	MenuItemImages[ITM_EXIT] = "images\\MenuItems\\ICONS\\TOOLS\\EXIT.jpg";

	if (!collapse) {
		//Drawing the left toolbar, excluding the last three icons(not needed now)
		for (int i = 1; i < DRAW_ITM_COUNT_LEFT - 2; i++)
			pWind->DrawImage(MenuItemImages[i], 1435, i * 50, UI.MenuItemWidthLeft, UI.MenuItemWidthLeft);
	}
	else {
		pWind->SetBrush(UI.BkGrndColor);
		pWind->SetPen(UI.BkGrndColor, 1);
		for (int j = 0; j < 80; j++) {
			//Drawing the left toolbar, excluding the last three icons(not needed now)
			for (int i = 1; i < DRAW_ITM_COUNT_LEFT - 2; i++) {
				pWind->DrawImage(MenuItemImages[i], 1435 + (0.7)*j, i * 50, UI.MenuItemWidthLeft, UI.MenuItemWidthLeft);
				pWind->DrawRectangle(1435, 50, 1435 + (0.7)*j, 600);
			}
		}
	}
	pWind->DrawImage(MenuItemImages[ITM_COLLAPSERIGHT], 1385, 0, UI.MenuItemWidthLeft, UI.MenuItemWidthLeft);
	pWind->DrawImage(MenuItemImages[ITM_EXIT], 1435, 0, UI.MenuItemWidthLeft, UI.MenuItemWidthLeft);
}


/*This function is responsible of drawing the upper toolber and all its sub menus*/
void Output::CreateDrawToolBarUp(int action, bool collapse) const
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
		string PlayModeIcon = "images\\MenuItems\\ICONS\\JOYSTICK.jpg";
		pWind->DrawImage(PlayModeIcon, 0, 0, 60, UI.MenuItemHeight);

		//Loading the icons for the main upper menu.
		string MenuItemImages[DRAW_LEFT_MENU_ITEMS_COUNT];
		MenuItemImages[ITM_FIGURE] = "images\\MenuItems\\ICONS\\TOOLS\\FIGURE.jpg";
		MenuItemImages[ITM_PEN] = "images\\MenuItems\\ICONS\\Pencils\\BLACK.jpg";
		MenuItemImages[ITM_BRUSH] = "images\\MenuItems\\ICONS\\Brushes\\GREEN.jpg";
		MenuItemImages[ITM_BCKGCOLOR] = "images\\MenuItems\\ICONS\\BkGROUND\\WHITE.jpg";
		MenuItemImages[STROKWIDTH] = "images\\MenuItems\\ICONS\\BORDERWIDTH\\GROUP.jpg";
		
		//Drawing the upper toolbar, 11 is a shifting factor to start drawing near the middle of the screen
		for (int i = 0; i < DRAW_LEFT_MENU_ITEMS_COUNT; i++)
			pWind->DrawImage(MenuItemImages[i], (11+i)*UI.MenuItemWidthUp, 0, UI.MenuItemWidthUp, UI.MenuItemWidthUp);
	}


	else if (action == 1) {
		string MenuItemImages[FigurelistIcons_Count];
		MenuItemImages[ITM_CIRCLE] = "images\\MenuItems\\ICONS\\CIRCULE.jpg";
		MenuItemImages[ITM_RECTANGLE] = "images\\MenuItems\\ICONS\\RECTANGLE.jpg";
		MenuItemImages[ITM_TRIANGLE]="images\\MenuItems\\ICONS\\TRIANGLE.jpg";
		MenuItemImages[ITM_LINE]="images\\MenuItems\\ICONS\\LINE.jpg";

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
		MenuItemImages[ITM_BORDERWIDTH1] = "images\\MenuItems\\ICONS\\BORDERWIDTH\\1.jpg";
		MenuItemImages[ITM_BORDERWIDTH2] = "images\\MenuItems\\ICONS\\BORDERWIDTH\\2.jpg";
		MenuItemImages[ITM_BORDERWIDTH3] = "images\\MenuItems\\ICONS\\BORDERWIDTH\\3.jpg";
		MenuItemImages[ITM_BORDERWIDTH4] = "images\\MenuItems\\ICONS\\BORDERWIDTH\\4.jpg";

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
		MenuItemImages[ITM_RESIZE25] = "images\\MenuItems\\ICONS\\RESIZE\\25.jpg";
		MenuItemImages[ITM_RESIZE50] = "images\\MenuItems\\ICONS\\RESIZE\\50.jpg";
		MenuItemImages[ITM_RESIZE200] = "images\\MenuItems\\ICONS\\RESIZE\\200.jpg";
		MenuItemImages[ITM_RESIZE400] = "images\\MenuItems\\ICONS\\RESIZE\\400.jpg";

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

void Output::CreatePlayToolBar() const
{
	UI.InterfaceMode = MODE_PLAY;

	//Collapse the left toolbar.
	pWind->SetBrush(UI.BkGrndColor);
	pWind->SetPen(UI.BkGrndColor, 1);
	pWind->DrawRectangle(0, 0, 120, 660);

	//Collapse the upper toolbar.
	pWind->DrawRectangle(500, 0, 900, 100);


	string MenuItemImages[PLAY_ITM_COUNT];
	MenuItemImages[ITM_SCRAMBLE] = "images\\MenuItems\\ICONS\\TOOLS\\SCRAMBLE.jpg";
	MenuItemImages[ITM_FIND] = "images\\MenuItems\\ICONS\\TOOLS\\FIND.jpg";
	MenuItemImages[ITEM_TODRAW] = "images\\MenuItems\\ICONS\\TOOLS\\TODRAW1.jpg";

	for (int i = 0; i<PLAY_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], 500 + (i - 5)*UI.MenuItemWidthUp, 0, UI.MenuItemWidthUp, UI.MenuItemWidthUp);

}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::ClearDrawArea() const
{
	pWind->SetPen(UI.BkGrndColor, 1);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(120, 100, UI.width - 115, UI.height - UI.StatusBarHeight);
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

//======================================================================================//
//								Figures Drawing Functions								//
//======================================================================================//

void Output::DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = RectGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, RectGfxInfo.BorderWdth);	//Set Drawing color & width

	drawstyle style;
	if (RectGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else
		style = FRAME;


	pWind->DrawRectangle(P1.x, P1.y, P2.x, P2.y, style);
}

void Output::DrawLine(Point P1, Point P2, GfxInfo LineGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = LineGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, LineGfxInfo.BorderWdth);	//Set Drawing color & width

	pWind->DrawLine(P1.x, P1.y, P2.x, P2.y, FRAME);
}

void Output::DrawTriangle(Point P1, Point P2, Point P3, GfxInfo TriangleGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = TriangleGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, TriangleGfxInfo.BorderWdth);

	drawstyle style;
	if (TriangleGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(TriangleGfxInfo.FillClr);
	}
	else
		style = FRAME;

	pWind->DrawTriangle(P1.x, P1.y, P2.x, P2.y, P3.x, P3.y, style);
}

void Output::DrawCircle(Point center, int radius, GfxInfo CircleGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = CircleGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, CircleGfxInfo.BorderWdth);

	drawstyle style;
	if (CircleGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(CircleGfxInfo.FillClr);
	}
	else
		style = FRAME;

	pWind->DrawCircle(center.x, center.y, radius, style);
}

//////////////////////////////////////////////////////////////////////////////////////////
Output::~Output()
{
	delete pWind;
}