#include "opsave.h"
#include "..\controller.h"
#include "..\GUI/GUI.h"
opsave::~opsave(){}
void opsave::Execute()
{
	GUI* pUI = pControl->GetUI();
	pUI->PrintMessage("ENTER FILE NAME ..");
	string name = pUI->GetSrting();
	ofstream outfile(name);
	pControl->getGraph()->Save(outfile);
	pUI->PrintMessage("saved succesfully "); 

}
