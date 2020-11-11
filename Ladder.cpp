#include "Ladder.h"
#include<fstream>

int Ladder::NumOfLadders = 0;

Ladder::Ladder(const CellPosition& startCellPos, const CellPosition& endCellPos) : GameObject(startCellPos)
{
	this->endCellPos = endCellPos;
	NumOfLadders++;
}

void Ladder::Draw(Output* pOut) const
{
	pOut->DrawLadder(position, endCellPos);
}

void Ladder::Apply(Grid* pGrid, Player* pPlayer)
{


	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- Print a message "You have reached a ladder. Click to continue ..." and wait mouse click

	// 2- Apply the ladder's effect by moving the player to the endCellPos
	//    Review the "pGrid" functions and decide which function can be used for that
	Output* pOut = pGrid->GetOutput();
	pOut->PrintMessage("You have reached a ladder. Click to continue ...");
	pGrid->UpdatePlayerCell(pPlayer, endCellPos);
	pOut->ClearStatusBar();
}

CellPosition Ladder::GetEndPosition() const
{
	return endCellPos;
}

void Ladder::increaseNOL()
{
	NumOfLadders++;
}

void Ladder::save(ofstream& outfile,int type)
{
	if(type==0)
	outfile << position.GetCellNum()<< " "<< endCellPos.GetCellNum()<< endl;

}

int Ladder::getnumofladders()
{
	return NumOfLadders;
}




Ladder::~Ladder()
{
	if (overlap == false)
	{
		CellPosition start = this->GetPosition();
		int starti = start.GetCellNum();
		int  endi = endCellPos.GetCellNum();
		for (size_t j = starti; j <= endi; j = j + 11)
		{
			UI.laddersCells[j] = 0;

		}
		UI.lSpecialCells[starti] = 0;
		UI.lSpecialCells[endi] = 0;
	}
	NumOfLadders--;
}
