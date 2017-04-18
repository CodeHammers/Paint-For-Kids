#include "Input.h"
#include "Output.h"

Input::Input(window* pW)
{
	pWind = pW; //point to the passed window
}

void Input::GetPointClicked(int &x, int &y) const
{
	pWind->WaitMouseClick(x, y);	//Wait for mouse click
}

string Input::GetSrting(Output *pO) const
{
	string Label;
	char Key;
	while (1)
	{
		pWind->WaitKeyPress(Key);
		if (Key == 27)	//ESCAPE key is pressed
			return "";	//returns nothing as user has cancelled label
		if (Key == 13)	//ENTER key is pressed
			return Label;
		if (Key == 8)	//BackSpace is pressed
			Label.resize(Label.size() - 1);
		else
			Label += Key;
		if(pO!=NULL)
			pO->PrintMessage(Label);
	}
}

//This function reads the position where the user clicks to determine the desired action
ActionType Input::GetUserAction() const
{
	int x, y;
	pWind->WaitMouseClick(x, y);


	if (x >= startingXforLeftMenu2ndCol && x <= ScreenEndX && y >= 0 && y <= leftMenuItemHeight) {
		if (x < startingXforLeftMenu1stCol)
			return ITM_COLLAPSERIGHT_Clicked;
		return EXIT;
	}
	else if (x >= startingXforLeftMenu2ndCol && x <= ScreenEndX	&& y >= 13 * leftMenuItemHeight && y <= UI.height - UI.StatusBarHeight) {
		if (x < startingXforLeftMenu1stCol)
			return ITM_ZOOM_IN_Clicked;
		return ITM_ZOOM_OUT_Clicked;
	}

	else if (x >= startingXforLeftMenu1stCol && x <= ScreenEndX	&& y > leftMenuItemHeight && y <= ScreenEndY) {
		int ClickedItemOrder = (y / UI.MenuItemWidthLeft);
		switch (ClickedItemOrder) {
		case    ITM_RESIZE:				return ITM_RESIZE_Clicked;
		case	ITM_MOVE:				return ITM_MOVE_Clicked;
		case	ITM_COPY:				return ITM_COPY_Clicked;
		case	ITM_CUT:				return ITM_CUT_Clicked;
		case	ITM_PASTE:				return ITM_PASTE_Clicked;
		case	ITM_DELETE:				return ITM_DELETE_Clicked;
		case	ITM_UNDO:				return ITM_UNDO_Clicked;
		case	ITM_REDO:				return ITM_REDO_Clicked;
		case	ITM_SELECT:				return ITM_SELECT_Clicked;
		case	ITM_LOAD:				return ITM_LOAD_Clicked;
		case	ITM_SAVE:				return ITM_SAVE_Clicked;
		case	ITM_SAVEAS:				return ITM_SAVEAS_Clicked;
		case	ITM_COLLAPSERIGHT:		return ITM_COLLAPSERIGHT_Clicked;
		default: return EMPTY;
		}
	}
	else if (y > 720)
		return STATUS;

	else if (UI.InterfaceMode == MODE_DRAW_SUB_MENU1) {
		if (x >= 0 && x <= UI.MenuItemWidthLeft) {
			int ClickedItemOrder = ((y - 200) / UI.MenuItemWidthLeft);
			switch (ClickedItemOrder) {
			case ITM_CIRCLE:		return DRAW_CIRC;
			case ITM_RECTANGLE:		return DRAW_RECT;
			case ITM_LINE:			return DRAW_LINE;
			case ITM_TRIANGLE:		return DRAW_TRI;
			default: return EMPTY;
			}
		}

		if (x >= 0 && x < UI.ToolBarWidth / 2 && y >= 0 && y <= originalToolBarWidth)
			return TO_PLAY;

		else if (x >= 550 && x < 600 && y>0 && y <= UI.MenuItemWidthLeft)
			return MODE_DRAW_SUB_MENU1_Clicked;
		else if (x >= 600 && x < 650 && y>0 && y <= UI.MenuItemWidthLeft)
			return MODE_DRAW_SUB_MENU2_Clicked;
		else if (x >= 650 && x < 700 && y>0 && y <= UI.MenuItemWidthLeft)
			return MODE_DRAW_SUB_MENU3_Clicked;
		else if (x >= 700 && x < 750 && y>0 && y <= UI.MenuItemWidthLeft)
			return MODE_DRAW_SUB_MENU4_Clicked;
		else if (x >= 750 && x < 800 && y>0 && y <= UI.MenuItemWidthLeft)
			return MODE_DRAW_SUB_MENU5_Clicked;
		else
			return DRAWING_AREA;
	}
	else if (UI.InterfaceMode == MODE_DRAW_SUB_MENU2) {
		if (x >= 0 && x <= UI.MenuItemWidthLeft) {
			int ClickedItemOrder = ((y - 100) / UI.MenuItemWidthLeft);
			switch (ClickedItemOrder)
			{
			case ITM_PEN1:		  return ITM_BRUSH1_Clicked;
			case ITM_PEN2:		  return ITM_BRUSH2_Clicked;
			case ITM_PEN3:		  return ITM_BRUSH3_Clicked;
			case ITM_PEN4:		  return ITM_BRUSH4_Clicked;
			case ITM_PEN5:		  return ITM_BRUSH5_Clicked;
			case ITM_PEN6:		  return ITM_BRUSH6_Clicked;
			case ITM_PEN7:		  return ITM_BRUSH7_Clicked;
			case ITM_PEN8:		  return ITM_BRUSH8_Clicked;
			case ITM_PEN9:		  return ITM_BRUSH9_Clicked;
			case ITM_PEN10:		  return ITM_BRUSH10_Clicked;

			default: return EMPTY;
			}
		}
		if (x >= 0 && x < UI.ToolBarWidth / 2 && y >= 0 && y <= originalToolBarWidth)
			return TO_PLAY;

		else if (x >= 550 && x < 600 && y>0 && y <= UI.MenuItemWidthLeft)
			return MODE_DRAW_SUB_MENU1_Clicked;
		else if (x >= 600 && x < 650 && y>0 && y <= UI.MenuItemWidthLeft)
			return MODE_DRAW_SUB_MENU2_Clicked;
		else if (x >= 650 && x < 700 && y>0 && y <= UI.MenuItemWidthLeft)
			return MODE_DRAW_SUB_MENU3_Clicked;
		else if (x >= 700 && x < 750 && y>0 && y <= UI.MenuItemWidthLeft)
			return MODE_DRAW_SUB_MENU4_Clicked;
		else if (x >= 750 && x < 800 && y>0 && y <= UI.MenuItemWidthLeft)
			return MODE_DRAW_SUB_MENU5_Clicked;
		else
			return DRAWING_AREA;
	}
	else if (UI.InterfaceMode == MODE_DRAW_SUB_MENU3) {
		if (x >= 0 && x <= UI.MenuItemWidthLeft) {
			int ClickedItemOrder = ((y - 100) / UI.MenuItemWidthLeft);
			switch (ClickedItemOrder)
			{
			case ITM_BRUSHFILL1:		  return ITM_BRUSHFILL1_Clicked;
			case ITM_BRUSHFILL2:		  return ITM_BRUSHFILL2_Clicked;
			case ITM_BRUSHFILL3:		  return ITM_BRUSHFILL3_Clicked;
			case ITM_BRUSHFILL4:		  return ITM_BRUSHFILL4_Clicked;
			case ITM_BRUSHFILL5:		  return ITM_BRUSHFILL5_Clicked;
			case ITM_BRUSHFILL6:		  return ITM_BRUSHFILL6_Clicked;
			case ITM_BRUSHFILL7:		  return ITM_BRUSHFILL7_Clicked;
			case ITM_BRUSHFILL8:		  return ITM_BRUSHFILL8_Clicked;
			case ITM_BRUSHFILL9:		  return ITM_BRUSHFILL9_Clicked;
			case ITM_BRUSHFILL10:		  return ITM_BRUSHFILL10_Clicked;

			default: return EMPTY;	//A click on empty place in desgin toolbar
			}
		}
		if (x >= 0 && x < UI.ToolBarWidth / 2 && y >= 0 && y <= originalToolBarWidth)
			return TO_PLAY;

		else if (x >= 550 && x < 600 && y>0 && y <= UI.MenuItemWidthLeft)
			return MODE_DRAW_SUB_MENU1_Clicked;
		else if (x >= 600 && x < 650 && y>0 && y <= UI.MenuItemWidthLeft)
			return MODE_DRAW_SUB_MENU2_Clicked;
		else if (x >= 650 && x < 700 && y>0 && y <= UI.MenuItemWidthLeft)
			return MODE_DRAW_SUB_MENU3_Clicked;
		else if (x >= 700 && x < 750 && y>0 && y <= UI.MenuItemWidthLeft)
			return MODE_DRAW_SUB_MENU4_Clicked;
		else if (x >= 750 && x < 800 && y>0 && y <= UI.MenuItemWidthLeft)
			return MODE_DRAW_SUB_MENU5_Clicked;
		else
			return DRAWING_AREA;
	}

	else if (UI.InterfaceMode == MODE_DRAW_SUB_MENU4) {
		if (x >= 0 && x <= UI.MenuItemWidthLeft) {
			int ClickedItemOrder = ((y - 100) / UI.MenuItemWidthLeft);
			switch (ClickedItemOrder)
			{
			case ITM_BCKG_WHITE:	return ITM_BCKG_WHITE_Clicked;
			case ITM_BCKG_BLUE:		return ITM_BCKG_BLUE_Clicked;
			case ITM_BCKG_RED:		return ITM_BCKG_RED_Clicked;
			case ITM_BCKG_BROWN:	return ITM_BCKG_BROWN_Clicked;
			case ITM_BCKG_PINK:		return ITM_BCKG_PINK_Clicked;
			case ITM_BCKG_NILE:		return ITM_BCKG_NILE_Clicked;
			case ITM_BCKG_YELLOW:	return ITM_BCKG_YELLOW_Clicked;
			case ITM_BCKG_ORANE:	return ITM_BCKG_ORANE_Clicked;
			case ITM_BCKG_PURPLE:	return ITM_BCKG_PURPLE_Clicked;
			case ITM_BCKG_GREEN:	return ITM_BCKG_GREEN_Clicked;
			default: return EMPTY;
			}
		}
		if (x >= 0 && x < UI.ToolBarWidth / 2 && y >= 0 && y <= originalToolBarWidth)
			return TO_PLAY;

		else if (x >= 550 && x < 600 && y>0 && y <= UI.MenuItemWidthLeft)
			return MODE_DRAW_SUB_MENU1_Clicked;
		else if (x >= 600 && x < 650 && y>0 && y <= UI.MenuItemWidthLeft)
			return MODE_DRAW_SUB_MENU2_Clicked;
		else if (x >= 650 && x < 700 && y>0 && y <= UI.MenuItemWidthLeft)
			return MODE_DRAW_SUB_MENU3_Clicked;
		else if (x >= 700 && x < 750 && y>0 && y <= UI.MenuItemWidthLeft)
			return MODE_DRAW_SUB_MENU4_Clicked;
		else if (x >= 750 && x < 800 && y>0 && y <= UI.MenuItemWidthLeft)
			return MODE_DRAW_SUB_MENU5_Clicked;
		else
			return DRAWING_AREA;
	}

	else if (UI.InterfaceMode == MODE_DRAW_SUB_MENU5) {
		if (x >= 0 && x <= UI.MenuItemWidthLeft) {
			int ClickedItemOrder = ((y - 200) / UI.MenuItemWidthLeft);
			switch (ClickedItemOrder)
			{
			case ITM_BORDERWIDTH1: return ITM_BORDERWIDTH1_Clicked;
			case ITM_BORDERWIDTH2: return ITM_BORDERWIDTH2_Clicked;
			case ITM_BORDERWIDTH3: return ITM_BORDERWIDTH3_Clicked;
			case ITM_BORDERWIDTH4: return ITM_BORDERWIDTH4_Clicked;

			default: return EMPTY;
			}
		}
		if (x >= 0 && x < UI.ToolBarWidth / 2 && y >= 0 && y <= originalToolBarWidth)
			return TO_PLAY;

		else if (x >= 550 && x < 600 && y>0 && y <= UI.MenuItemWidthLeft)
			return MODE_DRAW_SUB_MENU1_Clicked;
		else if (x >= 600 && x < 650 && y>0 && y <= UI.MenuItemWidthLeft)
			return MODE_DRAW_SUB_MENU2_Clicked;
		else if (x >= 650 && x < 700 && y>0 && y <= UI.MenuItemWidthLeft)
			return MODE_DRAW_SUB_MENU3_Clicked;
		else if (x >= 700 && x < 750 && y>0 && y <= UI.MenuItemWidthLeft)
			return MODE_DRAW_SUB_MENU4_Clicked;
		else if (x >= 750 && x < 800 && y>0 && y <= UI.MenuItemWidthLeft)
			return MODE_DRAW_SUB_MENU5_Clicked;
		else
			return DRAWING_AREA;
	}

	else if (UI.InterfaceMode == MODE_DRAW_SUB_MENU6) {
		if (x >= 0 && x <= UI.MenuItemWidthLeft) {
			int ClickedItemOrder = ((y - 200) / UI.MenuItemWidthLeft);
			switch (ClickedItemOrder)
			{
			case ITM_RESIZE25:	 return ITM_RESIZE25_Clicked;
			case ITM_RESIZE50:	 return ITM_RESIZE50_Clicked;
			case ITM_RESIZE200:	 return ITM_RESIZE200_Clicked;
			case ITM_RESIZE400:	 return ITM_RESIZE400_Clicked;

			default: return EMPTY;
			}
		}
		if (x >= 0 && x < UI.ToolBarWidth / 2 && y >= 0 && y <= originalToolBarWidth)
			return TO_PLAY;

		else if (x >= 550 && x < 600 && y>0 && y <= UI.MenuItemWidthLeft)
			return MODE_DRAW_SUB_MENU1_Clicked;
		else if (x >= 600 && x < 650 && y>0 && y <= UI.MenuItemWidthLeft)
			return MODE_DRAW_SUB_MENU2_Clicked;
		else if (x >= 650 && x < 700 && y>0 && y <= UI.MenuItemWidthLeft)
			return MODE_DRAW_SUB_MENU3_Clicked;
		else if (x >= 700 && x < 750 && y>0 && y <= UI.MenuItemWidthLeft)
			return MODE_DRAW_SUB_MENU4_Clicked;
		else if (x >= 750 && x < 800 && y>0 && y <= UI.MenuItemWidthLeft)
			return MODE_DRAW_SUB_MENU5_Clicked;
		else
			return DRAWING_AREA;
	}

	else if (UI.InterfaceMode == MODE_DRAW)	//GUI in the DRAW mode
	{
		// Edited .. UI Tool Bar Width =60*2 ;; 
		UI.ToolBarWidth = originalToolBarWidth * 2;  // 60 refers to The first column ,, 2 refers to double columns ;; 
													 //[1] If user clicks on the Toolbar

		if (x >= 0 && x < UI.ToolBarWidth / 2 && y >= 0 && y <= originalToolBarWidth)
			return TO_PLAY;

		else if (x >= 550 && x < 600 && y>0 && y <= UI.MenuItemWidthLeft)
			return MODE_DRAW_SUB_MENU1_Clicked;
		else if (x >= 600 && x < 650 && y>0 && y <= UI.MenuItemWidthLeft)
			return MODE_DRAW_SUB_MENU2_Clicked;
		else if (x >= 650 && x < 700 && y>0 && y <= UI.MenuItemWidthLeft)
			return MODE_DRAW_SUB_MENU3_Clicked;
		else if (x >= 700 && x < 750 && y>0 && y <= UI.MenuItemWidthLeft)
			return MODE_DRAW_SUB_MENU4_Clicked;
		else if (x >= 750 && x < 800 && y>0 && y <= UI.MenuItemWidthLeft)
			return MODE_DRAW_SUB_MENU5_Clicked;
	}
	if(x>=55 && x<=1435 && y>=60 && y<=710)
		return DRAWING_AREA;
	return EMPTY;
}
/////////////////////////////////

Input::~Input()
{
}
