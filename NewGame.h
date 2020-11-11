#pragma once
#include "Action.h"
class NewGame :
	public Action
{
public:
	NewGame(ApplicationManager* pApp);
	void ReadActionParameters();
	void Execute();
};

