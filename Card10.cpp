#include "Card10.h"
int Card10::price = 0;
int Card10::fees = 0;
bool Card10::bought = false;
bool Card10::saved = false;
bool Card10::added = false;
int Card10::owner = -1;
int Card10::thiscardsnum = 0;
Card10::Card10(const CellPosition& pos):Card(pos)
{
	cardNumber = 10;
	thiscardsnum++;
}

void Card10::ReadCardParameters(Grid* pGrid)
{
	if (!added)
	{
		Output* pOut = pGrid->GetOutput();
		Input* pIn = pGrid->GetInput();
		pOut->PrintMessage("please insert price ");
		int a = pIn->GetInteger(pOut);
		while (a < 0)
		{
			pOut->PrintMessage("Invalid price,please insert a valid price");
			a = pIn->GetInteger(pOut);
		}
		price = a;
		pOut->PrintMessage("please insert fees ");
		a = pIn->GetInteger(pOut);
		while (a < 0)
		{
			pOut->PrintMessage("Invalid price,please insert a valid price");
			a = pIn->GetInteger(pOut);
		}
		fees = a;
		added = true;
	}
}

void Card10::Apply(Grid* pGrid, Player* pPlayer)
{

	
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	
	if (!bought)
	{
		Card::Apply(pGrid, pPlayer);
		int x, y;
		pOut->PrintMessage("Do you want ot buy cells with card" + to_string(cardNumber) + ",enter 1 for yes 0 for no ");
		int a= pIn->GetInteger(pOut);
		if (a!=1&&a!=0)
		{
			pOut->PrintMessage(to_string(a)+" wasn't an option cell wont be bought,click to continue");
			pIn->GetPointClicked(x, y);
			return;
		}
		else if (a==1)
		{
			
			if (pPlayer->GetWallet() - price > 0)
			{
				pPlayer->SetWallet(pPlayer->GetWallet() - price);
				bought = true;
				owner = pPlayer->getplayernum();
				pOut->PrintMessage("cell is bought,Click to continue");
				pIn->GetPointClicked(x, y);
			}
			else
			{
				pOut->PrintMessage("You don't have enough money cell wont be bought click to continue");
				pIn->GetPointClicked(x, y);
				return;
			}
		}
		else if (a == 0)
		{
			pOut->PrintMessage("cell is not bought,click to continue");
			pIn->GetPointClicked(x, y);
			return;
		}


	}
	else
	{
		if (pPlayer->getplayernum()!=owner)
		{
			pGrid->PrintErrorMessage("you haved reached card"+to_string(cardNumber)+ ",Your wallet will be decreased by " + to_string(fees) + "click to continue");
			
			
				pPlayer->SetWallet(pPlayer->GetWallet() - fees);
			
			
		}
		else
		{
			pGrid->PrintErrorMessage("welcome to your cell,click to continue");
		}
	}

}

void Card10::setprice(int a)
{
	price = a;
}

void Card10::setfees(int a)
{
	fees = a;
}

int Card10::getfees()
{
	return fees;
}

int Card10::getprice()
{
	return price;
}

void Card10::save(ofstream& outfile, int type)
{
	if (type == 2)
	{
		if (!saved)
		{
			saved = true;
			outfile << cardNumber << " " << position.GetCellNum() << " " << price << " " << fees << endl;
		}
		else
		{
			outfile << cardNumber << " " << position.GetCellNum() << endl;
		}
	}
}

bool Card10::getaddstat()
{
	return added;
}

void Card10::setaddstat(bool stat)
{
	added = stat;
}

void Card10::setsaved(bool stat)
{
	saved = stat;
}

Card10::~Card10()
{
	NumOfCards--;
	thiscardsnum--;
	if (thiscardsnum ==0)
	{
		bought = false;
		added = false;
		saved = false;
	}
}

