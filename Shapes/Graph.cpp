#include "Graph.h"
#include "../GUI/GUI.h"
#include"../Shapes/Shape.h"

Graph::Graph()
{
	selectedShape = nullptr;   ///if null it is not selected    if not it is selected  isselected true_> pointer of a shape instead of the niullptr
}


Graph::~Graph()
{
}

//==================================================================================//
//						shapes Management Functions					     			//
//==================================================================================//

//Add a shape to the list of shapes
void Graph::Addshape(shape* pShp)
{
	//Add a new shape to the shapes vector
	shapesList.push_back(pShp);	
}


/////////////////////////////////////////
// //////////////////////////////////////
// //////////////////////////////////
// ////////////////////////////////////////////
// ////////////   ME   ////////////////////
// //////////////////////////////////////
// ////////////////////////////////////
// /////////////////////////////
//////////////////////////////////

shape* Graph::GetSelected()
{
	return selectedShape;
}

//void Graph::ChngSnglWidth(int wnum) //change width of a selected shape
//{
//	for (int i = 0; i < shapesList.size(); i++)
//	{
//		if (selectedShape == shapesList[i])
//		{
//			shapesList[i]->ChngDrawWidth(wnum);
//		}
//	}
//}
// 
//void Graph::ChngSnglBrdrClr(color Dclr)  //change border color of a single selected shape
//{
//	for (int i = 0; i < shapesList.size(); i++)
//	{
//		if (selectedShape == shapesList[i])
//		{
//			shapesList[i]->ChngDrawClr(Dclr);
//		}
//	}
//}
//
//void Graph::ChngSnglFillClr(color Fclr)   //change fill color of a single selected shape
//{
//	for (int i = 0; i < shapesList.size(); i++)
//	{
//		if (selectedShape == shapesList[i])
//		{
//			shapesList[i]->ChngFillClr(Fclr);
//		}
//	}
//}
 
 
 
 







//		if (selectedShape == shapesList[i])
//		{
//			GUI* pUI;
//			pUI->PrintMessage("Press W to change width, B to change border color, F to change fill color");
//			string get_input = pUI->GetSrting();
//			if (get_input == "W" || get_input == "w")
//			{
//				shapesList[i]->ChngDrawWidth(wnum);
//			}
//			else if (get_input == "B" || get_input == "b"|| get_input == "F" || get_input == "f")
//			{
//				pUI->PrintMessage("Press 'R' for RED, 'G' for GREEN, 'BL' for BLUE, 'Y' for Yellow, 'BK' for BLACK");
//				char get_input_CLR = pUI->GetSrting();
//				if (get_input == "B" || get_input == "b")
//				{
//					switch (get_input_CLR)
//					{
//					case 'R': ChngFillClr(RED); break;
//					case 'G': ChngFillClr(GREEN); break;
//					case 'BL': ChngFillClr(BLUE); break;
//					case 'Y': ChngFillClr(YELLOW); break;
//					case 'BK': ChngFillClr(BLACK); break;
//					}
//				}
//			
//			}
//		}
//	}
//}

////////////////////////////////////////////////////////////////////////////////////
//Draw all shapes on the user interface
void Graph::Draw(GUI* pUI) const
{
	pUI->ClearDrawArea();
	for (auto shapePointer : shapesList)
		shapePointer->Draw(pUI);
}

shape* Graph::Getshape(int x, int y) const
{
	//If a shape is found return a pointer to it.
	//if this point (x,y) does not belong to any shape return NULL


	///Add your code here to search for a shape given a point x,y	

	return nullptr;
}


/////////////////////////////////////////
// //////////////////////////////////////
// //////////////////////////////////
// ////////////////////////////////////////////
// ////////////   ME   ////////////////////
// //////////////////////////////////////
// ////////////////////////////////////
// /////////////////////////////
//////////////////////////////////
//void chngsnglbrdrclr(shape* selectedShape, operationType)  //change border color of a single shape
//{
//
//}
//void chngsnglfillclr(shape* selectedShape, operationType)  //change fill color of a single shape
//{
//
//}
//void chngsnglbrdrwidth( int newwidth)  //change border width of a single shape
//{
//
//}
