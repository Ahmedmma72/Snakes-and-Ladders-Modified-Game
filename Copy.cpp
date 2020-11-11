#include "Copy.h"

#include "Input.h"
#include "Output.h"
#include "Ladder.h"
Copy::Copy(ApplicationManager* pApp) : Action(pApp)
{
}

void Copy::ReadActionParameters()
{
	// Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// Read the Pos parameter
	pOut->PrintMessage("click on the Object To Copy");
	Pos = pIn->GetCellClicked();

	
}

void Copy::Execute()
{
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	if (Pos.GetCellNum() == -1)
		pOut->PrintMessage("Invild Cell");
	else if (pGrid->GetGetCardFromPos(&Pos) != NULL)
	{
		pGrid->SetClipboard(pGrid->GetGetCardFromPos(&Pos));
		pGrid->UpdateInterface();//not needed why you did it??
		pOut->PrintMessage("Card Copy Succesfull !");
	}
	else
		pOut->PrintMessage("This Cell Didn't Have A Card !");

}

Copy::~Copy()
{
}
