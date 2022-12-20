#pragma once
#include "Shape.h"

class irr_polygon :public shape
{

private:
	Point* array_points;

	int num = 0;  //number of vertices 
	int* Array_X = new int[num];
	int* Array_Y = new int[num];

public:
	irr_polygon();
	irr_polygon(Point*, int, GfxInfo shapeGfxInfo);
	virtual ~irr_polygon();
	void Save(ofstream& OutFile);
	void Load(ifstream& Infile);
	virtual void Draw(GUI* pUI) const;

};

