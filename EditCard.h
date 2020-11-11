#pragma once
#include "Action.h"
class EditCard :
	public Action
{
	CellPosition pos;
public:
	EditCard(ApplicationManager* pApp);
	void ReadActionParameters();
	void Execute();
	~EditCard();
};

