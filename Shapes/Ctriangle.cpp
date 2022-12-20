#include "Ctriangle.h"


Ctriangle::Ctriangle(Point P1, Point P2, Point P3,  GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	corner3 = P3;
}
Ctriangle::~Ctriangle(){}
void Ctriangle::Draw(GUI* pUI) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pUI->DrawTriangle(Corner1, Corner2, corner3, ShpGfxInfo);

}

void Ctriangle::Save(ofstream& Outfile)
{
	
	string DrawColor;
	Outfile << ID <<  Corner1.x << "corner1.y " << Corner1.y << "corner2.x " << Corner2.x << " corner2.y" << Corner2.y << " corner3.x" << corner3.x << " corner3.y" << corner3.y;
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


