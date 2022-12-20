#pragma once

#include "shape.h"

class Line : public shape
{
private:
	Point Corner1;
	Point Corner2;
public:
	Line();
	Line(Point, Point, GfxInfo shapeGfxInfo);
	virtual ~Line();
	void Save(ofstream& OutFile);
	void Load(ifstream& Infile);
	virtual void Draw(GUI* pUI) const;
};