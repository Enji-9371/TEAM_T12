#pragma once
#include "controller.h"
#include "GUI/GUI.h"
#include "Shapes/Graph.h"
#include "operations/operation.h"

class opdelete :operation {
public:
	opdelete(controller* pCont);
	virtual void Execute(); 
};