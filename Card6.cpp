#include "Card6.h"
Card6::Card6(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 6; // set the inherited cardNumber data member with the card number (6 here)
}

void Card6::save(ofstream& outfile, int type)
{
	if (type == 2)
		outfile << cardNumber << " " << position.GetCellNum()<< endl;
}

Card6::~Card6(void)
{
	NumOfCards--;
}

void Card6::ReadCardParameters(Grid* pGrid)
{

}

void Card6::Apply(Grid* pGrid, Player* pPlayer)
{

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below

	Card::Apply(pGrid, pPlayer);
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	CellPosition C = pPlayer->GetCell()->GetCellPosition();
	C.AddCellNum(-pPlayer->GetjustRolledDiceNum());
	pGrid->UpdatePlayerCell(pPlayer, C);
	
}
