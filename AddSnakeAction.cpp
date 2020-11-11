#include "AddSnakeAction.h"

#include "Input.h"
#include "Output.h"
#include "Snake.h"

AddSnakeAction::AddSnakeAction(ApplicationManager* pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

AddSnakeAction::~AddSnakeAction()
{
}

void AddSnakeAction::ReadActionParameters()
{
	// Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// Read the startPos parameter
	pOut->PrintMessage("New Snake: Click on its Start Cell ...");
//	startPos = pIn->GetCellClicked();
	CellPosition startPosition = pIn->GetCellClicked();
	// Read the endPos parameter
	pOut->PrintMessage("New Snake: Click on its End Cell ...");
	//endPos = pIn->GetCellClicked();
	CellPosition endPosition = pIn->GetCellClicked();


	if (startPosition.HCell() == endPosition.HCell())
	{
		if (startPosition.VCell() < endPosition.VCell())
		{
			
				startPos = startPosition;
				endPos = endPosition;
			
			
			
		}
		else
		{
			endPos.SetHCell(-1);
			endPos.SetVCell(-1);
		}
	}
	else
	{
		startPos.SetHCell(-1);
		startPos.SetVCell(-1);
	}

	
	// Clear messages
	pOut->ClearStatusBar();
}


// Execute the action
void AddSnakeAction::Execute()
{
	// The first line of any Action Execution is to read its parameter first 
	// and hence initializes its data members
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid(); // We get a pointer to the Grid from the ApplicationManager/	Grid* pGrid = pManager->GetGrid();

	if (startPos.IsValidCell() && endPos.IsValidCell())
	{

		// Create a Snake object with the parameters read from the user
		Snake* pSnake = new Snake(startPos, endPos);
		//pSnake->Draw(pOut);

		// Add the card object to the GameObject of its Cell:
		bool added = pGrid->AddObjectToCell(pSnake);
		// if the GameObject cannot be added
		if (!added)
		{
			// Print an appropriate message
			pGrid->PrintErrorMessage("Error: Cell already has an object ! Click to continue ...");
			delete pSnake;
			pSnake = NULL;
		}
		// Here, the Snake is created and added to the GameObject of its Cell, so we finished executing the AddSnakeAction
	
	}
	else
	{
		pGrid->PrintErrorMessage("Error: Cells chosen are invalid ! Click to continue ...");
	}


}
