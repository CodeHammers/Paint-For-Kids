#ifndef DEFS_H
#define DEFS_H

#include "CMUgraphicsLib\CMUgraphics.h"

//This file contais some global constants and definitions to be used in the project.
enum ActionType //The actions supported (you can add more if needed)
{
	// ITEMBRUSH BORDER // 
	ITM_BRUSH1_Clicked,
	ITM_BRUSH2_Clicked,
	ITM_BRUSH3_Clicked,
	ITM_BRUSH4_Clicked,
	ITM_BRUSH5_Clicked,
	ITM_BRUSH6_Clicked,
	ITM_BRUSH7_Clicked,
	ITM_BRUSH8_Clicked,
	ITM_BRUSH9_Clicked,
	ITM_BRUSH10_Clicked,
	ITM_BRUSH11_Clicked,
	ITM_COLLAPSELEFT_Clicked,

	// ITEM BRUSH FILL //
	ITM_BRUSHFILL1_Clicked,
	ITM_BRUSHFILL2_Clicked,
	ITM_BRUSHFILL3_Clicked,
	ITM_BRUSHFILL4_Clicked,
	ITM_BRUSHFILL5_Clicked,
	ITM_BRUSHFILL6_Clicked,
	ITM_BRUSHFILL7_Clicked,
	ITM_BRUSHFILL8_Clicked,
	ITM_BRUSHFILL10_Clicked,
	ITM_BRUSHFILL11_Clicked,

	// ZOOM ITEMS // 
	ITM_ZOOM_IN_Clicked,
	ITM_ZOOM_OUT_Clicked,


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
	DRAW_CIRC			//Draw Circle

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