#pragma once
#include "Shapes/Shape.h"
class polygon : public shape
{
private:
	Point center;
	Point point1;
	int num = 0;
	double distance;
	int* arrayX = new int[num];
	int* arrayY = new int[num];

public:
	polygon(Point, Point, int, GfxInfo shapeGfxInfo);
	virtual ~polygon();
	virtual void Draw(GUI* pUI) const;
	virtual void  save();

};