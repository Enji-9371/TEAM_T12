#include "Line.h"
#include <fstream>
#include <string>
#include <iostream>
using namespace std;
Line::Line()
{

}
Line::Line(Point P1, Point P2, GfxInfo shapeGfxInfo):shape(shapeGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
}

Line::~Line()
{}

void Line::Save(ofstream& outFile)
{}

void Line::Load(ifstream& Infile)
{
	string DrawColor;
	Infile >> ID >> Corner1.x >> Corner1.y >> Corner2.x >> Corner2.y >> DrawColor;
	GfxInfo info;
	Infile >> info.isSelected;
	Infile >> info.DrawClr.ucBlue;
	Infile >> info.DrawClr.ucGreen;
	Infile >> info.DrawClr.ucRed;
}

void Line::Draw(GUI* pUI) const
{
	//Call Output::DrawLine to draw a line on the screen	
	pUI->DrawLn(Corner1, Corner2, ShpGfxInfo);
}