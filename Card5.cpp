#include "Card5.h"
#include"Grid.h"
Card5::Card5(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 5; // set the inherited cardNumber data member with the card number (5 here)
}

void Card5::save(ofstream& outfile, int type)
{
	if (type == 2)
		outfile << cardNumber << " " << position.GetCellNum() << endl;
}

Card5::~Card5(void)
{
	NumOfCards--;
}

void Card5::ReadCardParameters(Grid* pGrid)
{


}

void Card5::Apply(Grid* pGrid, Player* pPlayer)
{

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below
	Card::Apply(pGrid, pPlayer);
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	CellPosition C = pPlayer->GetCell()->GetCellPosition();
	C.AddCellNum(pPlayer->GetjustRolledDiceNum());
	pGrid->UpdatePlayerCell(pPlayer, C);
	
}
