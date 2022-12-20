#include "Ccircle.h"



Ccircle::Ccircle(Point P1, Point P2, GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
{
	center = P1;
	center = P2;
}

Ccircle::~Ccircle()
{}

void Ccircle::Draw(GUI* pUI) const
{
	double rad = sqrt((center.x - border.x) * (center.x - border.x) + (center.y - border.y) * (center.y - border.y));	
	pUI->DrawCircle(center,rad , ShpGfxInfo);
}

void Ccircle::Save(ofstream& Outfile)
{

	string DrawColor;
	Outfile << ID << center.x<< DrawColor << "shape id  " << ID << "center .x " << center.x << "center .y  " << center.y << " " << border.x << " " << border.y << " ";
	GfxInfo info;
	Outfile << info.BorderWdth;
	Outfile << info.isFilled;
	Outfile << info.isSelected;
	Outfile << info.FillClr.ucBlue;
	Outfile << info.FillClr.ucGreen;
	Outfile << info.FillClr.ucRed;
	Outfile << info.DrawClr.ucBlue;
	Outfile << info.DrawClr.ucGreen;
	Outfile << info.DrawClr.ucRed;

}

