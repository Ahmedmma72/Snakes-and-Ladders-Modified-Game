#pragma once
#include "Action.h"
#include"Cell.h"
#include"Input.h"
#include"Action.h"
#include"Output.h"
#include"Grid.h"
#include "Player.h"
class InputDiceValue :
	public Action
{
	int Num;  //No.User Add from 1 to 6
	CellPosition cp; // object to send player 
public:
	InputDiceValue(ApplicationManager*);
	virtual void Execute();
	virtual void ReadActionParameters();
};

