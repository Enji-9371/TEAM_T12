#pragma once

#include "shape.h"

class Ellip : public shape
{
private:
	Point Corner1;
	Point Corner2;
public:
	Ellip();
	Ellip (Point, Point, GfxInfo shapeGfxInfo);
	virtual ~Ellip();
	void Save(ofstream& OutFile);
	void Load(ifstream& Infile);
	virtual void Draw(GUI* pUI) const;
};