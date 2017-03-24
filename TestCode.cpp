#include "GUI\Input.h"
#include "GUI\Output.h"
#include <iostream>
using namespace std;
//This is a test code to test the Input and Output classes

int main()
{
	int x, y;

	//Create Input and Output objects to test
	Output *pOut = new Output();;
	Input *pIn = pOut->CreateInput();

	//Starting the test
	pOut->PrintMessage("This demo is to test input and output classes, Click anywhere to start the test");
	pIn->GetPointClicked(x, y);	//Wait for any click


	///////////////////////////////////////////////////////////////////////////////////
	// TEST 1:	
	//			Create The FULL Tool bar, the drawing area and the status bar	
	//			This has already been done through the constrcutor of class Output
	///////////////////////////////////////////////////////////////////////////////////

	pOut->PrintMessage("TEST1: Drawing Tool bar and Status bar, Click anywhere to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click


	///////////////////////////////////////////////////////////////////////////////////
	// TEST 2:	
	//			Drawing all the Figures with all possible states: 
	//			Non-filled, Filled, and highlighted in both cases			
	///////////////////////////////////////////////////////////////////////////////////

	GfxInfo gfxInfo;//to be used with draw function of the class Ouput
	Point P1, P2, P3;

	pOut->PrintMessage("TEST2: Now we will show that Output class can draw any figure in any state, Click anywhere to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click

	/// 2.1- Rectangle Test ///
	/// =================== 
	pOut->PrintMessage("Drawing a Rectangle, filled/non-filled and Highlighted filled/non-filled,  Click to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click

	//2.1.1 - Drawing non-filled rectangle
	pOut->PrintMessage("Drawing a Rectangle ==> non-filled,  Click two points");
	pIn->GetPointClicked(P1.x, P1.y);
	pIn->GetPointClicked(P2.x, P2.y);

	gfxInfo.BorderWdth = 3;
	gfxInfo.DrawClr = BLACK;	//any color for border
	gfxInfo.isFilled = false;	//Figure is NOT filled
	pOut->DrawRect(P1, P2, gfxInfo, false);

	//2.1.2 - Drawing highlighted non-filled rectangle
	pOut->PrintMessage("Drawing a Rectangle ==> Highlighted non-filled, Click to Highlight");
	pIn->GetPointClicked(x, y);	//Wait for any click
	pOut->DrawRect(P1, P2, gfxInfo, true);


	//2.1.3 - Drawing a filled rectangle
	pOut->PrintMessage("Drawing a Rectangle ==> filled,  Click two points");
	pIn->GetPointClicked(P1.x, P1.y);
	pIn->GetPointClicked(P2.x, P2.y);

	gfxInfo.BorderWdth = 4;
	gfxInfo.DrawClr = BLUE;	//any color for border
	gfxInfo.FillClr = GREEN;//any color for filling
	gfxInfo.isFilled = true;//Figure is filled
	pOut->DrawRect(P1, P2, gfxInfo, false);


	//2.1.4 - Drawing a highlighted filled rectangle
	pOut->PrintMessage("Drawing a Rectangle ==> Highlighted filled, Click to Highlight");
	pIn->GetPointClicked(x, y);	//Wait for any click
	pOut->DrawRect(P1, P2, gfxInfo, true);



	pOut->PrintMessage("Drawing a Rectangle Test ==> OK,  Click anywhere to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click
	pOut->ClearDrawArea();

	///// 2.2- Line Test ///
	///// ============== 
	pOut->PrintMessage("Drawing a Line, normal and Highlighted, Click to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click

	///TODO: Add code to draw Line, Normal and Highlighted

	//Drawing non-highlighted line.
	pOut->PrintMessage("Drawing a Line, normal, click the two end points");
	pIn->GetPointClicked(P1.x, P1.y);
	pIn->GetPointClicked(P2.x, P2.y);

	gfxInfo.BorderWdth = 3;
	gfxInfo.DrawClr = BLACK;	//any color for border
	gfxInfo.isFilled = false;	//Figure is NOT filled
	pOut->DrawLine(P1, P2, gfxInfo, false);

	//Drawing a highlighted line.
	pOut->PrintMessage("Drawing a Line, highlighted, click anywhere");
	pIn->GetPointClicked(x, y);
	pOut->DrawLine(P1, P2, gfxInfo, true);

	pOut->PrintMessage("Drawing a Line Test ==> OK,  Click anywhere to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click
	pOut->ClearDrawArea();

	///2.3- Triangle Test ///
	///=================== 
	pOut->PrintMessage("Drawing a Triangle, filled/non-filled and Highlighted filled/non-filled,  Click to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click

	//Drawing non-filled, non-highlighted
	pOut->PrintMessage("Drawing a Triangle, normal, non-filled, Click to continue");
	pIn->GetPointClicked(x, y);

	pOut->PrintMessage("Click to position the three vertices of the triangle");
	pIn->GetPointClicked(P1.x, P1.y);
	pIn->GetPointClicked(P2.x, P2.y);
	pIn->GetPointClicked(P3.x, P3.y);

	gfxInfo.BorderWdth = 3;
	gfxInfo.DrawClr = BLACK;	//any color for border
	gfxInfo.isFilled = false;	//Figure is NOT filled

	pOut->DrawTriangle(P1, P2, P3, gfxInfo, false); //non-filled, non-highlighted

    //Drawing non-filled, highlighted
	pOut->PrintMessage("Drawing a Triangle, highlighted, non-filled, Click to continue");
	pIn->GetPointClicked(x, y);

	pOut->DrawTriangle(P1, P2, P3, gfxInfo, true);

	//Drawing filled, non-highlighted
	pOut->PrintMessage("Drawing a Triangle, normal, filled, Click to continue");
	pIn->GetPointClicked(x, y);

	pOut->PrintMessage("Click to position the three vertices of the triangle");
	pIn->GetPointClicked(P1.x, P1.y);
	pIn->GetPointClicked(P2.x, P2.y);
	pIn->GetPointClicked(P3.x, P3.y);

	gfxInfo.BorderWdth = 4;
	gfxInfo.DrawClr = BLUE;	//any color for border
	gfxInfo.FillClr = GREEN;//any color for filling
	gfxInfo.isFilled = true;//Figure is filled

	pOut->DrawTriangle(P1, P2, P3, gfxInfo, false);

	//Drawing filled, highlighted
	pOut->PrintMessage("Drawing a Triangle, Highlighted, filled, Click to continue");
	pIn->GetPointClicked(x, y);

	pOut->DrawTriangle(P1, P2, P3, gfxInfo, true);

	pOut->PrintMessage("Drawing a Triangle Test ==> OK,  Click anywhere to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click
	pOut->ClearDrawArea();

	/// 2.4- Circle Test ///
	/// =================== 
	pOut->PrintMessage("Drawing a Circle, filled/non-filled and Highlighted filled/non-filled,  Click to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click

	///TODO: Add code to draw Circle in all possible states
	//Drawing non-filled, non-highlighted
	pOut->PrintMessage("Drawing a Circle, normal, non-filled, Click to continue");
	pIn->GetPointClicked(x, y);

	pOut->PrintMessage("Drawing a Circle, normal, non-filled, click to position the center");
	pIn->GetPointClicked(P1.x, P1.y);

	gfxInfo.BorderWdth = 3;
	gfxInfo.DrawClr = BLACK;	//any color for border
	gfxInfo.isFilled = false;	//Figure is NOT filled

	pOut->DrawCircle(P1, 50, gfxInfo, false);

	//Drawing non-filled, highlighted
	pOut->PrintMessage("Drawing a Circle, highlighted, non-filled, click to highlight");
	pIn->GetPointClicked(x, y);

	pOut->DrawCircle(P1, 50, gfxInfo, true);

	//Drawing filled, non-highlighted
	pOut->PrintMessage("Drawing a Circle, normal, filled, click to position the center");
	pIn->GetPointClicked(P1.x, P1.y);

	gfxInfo.BorderWdth = 4;
	gfxInfo.DrawClr = BLUE;	//any color for border
	gfxInfo.FillClr = GREEN;//any color for filling
	gfxInfo.isFilled = true;//Figure is filled

	pOut->DrawCircle(P1, 70, gfxInfo, false);

	//Drawing filled highlighted.
	pOut->PrintMessage("Drawing a Circle, filled, highlighted, click to highlight");
	pIn->GetPointClicked(x,y);

	pOut->DrawCircle(P1, 70, gfxInfo, true);


	pOut->PrintMessage("Drawing a Circle Test ==> OK,  Click anywhere to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click
	pOut->ClearDrawArea();


	///////////////////////////////////////////////////////////////////////////////////
	// TEST 3: 
	//			Input Class: Read strings from the user
	///////////////////////////////////////////////////////////////////////////////////
	pOut->PrintMessage("TEST3: Now Time to test class Input, Click anywhere to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click

	pOut->PrintMessage("Testing Input ability to read strings");

	///TODO: Add code here to 
	// 1- Read a string from the user on the status bar
	// 2- After reading the string clear the status bar
	// 3- print on the status bar "You Entered" then print the string


	pIn->GetPointClicked(x, y);	//Wait for any click
	pOut->ClearDrawArea();

	///////////////////////////////////////////////////////////////////////////////////
	// TEST 4: 
	//			Input Class : Check for the user action
	///////////////////////////////////////////////////////////////////////////////////
	pOut->PrintMessage("TEST4: Testing Input ability to detect User Action, click anywhere");

	ActionType ActType;

	///TODO:  
	//You must add a case for each action (both Draw mode and Play mode actions)
	//Add cases for the missing actions below
	do
	{
		ActType = pIn->GetUserAction();

		switch (ActType)
		{

		case TO_PLAY:
			pOut->PrintMessage("Action: Switch to Play Mode, creating Design tool bar");
			pOut->CreatePlayToolBar();
			break;

			// The First Column //
		case  ITM_BRUSH1_Clicked:
			pOut->PrintMessage("Action: BRUSH 1 Clicked");
			break;

		case  ITM_BRUSH2_Clicked:
			pOut->PrintMessage("Action: BRUSH 2 Clicked");
			break;

		case  ITM_BRUSH3_Clicked:
			pOut->PrintMessage("Action: BRUSH 3 Clicked");
			break;

		case  ITM_BRUSH4_Clicked:
			pOut->PrintMessage("Action: BRUSH 4 Clicked");
			break;

		case  ITM_BRUSH5_Clicked:
			pOut->PrintMessage("Action: BRUSH 5 Clicked");
			break;

		case  ITM_BRUSH6_Clicked:
			pOut->PrintMessage("Action: BRUSH 6 Clicked");
			break;

		case  ITM_BRUSH7_Clicked:
			pOut->PrintMessage("Action: BRUSH 7 Clicked");
			break;

		case  ITM_BRUSH8_Clicked:
			pOut->PrintMessage("Action: BRUSH 8 Clicked");
			break;

		case  ITM_BRUSH9_Clicked:
			pOut->PrintMessage("Action: BRUSH 9 Clicked");
			break;

		case  ITM_BRUSH10_Clicked:
			pOut->PrintMessage("Action: BRUSH 10 Clicked");
			break;

		case ITM_COLLAPSELEFT_Clicked:
			pOut->PrintMessage("Action: Collapse Button Clicked");
			break;


			// The Second Column from left //
		case  ITM_BRUSHFILL1_Clicked:
			pOut->PrintMessage("Action: BRUSHFILL 1 Clicked");
			break;

		case  ITM_BRUSHFILL2_Clicked:
			pOut->PrintMessage("Action: BRUSHFILL 2 Clicked");
			break;

		case  ITM_BRUSHFILL3_Clicked:
			pOut->PrintMessage("Action: BRUSHFILL 3 Clicked");
			break;

		case  ITM_BRUSHFILL4_Clicked:
			pOut->PrintMessage("Action: BRUSHFILL 4 Clicked");
			break;

		case  ITM_BRUSHFILL5_Clicked:
			pOut->PrintMessage("Action: BRUSHFILL 5 Clicked");
			break;

		case  ITM_BRUSHFILL6_Clicked:
			pOut->PrintMessage("Action: BRUSHFILL 6 Clicked");
			break;

		case  ITM_BRUSHFILL7_Clicked:
			pOut->PrintMessage("Action: BRUSHFILL 7 Clicked");
			break;

		case  ITM_BRUSHFILL8_Clicked:
			pOut->PrintMessage("Action: BRUSHFILL 8 Clicked");
			break;

		case  ITM_BRUSHFILL9_Clicked:
			pOut->PrintMessage("Action: BRUSHFILL 9 Clicked");
			break;

		case  ITM_BRUSHFILL10_Clicked:
			pOut->PrintMessage("Action: BRUSHFILL 10 Clicked");
			break;

			//The Horizontal ITEMS //
		case DRAW_CIRC:
			pOut->PrintMessage("Action: Circule Button Clicked");
			break;

		case DRAW_RECT:
			pOut->PrintMessage("Action: Rectangle Button Clicked");
			break;

		case DRAW_TRI:
			pOut->PrintMessage("Action: Triangle Button Clicked");
			break;

		case DRAW_LINE:
			pOut->PrintMessage("Action: Line Button Clicked");
			break;

			//ZOOM ITEMS //
		case ITM_ZOOM_IN_Clicked:
			pOut->PrintMessage("Action: ZOOM IN Button Clicked");
			break;

		case ITM_ZOOM_OUT_Clicked:
			pOut->PrintMessage("Action: ZOOM OUT Button Clicked");
			break;

			// The RIGHT COLUMN ITEMS // 

		case ITM_RESIZE_Clicked:
			pOut->PrintMessage("Action: Resize Button Clicked");
			break;

		case ITM_COPY_Clicked:
			pOut->PrintMessage("Action: Copy Button Clicked");
			break;

		case ITM_MOVE_Clicked:
			pOut->PrintMessage("Action: Move Button Clicked");
			break;

		case ITM_CUT_Clicked:
			pOut->PrintMessage("Action: Cut Button Clicked");
			break;

		case ITM_PASTE_Clicked:
			pOut->PrintMessage("Action: Paste Button Clicked");
			break;

		case ITM_DELETE_Clicked:
			pOut->PrintMessage("Action: Delete Button Clicked");
			break;

		case ITM_UNDO_Clicked:
			pOut->PrintMessage("Action: Undo Button Clicked");
			break;

		case ITM_REDO_Clicked:
			pOut->PrintMessage("Action: Redo Button Clicked");
			break;

		case ITM_SELECT_Clicked:
			pOut->PrintMessage("Action: Select Button Clicked");
			break;

		case ITM_LOAD_Clicked:
			pOut->PrintMessage("Action: Load Button Clicked");
			break;

		case ITM_SAVE_Clicked:
			pOut->PrintMessage("Action: Save Button Clicked");
			break;

		case ITM_SAVEAS_Clicked:
			pOut->PrintMessage("Action: Save As Button Clicked");
			break;

		case ITM_COLLAPSERIGHT_Clicked:
			pOut->PrintMessage("Action: COLLAPSERIGHT Button Clicked");
			break;

			// GAME_MODE ICONS //
		case ITM_SCRAMBLE_Clicked:
			pOut->PrintMessage("Action: SCRAMBLE Button Clicked");
			break;

		case ITM_FIND_Clicked:
			pOut->PrintMessage("Action: FIND Button Clicked");
			break;

		case CHNG_DRAW_CLR:
			pOut->PrintMessage("Action: Change the drawing color , Click anywhere");
			break;

		case CHNG_FILL_CLR:
			pOut->PrintMessage("Action: Change background color , Click anywhere");
			break;

		case STATUS:
			pOut->PrintMessage("Action: a click on the Status Bar, Click anywhere");
			break;

		case DRAWING_AREA:
			pOut->PrintMessage("Action: a click on the Drawing Area, Click anywhere");
			break;

		case EMPTY:
			pOut->PrintMessage("Action: a click on empty area in the Design Tool Bar, Click anywhere");
			break;

		case TO_DRAW:
			pOut->PrintMessage("Action: Switch to Draw Mode, creating simualtion tool bar");
			pOut->CreateDrawToolBarLeft();
			pOut->CreateDrawToolBarUp();
			break;


		case EXIT:
			exit(0);
		}
	} while (ActType != EXIT);


	/// Exiting
	pOut->PrintMessage("Action: EXIT, test is finished, click anywhere to exit");
	pIn->GetPointClicked(x, y);


	delete pIn;
	delete pOut;
	return 0;
}