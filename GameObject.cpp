#include "GameObject.h"
#include"Ladder.h"
#include"Card.h"
#include"Snake.h"
#include"CellPosition.h"
#include "UI_Info.h"
GameObject::GameObject(const CellPosition& pos)
{
	position = pos; // Sets Position
}

CellPosition GameObject::GetPosition() const
{
	return position;
}

bool GameObject::IsOverLapping()
{

	overlap = false;
	CellPosition startcell = this->GetPosition();
	
	int starti=0, endi=0;
	Ladder* p = dynamic_cast<Ladder*>(this);
	Snake* s= dynamic_cast<Snake*>(this);
	Card* c = dynamic_cast<Card*>(this);
	if (p)
	{
		CellPosition endcell = p->GetEndPosition();
		 starti = startcell.GetCellNum();
		 endi = endcell.GetCellNum();
		 for (size_t i = starti; i <= endi; i = i + 11)
		 {
			 bool status = UI.laddersCells[i] == 1 || UI.sSpecialCells[starti] == 3 ||( UI.sSpecialCells[endi] == 3 && UI.sSpecialCells[starti] == 4 )||UI.cardsindex[starti]==1;
			 if (status)
			 {
				 overlap = true;
				 break;
			 }
		 }
		 if (!overlap)
		 {
			
			 for (size_t i = starti; i <= endi; i = i + 11)
			 {
				 UI.laddersCells[i] = 1;

			 }
			 UI.lSpecialCells[starti] = 1;//ladder startcell
			 UI.lSpecialCells[endi] = 2;//ladder endcell

		 }
	}
	else if (s)
	{
	
		CellPosition endcell = s->GetEndPosition();
		endi = startcell.GetCellNum();
		starti = endcell.GetCellNum();
		for (size_t i = starti; i <= endi; i = i + 11)
		{
			bool status = UI.snakesCells[i] == 2|| UI.lSpecialCells[endi] ==1|| (UI.lSpecialCells[endi] == 2&&UI.lSpecialCells[starti]==1 ) || UI.cardsindex[starti] == 1;
			if (status)
			{
				overlap = true;
				break;
			}
		}
		if (!overlap)
		{
			for (size_t i = starti; i <= endi; i = i + 11)
			{
				UI.snakesCells[i] = 2;

			}
			UI.sSpecialCells[starti] = 4;//snake endcell
			UI.sSpecialCells[endi] = 3;//snake startcell
		}
	}
	else if (c)
	{
		
			int num = startcell.GetCellNum();
			bool stat = UI.cardsindex[num] == 1 || UI.sSpecialCells[num] == 3 || UI.lSpecialCells[num] == 1;
			if (stat)
			{
				overlap = true;
			}
			if (!overlap)
			{
				UI.cardsindex[num] = 1;

			}
		 
	
	}
	
	

	return overlap;

}

void GameObject::setsaved(bool stat)
{
}




GameObject::~GameObject()
{
}