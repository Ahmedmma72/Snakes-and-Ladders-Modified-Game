#include "AddCardAction.h"

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



AddCardAction::AddCardAction(ApplicationManager* pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

AddCardAction::~AddCardAction()
{
}

void AddCardAction::ReadActionParameters()
{

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	// 2- Read the "cardNumber" parameter and set its data member
	pOut->PrintMessage("New Card: Enter cardNumber ...");

	cardNumber = pIn->GetInteger(pOut);
	// 3- Read the "cardPosition" parameter (its cell position) and set its data member
	pOut->PrintMessage("New Card: Click on Card Cell ...");

	cardPosition = pIn->GetCellClicked();

	pOut->ClearStatusBar();
}

void AddCardAction::Execute()
{


	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- The first line of any Action Execution is to read its parameter first
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	ReadActionParameters();
	if (cardNumber > 0 && cardNumber <= 14)
	{

		if (cardPosition.GetCellNum() != -1 && cardPosition.GetCellNum() != 99&& cardPosition.GetCellNum() != 1) //error
		{




			// 2- Switch case on cardNumber data member and create the appropriate card object type
			Card* pCard = NULL; // will point to the card object type
			switch (cardNumber)
			{
			case 1:
				pCard = new CardOne(cardPosition);
				break;
			case 2:
				pCard = new CardTwo(cardPosition);
				break;
			case 3:
				pCard = new Card3(cardPosition);
				break;
			case 4:
				pCard = new Card4(cardPosition);
				break;
			case 5:
				pCard = new Card5(cardPosition);
				break;
			case 6:
				pCard = new Card6(cardPosition);
				break;
			case 7:
				pCard = new Card7(cardPosition);
				break;
			case 8:
				pCard = new Card8(cardPosition);
				break;
			case 9:
				pCard = new Card9(cardPosition);
				break;
			case 10:
				pCard = new Card10(cardPosition);
				break;
			case 11:
				pCard = new Card11(cardPosition);
				break;
			case 12:
				pCard = new Card12(cardPosition);
				break;
			case 13:
				pCard = new Card13(cardPosition);
				break;
			case 14:
				pCard = new Card14(cardPosition);
				break;

			default:
				pCard = NULL;
				break;


				// A- Add the remaining cases

			}

			// 3- if pCard is correctly set in the switch case (i.e. if pCard is pointing to an object -- NOT NULL)
			if (pCard)
			{
				// A- We get a pointer to the Grid from the ApplicationManager
				Grid* pGrid = pManager->GetGrid();
				Output* pOut = pGrid->GetOutput();
				// B- Make the "pCard" reads its card parameters: ReadCardParameters(), It is virtual and depends on the card type
				pCard->ReadCardParameters(pGrid);
				// C- Add the card object to the GameObject of its Cell:

				bool check = pGrid->AddObjectToCell(pCard);

				// D- if the GameObject cannot be added in the Cell, Print the appropriate error message on statusbar
				if (check == 0)//the cell already contains a game object
				{
					pOut->PrintMessage("the cell already contains a game object");
					delete pCard;
					pCard = NULL;
				}
			}


		}
		else
		{
			pOut->PrintMessage("Error the Cell is invlid");
		}
	}
	else
	{
		pOut->PrintMessage("Error the card num is invlid");
	}
	// Here, the card is created and added to the GameObject of its Cell, so we finished executing the AddCardAction

}
