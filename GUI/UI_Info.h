#ifndef UI_INFO_H
#define UI_INFO_H

#include "..\CMUgraphicsLib\CMUgraphics.h"

//User Interface information file.
//This file contains info that is needed by Input and Output classes to
//handle the user interface

enum GUI_MODE	//Graphical user interface mode
{
	MODE_DRAW,	//Drawing mode (startup mode)
	MODE_PLAY	//Playing mode
};

enum DrawMenuItemLeft //The items of the Draw menu (you should add more items)
{
	//Note: Items are ordered here as they appear in menu
	//If you want to change the menu items order, change the order here

	/*Here we construct our menus, we have 3 menus, up, left and right*/

	//Items for the left menu (edit related icons)
	ITM_RESIZE = 1,
	ITM_MOVE,
	ITM_COPY,
	ITM_CUT,
	ITM_PASTE,
	ITM_DELETE,
	ITM_UNDO,
	ITM_REDO,
	ITM_SELECT,
	ITM_LOAD,
	ITM_SAVE,       //save icon (for testing)
	ITM_SAVEAS,
	ITM_COLLAPSERIGHT,
	ITM_EXIT,

	DRAW_ITM_COUNT_LEFT		//no. of menu items ==> This should be the last line in this enum

};
enum zoomControls
{
	ITM_ZOOM_IN,
	ITM_ZOOM_OUT,

	CounterZoom

};

enum DrawMenuItemUp  //enumeration for icons on the upper menu
{
	ITM_CIRCLE = 5,
	ITM_RECTANGLE,
	ITM_TRIANGLE,
	ITM_LINE,
	DRAW_ITEM_COUNT_UP
};


enum DrawMenuItemRight  //enumeration for icons on the right menu
{
	ITM_BRUSH1,
	ITM_BRUSH2,
	ITM_BRUSH3,
	ITM_BRUSH4,
	ITM_BRUSH5,
	ITM_BRUSH6,
	ITM_BRUSH7,
	ITM_BRUSH8,
	ITM_BRUSH9,
	ITM_BRUSH10,
	ITM_COLLAPSELEFT,
	DRAW_ITEM_COUNT_RIGHTBRUSH
};

enum DrawMenuItemRightBrushFill
{
	ITM_BRUSHFILL1,
	ITM_BRUSHFILL2,
	ITM_BRUSHFILL3,
	ITM_BRUSHFILL4,
	ITM_BRUSHFILL5,
	ITM_BRUSHFILL6,
	ITM_BRUSHFILL7,
	ITM_BRUSHFILL8,
	ITM_BRUSHFILL9,
	ITM_BRUSHFILL10,
	DRAW_ITEM_COUNT_RIGHTBRUSHFILL
};

enum PlayMenuItem //The items of the Play menu (you should add more items)
{
	//Note: Items are ordered here as they appear in menu
	//If you want to change the menu items order, change the order here

	///TODO: Add more items names here
	ITM_SCRAMBLE,
	ITM_FIND,
	ITEM_TODRAW,
	PLAY_ITM_COUNT
	//no. of menu items ==> This should be the last line in this enum
};


__declspec(selectany) //This line to prevent "redefinition error"

struct UI_Info	//User Interface Info.
{
	GUI_MODE InterfaceMode;

	int	width, height,	//Window width and height
		wx, wy,			//Window starting coordinates
		StatusBarHeight,	//Status Bar Height
		ToolBarHeight,		//Tool Bar Height (distance from top of window to bottom line of toolbar)
		ToolBarWidth,      // Tool Bar Width
		MenuItemHeight,  // menuitem icon height .. we defined it as 60
		MenuItemWidthLeft,		//Width of each item in toolbar menu
		MenuItemWidthRight,
		MenuItemWidthUp;

	color DrawColor;		//Drawing color
	color FillColor;		//Filling color
	color HighlightColor;	//Highlighting color
	color MsgColor;			//Messages color
	color BkGrndColor;		//Background color
	color StatusBarColor;	//Status bar color
	int PenWidth;			//width of the pen that draws shapes

							/// Add more members if needed

}UI;	//create a global object UI

#endif