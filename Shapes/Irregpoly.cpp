#include "Irregpoly.h"

irr_polygon::irr_polygon()
{

}

irr_polygon::irr_polygon(Point* p1, int x, GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
{
	array_points = p1;
	num = x;



}

irr_polygon::~irr_polygon()
{

}

void irr_polygon::Save(ofstream& outFile)
{}

void irr_polygon::Load(ifstream& Infile)
{
string DrawColor;
    Infile >> ID >> DrawColor;
	GfxInfo info;
	Infile >> info.BorderWdth;
	Infile >> info.isFilled;
	Infile >> info.isSelected;
	Infile >> info.FillClr.ucBlue;
	Infile >> info.FillClr.ucGreen;
	Infile >> info.FillClr.ucRed;
	Infile >> info.DrawClr.ucBlue;
	Infile >> info.DrawClr.ucGreen;
	Infile >> info.DrawClr.ucRed;
}

void irr_polygon::Draw(GUI* pUI) const
{

	for (int i = 0; i < num; i++)
	{
		Array_X[i] = array_points[i].x;
		Array_Y[i] = array_points[i].y;
	}

	//Call Output::Draw irrpolygon to draw an irrpolygon on the screen	
	pUI->DrawPolygon(Array_X, Array_Y, num, ShpGfxInfo);

};
