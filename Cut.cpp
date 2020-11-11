#include "Cut.h"
#include "Input.h"
#include "Output.h"
#include "Ladder.h"
#include"Card.h"

Cut::Cut(ApplicationManager* pApp) : Action(pApp)
{

}

void Cut::ReadActionParameters()
{
	// Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// Read the Pos parameter
	pOut->PrintMessage("click on the Object To Cut");
	Pos = pIn->GetCellClicked();


}

void Cut::Execute()
{
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

/*	Cell* C = pGrid->GetCellFromPos(&Pos);
	if (C->HasCard() != NULL)
	{
		pGrid->SetClipboard(C->HasCard());
		pGrid->UpdateInterface();
		pGrid->RemoveObjectFromCell(Pos);
		pOut->PrintMessage("Card Cut Succesfull !");
	}
	else
		pOut->PrintMessage("This Cell Didn't Have A Card !");*/
	if (Pos.GetCellNum() == -1)
		pOut->PrintMessage("Invild Cell");
	else if (pGrid->GetGetCardFromPos(&Pos) != NULL)
	{
		//Card* C = new Card(*pGrid->GetGetCardFromPos(&Pos));
		pGrid->SetClipboard(pGrid->GetGetCardFromPos(&Pos),1);
		pGrid->UpdateInterface();//not needed why you put it 
	//	pGrid->RemoveObjectFromCell(Pos);
		pOut->PrintMessage("Card Cut Succesfull !");
	}
	else
		pOut->PrintMessage("This Cell Didn't Have A Card !");

}

Cut::~Cut()
{
}
