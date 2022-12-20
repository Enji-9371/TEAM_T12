#include "Cregpolygon.h"
#include <math.h>
#include <corecrt_math_defines.h>



polygon::polygon(Point p1, Point p2, int i, GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
{
	center.x = p1.x;
	center.y = p1.y;
	point1.x = p2.x;
	point1.y = p2.y;
	num = i;
	distance = sqrt(pow(point1.x - center.x, 2) + pow((point1.y - center.y), 2));
}
polygon::~polygon()
{}
void polygon::Draw(GUI* pUI) const
{
	if (num == 4) {
		for (int i = 0; i < num; i++)
		{

			int vertixofX = center.x + distance * cos(i * 2 * M_PI / num);
			int vertixofY = center.y + distance * sin(i * 2 * M_PI / num);
			arrayX[i] = vertixofX; arrayY[i] = vertixofY;
		}
		pUI->DrawPolygon(arrayX, arrayY, num, ShpGfxInfo);
	}
	else
	{
		double x = ((num - 2) * M_PI) / (2 * num);
		for (int i = 0; i < num; i++)
		{

			int vertixofX = center.x + distance * cos(i * 2 * M_PI / num + x);
			int vertixofY = center.y + distance * sin(i * 2 * M_PI / num + x);
			arrayX[i] = vertixofX;
			arrayY[i] = vertixofY;
		}pUI->DrawPolygon(arrayX, arrayY, num, ShpGfxInfo);
	}

	double x = ((num - 2) * M_PI) / (2 * num);
	for (int i = 0; i < num; i++)
	{

		int vertixofX = center.x + distance * cos(i * 2 * M_PI / num + x);
		int vertixofY = center.y + distance * sin(i * 2 * M_PI / num + x);
		arrayX[i] = vertixofX;
		arrayY[i] = vertixofY;
	}
	pUI->DrawPolygon(arrayX, arrayY, num, ShpGfxInfo);



}

void polygon::save()
{
}
