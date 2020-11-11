#include "CellPosition.h"
#include "UI_Info.h"


CellPosition::CellPosition()
{
	// (-1) indicating an invalid cell (uninitialized by the user)
	vCell = -1;
	hCell = -1;
}

CellPosition::CellPosition(int v, int h)
{
	// (-1) indicating an invalid cell (uninitialized by the user)
	vCell = -1;
	hCell = -1;

	SetVCell(v);
	SetHCell(h);
}

CellPosition::CellPosition(int cellNum)
{
	(*this) = GetCellPositionFromNum(cellNum); // the function call with build a cell position (vCell and hCell)
												// from the passed (cellNum)
												// (*this) = ... --> this will copy the returned (vCell and hCell)
												//                   to the data members (vCell and hCell)
}

bool CellPosition::SetVCell(int v)
{
	if (v < 0 || v>8)
	{
		vCell = -1;
		return false;
		
	}
	else
	{
		vCell = v;
		return true;
		
	}
}

bool CellPosition::SetHCell(int h)
{
	if (h < 0 || h > 11)
	{
		hCell = -1;
		return false;
	}
	else
	{
		hCell = h;
		return true;
	}




}

int CellPosition::VCell() const
{
	return vCell;
}

int CellPosition::HCell() const
{
	return hCell;
}

bool CellPosition::IsValidCell() const
{
	if (vCell >= 0 && vCell <= 8 && hCell >= 0 && hCell <= 10)
		return true;
	else 
		return false;
}

int CellPosition::GetCellNum() const
{
	return GetCellNumFromPosition(*this); // (*this) is the calling object of GetCellNum
										  // which means the object of the current data members (vCell and hCell)
}

int CellPosition::GetCellNumFromPosition(const CellPosition& cellPosition)
{
	
	int CellNum;
		if (cellPosition.VCell()==-1||cellPosition.HCell()==-1)
		{
			CellNum = -1;
			return CellNum;
		}
		else
		{
			CellNum = 89 - cellPosition.vCell * 11 + cellPosition.hCell;
			return CellNum;
		}
	
}

CellPosition CellPosition::GetCellPositionFromNum(int cellNum)
{
	// this is a static function (do NOT need a calling object so CANNOT use the data members of the calling object, vCell&hCell)
	CellPosition position(-1,-1);
	if (cellNum < 1 || cellNum>99)
	{

		return position;
	}
	else
	{
		

		if (cellNum % 11 == 0)
		{
			position.SetHCell(10);
			position.SetVCell(9 - cellNum / 11);
		}
		else
		{
			position.SetHCell((cellNum % 11) - 1);
			position.SetVCell(8 - cellNum / 11);
		}
		return position;
	}
	
}

void CellPosition::AddCellNum(int addedNum)
{
	int sum;
	
	sum =this->GetCellNum() + addedNum;
	CellPosition c1(sum);
	c1 = GetCellPositionFromNum(sum);
	(*this) = c1;
	
}