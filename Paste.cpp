#include "Paste.h"
#include "Input.h"
#include "Output.h"
#include "Card.h"
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
Paste::Paste(ApplicationManager* pApp):Action(pApp)
{

}
void Paste::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// Read the Pos parameter
	pOut->PrintMessage("click on the Cell To Paste");
	Pos = pIn->GetCellClicked();
}

void Paste::Execute()
{
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	bool cut = 0;
	Card *p = pGrid->GetClipboard(cut);
	bool check = 0;
	if (p != NULL)
	{
		if (Pos.GetCellNum() != -1)
		{
			if (dynamic_cast<CardOne*>(p) != NULL)
			{
				PasteCard = new CardOne(Pos);
				PasteCard->setwalletamount(p->getwalletamount());
				check = pGrid->AddObjectToCell(PasteCard);
				// D- if the GameObject cannot be added in the Cell, Print the appropriate error message on statusbar
				
			}
			else if (dynamic_cast<CardTwo*>(p) != NULL)
			{
				PasteCard = new CardTwo(Pos);
				PasteCard->setwalletamount(p->getwalletamount());
				check = pGrid->AddObjectToCell(PasteCard);
				
				// D- if the GameObject cannot be added in the Cell, Print the appropriate error message on statusbar

			}
			else if (dynamic_cast<Card3*>(p) != NULL)
			{
				PasteCard = new Card3(Pos);
				check = pGrid->AddObjectToCell(PasteCard);
				// D- if the GameObject cannot be added in the Cell, Print the appropriate error message on statusbar

			}
			else if (dynamic_cast<Card4*>(p) != NULL)
			{
				PasteCard = new Card4(Pos);
				check = pGrid->AddObjectToCell(PasteCard);
				// D- if the GameObject cannot be added in the Cell, Print the appropriate error message on statusbar

			}
			else if (dynamic_cast<Card5*>(p) != NULL)
			{
				PasteCard = new Card5(Pos);
				check = pGrid->AddObjectToCell(PasteCard);
				// D- if the GameObject cannot be added in the Cell, Print the appropriate error message on statusbar

			}
			else if (dynamic_cast<Card6*>(p) != NULL)
			{
				PasteCard = new Card6(Pos);
				check = pGrid->AddObjectToCell(PasteCard);
				// D- if the GameObject cannot be added in the Cell, Print the appropriate error message on statusbar

			}
			else if (dynamic_cast<Card7*>(p) != NULL)
			{
				PasteCard = new Card7(Pos);
				check = pGrid->AddObjectToCell(PasteCard);
				// D- if the GameObject cannot be added in the Cell, Print the appropriate error message on statusbar

			}
			else if (dynamic_cast<Card8*>(p) != NULL)
			{
				PasteCard = new Card8(Pos);
				check = pGrid->AddObjectToCell(PasteCard);
				// D- if the GameObject cannot be added in the Cell, Print the appropriate error message on statusbar

			}
			else if (dynamic_cast<Card9*>(p) != NULL)
			{
				PasteCard = new Card9(Pos);
				PasteCard->setpos(p->GetPosition());
				check = pGrid->AddObjectToCell(PasteCard);
				// D- if the GameObject cannot be added in the Cell, Print the appropriate error message on statusbar

			}
			else if (dynamic_cast<Card10*>(p) != NULL)
			{
				PasteCard = new Card10(Pos);
				PasteCard->setfees(p->getfees());
				PasteCard->setprice(p->getprice());
				check = pGrid->AddObjectToCell(PasteCard);
				
				
			}
			else if (dynamic_cast<Card11*>(p) != NULL)
			{
				PasteCard = new Card11(Pos);
				PasteCard->setfees(p->getfees());
				PasteCard->setprice(p->getprice());
				check = pGrid->AddObjectToCell(PasteCard);


			}
			else if (dynamic_cast<Card12*>(p) != NULL)
			{
				PasteCard = new Card12(Pos);
				PasteCard->setfees(p->getfees());
				PasteCard->setprice(p->getprice());
				check = pGrid->AddObjectToCell(PasteCard);


			}
			else if (dynamic_cast<Card13*>(p) != NULL)
			{
				PasteCard = new Card13(Pos);
				PasteCard->setfees(p->getfees());
				PasteCard->setprice(p->getprice());
				check = pGrid->AddObjectToCell(PasteCard);


			}
			else if (dynamic_cast<Card14*>(p) != NULL)
			{
			PasteCard = new Card11(Pos);
			PasteCard->setfees(p->getfees());
			PasteCard->setprice(p->getprice());
			check = pGrid->AddObjectToCell(PasteCard);


			}

			if (check == 0)//the cell already contains a game object
				pOut->PrintMessage("the cell already contains a game object");
			else
			{
				PasteCard->Draw(pOut);
				pGrid->SetClipboard(NULL);
			}
			if (cut == 1 && check)
				pGrid->RemoveObjectFromCell(p->GetPosition());


		}
		else
			pOut->PrintMessage("Invaild Cell");

	}
	else
		pOut->PrintMessage("You didn't copy or cut Card To Paste it");
}

Paste::~Paste()
{
}
