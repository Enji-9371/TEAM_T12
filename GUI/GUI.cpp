#include "GUI.h"
#include<iostream>

GUI::GUI()
{
	//Initialize user interface parameters
	InterfaceMode = MODE_DRAW;

	width = 1300;
	height = 700;
	wx = 5;
	wy = 5;


	StatusBarHeight = 50;
	ToolBarHeight = 50;
	MenuIconWidth = 80;

	DrawColor = BLACK;	//default Drawing color
	FillColor = BLACK;	//default Filling color
	MsgColor = BLACK;		//Messages color
	BkGrndColor = WHITE;	//Background color
	IsFilled = false;       //default is not filled
	HighlightColor = MAGENTA;	//This color should NOT be used to draw shapes. use if for highlight only
	StatusBarColor = LIGHTSEAGREEN;
	PenWidth = 3;	//default width of the shapes frames


	//Create the output window
	pWind = CreateWind(width, height, wx, wy);
	//Change the title
	pWind->ChangeTitle("- - - - - - - - - - PAINT ^ ^ PLAY - - - - - - - - - -");

	CreateDrawToolBar();
	CreateStatusBar();
}


bool GUI::GetIsFilled()const  //get current fill status
{
	return IsFilled;
}



//======================================================================================//
//								Input Functions								     		//
//======================================================================================//
void GUI::GetPointClicked(int& x, int& y) const
{
	pWind->WaitMouseClick(x, y);	//Wait for mouse click
}

string GUI::GetSrting() const
{
	string Label;
	char Key;
	keytype ktype;
	pWind->FlushKeyQueue();
	while (1)
	{
		ktype = pWind->WaitKeyPress(Key);
		if (ktype == ESCAPE )	//ESCAPE key is pressed
			return "";	//returns nothing as user has cancelled label
		if (Key == 13)	//ENTER key is pressed
			return Label;
		if (Key == 8)	//BackSpace is pressed
			if( Label.size() > 0)	
				Label.resize(Label.size() - 1);
			else
				Key = '\0';		
		else
			Label += Key;
		PrintMessage(Label);
	}
}

//This function reads the position where the user clicks to determine the desired operation
operationType GUI::GetUseroperation() const
{
	int x, y;
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click

	if (InterfaceMode == MODE_DRAW)	//GUI in the DRAW mode
	{
		//[1] If user clicks on the Toolbar
		if (y >= 0 && y < ToolBarHeight)
		{
			//Check whick Menu icon was clicked
			//==> This assumes that menu icons are lined up horizontally <==
			int ClickedIconOrder = (x / MenuIconWidth);
			//Divide x coord of the point clicked by the menu icon width (int division)
			//if division result is 0 ==> first icon is clicked, if 1 ==> 2nd icon and so on

			switch (ClickedIconOrder)
			{
			case ICON_RECT: return DRAW_RECT; break;
			case ICON_CIRC: return DRAW_CIRC;  break;
			case ICON_CLRPLT: return COLOR_PALETTE;  break;
			case ICON_PNWDTH: return PEN_WIDTH; break;
			case ICON_EXIT: return EXIT; break;


			default: return EMPTY;	//A click on empty place in desgin toolbar
			}
		}

		//[2] User clicks on the drawing area
		if (y >= ToolBarHeight && y < height - StatusBarHeight)
		{
			return DRAWING_AREA;
		}

		//[3] User clicks on the status bar
		return STATUS;
	}
	if (COLOR_PALETTE)
	{
		return COLOR_PALETTE;
		
	}
}


////////////////////////////////////////////////////



//======================================================================================//
//								Output Functions										//
//======================================================================================//

