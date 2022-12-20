#include "Squr.h"

Squr::Squr()
{
}
Squr::Squr(Point P1, Point P2, GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
{
	double L;
	L = sqrt(pow((P2.x - P1.x), 2) + pow((P2.y - P1.y), 2));
	P2.x = P1.x + L / sqrt(2);
	P2.y = P1.y + L / sqrt(2);
	Corner1 = P1;
	Corner2 = P2;
}

Squr::~Squr()
{}

void Squr::Save(ofstream& outFile)
{}


void Squr::Load(ifstream& Infile)
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

void Squr::Draw(GUI* pUI) const
{
	//Call Output::DrawSqur to draw a square on the screen	
	pUI->DrawSqur(Corner1, Corner2, ShpGfxInfo);
}