#include "Card8.h"
#include<time.h>
#include"RollDiceAction.h"
Card8::Card8(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 8; // set the inherited cardNumber data member with the card number (1 here)
}

void Card8::save(ofstream& outfile, int type)
{
	if (type == 2)
		outfile << cardNumber << " " << position.GetCellNum()<< endl;
}

Card8::~Card8(void)
{
	NumOfCards--;
}

void Card8::ReadCardParameters(Grid* pGrid)
{


}

void Card8::Apply(Grid* pGrid, Player* pPlayer)
{

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==

	// 1- Call Apply() of the base class Card to print the message that you reached this card number
	Card::Apply(pGrid, pPlayer);
	// 2- Decrement the wallet of pPlayer by the walletAmount data member of CardOne


	pPlayer->SetVaildtoMove(0);//to didnot move in the next turn
	

}
