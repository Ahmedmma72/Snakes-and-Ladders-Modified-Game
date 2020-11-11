#include "Card9.h"
#include"CellPosition.h"
Card9::Card9(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 9; // set the inherited cardNumber data member with the card number (1 here)
}

void Card9::save(ofstream& outfile, int type)
{
	if (type == 2)
		outfile << cardNumber << " " << position.GetCellNum() << " " <<pos.GetCellNum()<< endl;
}

void Card9::setpos(CellPosition p)
{
	pos = p;
}

Card9::~Card9(void)
{
	NumOfCards--;
}

void Card9::ReadCardParameters(Grid* pGrid)
{
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	pOut->PrintMessage("Click on cell you want to move");
	pos = pIn->GetCellClicked();
	if (pos.GetCellNum() == -1)
	{

		pOut->ClearStatusBar();
		pOut->PrintMessage("Invalid Cell");
		delete this;
	
		
	}
	else
		pOut->ClearStatusBar();
}

void Card9::Apply(Grid* pGrid, Player* pPlayer)
{

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below
	

	Card::Apply(pGrid, pPlayer);
	//ReadCardParameters(pGrid);

	/*int l=pos.GetCellNum();

	Cell* ce = pPlayer->GetCell();
	CellPosition* cellOFPlayer = &ce->GetCellPosition();
	int NumOFCELL = cellOFPlayer->GetCellNum();
	int move = l - NumOFCELL;
	pPlayer->Move(pGrid, move);*/
	Output* pOut = pGrid->GetOutput();
	pGrid->UpdatePlayerCell(pPlayer, pos);
}
