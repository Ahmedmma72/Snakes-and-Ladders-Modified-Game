#pragma once
#include "Action.h"
#include<fstream>
class SaveGridAction :
	public Action
{
private:

	char name[100];
	ifstream checkfile;
	ofstream  outputfile;

public:
	SaveGridAction(ApplicationManager* pApp);
	void ReadActionParameters();
	void Execute();
	~SaveGridAction();



};

