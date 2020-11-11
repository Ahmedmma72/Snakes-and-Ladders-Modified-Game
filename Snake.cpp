#include "Snake.h"
#include<fstream>


int Snake::NumOfSnakes = 0;
Snake::Snake(const CellPosition& startCellPos, const CellPosition& endCellPos) : GameObject(startCellPos)
{
	this->endCellPos = endCellPos;
	NumOfSnakes++;
	
}

void Snake::Draw(Output* pOut) const
{
	pOut->DrawSnake(position, endCellPos);
}

void Snake::Apply(Grid* pGrid, Player* pPlayer)
{


	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- Print a message "You have reached a snake. Click to continue ..." and wait mouse click

	// 2- Apply the ladder's effect by moving the player to the endCellPos
	//    Review the "pGrid" functions and decide which function can be used for that
	Output* pOut = pGrid->GetOutput();
	pOut->PrintMessage("You have reached a Snake. Click to continue ...");
	pGrid->UpdatePlayerCell(pPlayer, endCellPos);
	pOut->ClearStatusBar();


}

CellPosition Snake::GetEndPosition() const
{
	return endCellPos;
}

void Snake::save(ofstream& outfile,int type)
{
	if(type==1)
		outfile << position.GetCellNum() << " " << endCellPos.GetCellNum() << endl;
}

void Snake::increaseNOS()
{
	NumOfSnakes++;
}

int Snake::getnumofsnakes()
{
	return NumOfSnakes;
}



Snake::~Snake()
{
	if (overlap == false)
	{
		CellPosition start = this->GetPosition();
		int endi = start.GetCellNum();
		int  starti = endCellPos.GetCellNum();
		for (size_t j = starti; j <= endi; j = j + 11)
		{
			UI.snakesCells[j] = 0;

		}
		UI.sSpecialCells[starti] = 0;
		UI.sSpecialCells[endi] = 0;
	}
	NumOfSnakes--;
}
