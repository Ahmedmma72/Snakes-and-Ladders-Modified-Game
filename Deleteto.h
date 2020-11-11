#pragma once
#include "Action.h"
class Deleteto :
	public Action
{
	CellPosition cp; //position of object 

public:
	Deleteto(ApplicationManager* pApp);
	~Deleteto(void);
	virtual void Execute();
	virtual void ReadActionParameters();
};

