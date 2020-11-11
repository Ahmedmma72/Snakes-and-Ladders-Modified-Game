#include "Card4.h"
#include"Snake.h"
Card4::Card4(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 4; // set the inherited cardNumber data member with the card number (4 here)
}

void Card4::save(ofstream& outfile, int type)
{
	if (type == 2)
		outfile << cardNumber << " " << position.GetCellNum() << endl;
}

Card4::~Card4(void)
{
	NumOfCards--;
}

void Card4::ReadCardParameters(Grid* pGrid)
{


}

void Card4::Apply(Grid* pGrid, Player* pPlayer)
{

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below

	Card::Apply(pGrid, pPlayer);
	Cell* c = pPlayer->GetCell();
	CellPosition* cellOFPlayer = &c->GetCellPosition();
	int NumOFCELL = cellOFPlayer->GetCellNum();

	//c->GetCellPosition();
	Snake* S = pGrid->getNextSnake(*cellOFPlayer);
	if (S != NULL)//there are snake near
	{
		CellPosition* Cell = &(S->GetEndPosition());
		/*int numofcellendSnake = Cell->GetCellNum();
		int move = numofcellendSnake - NumOFCELL;

		pPlayer->Move(pGrid, move);*/
		pGrid->UpdatePlayerCell(pPlayer, *Cell);
	}
}
