#pragma once
#include "Action.h"
#include<fstream>
class OpenGridAction :
	public Action
{
private:
	ifstream ReadFromFile;
	char name[100];
	bool cancelaction;
public:
	OpenGridAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();

	virtual void Execute();

	~OpenGridAction();
};

