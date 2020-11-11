#include "Card7.h"
#include<time.h>
#include"RollDiceAction.h"
#include"Grid.h"
Card7::Card7(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 7; // set the inherited cardNumber data member with the card number (7 here)
}

void Card7::save(ofstream& outfile, int type)
{
	if (type == 2)
		outfile << cardNumber << " " << position.GetCellNum() << endl;
}

Card7::~Card7(void)
{
	NumOfCards--;
}

void Card7::ReadCardParameters(Grid* pGrid)
{


}

void Card7::Apply(Grid* pGrid, Player* pPlayer)
{

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==

	// 1- Call Apply() of the base class Card to print the message that you reached this card number
	Card::Apply(pGrid, pPlayer);
	// 2- Decrement the wallet of pPlayer by the walletAmount data member of CardOne

	int Roll=0;
	bool end = pGrid->GetEndGame();
	if (end)
	{
		pGrid->PrintErrorMessage("Game Finshed......");
	}
	else
	{
		srand((int)time(NULL)); // time is for different seed each run
		Roll = 1 + rand() % 6; // from 1 to 6 --> should change seed

	}
	CellPosition C;
	
	pGrid->UpdatePlayerCell(pPlayer, C.GetCellPositionFromNum(pPlayer->GetCell()->GetCellPosition().GetCellNum() + Roll));
	
	//pGrid->AdvanceCurrentPlayer();//to switch to new player

}
