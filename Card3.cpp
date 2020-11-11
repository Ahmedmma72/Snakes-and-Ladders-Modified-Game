#include "Card3.h"
#include"Ladder.h"

Card3::Card3(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 3; // set the inherited cardNumber data member with the card number (3 here)
}

void Card3::save(ofstream& outfile, int type)
{
	if (type == 2)
		outfile << cardNumber << " " << position.GetCellNum()<< endl;
}

Card3::~Card3(void)
{
	NumOfCards--;
}

void Card3::ReadCardParameters(Grid* pGrid)
{


}

void Card3::Apply(Grid* pGrid, Player* pPlayer)
{

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==

	// 1- Call Apply() of the base class Card to print the message that you reached this card number
	Card::Apply(pGrid, pPlayer);
	Cell *c = pPlayer->GetCell();
	CellPosition* cellOFPlayer = &c->GetCellPosition();
	int NumOFCELL = cellOFPlayer->GetCellNum();
	
	//c->GetCellPosition();
	Ladder* L = pGrid->GetNextLadder(c->GetCellPosition());
	if (L != NULL)//there are ladder near
	{
		CellPosition* Cell = &(L->GetEndPosition());
		/*int numofcellendLadder = Cell->GetCellNum();
		int move = numofcellendLadder - NumOFCELL;*/

		//pPlayer->Move(pGrid, move);
		pGrid->UpdatePlayerCell(pPlayer, *Cell);
	}
}
