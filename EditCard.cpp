#include "EditCard.h"
#include"Grid.h"
#include"Cell.h"
#include"Card.h"
#include "Input.h"
#include "Output.h"
#include "CardOne.h"
#include"CardTwo.h"
#include"Card3.h"
#include"Card4.h"
#include"Card5.h"
#include"Card6.h"
#include"Card7.h"
#include"Card8.h"
#include"Card9.h"
#include"Card10.h"
#include"Card11.h"
#include"Card12.h"
#include"Card13.h"
#include"Card14.h"

EditCard::EditCard(ApplicationManager* pApp):Action(pApp)
{
}

void EditCard::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("click on the card you want to edit");
	CellPosition Position = pIn->GetCellClicked();
	pos = Position;
}

void EditCard::Execute()
{
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	Card* pcard;
	bool status = pos.IsValidCell();
	if (status)
	{
		if (pGrid->hascard(pos))
		{
			pcard = pGrid->hascard(pos);
			int num = pcard->GetCardNumber();
			bool status = num != 1 && num != 2 && num != 10 && num != 11 && num != 12 && num != 13 && num != 14;
			if (status)
			{
				pGrid->PrintErrorMessage("Card doesn't take parameters, click to continue");

			}
			else
			{
				pGrid->RemoveObjectFromCell(pos);
				if (num==1)
				{
					pcard = new CardOne(pos);
				}
				else if (num==2)
				{
					pcard = new CardTwo(pos);
				}
				else if (num == 10)
				{
					pcard = new Card10(pos);
					pcard->setaddstat(false);
				}
				else if (num == 11)
				{
					pcard = new Card11(pos);
					pcard->setaddstat(false);
				}
				else if (num == 12)
				{
					pcard = new Card12(pos);
					pcard->setaddstat(false);
				}
				else if (num == 13)
				{
					pcard = new Card13(pos);
					pcard->setaddstat(false);
				}
				else if (num == 14)
				{
					pcard = new Card14(pos);
					pcard->setaddstat(false);
				}
				pcard->ReadCardParameters(pGrid);
				pGrid->AddObjectToCell(pcard);
				pcard->increaseNOC();
				pGrid->PrintErrorMessage("Card will be edited, click to continue");
			}

		}
		else
		{
			pGrid->PrintErrorMessage("Cell Doesn't have a card, click to continue");
		}
	}
	else
	{
		pGrid->PrintErrorMessage("Invalid cell clicked, click to continue");
	}
}

EditCard::~EditCard()
{
}
