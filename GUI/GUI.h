#pragma once

#include"../CMUgraphicsLib/colors.h"
//#include"../Shapes/Graph.h"
#include "..\CMUgraphicsLib\CMUgraphics.h"
#include "..\Defs.h"
//#include"../Shapes/Shape.h"
#include <string>
using namespace std;

struct Point	//To be used for shapes points
{
	int x, y;
};

struct GfxInfo	//Graphical info common for all shapes (you may add more members)
{
	color DrawClr;	//Draw color of the shape
	color FillClr;	//Fill color of the shape
	bool isFilled;	//shape Filled or not
	int BorderWdth;	//Width of shape borders
	bool isSelected;	//true if the shape is selected.
};


class GUI
{
	enum GUI_MODE	//Graphical user interface mode
	{
		MODE_DRAW,	//Drawing mode (startup mode)
		MODE_PLAY,	//Playing mode
		MODE_PLT     //color palette mode
	};

	enum DrawMenuIcon //The icons of the Draw menu (you should add more icons)
	{
		//Note: Icons are ordered here as they appear in menu
		//If you want to change the menu icons order, change the order here
		ICON_RECT,		//Recangle icon in menu
		ICON_CIRC,		//Circle icon in menu

		//TODO: Add more icons names here
		ICON_CLRPLT,     //color palette icon
		ICON_PNWDTH,      //pen width icon

		ICON_EXIT,		//Exit icon


		DRAW_ICON_COUNT		//no. of menu icons ==> This should be the last line in this enum

		
	};

	enum ClrPltMenuIcon //The icons of the Draw menu (you should add more icons)
	{
		//Note: Icons are ordered here as they appear in menu
		//If you want to change the menu icons order, change the order here
		ICON_Red,		//red color icon in menu
		ICON_Green,		//green color icon in menu
		ICON_Blue,		//blue color icon
		ICON_Yellow,		//yellow color icon
		ICON_Black,        //Black color icon

		Clr_ICON_COUNT		//no. of menu icons ==> This should be the last line in this enum

	};


	enum PlayMenuIcon //The icons of the Play menu (you should add more icons)
	{
		//Note: Icons are ordered here as they appear in menu
		//If you want to change the menu icons order, change the order here

		//TODO: Add more icons names here

		PLAY_ICON_COUNT		//no. of menu icons ==> This should be the last line in this enum

	};


	GUI_MODE InterfaceMode;

	int	width, height,	//Window width and height
		wx, wy,			//Window starting coordinates
		StatusBarHeight,	//Status Bar Height
		ToolBarHeight,		//Tool Bar Height (distance from top of window to bottom line of toolbar)
		MenuIconWidth;		//Width of each icon in toolbar menu


	color DrawColor;		//Drawing color
	color FillColor;		//Filling color
	color HighlightColor;	//Highlighting color
	color MsgColor;			//Messages color
	color BkGrndColor;		//Background color
	color StatusBarColor;	//Status bar color
	int PenWidth;			//width of the pen that draws shapes
	bool IsFilled;          //filling status

	/// Add more members if needed



	window* pWind;

public:

	GUI();

	// Input Functions  ---------------------------
	void GetPointClicked(int& x, int& y) const;//Get coordinate where user clicks
	string GetSrting() const;	 //Returns a string entered by the user
	operationType GetUseroperation() const; //Read the user click and map to an operation
	//color GetUseroperationClrMode() const; //Read the user click in the color mode and map to an certain color

	// Output Functions  ---------------------------
	window* CreateWind(int, int, int, int) const; //creates the application window
	void CreateDrawToolBar();	//creates Draw mode toolbar & menu
	void CreatePlayToolBar();	//creates Play mode toolbar & menu
	void CreateStatusBar() const;	//create the status bar
	operationType CreateColorBar();          //create the new window of the colors

	void ClearStatusBar() const;	//Clears the status bar
	void ClearDrawArea() const;	//Clears the drawing area

	//void SetDrawColor(operationType);

	// -- shapes Drawing functions
	void DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo) const;  //Draw a rectangle

	///Make similar functions for drawing all other shapes.

	void PrintMessage(string msg) const;	//Print a message on Status bar

	color getCrntDrawColor() const;	//get current drawing color
	color getCrntFillColor() const;	//get current filling color
	int getCrntPenWidth() const;		//get current pen width
	bool GetIsFilled() const;

	void setCrntDrawColor(operationType dcolor);	//set current drawing color
	void setCrntFillColor(operationType fcolor);	//set current filling color
	void setCrntPenWidth(int width);		//set current pen width


	~GUI();
};

