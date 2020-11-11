#pragma once
#include "Action.h"
class Cut :
	public Action
{
	//GameObject* g;
	CellPosition Pos; // the postion this read
	Card* CpyCard;

public:

	Cut(ApplicationManager* pApp); // A Constructor

	virtual void ReadActionParameters(); // Reads AddLadderAction action parameters (startPos, endPos)

	virtual void Execute(); // Creates a new Ladder Object 
							// then Sets this Ladder object to the GameObject Pointer of its Cell


	virtual ~Cut(); // Virtual Destructor
};

