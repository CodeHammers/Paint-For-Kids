//
//#include "GUI\Input.h"
//#include "GUI\Output.h"
//#include <iostream>
//using namespace std;
////This is a test code to test the Input and Output classes
//
//int main()
//{
//	int x, y;
//
//	//Create Input and Output objects to test
//	Output *pOut = new Output();;
//	Input *pIn = pOut->CreateInput();
//
//	//Starting the test
//	pOut->PrintMessage("This demo is to test input and output classes, Click anywhere to start the test");
//	pIn->GetPointClicked(x, y);	//Wait for any click
//
//
//
//								///////////////////////////////////////////////////////////////////////////////////
//								// TEST 1:	
//								//			Create The FULL Tool bar, the drawing area and the status bar	
//								//			This has already been done through the constrcutor of class Output
//								///////////////////////////////////////////////////////////////////////////////////
//
//	pOut->PrintMessage("TEST1: Drawing Tool bar and Status bar, Click anywhere to continue");
//	pIn->GetPointClicked(x, y);	//Wait for any click
//
//	/*
//								///////////////////////////////////////////////////////////////////////////////////
//								// TEST 2:	
//								//			Drawing all the Figures with all possible states: 
//								//			Non-filled, Filled, and highlighted in both cases			
//								///////////////////////////////////////////////////////////////////////////////////
//
//	GfxInfo gfxInfo;//to be used with draw function of the class Ouput
//	Point P1, P2, P3;
//
//	pOut->PrintMessage("TEST2: Now we will show that Output class can draw any figure in any state, Click anywhere to continue");
//	pIn->GetPointClicked(x, y);	//Wait for any click
//
//								/// 2.1- Rectangle Test ///
//								/// =================== 
//	pOut->PrintMessage("Drawing a Rectangle, filled/non-filled and Highlighted filled/non-filled,  Click to continue");
//	pIn->GetPointClicked(x, y);	//Wait for any click
//
//								//2.1.1 - Drawing non-filled rectangle
//	pOut->PrintMessage("Drawing a Rectangle ==> non-filled,  Click two points");
//	pIn->GetPointClicked(P1.x, P1.y);
//	pIn->GetPointClicked(P2.x, P2.y);
//
//	gfxInfo.BorderWdth = 3;
//	gfxInfo.DrawClr = BLACK;	//any color for border
//	gfxInfo.isFilled = false;	//Figure is NOT filled
//	pOut->DrawRect(P1, P2, gfxInfo, false);
//
//	//2.1.2 - Drawing highlighted non-filled rectangle
//	pOut->PrintMessage("Drawing a Rectangle ==> Highlighted non-filled, Click to Highlight");
//	pIn->GetPointClicked(x, y);	//Wait for any click
//	pOut->DrawRect(P1, P2, gfxInfo, true);
//
//
//	//2.1.3 - Drawing a filled rectangle
//	pOut->PrintMessage("Drawing a Rectangle ==> filled,  Click two points");
//	pIn->GetPointClicked(P1.x, P1.y);
//	pIn->GetPointClicked(P2.x, P2.y);
//
//	gfxInfo.BorderWdth = 4;
//	gfxInfo.DrawClr = BLUE;	//any color for border
//	gfxInfo.FillClr = GREEN;//any color for filling
//	gfxInfo.isFilled = true;//Figure is filled
//	pOut->DrawRect(P1, P2, gfxInfo, false);
//
//
//	//2.1.4 - Drawing a highlighted filled rectangle
//	pOut->PrintMessage("Drawing a Rectangle ==> Highlighted filled, Click to Highlight");
//	pIn->GetPointClicked(x, y);	//Wait for any click
//	pOut->DrawRect(P1, P2, gfxInfo, true);
//
//
//	pOut->PrintMessage("Drawing a Rectangle Test ==> OK,  Click anywhere to continue");
//	pIn->GetPointClicked(x, y);	//Wait for any click
//	pOut->ClearDrawArea();
//
//	///// 2.2- Line Test ///
//	///// ============== 
//	pOut->PrintMessage("Drawing a Line, normal and Highlighted, Click to continue");
//	pIn->GetPointClicked(x, y);	//Wait for any click
//
//								///TODO: Add code to draw Line, Normal and Highlighted
//
//								//Drawing non-highlighted line.
//	pOut->PrintMessage("Drawing a Line, normal, click the two end points");
//	pIn->GetPointClicked(P1.x, P1.y);
//	pIn->GetPointClicked(P2.x, P2.y);
//
//	gfxInfo.BorderWdth = 3;
//	gfxInfo.DrawClr = BLACK;	//any color for border
//	gfxInfo.isFilled = false;	//Figure is NOT filled
//	pOut->DrawLine(P1, P2, gfxInfo, false);
//
//	//Drawing a highlighted line.
//	pOut->PrintMessage("Drawing a Line, highlighted, click anywhere");
//	pIn->GetPointClicked(x, y);
//	pOut->DrawLine(P1, P2, gfxInfo, true);
//
//	pOut->PrintMessage("Drawing a Line Test ==> OK,  Click anywhere to continue");
//	pIn->GetPointClicked(x, y);	//Wait for any click
//	pOut->ClearDrawArea();
//
//	///2.3- Triangle Test ///
//	///=================== 
//	pOut->PrintMessage("Drawing a Triangle, filled/non-filled and Highlighted filled/non-filled,  Click to continue");
//	pIn->GetPointClicked(x, y);	//Wait for any click
//
//								//Drawing non-filled, non-highlighted
//	pOut->PrintMessage("Drawing a Triangle, normal, non-filled, Click to continue");
//	pIn->GetPointClicked(x, y);
//
//	pOut->PrintMessage("Click to position the three vertices of the triangle");
//	pIn->GetPointClicked(P1.x, P1.y);
//	pIn->GetPointClicked(P2.x, P2.y);
//	pIn->GetPointClicked(P3.x, P3.y);
//
//	gfxInfo.BorderWdth = 3;
//	gfxInfo.DrawClr = BLACK;	//any color for border
//	gfxInfo.isFilled = false;	//Figure is NOT filled
//
//	pOut->DrawTriangle(P1, P2, P3, gfxInfo, false); //non-filled, non-highlighted
//
//													//Drawing non-filled, highlighted
//	pOut->PrintMessage("Drawing a Triangle, highlighted, non-filled, Click to continue");
//	pIn->GetPointClicked(x, y);
//
//	pOut->DrawTriangle(P1, P2, P3, gfxInfo, true);
//
//	//Drawing filled, non-highlighted
//	pOut->PrintMessage("Drawing a Triangle, normal, filled, Click to continue");
//	pIn->GetPointClicked(x, y);
//
//	pOut->PrintMessage("Click to position the three vertices of the triangle");
//	pIn->GetPointClicked(P1.x, P1.y);
//	pIn->GetPointClicked(P2.x, P2.y);
//	pIn->GetPointClicked(P3.x, P3.y);
//
//	gfxInfo.BorderWdth = 4;
//	gfxInfo.DrawClr = BLUE;	//any color for border
//	gfxInfo.FillClr = GREEN;//any color for filling
//	gfxInfo.isFilled = true;//Figure is filled
//
//	pOut->DrawTriangle(P1, P2, P3, gfxInfo, false);
//
//	//Drawing filled, highlighted
//	pOut->PrintMessage("Drawing a Triangle, Highlighted, filled, Click to continue");
//	pIn->GetPointClicked(x, y);
//
//	pOut->DrawTriangle(P1, P2, P3, gfxInfo, true);
//
//	pOut->PrintMessage("Drawing a Triangle Test ==> OK,  Click anywhere to continue");
//	pIn->GetPointClicked(x, y);	//Wait for any click
//	pOut->ClearDrawArea();
//
//	/// 2.4- Circle Test ///
//	/// =================== 
//	pOut->PrintMessage("Drawing a Circle, filled/non-filled and Highlighted filled/non-filled,  Click to continue");
//	pIn->GetPointClicked(x, y);	//Wait for any click
//
//								///TODO: Add code to draw Circle in all possible states
//								//Drawing non-filled, non-highlighted
//	pOut->PrintMessage("Drawing a Circle, normal, non-filled, Click to continue");
//	pIn->GetPointClicked(x, y);
//
//	pOut->PrintMessage("Drawing a Circle, normal, non-filled, click to position the center");
//	pIn->GetPointClicked(P1.x, P1.y);
//
//	pOut->PrintMessage("Drawing a Circle, normal, filled, click to position the end point of the radius");
//	pIn->GetPointClicked(P2.x, P2.y);
//
//	//calculate the radius
//	int dist = sqrt(pow(P1.x - P2.x, 2) + pow(P1.y - P2.y, 2));
//
//	gfxInfo.BorderWdth = 3;
//	gfxInfo.DrawClr = BLACK;	//any color for border
//	gfxInfo.isFilled = false;	//Figure is NOT filled
//
//	pOut->DrawCircle(P1, dist, gfxInfo, false);
//
//	//Drawing non-filled, highlighted
//	pOut->PrintMessage("Drawing a Circle, highlighted, non-filled, click to highlight");
//	pIn->GetPointClicked(x, y);
//
//	pOut->DrawCircle(P1, dist, gfxInfo, true);
//
//	//Drawing filled, non-highlighted
//	pOut->PrintMessage("Drawing a Circle, normal, filled, click to position the center");
//	pIn->GetPointClicked(P1.x, P1.y);
//
//	pOut->PrintMessage("Drawing a Circle, normal, filled, click to position the end point of the radius");
//	pIn->GetPointClicked(P2.x, P2.y);
//
//	//calculate the radius
//	dist = sqrt(pow(P1.x - P2.x, 2) + pow(P1.y - P2.y, 2));
//
//	gfxInfo.BorderWdth = 4;
//	gfxInfo.DrawClr = BLUE;	//any color for border
//	gfxInfo.FillClr = GREEN;//any color for filling
//	gfxInfo.isFilled = true;//Figure is filled
//
//	pOut->DrawCircle(P1, dist, gfxInfo, false);
//
//	//Drawing filled highlighted.
//	pOut->PrintMessage("Drawing a Circle, filled, highlighted, click to highlight");
//	pIn->GetPointClicked(x, y);
//
//	pOut->DrawCircle(P1, dist, gfxInfo, true);
//
//	pOut->PrintMessage("Drawing a Circle Test ==> OK,  Click anywhere to continue");
//	pIn->GetPointClicked(x, y);	//Wait for any click
//	pOut->ClearDrawArea();
//
//
//	///////////////////////////////////////////////////////////////////////////////////
//	// TEST 3: 
//	//			Input Class: Read strings from the user
//	///////////////////////////////////////////////////////////////////////////////////
//	pOut->PrintMessage("TEST3: Now Time to test class Input, Click anywhere to continue");
//	pIn->GetPointClicked(x, y);	//Wait for any click
//
//	pOut->PrintMessage("Testing Input ability to read strings");
//	pIn->GetPointClicked(x, y);	//Wait for any click
//
//	pOut->PrintMessage("Testing the ability to read strings, enter your name");
//	string name = pIn->GetSrting(pOut);
//
//	pOut->PrintMessage("Hello!, " + name + " ,Click anywhere to continue");
//	pIn->GetPointClicked(x, y);	//Wait for any click
//
//	pOut->ClearDrawArea();
//	*/
//	///////////////////////////////////////////////////////////////////////////////////
//	// TEST 4: 
//	//			Input Class : Check for the user action
//	///////////////////////////////////////////////////////////////////////////////////
//	pOut->PrintMessage("TEST4: Testing Input ability to detect User Action, click anywhere");
//
//	ActionType ActType;
//
//	///TODO:  
//	//You must add a case for each action (both Draw mode and Play mode actions)
//	//Add cases for the missing actions below
//	do
//	{
//		ActType = pIn->GetUserAction();
//
//		switch (ActType)
//		{
//
//			
//
//
//		case ITM_BCKG_WHITE_Clicked:
//			pOut->PrintMessage("Action: BackGround  WHITE");
//			UI.InterfaceMode = MODE_DRAW;
//			pOut->CreateDrawToolBarUp(4, true);
//			break;
//
//		case ITM_BCKG_BLUE_Clicked:
//			pOut->PrintMessage("Action: BackGround BLUE");
//			UI.InterfaceMode = MODE_DRAW;
//			pOut->CreateDrawToolBarUp(4, true);
//			break;
//
//		case ITM_BCKG_RED_Clicked:
//			pOut->PrintMessage("Action: BackGround  RED");
//			UI.InterfaceMode = MODE_DRAW;
//			pOut->CreateDrawToolBarUp(4, true);
//			break;
//
//
//		case ITM_BCKG_BROWN_Clicked:
//			pOut->PrintMessage("Action: BackGround  BROWN");
//			UI.InterfaceMode = MODE_DRAW;
//			pOut->CreateDrawToolBarUp(4, true);
//			break;
//
//
//		case ITM_BCKG_PINK_Clicked:
//			pOut->PrintMessage("Action: BackGround  PINK");
//			UI.InterfaceMode = MODE_DRAW;
//			pOut->CreateDrawToolBarUp(4, true);
//			break;
//
//
//		case ITM_BCKG_NILE_Clicked:
//			pOut->PrintMessage("Action: BackGround  NILE");
//			UI.InterfaceMode = MODE_DRAW;
//			pOut->CreateDrawToolBarUp(4, true);
//			break;
//
//		case ITM_BCKG_YELLOW_Clicked:
//			pOut->PrintMessage("Action: BackGround  YELLOW");
//			UI.InterfaceMode = MODE_DRAW;
//			pOut->CreateDrawToolBarUp(4, true);
//			break;
//
//		case ITM_BCKG_ORANE_Clicked:
//			pOut->PrintMessage("Action: BackGround  ORANGE");
//			UI.InterfaceMode = MODE_DRAW;
//			pOut->CreateDrawToolBarUp(4, true);
//			break;
//
//
//		case ITM_BCKG_PURPLE_Clicked:
//			pOut->PrintMessage("Action: BackGround  PURPLE");
//			UI.InterfaceMode = MODE_DRAW;
//			pOut->CreateDrawToolBarUp(4, true);
//			break;
//
//
//		case ITM_BCKG_GREEN_Clicked:
//			pOut->PrintMessage("Action: BackGround  GREEN");
//			UI.InterfaceMode = MODE_DRAW;
//			pOut->CreateDrawToolBarUp(4, true);
//			break;
//			
//
//			// ... // 
//
//		case ITM_BORDERWIDTH1_Clicked:
//			pOut->PrintMessage("Action: Smallest Border Width Clicked");
//			UI.InterfaceMode = MODE_DRAW;
//			pOut->CreateDrawToolBarUp(5, true);
//			break;
//
//		case ITM_BORDERWIDTH2_Clicked:
//			pOut->PrintMessage("Action: Above Smallest Border Width Clicked");
//			UI.InterfaceMode = MODE_DRAW;
//			pOut->CreateDrawToolBarUp(5, true);
//			break;
//
//
//		case ITM_BORDERWIDTH3_Clicked:
//			pOut->PrintMessage("Action: Medium Border Width Clicked");
//			UI.InterfaceMode = MODE_DRAW;
//			pOut->CreateDrawToolBarUp(5, true);
//			break;
//
//
//		case ITM_BORDERWIDTH4_Clicked:
//			pOut->PrintMessage("Action: Greatest Border Width Clicked");
//			UI.InterfaceMode = MODE_DRAW;
//			pOut->CreateDrawToolBarUp(5, true);
//			break;
//
//			// .. // 
//
//		case MODE_DRAW_SUB_MENU1_Clicked:
//			pOut->PrintMessage("Action: Choose your Figure");
//
//			if (UI.InterfaceMode == MODE_DRAW_SUB_MENU1)
//				break;
//			else if (UI.InterfaceMode == MODE_DRAW_SUB_MENU2)
//				pOut->CreateDrawToolBarUp(2, true);
//			else if (UI.InterfaceMode == MODE_DRAW_SUB_MENU3)
//				pOut->CreateDrawToolBarUp(3, true);
//			else if (UI.InterfaceMode == MODE_DRAW_SUB_MENU4)
//				pOut->CreateDrawToolBarUp(4, true);
//			else if (UI.InterfaceMode == MODE_DRAW_SUB_MENU5)
//				pOut->CreateDrawToolBarUp(5, true);
//			else if (UI.InterfaceMode == MODE_DRAW_SUB_MENU6)
//				pOut->CreateDrawToolBarUp(6, true);
//
//			UI.InterfaceMode = MODE_DRAW_SUB_MENU1;
//			pOut->CreateDrawToolBarUp(1, false);
//			break;
//
//		case MODE_DRAW_SUB_MENU2_Clicked:
//			pOut->PrintMessage("Action: Choose Your Color");
//			if (UI.InterfaceMode == MODE_DRAW_SUB_MENU1)
//				pOut->CreateDrawToolBarUp(1, true);
//			else if (UI.InterfaceMode == MODE_DRAW_SUB_MENU2)
//				break;
//			else if (UI.InterfaceMode == MODE_DRAW_SUB_MENU3)
//				pOut->CreateDrawToolBarUp(3, true);
//			else if (UI.InterfaceMode == MODE_DRAW_SUB_MENU4)
//				pOut->CreateDrawToolBarUp(4, true);
//			else if (UI.InterfaceMode == MODE_DRAW_SUB_MENU5)
//				pOut->CreateDrawToolBarUp(5, true);
//			else if (UI.InterfaceMode == MODE_DRAW_SUB_MENU6)
//				pOut->CreateDrawToolBarUp(6, true);
//
//			UI.InterfaceMode = MODE_DRAW_SUB_MENU2;
//			pOut->CreateDrawToolBarUp(2, false);
//			break;
//
//		case MODE_DRAW_SUB_MENU3_Clicked:
//			pOut->PrintMessage("Action: Choose Your Color");
//			if (UI.InterfaceMode == MODE_DRAW_SUB_MENU1)
//				pOut->CreateDrawToolBarUp(1, true);
//			else if (UI.InterfaceMode == MODE_DRAW_SUB_MENU2)
//				pOut->CreateDrawToolBarUp(2, true);
//			else if (UI.InterfaceMode == MODE_DRAW_SUB_MENU3)
//				break;
//			else if (UI.InterfaceMode == MODE_DRAW_SUB_MENU4)
//				pOut->CreateDrawToolBarUp(4, true);
//			else if (UI.InterfaceMode == MODE_DRAW_SUB_MENU5)
//				pOut->CreateDrawToolBarUp(5, true);
//			else if (UI.InterfaceMode == MODE_DRAW_SUB_MENU6)
//				pOut->CreateDrawToolBarUp(6, true);
//			UI.InterfaceMode = MODE_DRAW_SUB_MENU3;
//			pOut->CreateDrawToolBarUp(3, false);
//			break;
//
//		case MODE_DRAW_SUB_MENU4_Clicked:
//			pOut->PrintMessage("Action: Choose Your Color");
//			if (UI.InterfaceMode == MODE_DRAW_SUB_MENU1)
//				pOut->CreateDrawToolBarUp(1, true);
//			else if (UI.InterfaceMode == MODE_DRAW_SUB_MENU2)
//				pOut->CreateDrawToolBarUp(2, true);
//			else if (UI.InterfaceMode == MODE_DRAW_SUB_MENU3)
//				pOut->CreateDrawToolBarUp(3, true);
//			else if (UI.InterfaceMode == MODE_DRAW_SUB_MENU4)
//				break;
//			else if (UI.InterfaceMode == MODE_DRAW_SUB_MENU5)
//				pOut->CreateDrawToolBarUp(5, true);
//			else if (UI.InterfaceMode == MODE_DRAW_SUB_MENU6)
//				pOut->CreateDrawToolBarUp(6, true);
//			UI.InterfaceMode = MODE_DRAW_SUB_MENU4;
//			pOut->CreateDrawToolBarUp(4, false);
//			break;
//
//		case MODE_DRAW_SUB_MENU5_Clicked:
//			pOut->PrintMessage("Action: Choose your border size");
//			if (UI.InterfaceMode == MODE_DRAW_SUB_MENU1)
//				pOut->CreateDrawToolBarUp(1, true);
//			else if (UI.InterfaceMode == MODE_DRAW_SUB_MENU2)
//				pOut->CreateDrawToolBarUp(2, true);
//			else if (UI.InterfaceMode == MODE_DRAW_SUB_MENU3)
//				pOut->CreateDrawToolBarUp(3, true);
//			else if (UI.InterfaceMode == MODE_DRAW_SUB_MENU4)
//				pOut->CreateDrawToolBarUp(4, true);
//			else if (UI.InterfaceMode == MODE_DRAW_SUB_MENU5)
//				break;
//			else if (UI.InterfaceMode == MODE_DRAW_SUB_MENU6)
//				pOut->CreateDrawToolBarUp(6, true);
//			UI.InterfaceMode = MODE_DRAW_SUB_MENU5;
//			pOut->CreateDrawToolBarUp(5, false);
//			break;
//
//			
//
//			// .. // 
//
//		case TO_PLAY:
//			pOut->PrintMessage("Action: Switch to Play Mode, creating Design tool bar");
//			pOut->CreatePlayToolBar();
//			break;
//
//			// The First Column //
//		case  ITM_BRUSH_BLACK_Clicked:
//			pOut->PrintMessage("Action: BRUSH BLACK Clicked");
//			UI.InterfaceMode = MODE_DRAW;
//			pOut->CreateDrawToolBarUp(2, true);
//			break;
//
//		case  ITM_BRUSH_YELLOW_Clicked:
//			pOut->PrintMessage("Action: BRUSH YELLOW Clicked");
//			UI.InterfaceMode = MODE_DRAW;
//			pOut->CreateDrawToolBarUp(2, true);
//			break;
//
//		case  ITM_BRUSH3_BLUE_Clicked:
//			pOut->PrintMessage("Action: BRUSH BLUE Clicked");
//			UI.InterfaceMode = MODE_DRAW;
//			pOut->CreateDrawToolBarUp(2, true);
//			break;
//
//		case  ITM_BRUSH_BROWN_Clicked:
//			pOut->PrintMessage("Action: BRUSH BROWN Clicked");
//			UI.InterfaceMode = MODE_DRAW;
//			pOut->CreateDrawToolBarUp(2, true);
//			break;
//
//		case  ITM_BRUSH_PINK_Clicked:
//			pOut->PrintMessage("Action: BRUSH PINK Clicked");
//			UI.InterfaceMode = MODE_DRAW;
//			pOut->CreateDrawToolBarUp(2, true);
//			break;
//
//		case  ITM_BRUSH_GREEN_Clicked:
//			pOut->PrintMessage("Action: BRUSH GREEN Clicked");
//			UI.InterfaceMode = MODE_DRAW;
//			pOut->CreateDrawToolBarUp(2, true);
//			break;
//
//		case  ITM_BRUSH_NILE_Clicked:
//			pOut->PrintMessage("Action: BRUSH NILE Clicked");
//			UI.InterfaceMode = MODE_DRAW;
//			pOut->CreateDrawToolBarUp(2, true);
//			break;
//
//		case  ITM_BRUSH_ORANGE_Clicked:
//			pOut->PrintMessage("Action: BRUSH ORANGE Clicked");
//			UI.InterfaceMode = MODE_DRAW;
//			pOut->CreateDrawToolBarUp(2, true);
//			break;
//
//		case  ITM_BRUSH_PURPLE_Clicked:
//			pOut->PrintMessage("Action: BRUSH PURPLE Clicked");
//			UI.InterfaceMode = MODE_DRAW;
//			pOut->CreateDrawToolBarUp(2, true);
//			break;
//
//		case  ITM_BRUSH_RED_Clicked:
//			pOut->PrintMessage("Action: BRUSH RED Clicked");
//			UI.InterfaceMode = MODE_DRAW;
//			pOut->CreateDrawToolBarUp(2, true);
//			break;
//
//
//			// The Second Column from left //
//		case  ITM_BRUSHFILL_BLACK_Clicked:
//			pOut->PrintMessage("Action: BRUSHFILL BLACK Clicked");
//			UI.InterfaceMode = MODE_DRAW;
//			pOut->CreateDrawToolBarUp(3, true);
//			break;
//
//		case  ITM_BRUSHFILL_YELLOW_Clicked:
//			pOut->PrintMessage("Action: BRUSHFILL YELLOW Clicked");
//			UI.InterfaceMode = MODE_DRAW;
//			pOut->CreateDrawToolBarUp(3, true);
//			break;
//
//		case  ITM_BRUSHFILL_BLUE_Clicked:
//			pOut->PrintMessage("Action: BRUSHFILL BLUE Clicked");
//			UI.InterfaceMode = MODE_DRAW;
//			pOut->CreateDrawToolBarUp(3, true);
//			break;
//
//		case  ITM_BRUSHFILL_BROWN_Clicked:
//			pOut->PrintMessage("Action: BRUSHFILL BROWN Clicked");
//			UI.InterfaceMode = MODE_DRAW;
//			pOut->CreateDrawToolBarUp(3, true);
//			break;
//
//		case  ITM_BRUSHFILL_PINK_Clicked:
//			pOut->PrintMessage("Action: BRUSHFILL PINK Clicked");
//			UI.InterfaceMode = MODE_DRAW;
//			pOut->CreateDrawToolBarUp(3, true);
//			break;
//
//		case  ITM_BRUSHFILL_GREEN_Clicked:
//			pOut->PrintMessage("Action: BRUSHFILL GREEN Clicked");
//			UI.InterfaceMode = MODE_DRAW;
//			pOut->CreateDrawToolBarUp(3, true);
//			break;
//
//		case  ITM_BRUSHFILL_NILE_Clicked:
//			pOut->PrintMessage("Action: BRUSHFILL NILE Clicked");
//			UI.InterfaceMode = MODE_DRAW;
//			pOut->CreateDrawToolBarUp(3, true);
//			break;
//
//		case  ITM_BRUSHFILL_ORANGE_Clicked:
//			pOut->PrintMessage("Action: BRUSHFILL ORANGE Clicked");
//			UI.InterfaceMode = MODE_DRAW;
//			pOut->CreateDrawToolBarUp(3, true);
//			break;
//
//		case  ITM_BRUSHFILL_PURPLE_Clicked:
//			pOut->PrintMessage("Action: BRUSHFILL PURPLE Clicked");
//			UI.InterfaceMode = MODE_DRAW;
//			pOut->CreateDrawToolBarUp(3, true);
//			break;
//
//		case  ITM_BRUSHFILL_RED_Clicked:
//			pOut->PrintMessage("Action: BRUSHFILL RED Clicked");
//			UI.InterfaceMode = MODE_DRAW;
//			pOut->CreateDrawToolBarUp(3, true);
//			break;
//
//			//The Horizontal ITEMS //
//
//		case DRAW_CIRC:
//			pOut->PrintMessage("Action: Circule Button Clicked");
//			UI.InterfaceMode = MODE_DRAW;
//			pOut->CreateDrawToolBarUp(1, true);
//			break;
//
//		case DRAW_RECT:
//			pOut->PrintMessage("Action: Rectangle Button Clicked");
//			UI.InterfaceMode = MODE_DRAW;
//			pOut->CreateDrawToolBarUp(1, true);
//			break;
//
//		case DRAW_TRI:
//			pOut->PrintMessage("Action: Triangle Button Clicked");
//			UI.InterfaceMode = MODE_DRAW;
//			pOut->CreateDrawToolBarUp(1, true);
//			break;
//
//		case DRAW_LINE:
//			pOut->PrintMessage("Action: Line Button Clicked");
//			UI.InterfaceMode = MODE_DRAW;
//			pOut->CreateDrawToolBarUp(1, true);
//			break;
//
//			// .. // 
//		case ITM_RESIZE25_Clicked:
//			pOut->PrintMessage("Action: Resize By 25 %");
//			UI.InterfaceMode = MODE_DRAW;
//			pOut->CreateDrawToolBarUp(6, true);
//			break;
//
//		case ITM_RESIZE50_Clicked:
//			pOut->PrintMessage("Action: Resize By 50 %");
//			UI.InterfaceMode = MODE_DRAW;
//			pOut->CreateDrawToolBarUp(6, true);
//			break;
//
//		case ITM_RESIZE200_Clicked:
//			pOut->PrintMessage("Action: Resize By 200 %");
//			UI.InterfaceMode = MODE_DRAW;
//			pOut->CreateDrawToolBarUp(6, true);
//			break;
//
//		case ITM_RESIZE400_Clicked:
//			pOut->PrintMessage("Action: Resize By 400 %");
//			UI.InterfaceMode = MODE_DRAW;
//			pOut->CreateDrawToolBarUp(6, true);
//			break;
//
//
//			//ZOOM ITEMS //
//		case ITM_ZOOM_IN_Clicked:
//			pOut->PrintMessage("Action: ZOOM IN Button Clicked");
//			if (UI.InterfaceMode == MODE_DRAW_SUB_MENU1)
//				pOut->CreateDrawToolBarUp(1, true);
//			else if (UI.InterfaceMode == MODE_DRAW_SUB_MENU2)
//				pOut->CreateDrawToolBarUp(2, true);
//			else if (UI.InterfaceMode == MODE_DRAW_SUB_MENU3)
//				pOut->CreateDrawToolBarUp(3, true);
//			else if (UI.InterfaceMode == MODE_DRAW_SUB_MENU4)
//				pOut->CreateDrawToolBarUp(4, true);
//			else if (UI.InterfaceMode == MODE_DRAW_SUB_MENU5)
//				pOut->CreateDrawToolBarUp(5, true);
//			else if (UI.InterfaceMode == MODE_DRAW_SUB_MENU6)
//				pOut->CreateDrawToolBarUp(6, true);
//
//			UI.InterfaceMode = MODE_DRAW;
//			break;
//
//		case ITM_ZOOM_OUT_Clicked:
//			pOut->PrintMessage("Action: ZOOM OUT Button Clicked");
//			if (UI.InterfaceMode == MODE_DRAW_SUB_MENU1)
//				pOut->CreateDrawToolBarUp(1, true);
//			else if (UI.InterfaceMode == MODE_DRAW_SUB_MENU2)
//				pOut->CreateDrawToolBarUp(2, true);
//			else if (UI.InterfaceMode == MODE_DRAW_SUB_MENU3)
//				pOut->CreateDrawToolBarUp(3, true);
//			else if (UI.InterfaceMode == MODE_DRAW_SUB_MENU4)
//				pOut->CreateDrawToolBarUp(4, true);
//			else if (UI.InterfaceMode == MODE_DRAW_SUB_MENU5)
//				pOut->CreateDrawToolBarUp(5, true);
//			else if (UI.InterfaceMode == MODE_DRAW_SUB_MENU6)
//				pOut->CreateDrawToolBarUp(6, true);
//
//			UI.InterfaceMode = MODE_DRAW;
//			break;
//
//			// The RIGHT COLUMN ITEMS // 
//
//		case ITM_RESIZE_Clicked:
//			pOut->PrintMessage("Action: Resize Button Clicked");
//			if (UI.InterfaceMode == MODE_DRAW_SUB_MENU1)
//				pOut->CreateDrawToolBarUp(1, true);
//			else if (UI.InterfaceMode == MODE_DRAW_SUB_MENU2)
//				pOut->CreateDrawToolBarUp(2, true);
//			else if (UI.InterfaceMode == MODE_DRAW_SUB_MENU3)
//				pOut->CreateDrawToolBarUp(3, true);
//			else if (UI.InterfaceMode == MODE_DRAW_SUB_MENU4)
//				pOut->CreateDrawToolBarUp(4, true);
//			else if (UI.InterfaceMode == MODE_DRAW_SUB_MENU5)
//				pOut->CreateDrawToolBarUp(5, true);
//			else if (UI.InterfaceMode == MODE_DRAW_SUB_MENU6)
//				break;
//
//			UI.InterfaceMode = MODE_DRAW_SUB_MENU6;
//			pOut->CreateDrawToolBarUp(6, false);
//			break;
//
//		case ITM_COPY_Clicked:
//			pOut->PrintMessage("Action: Copy Button Clicked");
//			if (UI.InterfaceMode == MODE_DRAW_SUB_MENU1)
//				pOut->CreateDrawToolBarUp(1, true);
//			else if (UI.InterfaceMode == MODE_DRAW_SUB_MENU2)
//				pOut->CreateDrawToolBarUp(2, true);
//			else if (UI.InterfaceMode == MODE_DRAW_SUB_MENU3)
//				pOut->CreateDrawToolBarUp(3, true);
//			else if (UI.InterfaceMode == MODE_DRAW_SUB_MENU4)
//				pOut->CreateDrawToolBarUp(4, true);
//			else if (UI.InterfaceMode == MODE_DRAW_SUB_MENU5)
//				pOut->CreateDrawToolBarUp(5, true);
//			else if (UI.InterfaceMode == MODE_DRAW_SUB_MENU6)
//				pOut->CreateDrawToolBarUp(6, true);
//
//			UI.InterfaceMode = MODE_DRAW;
//			break;
//
//		case ITM_MOVE_Clicked:
//			pOut->PrintMessage("Action: Move Button Clicked");
//			if (UI.InterfaceMode == MODE_DRAW_SUB_MENU1)
//				pOut->CreateDrawToolBarUp(1, true);
//			else if (UI.InterfaceMode == MODE_DRAW_SUB_MENU2)
//				pOut->CreateDrawToolBarUp(2, true);
//			else if (UI.InterfaceMode == MODE_DRAW_SUB_MENU3)
//				pOut->CreateDrawToolBarUp(3, true);
//			else if (UI.InterfaceMode == MODE_DRAW_SUB_MENU4)
//				pOut->CreateDrawToolBarUp(4, true);
//			else if (UI.InterfaceMode == MODE_DRAW_SUB_MENU5)
//				pOut->CreateDrawToolBarUp(5, true);
//			else if (UI.InterfaceMode == MODE_DRAW_SUB_MENU6)
//				pOut->CreateDrawToolBarUp(6, true);
//
//			UI.InterfaceMode = MODE_DRAW;
//			break;
//
//		case ITM_CUT_Clicked:
//			pOut->PrintMessage("Action: Cut Button Clicked");
//			if (UI.InterfaceMode == MODE_DRAW_SUB_MENU1)
//				pOut->CreateDrawToolBarUp(1, true);
//			else if (UI.InterfaceMode == MODE_DRAW_SUB_MENU2)
//				pOut->CreateDrawToolBarUp(2, true);
//			else if (UI.InterfaceMode == MODE_DRAW_SUB_MENU3)
//				pOut->CreateDrawToolBarUp(3, true);
//			else if (UI.InterfaceMode == MODE_DRAW_SUB_MENU4)
//				pOut->CreateDrawToolBarUp(4, true);
//			else if (UI.InterfaceMode == MODE_DRAW_SUB_MENU5)
//				pOut->CreateDrawToolBarUp(5, true);
//			else if (UI.InterfaceMode == MODE_DRAW_SUB_MENU6)
//				pOut->CreateDrawToolBarUp(6, true);
//
//			UI.InterfaceMode = MODE_DRAW;
//			break;
//
//		case ITM_PASTE_Clicked:
//			pOut->PrintMessage("Action: Paste Button Clicked");
//			if (UI.InterfaceMode == MODE_DRAW_SUB_MENU1)
//				pOut->CreateDrawToolBarUp(1, true);
//			else if (UI.InterfaceMode == MODE_DRAW_SUB_MENU2)
//				pOut->CreateDrawToolBarUp(2, true);
//			else if (UI.InterfaceMode == MODE_DRAW_SUB_MENU3)
//				pOut->CreateDrawToolBarUp(3, true);
//			else if (UI.InterfaceMode == MODE_DRAW_SUB_MENU4)
//				pOut->CreateDrawToolBarUp(4, true);
//			else if (UI.InterfaceMode == MODE_DRAW_SUB_MENU5)
//				pOut->CreateDrawToolBarUp(5, true);
//			else if (UI.InterfaceMode == MODE_DRAW_SUB_MENU6)
//				pOut->CreateDrawToolBarUp(6, true);
//
//			UI.InterfaceMode = MODE_DRAW;
//			break;
//
//		case ITM_DELETE_Clicked:
//			pOut->PrintMessage("Action: Delete Button Clicked");
//			if (UI.InterfaceMode == MODE_DRAW_SUB_MENU1)
//				pOut->CreateDrawToolBarUp(1, true);
//			else if (UI.InterfaceMode == MODE_DRAW_SUB_MENU2)
//				pOut->CreateDrawToolBarUp(2, true);
//			else if (UI.InterfaceMode == MODE_DRAW_SUB_MENU3)
//				pOut->CreateDrawToolBarUp(3, true);
//			else if (UI.InterfaceMode == MODE_DRAW_SUB_MENU4)
//				pOut->CreateDrawToolBarUp(4, true);
//			else if (UI.InterfaceMode == MODE_DRAW_SUB_MENU5)
//				pOut->CreateDrawToolBarUp(5, true);
//			else if (UI.InterfaceMode == MODE_DRAW_SUB_MENU6)
//				pOut->CreateDrawToolBarUp(6, true);
//
//			UI.InterfaceMode = MODE_DRAW;
//			break;
//
//		case ITM_UNDO_Clicked:
//			pOut->PrintMessage("Action: Undo Button Clicked");
//			if (UI.InterfaceMode == MODE_DRAW_SUB_MENU1)
//				pOut->CreateDrawToolBarUp(1, true);
//			else if (UI.InterfaceMode == MODE_DRAW_SUB_MENU2)
//				pOut->CreateDrawToolBarUp(2, true);
//			else if (UI.InterfaceMode == MODE_DRAW_SUB_MENU3)
//				pOut->CreateDrawToolBarUp(3, true);
//			else if (UI.InterfaceMode == MODE_DRAW_SUB_MENU4)
//				pOut->CreateDrawToolBarUp(4, true);
//			else if (UI.InterfaceMode == MODE_DRAW_SUB_MENU5)
//				pOut->CreateDrawToolBarUp(5, true);
//			else if (UI.InterfaceMode == MODE_DRAW_SUB_MENU6)
//				pOut->CreateDrawToolBarUp(6, true);
//
//			UI.InterfaceMode = MODE_DRAW;
//			break;
//
//		case ITM_REDO_Clicked:
//			pOut->PrintMessage("Action: Redo Button Clicked");
//			if (UI.InterfaceMode == MODE_DRAW_SUB_MENU1)
//				pOut->CreateDrawToolBarUp(1, true);
//			else if (UI.InterfaceMode == MODE_DRAW_SUB_MENU2)
//				pOut->CreateDrawToolBarUp(2, true);
//			else if (UI.InterfaceMode == MODE_DRAW_SUB_MENU3)
//				pOut->CreateDrawToolBarUp(3, true);
//			else if (UI.InterfaceMode == MODE_DRAW_SUB_MENU4)
//				pOut->CreateDrawToolBarUp(4, true);
//			else if (UI.InterfaceMode == MODE_DRAW_SUB_MENU5)
//				pOut->CreateDrawToolBarUp(5, true);
//			else if (UI.InterfaceMode == MODE_DRAW_SUB_MENU6)
//				pOut->CreateDrawToolBarUp(6, true);
//
//			UI.InterfaceMode = MODE_DRAW;
//			break;
//
//		case ITM_SELECT_Clicked:
//			pOut->PrintMessage("Action: Select Button Clicked");
//			if (UI.InterfaceMode == MODE_DRAW_SUB_MENU1)
//				pOut->CreateDrawToolBarUp(1, true);
//			else if (UI.InterfaceMode == MODE_DRAW_SUB_MENU2)
//				pOut->CreateDrawToolBarUp(2, true);
//			else if (UI.InterfaceMode == MODE_DRAW_SUB_MENU3)
//				pOut->CreateDrawToolBarUp(3, true);
//			else if (UI.InterfaceMode == MODE_DRAW_SUB_MENU4)
//				pOut->CreateDrawToolBarUp(4, true);
//			else if (UI.InterfaceMode == MODE_DRAW_SUB_MENU5)
//				pOut->CreateDrawToolBarUp(5, true);
//			else if (UI.InterfaceMode == MODE_DRAW_SUB_MENU6)
//				pOut->CreateDrawToolBarUp(6, true);
//
//			UI.InterfaceMode = MODE_DRAW;
//			break;
//
//		case ITM_LOAD_Clicked:
//			pOut->PrintMessage("Action: Load Button Clicked");
//			if (UI.InterfaceMode == MODE_DRAW_SUB_MENU1)
//				pOut->CreateDrawToolBarUp(1, true);
//			else if (UI.InterfaceMode == MODE_DRAW_SUB_MENU2)
//				pOut->CreateDrawToolBarUp(2, true);
//			else if (UI.InterfaceMode == MODE_DRAW_SUB_MENU3)
//				pOut->CreateDrawToolBarUp(3, true);
//			else if (UI.InterfaceMode == MODE_DRAW_SUB_MENU4)
//				pOut->CreateDrawToolBarUp(4, true);
//			else if (UI.InterfaceMode == MODE_DRAW_SUB_MENU5)
//				pOut->CreateDrawToolBarUp(5, true);
//			else if (UI.InterfaceMode == MODE_DRAW_SUB_MENU6)
//				pOut->CreateDrawToolBarUp(6, true);
//
//			UI.InterfaceMode = MODE_DRAW;
//			break;
//
//		case ITM_SAVE_Clicked:
//			pOut->PrintMessage("Action: Save Button Clicked");
//			if (UI.InterfaceMode == MODE_DRAW_SUB_MENU1)
//				pOut->CreateDrawToolBarUp(1, true);
//			else if (UI.InterfaceMode == MODE_DRAW_SUB_MENU2)
//				pOut->CreateDrawToolBarUp(2, true);
//			else if (UI.InterfaceMode == MODE_DRAW_SUB_MENU3)
//				pOut->CreateDrawToolBarUp(3, true);
//			else if (UI.InterfaceMode == MODE_DRAW_SUB_MENU4)
//				pOut->CreateDrawToolBarUp(4, true);
//			else if (UI.InterfaceMode == MODE_DRAW_SUB_MENU5)
//				pOut->CreateDrawToolBarUp(5, true);
//			else if (UI.InterfaceMode == MODE_DRAW_SUB_MENU6)
//				pOut->CreateDrawToolBarUp(6, true);
//
//			UI.InterfaceMode = MODE_DRAW;
//			break;
//
//		case ITM_SAVEAS_Clicked:
//			pOut->PrintMessage("Action: Save As Button Clicked");
//			if (UI.InterfaceMode == MODE_DRAW_SUB_MENU1)
//				pOut->CreateDrawToolBarUp(1, true);
//			else if (UI.InterfaceMode == MODE_DRAW_SUB_MENU2)
//				pOut->CreateDrawToolBarUp(2, true);
//			else if (UI.InterfaceMode == MODE_DRAW_SUB_MENU3)
//				pOut->CreateDrawToolBarUp(3, true);
//			else if (UI.InterfaceMode == MODE_DRAW_SUB_MENU4)
//				pOut->CreateDrawToolBarUp(4, true);
//			else if (UI.InterfaceMode == MODE_DRAW_SUB_MENU5)
//				pOut->CreateDrawToolBarUp(5, true);
//			else if (UI.InterfaceMode == MODE_DRAW_SUB_MENU6)
//				pOut->CreateDrawToolBarUp(6, true);
//
//			UI.InterfaceMode = MODE_DRAW;
//			break;
//
//		case ITM_COLLAPSERIGHT_Clicked:
//			pOut->PrintMessage("Action: COLLAPSERIGHT Button Clicked");
//			if (UI.InterfaceMode == MODE_DRAW_SUB_MENU1)
//				pOut->CreateDrawToolBarUp(1, true);
//			else if (UI.InterfaceMode == MODE_DRAW_SUB_MENU2)
//				pOut->CreateDrawToolBarUp(2, true);
//			else if (UI.InterfaceMode == MODE_DRAW_SUB_MENU3)
//				pOut->CreateDrawToolBarUp(3, true);
//			else if (UI.InterfaceMode == MODE_DRAW_SUB_MENU4)
//				pOut->CreateDrawToolBarUp(4, true);
//			else if (UI.InterfaceMode == MODE_DRAW_SUB_MENU5)
//				pOut->CreateDrawToolBarUp(5, true);
//			else if (UI.InterfaceMode == MODE_DRAW_SUB_MENU6)
//				pOut->CreateDrawToolBarUp(6, true);
//
//			UI.InterfaceMode = MODE_DRAW;
//			break;
//
//			// GAME_MODE ICONS //
//		case ITM_SCRAMBLE_Clicked:
//			pOut->PrintMessage("Action: SCRAMBLE Button Clicked");
//			break;
//
//		case ITM_FIND_Clicked:
//			pOut->PrintMessage("Action: FIND Button Clicked");
//			break;
//
//		case CHNG_DRAW_CLR:
//			pOut->PrintMessage("Action: Change the drawing color , Click anywhere");
//			break;
//
//		case CHNG_FILL_CLR:
//			pOut->PrintMessage("Action: Change background color , Click anywhere");
//			break;
//
//		case STATUS:
//			pOut->PrintMessage("Action: a click on the Status Bar, Click anywhere");
//			if (UI.InterfaceMode == MODE_DRAW_SUB_MENU1)
//				pOut->CreateDrawToolBarUp(1, true);
//			else if (UI.InterfaceMode == MODE_DRAW_SUB_MENU2)
//				pOut->CreateDrawToolBarUp(2, true);
//			else if (UI.InterfaceMode == MODE_DRAW_SUB_MENU3)
//				pOut->CreateDrawToolBarUp(3, true);
//			else if (UI.InterfaceMode == MODE_DRAW_SUB_MENU4)
//				pOut->CreateDrawToolBarUp(4, true);
//			else if (UI.InterfaceMode == MODE_DRAW_SUB_MENU5)
//				pOut->CreateDrawToolBarUp(5, true);
//			else if (UI.InterfaceMode == MODE_DRAW_SUB_MENU6)
//				pOut->CreateDrawToolBarUp(6, true);
//
//			UI.InterfaceMode = MODE_DRAW;
//			break;
//
//		case DRAWING_AREA:
//			pOut->PrintMessage("Action: a click on the Drawing Area, Click anywhere");
//			if (UI.InterfaceMode == MODE_DRAW_SUB_MENU1)
//				pOut->CreateDrawToolBarUp(1, true);
//			else if (UI.InterfaceMode == MODE_DRAW_SUB_MENU2)
//				pOut->CreateDrawToolBarUp(2, true);
//			else if (UI.InterfaceMode == MODE_DRAW_SUB_MENU3)
//				pOut->CreateDrawToolBarUp(3, true);
//			else if (UI.InterfaceMode == MODE_DRAW_SUB_MENU4)
//				pOut->CreateDrawToolBarUp(4, true);
//			else if (UI.InterfaceMode == MODE_DRAW_SUB_MENU5)
//				pOut->CreateDrawToolBarUp(5, true);
//			else if (UI.InterfaceMode == MODE_DRAW_SUB_MENU6)
//				pOut->CreateDrawToolBarUp(6, true);
//
//			UI.InterfaceMode = MODE_DRAW;
//			break;
//
//		case EMPTY:
//			pOut->PrintMessage("Action: a click on empty area in the Design Tool Bar, Click anywhere");
//			if (UI.InterfaceMode == MODE_DRAW_SUB_MENU1)
//				pOut->CreateDrawToolBarUp(1, true);
//			else if (UI.InterfaceMode == MODE_DRAW_SUB_MENU2)
//				pOut->CreateDrawToolBarUp(2, true);
//			else if (UI.InterfaceMode == MODE_DRAW_SUB_MENU3)
//				pOut->CreateDrawToolBarUp(3, true);
//			else if (UI.InterfaceMode == MODE_DRAW_SUB_MENU4)
//				pOut->CreateDrawToolBarUp(4, true);
//			else if (UI.InterfaceMode == MODE_DRAW_SUB_MENU5)
//				pOut->CreateDrawToolBarUp(5, true);
//			else if (UI.InterfaceMode == MODE_DRAW_SUB_MENU6)
//				pOut->CreateDrawToolBarUp(6, true);
//
//			UI.InterfaceMode = MODE_DRAW;
//			break;
//
//		case TO_DRAW:
//			pOut->PrintMessage("Action: Switch to Draw Mode, creating simualtion tool bar");
//			break;
//
//
//		case EXIT:
//			exit(0);
//		}
//	} while (ActType != EXIT);
//
//
//	/// Exiting
//	pOut->PrintMessage("Action: EXIT, test is finished, click anywhere to exit");
//	pIn->GetPointClicked(x, y);
//
//	delete pIn;
//	delete pOut;
//	return 0;
//}