window* GUI::CreateWind(int w, int h, int x, int y) const
{
	window* pW = new window(w, h, x, y);
	pW->SetBrush(BkGrndColor);
	pW->SetPen(BkGrndColor, 1);
	pW->DrawRectangle(0, ToolBarHeight, w, h);
	return pW;
}
//////////////////////////////////////////////////////////////////////////////////////////
void GUI::CreateStatusBar() const
{
	pWind->SetPen(StatusBarColor, 1);
	pWind->SetBrush(StatusBarColor);
	pWind->DrawRectangle(0, height - StatusBarHeight, width, height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void GUI::ClearStatusBar() const
{
	//Clear Status bar by drawing a filled white rectangle
	pWind->SetPen(StatusBarColor, 1);
	pWind->SetBrush(StatusBarColor);
	pWind->DrawRectangle(0, height - StatusBarHeight, width, height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void GUI::CreateDrawToolBar() 
{
	InterfaceMode = MODE_DRAW;

	//You can draw the tool bar icons in any way you want.
	//Below is one possible way

	//First prepare List of images for each menu icon
	//To control the order of these images in the menu, 
	//reoder them in UI_Info.h ==> enum DrawMenuIcon
	string MenuIconImages[DRAW_ICON_COUNT];
	MenuIconImages[ICON_RECT] = "images\\MenuIcons\\Menu_Rect.jpg";
	MenuIconImages[ICON_CIRC] = "images\\MenuIcons\\Menu_Circ.jpg";
	MenuIconImages[ICON_EXIT] = "images\\MenuIcons\\Menu_Exit.jpg";
	MenuIconImages[ICON_CLRPLT] = "images\\MenuIcons\\Menu_ClrPlt.jpg";
	MenuIconImages[ICON_PNWDTH] = "images\\MenuIcons\\Menu_Width.jpg";

	//TODO: Prepare images for each menu icon and add it to the list

	//Draw menu icon one image at a time
	for (int i = 0; i < DRAW_ICON_COUNT; i++)
		pWind->DrawImage(MenuIconImages[i], i * MenuIconWidth, 0, MenuIconWidth, ToolBarHeight);



	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, ToolBarHeight, width, ToolBarHeight);

}

operationType GUI::CreateColorBar()
{
	InterfaceMode = MODE_PLT; //set interfacemode to the color bar mode 
	int x, y;
	string MenuIconImages[Clr_ICON_COUNT];
	MenuIconImages[ICON_Red] = "images\\MenuIcons\\Red.jpg";
	MenuIconImages[ICON_Green] = "images\\MenuIcons\\Green.jpg";
	MenuIconImages[ICON_Blue] = "images\\MenuIcons\\Blue.jpg";
	MenuIconImages[ICON_Yellow] = "images\\MenuIcons\\Yellow.jpg";
	MenuIconImages[ICON_Black] = "images\\MenuIcons\\Black.jpg";
	PrintMessage("Press 'D' to Change The General Drawing Color, 'F' to Chang The General Filling Color : ");
	string choice = GetSrting();  //get the input 

	if (choice=="d" || choice=="D") //if this case is true, user wants to change draw color
	{
		ClearStatusBar(); //clear the status bar
		PrintMessage("Now Choose a Color: ");
		//Draw menu icon one image at a time
		for (int i = 0; i < Clr_ICON_COUNT; i++)
			pWind->DrawImage(MenuIconImages[i], i * MenuIconWidth, 0, MenuIconWidth, ToolBarHeight);
		//[1] If user clicks on the Toolbar
		pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click
		if (y >= 0 && y < ToolBarHeight)
		{
			ClearStatusBar();   //clear the status bar
			int ClickedIconOrder = (x / MenuIconWidth);
			//Divide x coord of the point clicked by the menu icon width (int division)
			//if division result is 0 ==> first icon is clicked, if 1 ==> 2nd icon and so on

			switch (ClickedIconOrder) //return enum to determine which draw color is chosen
			{
			case ICON_Red: { return dChangeToRed; break; }
			case ICON_Green: { return dChangeToGreen; break; }
			case ICON_Blue: {return dChangeToBlue; break; }
			case ICON_Yellow: { return dChangeToYellow; break; }
			case ICON_Black: {return dChangeToBlack; break; }
			default: {return EMPTY; break; }	//A click on empty place in desgin toolbar
			}
		}		
	}
	else if (choice == "f" || choice == "F") //if this case is true, user wants to change fill color
	{
		ClearStatusBar(); //clear the status bar
		PrintMessage("Now Choose a Color: ");
		//Draw menu icon one image at a time
		for (int i = 0; i < Clr_ICON_COUNT; i++)
			pWind->DrawImage(MenuIconImages[i], i * MenuIconWidth, 0, MenuIconWidth, ToolBarHeight);
		//[1] If user clicks on the Toolbar
		pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click
		if (y >= 0 && y < ToolBarHeight)
		{
			ClearStatusBar();  //clear the status bar 
			int ClickedIconOrder = (x / MenuIconWidth);
			//Divide x coord of the point clicked by the menu icon width (int division)
			//if division result is 0 ==> first icon is clicked, if 1 ==> 2nd icon and so on

			switch (ClickedIconOrder) //return enum to determine which fill color is chosen
			{
			case ICON_Red: {return fChangeToRed; break; }
			case ICON_Green: { return fChangeToGreen; break; }
			case ICON_Blue: {return fChangeToBlue; break; }
			case ICON_Yellow: { return fChangeToYellow; break; }
			case ICON_Black: { return fChangeToBlack; break; }
			default: {return EMPTY; break; }	//A click on empty place in desgin toolbar
			}
		}
	}
	else	
	{
			PrintMessage("Unsupportted Operation!"); //if input is out of range
			return EMPTY;
	}
}
//////////////////////////////////////////////////////////////////////////////////////////


void GUI::CreatePlayToolBar() 
{
	InterfaceMode = MODE_PLAY;
	///TODO: write code to create Play mode menu
}
//////////////////////////////////////////////////////////////////////////////////////////

void GUI::ClearDrawArea() const
{
	pWind->SetPen(BkGrndColor, 1);
	pWind->SetBrush(BkGrndColor);
	pWind->DrawRectangle(0, ToolBarHeight, width, height - StatusBarHeight);

}
 

//======================================================================================//
//						draw_fill colors & width setters(general shapes)	        	//
//======================================================================================//

void GUI::setCrntDrawColor(operationType dcolor)   //set current general drawing color            
{
	switch (dcolor)
	{
	case dChangeToRed: DrawColor = RED; break;   //set the draw color according to the enum(operationtype) returned from the function CreateColorBar()
	case dChangeToGreen: DrawColor = GREEN; break;
	case dChangeToBlack: DrawColor = BLACK; break;
	case dChangeToBlue: DrawColor = BLUE; break;
	case dChangeToYellow: DrawColor = YELLOW; break;
	}
}

void GUI::setCrntFillColor(operationType fcolor) 	//set current general filling color
{
	IsFilled = true;
	switch (fcolor)
	{
	case fChangeToRed:FillColor =RED; break;  //set the fill color according to the enum(operationtype) returned from the function CreateColorBar()
	case fChangeToGreen: FillColor = GREEN; break;
	case fChangeToBlack:FillColor = BLACK; break;
	case fChangeToBlue:FillColor = BLUE; break;
	case fChangeToYellow: FillColor = YELLOW; break;
	}
}

void GUI::setCrntPenWidth(int width) 		//set current general pen width
{
	PenWidth=width;  //set the pen width according to the enum(operationtype) returned from the function CreateColorBar()
}




//////////////////////////////////////////////////////////////////////////////////////////
void GUI::PrintMessage(string msg) const	//Prints a message on status bar
{
	ClearStatusBar();	//First clear the status bar

	pWind->SetPen(MsgColor, 50);
	pWind->SetFont(24, BOLD, BY_NAME, "Arial");
	pWind->DrawString(10, height - (int)(0.75 * StatusBarHeight), msg);
}
//////////////////////////////////////////////////////////////////////////////////////////

color GUI::getCrntDrawColor() const	//get current drwawing color
{
	return DrawColor;
}
//////////////////////////////////////////////////////////////////////////////////////////

color GUI::getCrntFillColor() const	//get current filling color
{
	return FillColor;
}
//////////////////////////////////////////////////////////////////////////////////////////

int GUI::getCrntPenWidth() const		//get current pen width
{
	return PenWidth;
}

//======================================================================================//
//								shapes Drawing Functions								//
//======================================================================================//

void GUI::DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo) const
{
	color DrawingClr;
	if (RectGfxInfo.isSelected)	//shape is selected
		DrawingClr = HighlightColor; //shape should be drawn highlighted
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

//////////////////////////////////////////////////////////////////////////////////////////
GUI::~GUI()
{
	delete pWind;
}

