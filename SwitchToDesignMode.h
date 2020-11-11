#pragma once
#include "Action.h"
#include"Output.h"
class SwitchToDesignMode :
	public Action
{
	Output p;
public:
	void ReadActionParameters();
	void Execute();

	SwitchToDesignMode(ApplicationManager* pApp);
};

