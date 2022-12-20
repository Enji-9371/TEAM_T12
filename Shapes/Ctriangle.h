#pragma once

#include "shape.h"

class Ctriangle : public shape
{
private:
	Point Corner1;
	Point Corner2;
	Point corner3;
public:
	Ctriangle(Point, Point, Point, GfxInfo shapeGfxInfo);
	virtual ~Ctriangle();
	virtual void Draw(GUI* pUI) const;
	void Save(ofstream& Outfile);
};

