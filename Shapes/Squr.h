#pragma once

#include "shape.h"

class Squr : public shape
{
private:
	Point Corner1;
	Point Corner2;
public:
	Squr();
	Squr(Point, Point, GfxInfo shapeGfxInfo);
	virtual ~Squr();
	void Save(ofstream& OutFile);
	void Load(ifstream& Infile);
	virtual void Draw(GUI* pUI) const;
};