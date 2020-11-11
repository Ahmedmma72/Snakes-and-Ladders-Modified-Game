#include "Deleteto.h"
#include"Cell.h"
#include"Input.h"
#include"Output.h"
#include"Grid.h"



Deleteto::Deleteto(ApplicationManager* pApp) :Action(pApp) //
{
}


Deleteto::~Deleteto(void)
{
}

void Deleteto::Execute()
{

	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	pGrid->RemoveObjectFromCell(cp);
	pOut->PrintMessage("object removed");



}


void Deleteto::ReadActionParameters()
{

	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("Click on the cell to delete its gameobject...");
	cp = pIn->GetCellClicked();
	
}
