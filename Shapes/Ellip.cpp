#include "Ellip.h"

Ellip::Ellip()
{

}

Ellip::Ellip(Point P1, Point P2, GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
}

Ellip::~Ellip()
{}

void Ellip::Save(ofstream& outFile)
{}


void Ellip::Load(ifstream& Infile)
{
	string DrawColor;
	Infile >> ID >> Corner1.x >> Corner1.y >> Corner2.x >> Corner2.y >> DrawColor;
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

void Ellip::Draw(GUI* pUI) const
{
	//Call Output::DrawEllip to draw an ellipse on the screen	
	pUI->DrawEllip(Corner1, Corner2, ShpGfxInfo);
}