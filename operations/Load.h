#pragma once
#include "operation.h"
#include <fstream>

class  Load : public operation
{
private:
	string Name;
	ifstream Infile;
public:
	Load(controller* pCont);
	virtual void Execute();
};