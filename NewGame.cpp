#include "NewGame.h"
#include"Grid.h"
#include"Player.h"
NewGame::NewGame(ApplicationManager* pApp) :Action(pApp)
{
}

void NewGame::ReadActionParameters()
{
}

void NewGame::Execute()
{
	Grid* pGrid = pManager->GetGrid();
	for (int i = 0; i < 4; i++)
	{
		Player* Pplayer = pGrid->GetCurrentPlayer();
		Pplayer->NewGame(pGrid);
		pGrid->AdvanceCurrentPlayer();
		
	}
	pGrid->setCurrentPlayer(0);

}
