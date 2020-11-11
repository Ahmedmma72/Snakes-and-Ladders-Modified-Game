#pragma once
#include "Action.h"
class Paste :public Action
{
	CellPosition Pos; // the postion this read
	Card* PasteCard;
public:
	Paste(ApplicationManager* pApp); // A Constructor

	virtual void ReadActionParameters(); // Reads AddLadderAction action parameters (startPos, endPos)

	virtual void Execute(); // Creates a new Ladder Object 
							// then Sets this Ladder object to the GameObject Pointer of its Cell


	virtual ~Paste(); // Virtual Destructor
};

