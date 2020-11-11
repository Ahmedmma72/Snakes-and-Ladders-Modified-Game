#include "Card.h"
#include<fstream>


int Card::NumOfCards = 0;
Card::Card(const CellPosition & pos) : GameObject(pos) // sets the cell position of the GameObject
{
	NumOfCards++;
}

void Card::SetCardNumber(int cnum)
{
	cardNumber = cnum; // needs validation
}

int Card::GetCardNumber()
{
	return cardNumber;
}

void Card::Draw(Output* pOut) const
{

	///TODO: call the appropriate Ouput function that draws a cell containing the "cardNumber" in "position"

	pOut->DrawCell(position, cardNumber); //done
}

void Card::ReadCardParameters(Grid * pGrid)
{
	// we should not make it pure virtual because some Cards doesn't have parameters
	// and if we make it pure virtual, that will make those Cards abstract classes
}

void Card::Apply(Grid* pGrid, Player* pPlayer) 
{
	// As written below the "Roll Dice" action in the document ==> Check the Project Document
	// "If a player reaches a card of any other type", the following message should be printed then wait mouse click

	pGrid->PrintErrorMessage("You have reached card " + to_string(cardNumber) + ". Click to continue ...");
}

//void Card::save(ofstream& outfile,int type)
//{
//	if(type==2)
//	outfile << cardNumber << " " << position.GetCellNum() << endl;
//}

int Card::getnumofcards()
{
	return NumOfCards;
}

void Card::setwalletamount(int a)
{
}

int Card::getwalletamount()
{
	return 0;
}

void Card::setpos(CellPosition p)
{
}

void Card::setprice(int a)
{
}

void Card::setfees(int a)
{
}

int Card::getfees()
{
	return 0;
}

int Card::getprice()
{
	return 0;
}

bool Card::getaddstat()
{
	return false;
}

void Card::setaddstat(bool stat)
{
	
}

void Card::increaseNOC()
{
	NumOfCards++;
}

void Card::setsaved(bool stat)
{
}

Card::~Card()
{
	int num = position.GetCellNum();
	UI.cardsindex[num]=0;
}
