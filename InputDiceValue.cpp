#include "InputDiceValue.h"
#include "InputDiceValue.h"
#include"Output.h"
#include"Grid.h"
#include"Action.h"
InputDiceValue::InputDiceValue(ApplicationManager* pApp) :Action(pApp)
{

}

void InputDiceValue::Execute()
{
	ReadActionParameters();
}

void InputDiceValue::ReadActionParameters()
{   //Read Iput/OutPut Interface
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("InputDiceValue:Enter Number From 1 To 6... ");
	Num = pIn->GetInteger(pOut);
	while (Num <= 0 || Num > 6)  //condition
	{
		pOut->PrintMessage("You Entered Wrong Number..TryAgain");
		Num = pIn->GetInteger(pOut);
		pOut->ClearStatusBar();

	}
	pGrid->GetCurrentPlayer()->Move(pGrid, Num); //GetPlayer Turn nd Move It 
	pGrid->AdvanceCurrentPlayer(); // To Turn Next Plyaer
	bool End = pGrid->GetEndGame();//what is this 
	pOut->ClearStatusBar();
}
