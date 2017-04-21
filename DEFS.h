#ifndef DEFS_H
#define DEFS_H

#include "CMUgraphicsLib\CMUgraphics.h"

//This file contais some global constants and definitions to be used in the project.
enum ActionType //The actions supported (you can add more if needed)
{
	// ITEMBRUSH BORDER // 
	ITM_BRUSH_BLACK_Clicked,
	ITM_BRUSH_YELLOW_Clicked,
	ITM_BRUSH3_BLUE_Clicked,
	ITM_BRUSH_BROWN_Clicked,
	ITM_BRUSH_PINK_Clicked,
	ITM_BRUSH_GREEN_Clicked,
	ITM_BRUSH_NILE_Clicked,
	ITM_BRUSH_ORANGE_Clicked,
	ITM_BRUSH_PURPLE_Clicked,
	ITM_BRUSH_RED_Clicked,
	ITM_COLLAPSELEFT_Clicked,

	// ITEM BRUSH FILL //
	ITM_BRUSHFILL_BLACK_Clicked,
	ITM_BRUSHFILL_YELLOW_Clicked,
	ITM_BRUSHFILL_BLUE_Clicked,
	ITM_BRUSHFILL_BROWN_Clicked,
	ITM_BRUSHFILL_PINK_Clicked,
	ITM_BRUSHFILL_GREEN_Clicked,
	ITM_BRUSHFILL_NILE_Clicked,
	ITM_BRUSHFILL_ORANGE_Clicked,
	ITM_BRUSHFILL_PURPLE_Clicked,
	ITM_BRUSHFILL_RED_Clicked,

	// ZOOM ITEMS // 
	ITM_ZOOM_IN_Clicked,
	ITM_ZOOM_OUT_Clicked,

	MODE_DRAW_SUB_MENU1_Clicked,
	MODE_DRAW_SUB_MENU2_Clicked,
	MODE_DRAW_SUB_MENU3_Clicked,
	MODE_DRAW_SUB_MENU4_Clicked,
	MODE_DRAW_SUB_MENU5_Clicked,
	MODE_DRAW_SUB_MENU6_Clicked,



	ITM_BCKG_WHITE_Clicked,
	ITM_BCKG_BLUE_Clicked,
	ITM_BCKG_RED_Clicked,
	ITM_BCKG_BROWN_Clicked,
	ITM_BCKG_PINK_Clicked,
	ITM_BCKG_NILE_Clicked,
	ITM_BCKG_YELLOW_Clicked,
	ITM_BCKG_ORANE_Clicked,
	ITM_BCKG_PURPLE_Clicked,
	ITM_BCKG_GREEN_Clicked,



	ITM_BORDERWIDTH1_Clicked,
	ITM_BORDERWIDTH2_Clicked,
	ITM_BORDERWIDTH3_Clicked,
	ITM_BORDERWIDTH4_Clicked,


	ITM_RESIZE25_Clicked,
	ITM_RESIZE50_Clicked,
	ITM_RESIZE200_Clicked,
	ITM_RESIZE400_Clicked,


	// RIGHT COLUMN CLICKED //
	ITM_RESIZE_Clicked,
	ITM_MOVE_Clicked,
	ITM_COPY_Clicked,
	ITM_CUT_Clicked,
	ITM_PASTE_Clicked,
	ITM_DELETE_Clicked,
	ITM_UNDO_Clicked,
	ITM_REDO_Clicked,
	ITM_SELECT_Clicked,
	ITM_LOAD_Clicked,
	ITM_SAVE_Clicked,
	ITM_SAVEAS_Clicked,
	ITM_COLLAPSERIGHT_Clicked,

	// GAME MODE ITEMS \\

	ITM_SCRAMBLE_Clicked,
	ITM_FIND_Clicked,
	ITEM_TODRAW_Clicked,



	CHNG_DRAW_CLR,	//Change the drawing color
	CHNG_FILL_CLR,	//Change the filling color
	CHNG_BK_CLR,	//Change background color
	DEL,			//Delete a figure(s)
	MOVE,			//Move a figure(s)
	RESIZE,			//Resize a figure(s)
	ROTATE,			//Rotate a figure(s)
	SEND_BACK,		//Send a figure to the back of all figures
	BRNG_FRNT,		//Bring a figure to the front of all figures
	SAVE,			//Save the whole graph to a file
	LOAD,			//Load a graph from a file
	EXIT,			//Exit the application

	DRAWING_AREA,	//A click on the drawing area
	STATUS,			//A click on the status bar
	EMPTY,			//A click on empty place in the toolbar

	TO_PLAY,			//Switch interface to Play mode
	TO_DRAW,			//Switch interface to Draw mode
	DRAW_LINE,		//Draw Line
	DRAW_RECT,		//Draw Rectangle
	DRAW_TRI,			//Draw Triangle
	DRAW_CIRC,			//Draw Circle
		
						///TODO: Add more action types (if needed)
};

struct Point	//To be used for figures points
{
	int x, y;
};

struct GfxInfo	//Graphical info of each figure (you may add more members)
{
	color DrawClr;	//Draw color of the figure
	color FillClr;	//Fill color of the figure
	bool isFilled;	//Figure Filled or not
	int BorderWdth;	//Width of figure borders

};

#endif