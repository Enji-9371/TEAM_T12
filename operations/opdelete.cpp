#include "opdelete.h"

opdelete::opdelete(controller* pCont) : operation(pCont)
{}

void opdelete::Execute()
{
	GUI* pUI = pControl->GetUI();

	Graph* pGr = pControl->getGraph();

//	pGr->Fdelete(pGr->getselected()); 
}



