#include "Player.h"

#include "GameObject.h"

Player::Player(Cell * pCell, int playerNum) : stepCount(0), wallet(100), playerNum(playerNum),ValidToMove(1)
{
	this->pCell = pCell;
	this->turnCount = 0;

	// Make all the needed initialization or validations
}

// ====== Setters and Getters ======

void Player::SetVaildtoMove(bool v)
{
	ValidToMove = v;
}

void Player::SetCell(Cell * cell)
{
	pCell = cell;
}

Cell* Player::GetCell() const
{
	return pCell;
}

void Player::SetWallet(int wallet)
{
	this->wallet = wallet>0? wallet:0;
	// Make any needed validations
}

int Player::GetWallet() const
{
	return wallet;
}

int Player::GetjustRolledDiceNum() const
{
	return justRolledDiceNum;
}

int Player::GetTurnCount() const
{
	return turnCount;
}

bool Player::GetValidToMove()
{
	return ValidToMove;
}

// ====== Drawing Functions ======

void Player::Draw(Output* pOut) const
{
	color playerColor = UI.PlayerColors[playerNum];


	///TODO: use the appropriate output function to draw the player with "playerColor"
	pOut->DrawPlayer(pCell->GetCellPosition(), playerNum, playerColor);

}

void Player::ClearDrawing(Output* pOut) const
{
	color cellColor = pCell->HasCard() ? UI.CellColor_HasCard : UI.CellColor_NoCard;
	
	
	///TODO: use the appropriate output function to draw the player with "cellColor" (to clear it)
	pOut->DrawPlayer(pCell->GetCellPosition(), playerNum, cellColor);
}

// ====== Game Functions ======

void Player::Move(Grid * pGrid, int diceNumber)
{

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==
	Output* pOut = pGrid->GetOutput();
	// 1- Increment the turnCount because calling Move() means that the player has rolled the dice once
	turnCount++;
	// 2- Check the turnCount to know if the wallet recharge turn comes (recharge wallet instead of move)
	//    If yes, recharge wallet and reset the turnCount and return from the function (do NOT move)
	if (turnCount == 3) //no roll ..... earn money
	{
		pOut->PrintMessage("You in roll 3 no move to earn money");
		wallet += 10 * justRolledDiceNum;
		turnCount = 0;
		if (wallet < 1)
		{
			if (GetCell()->GetGameObject() != NULL)
				GetCell()->GetGameObject()->Apply(pGrid, this);
		}

	}
	else
	{

		if (ValidToMove == 0)//card 8
		{
			ValidToMove = 1;
		}
		else
		{
			// 3- Set the justRolledDiceNum with the passed diceNumber
			justRolledDiceNum = diceNumber;
			// 4- Get the player current cell position, say "pos", and add to it the diceNumber (update the position)
			//    Using the appropriate function of CellPosition class to update "pos"
			CellPosition pos = GetCell()->GetCellPosition();
			if (pos.GetCellNum() != -1)
			{
				pos.AddCellNum(justRolledDiceNum);
				if (pos.GetCellNum() != -1) //still play
				{
					// 5- Use pGrid->UpdatePlayerCell() func to Update player's cell POINTER (pCell) with the cell in the passed position, "pos" (the updated one)
					//    the importance of this function is that it Updates the pCell pointer of the player and Draws it in the new position
					if (wallet >= 1)
					{
						pGrid->UpdatePlayerCell(this, pos);
						if (GetCell()->GetGameObject() != NULL)
							GetCell()->GetGameObject()->Apply(pGrid, this);
					}
					else
						pOut->PrintMessage("You Don't have money to move");
					// 6- Apply() the game object of the reached cell (if any)

					// 7- Check if the player reached the end cell of the whole game, and if yes, Set end game with true: pGrid->SetEndGame(true)
				}
				else // 7- Check if the player reached the end cell of the whole game, and if yes, Set end game with true: pGrid->SetEndGame(true)
				{
					playerWin = pGrid->GetCurrentPlayer()->playerNum + 1;
					pGrid->SetEndGame(true);
					pGrid->UpdatePlayerCell(this, 99);
				}
			}
		}
	}

	if (pGrid->GetEndGame())
	{
		Output* o = pGrid->GetOutput();

		const string s = to_string(playerWin);
		o->PrintMessage("The Game is Ended..The Winner is " + s);
		//o->PrintMessage(s);

	}


}

int Player::getplayernum()
{
	return playerNum;
}

void Player::AppendPlayerInfo(string & playersInfo) const
{
	//if (GetEndGame() == 0)
	playersInfo += "P" + to_string(playerNum) + "(" ;
	playersInfo += to_string(wallet) + ", ";
	playersInfo += to_string(turnCount) + ")";
	
}

void Player::NewGame(Grid* pGrid)
{
	playerWin = -1;
	stepCount=0;		   // step count which is the same as his cellNum: from 1 to NumVerticalCells*NumHorizontalCells
	wallet=100;		       // player's wallet (how many coins he has -- integer)
	justRolledDiceNum = 0; // the current dice number which is just rolled by the player
	turnCount=0;         // a counter that starts with 0, is incremented with each dice roll
						   // and reset again when reached 3
	ValidToMove=1;
	pGrid->UpdatePlayerCell(this, 1);
}
