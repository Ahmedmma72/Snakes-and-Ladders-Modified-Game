#pragma once
#include "Action.h"
#include"Output.h"
class SwitchToPlayMode :public Action
{
	Output p;
public:
	void ReadActionParameters();
	void Execute();

	SwitchToPlayMode(ApplicationManager* pApp);
};

