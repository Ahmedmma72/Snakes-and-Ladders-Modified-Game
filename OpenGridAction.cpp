#include "OpenGridAction.h"
#include "Input.h"
#include "Output.h"
#include "Grid.h"
#include "Ladder.h"
#include "Snake.h"
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

#include <string>
#include<fstream>
OpenGridAction::OpenGridAction(ApplicationManager* pApp) :Action(pApp)
{
	cancelaction = false;
}

void OpenGridAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	pOut->PrintMessage("Please Enter The File name");
	string Name = pIn->GetSrting(pOut) + ".txt";
	strcpy(name, Name.c_str());
	ReadFromFile.open(name);
	bool status = ReadFromFile.is_open();
	while (!status)
	{
		pOut->PrintMessage("There is no file with such name.(if you want ot cancel action press 1 to continue press 0)");
		int value = pIn->GetInteger(pOut);
		if (value != 1 && value != 0)
		{
			pOut->PrintMessage(to_string(value) + " wasn't an option action is canceled");
			cancelaction = true;
			status = true;
		}
		else if (value == 1)
		{
			pOut->PrintMessage("action is canceled");
			cancelaction = true;
			status = true;
		}
		else if (value == 0)
		{

			pOut->PrintMessage("Please enter another name ");
			Name = pIn->GetSrting(pOut) + ".txt";
			strcpy(name, Name.c_str());
			ReadFromFile.open(name);
			status = ReadFromFile.is_open();
			cancelaction = false;
		}

	}


}

void OpenGridAction::Execute()
{
	ReadActionParameters();
	if (!cancelaction)
	{
		
		Grid* pGrid = pManager->GetGrid();
		Output* pOut = pGrid->GetOutput();
		Input* pIn = pGrid->GetInput();

		pGrid->cleargrid();
		for (int i = 0; i < 4; i++)
		{
			Player* Pplayer = pGrid->GetCurrentPlayer();
			Pplayer->NewGame(pGrid);
			pGrid->AdvanceCurrentPlayer();

		}
		pGrid->setCurrentPlayer(0);
		pGrid->UpdateInterface();
		int NOL, NOS, NOC, sn, en, cardnum, pos,price,fees;
		CellPosition startcell;
		CellPosition endcell;
		//drawing ladders
		ReadFromFile >> NOL;
		if (NOL > 0)
		{
			for (size_t i = 0; i < NOL; i++)
			{
				ReadFromFile >> sn >> en;
				startcell = startcell.GetCellPositionFromNum(sn);
				endcell = endcell.GetCellPositionFromNum(en);
				Ladder* pLadder = new Ladder(startcell, endcell);
				pGrid->AddObjectToCell(pLadder);
				/*pLadder->increaseNOL();*/
			}
		}
		//drawing snakes
		ReadFromFile >> NOS;
		if (NOS > 0)
		{
			for (size_t i = 0; i < NOS; i++)
			{
				ReadFromFile >> sn >> en;
				startcell = startcell.GetCellPositionFromNum(sn);
				endcell = endcell.GetCellPositionFromNum(en);
				Snake* pSnake = new Snake(startcell, endcell);
				pGrid->AddObjectToCell(pSnake);
				/*pSnake->increaseNOS();*/
			}
		}
		//drawing cards
		ReadFromFile >> NOC;
		if (NOC > 0)
		{
			Card* pcard;
			for (size_t i = 0; i < NOC; i++)
			{
				ReadFromFile >> cardnum;
				ReadFromFile >> pos;
				startcell = startcell.GetCellPositionFromNum(pos);
				if (cardnum == 1)
				{
					int wallet;
					pcard = new CardOne(startcell);
					ReadFromFile >> wallet;
					pcard->setwalletamount(wallet);
					
				}
				else if (cardnum == 2)
				{
					int wallet;
				    pcard = new CardTwo(startcell);
					ReadFromFile >> wallet;
					pcard->setwalletamount(wallet);
					
				}
				else if (cardnum == 3)
				{
					 pcard = new Card3(startcell);
					
				}
				else if (cardnum == 4)
				{
					 pcard = new Card4(startcell);
					
				}
				else if (cardnum == 5)
				{
					 pcard = new Card5(startcell);
				
				}
				else if (cardnum == 6)
				{
					 pcard = new Card6(startcell);
					
				}
				else if (cardnum == 7)
				{
					 pcard = new Card7(startcell);
				
				}
				else if (cardnum == 8)
				{
					 pcard = new Card8(startcell);
					
				}
				else if (cardnum == 9)
				{
					 pcard = new Card9(startcell);
				
				}
				
				else if (cardnum == 10)
				{
					pcard = new Card10(startcell);
					if (!pcard->getaddstat())
					{
						pcard->setaddstat(true);
						ReadFromFile >> price;
						pcard->setprice(price);
						ReadFromFile >> fees;
						pcard->setfees(fees);
					}
					
				
				}
				else if (cardnum == 11)
				{
					 pcard = new Card11(startcell);
					 if (!pcard->getaddstat())
					 {
						 pcard->setaddstat(true);
						 ReadFromFile >> price;
						 pcard->setprice(price);
						 ReadFromFile >> fees;
						 pcard->setfees(fees);
					 }
				}
		   		else if (cardnum == 12)
				{
					 pcard = new Card12(startcell);
					 if (!pcard->getaddstat())
					 {
						 pcard->setaddstat(true);
						 ReadFromFile >> price;
						 pcard->setprice(price);
						 ReadFromFile >> fees;
						 pcard->setfees(fees);
					 }
				
				}
				else if (cardnum == 13)
				{
					 pcard = new Card13(startcell);
					 if (!pcard->getaddstat())
					 {
						 pcard->setaddstat(true);
						 ReadFromFile >> price;
						 pcard->setprice(price);
						 ReadFromFile >> fees;
						 pcard->setfees(fees);
					 }
				}
				else if (cardnum == 14)
				{
					 pcard = new Card14(startcell);
					 if (!pcard->getaddstat())
					 {
						 pcard->setaddstat(true);
						 ReadFromFile >> price;
						 pcard->setprice(price);
						 ReadFromFile >> fees;
						 pcard->setfees(fees);
					 }
				}
				pGrid->AddObjectToCell(pcard);
				/*pcard->increaseNOC();*/
			}
		}
		
		//pGrid->PrintErrorMessage("File will be opened,Click to continue");
		
		ReadFromFile.close();
	}
}

OpenGridAction::~OpenGridAction()
{
}
