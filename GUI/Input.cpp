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
		pO->PrintMessage(Label);
	}
}

//This function reads the position where the user clicks to determine the desired action
ActionType Input::GetUserAction() const
{
	int x, y;
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click

									//special hadling for mode switching
									//if (x >= 60 && x <= 120 && y >= 600 && y <= 660 && UI.InterfaceMode == MODE_DRAW) //click on the play mode
									//UI.InterfaceMode = MODE_PLAY;
									//else if(x >= 60 && x <= 120 && y >= 600 && y <= 660 && UI.InterfaceMode == MODE_PLAY)
									//UI.InterfaceMode = MODE_DRAW;

	if (UI.InterfaceMode == MODE_DRAW)	//GUI in the DRAW mode
	{
		// Edited .. UI Tool Bar Width =60*2 ;; 
		UI.ToolBarWidth = originalToolBarWidth * 2;  // 60 refers to The first column ,, 2 refers to double columns ;; 
													 //[1] If user clicks on the Toolbar

		if (x >= 0 && x < UI.ToolBarWidth / 2 && y >= 0 && y <= originalToolBarWidth)
			return TO_PLAY;

		if (x >= originalToolBarWidth && x < UI.ToolBarWidth  && y >= 0 && y <= originalToolBarWidth)
			return ITM_COLLAPSELEFT_Clicked;

		else if (x >= 0 && x < UI.ToolBarWidth / 2)
		{
			//Check which Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = ((y - originalToolBarWidth) / UI.MenuItemHeight);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
				///TODO: Add the rest of user actions here.
			case ITM_BRUSH1:		  return ITM_BRUSH1_Clicked;
			case ITM_BRUSH2:		  return ITM_BRUSH2_Clicked;
			case ITM_BRUSH3:		  return ITM_BRUSH3_Clicked;
			case ITM_BRUSH4:		  return ITM_BRUSH4_Clicked;
			case ITM_BRUSH5:		  return ITM_BRUSH5_Clicked;
			case ITM_BRUSH6:		  return ITM_BRUSH6_Clicked;
			case ITM_BRUSH7:		  return ITM_BRUSH7_Clicked;
			case ITM_BRUSH8:		  return ITM_BRUSH8_Clicked;
			case ITM_BRUSH9:		  return ITM_BRUSH9_Clicked;
			case ITM_BRUSH10:		  return ITM_BRUSH10_Clicked;

			default: return EMPTY;	//A click on empty place in desgin toolbar
			}
		}
		else if (x >= originalToolBarWidth && x < UI.ToolBarWidth) { // The Second  Column from left
			int ClickedItemOrder = ((y - originalToolBarWidth) / UI.MenuItemHeight);

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
		else if (x >= startingXForUpperMenu && x <= (4 * UI.MenuItemWidthUp + startingXForUpperMenu)
			&& y >= 0 && y <= UI.MenuItemWidthUp) {
			int ClickedItemOrder = ((x) / UI.MenuItemWidthUp);
			switch (ClickedItemOrder) {
			case ITM_CIRCLE:			return DRAW_CIRC;
			case ITM_RECTANGLE:	return DRAW_RECT;
			case ITM_LINE:			return DRAW_LINE;
			case ITM_TRIANGLE:		return DRAW_TRI;
			default: return EMPTY;
			}
		}


		// EXIT AND COLLAPSE //
		else if (x >= startingXforLeftMenu2ndCol && x <= ScreenEndX && y >= 0 && y <= leftMenuItemHeight)
		{
			if (x < startingXforLeftMenu1stCol)
				return ITM_COLLAPSERIGHT_Clicked;
			return EXIT;
		}

		// ZOOM ITEMS //
		else if (x >= startingXforLeftMenu2ndCol && x <= ScreenEndX
			&& y >= 13 * leftMenuItemHeight && y <= UI.height - UI.StatusBarHeight) {
			if (x < startingXforLeftMenu1stCol)
				return ITM_ZOOM_IN_Clicked;
			return ITM_ZOOM_OUT_Clicked;
		}

		// The Right Column ITEMS // 
		else if (x >= startingXforLeftMenu1stCol && x <= ScreenEndX
			&& y > leftMenuItemHeight && y <= ScreenEndY) {
			int ClickedItemOrder = (y / UI.MenuItemWidthLeft);
			switch (ClickedItemOrder) {
			case ITM_RESIZE:				return ITM_RESIZE_Clicked;
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

		//[2] User clicks on the drawing area
		else if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;
		}
		//[3] User clicks on the status bar
		return STATUS;
	}
	else
	{
		// ZOOM ITEMS //
		if (x >= startingXforLeftMenu2ndCol && x <= ScreenEndX && y >= 13 * leftMenuItemHeight
			&& y <= UI.height - UI.StatusBarHeight) {
			if (x < startingXforLeftMenu1stCol)
				return ITM_ZOOM_IN_Clicked;
			return ITM_ZOOM_OUT_Clicked;
		}
		// EXIT AND COLLAPSE //
		else if (x >= startingXforLeftMenu2ndCol && x <= ScreenEndX && y >= 0 && y <= leftMenuItemHeight)
		{
			if (x < startingXforLeftMenu1stCol)
				return ITM_COLLAPSERIGHT_Clicked;
			return EXIT;
		}


		else if (y >= 0 && y <= playModeItemHeight && x >= 0 && x <= PLAY_ITM_COUNT * UI.MenuItemWidthUp) {
			int ClickedItemOrder = (x / UI.MenuItemWidthUp);
			switch (ClickedItemOrder) {
			case ITM_SCRAMBLE:			return ITM_SCRAMBLE_Clicked;
			case ITM_FIND:				return ITM_FIND_Clicked;
			case ITEM_TODRAW:			return TO_DRAW;
			default: return EMPTY;
			}
		}

		else if (x >= startingXforLeftMenu1stCol && x <= ScreenEndX && y > leftMenuItemHeight && y <= ScreenEndY) {
			int ClickedItemOrder = (y / UI.MenuItemWidthLeft);
			switch (ClickedItemOrder) {
			case ITM_RESIZE:				return ITM_RESIZE_Clicked;
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
			default: return EMPTY;
			}
		}

		else if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
			return DRAWING_AREA;
		else
			return STATUS;
	}


}
/////////////////////////////////

Input::~Input()
{
}
