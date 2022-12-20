#include"Load.h"
#include "..\Shapes\Line.h"
#include "..\Shapes\Rect.h"
#include "..\Shapes\Ellip.h"
#include "..\Shapes\Squr.h"
#include "..\Shapes\Irregpoly.h"
#include "..\controller.h"
#include "..\GUI\GUI.h"
#include "..\controller.h"

Load::Load(controller* pCont) :operation(pCont)
{}

void Load::Execute()
{
	GUI* pUI = pControl->GetUI();
	//controller* pCon;

	pUI->PrintMessage("Enter the name of the file");
	Name = pUI->GetSrting() + ".txt";

	
	pUI->ClearDrawArea();

	if (Infile.is_open()) {
		pUI->PrintMessage("File is opened");
		//pCon->Load(file,Name);
	}
		
	else
		pUI->PrintMessage("No file has the same name");
	if (Infile.is_open())

	{

		shape* newshape;
		int num_of_shapes;

		for (int i = 0; i < num_of_shapes; i++)
		{
			int shape;
			Infile >> shape;
			if (shape == _Rectangle)
				newshape = new Rect();
			else if (shape == _Line)
				newshape = new Line;
			else if (shape == _Ellipse)
				newshape = new Ellip;
			else if (shape == _Square)
				newshape = new Squr;
			else if (shape == _IrrPoly)
				newshape = new irr_polygon;

			newshape->Load(Infile);

		}
		Infile.close();

	}
}
