#ifndef UI_INFO_H
#define UI_INFO_H

#include "..\CMUgraphicsLib\CMUgraphics.h"

//User Interface information file.
//This file contains info that is needed by Input and Output classes to
//handle the user interface

enum GUI_MODE	//Graphical user interface mode
{
	MODE_DRAW,	//Drawing mode (startup mode)
	MODE_DRAW_SUB_MENU1,  //figure list
	MODE_DRAW_SUB_MENU2,  //pen collection
	MODE_DRAW_SUB_MENU3,  //brush collection
	MODE_DRAW_SUB_MENU4,  //background colors collection
	MODE_DRAW_SUB_MENU5,  //border width options
	MODE_DRAW_SUB_MENU6,  //resize options
	MODE_PLAY_SUB_MENU1,  // For ScrambleAndFind
	MODE_PLAY_SUB_MENU2,  // For PickAndHide
	MODE_PLAY_Choosing_Figure,
	MODE_PLAY_Choosing_Color,
	MODE_PLAY_Choosing_Size,

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

enum FigurelistIcons  //enumeration for icons on the upper menu
{
	ITM_CIRCLE ,
	ITM_RECTANGLE,
	ITM_TRIANGLE,
	ITM_LINE,
	FigurelistIcons_Count
};

enum DrawMenuItemRight
{
	ITM_FIGURE,
	ITM_PEN,
	ITM_BRUSH,
	ITM_BCKGCOLOR,
	STROKWIDTH,
	DRAW_LEFT_MENU_ITEMS_COUNT
};

enum DrawMenuItemRightPen  //enumeration for icons on the right menu
{
	ITM_PEN1,
	ITM_PEN2,
	ITM_PEN3,
	ITM_PEN4,
	ITM_PEN5,
	ITM_PEN6,
	ITM_PEN7,
	ITM_PEN8,
	ITM_PEN9,
	ITM_PEN10,
	DRAW_ITEM_COUNT_RIGHTPEN
};

enum DrawMenuItemRightBrush
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

enum DrawingAreaBackGroundColor
{
	ITM_BCKG_WHITE,
	ITM_BCKG_BLUE,
	ITM_BCKG_RED,
	ITM_BCKG_BROWN,
	ITM_BCKG_PINK,
	ITM_BCKG_NILE,
	ITM_BCKG_YELLOW,
	ITM_BCKG_ORANE,
	ITM_BCKG_PURPLE,
	ITM_BCKG_GREEN,
	BKCG_COLOR_COUNT
};

enum BorderWidthMenu
{
	ITM_BORDERWIDTH1,
	ITM_BORDERWIDTH2,
	ITM_BORDERWIDTH3,
	ITM_BORDERWIDTH4,
	BORDER_WIDTH_COUNT
};

enum ResizeControlsIcons
{
	ITM_RESIZE25,
	ITM_RESIZE50,
	ITM_RESIZE200,
	ITM_RESIZE400,
	RESIZE_CONTROLS_COUNT
};

enum PlayMenuItem //The items of the Play menu (you should add more items)
{
	//Note: Items are ordered here as they appear in menu
	//If you want to change the menu items order, change the order here

	///TODO: Add more items names here
	ITM_SCRAMBLEAndFind,
	ITM_PickAndHide,
	ITEM_TODRAW,
	PLAY_ITM_COUNT
	//no. of menu items ==> This should be the last line in this enum
};

enum PickAndHide
{
	ITM_BY_TYPE,
	ITM_BY_FILLCOL,
	ITM_BY_TYPE_AND_FILLCOL,
	ITM_BY_AREA,
	Pick_And_Hide_Menu_Count
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
	bool male;
	color DrawColor;		//Drawing color
	color FillColor;		//Filling color
	color HighlightColor;	//Highlighting color
	color MsgColor;			//Messages color
	color BkGrndColor;		//Background color
	color StatusBarColor;	//Status bar color
	int PenWidth;			//width of the pen that draws shapes
	double Ratio;
	bool isFilled;
	double Zoom;
	Point ZoomCenter;
	/// Add more members if needed

}UI;	//create a global object UI

#endif