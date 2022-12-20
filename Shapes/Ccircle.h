#pragma once
#include "shape.h"
class Ccircle : public shape
{private:
	Point center;Point border;
public:
Ccircle(Point, Point, GfxInfo shapeGfxInfo);	
	virtual ~Ccircle();
	virtual void Draw(GUI* pUI) const;
	void Save(ofstream& Outfile);
};


