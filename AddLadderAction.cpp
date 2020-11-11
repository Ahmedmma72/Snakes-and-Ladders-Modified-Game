#include "AddLadderAction.h"

#include "Input.h"
#include "Output.h"
#include "Ladder.h"

AddLadderAction::AddLadderAction(ApplicationManager* pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

AddLadderAction::~AddLadderAction()
{
}

void AddLadderAction::ReadActionParameters()
{
	// Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// Read the startPos parameter
	pOut->PrintMessage("New Ladder: Click on its Start Cell ...");
	CellPosition startPosition = pIn->GetCellClicked();
	// startPos = pIn->GetCellClicked();
	// Read the endPos parameter
	pOut->PrintMessage("New Ladder: Click on its End Cell ...");
	CellPosition endPosition = pIn->GetCellClicked();
	//endPos = pIn->GetCellClicked();

	/*startPos = startPosition;
	endPos = endPosition;*/


	if (startPosition.HCell() == endPosition.HCell()&& startPosition.VCell() > endPosition.VCell()&&startPosition.GetCellNum()!=1)
	{
		
		
			startPos = startPosition;
			endPos = endPosition;

	}
	else
	{
		startPos.SetHCell(-1);
		startPos.SetVCell(-1);
		endPos.SetHCell(-1);
		endPos.SetVCell(-1);
	}
	// Clear messages
	pOut->ClearStatusBar();
}


// Execute the action
void AddLadderAction::Execute()
{
	// The first line of any Action Execution is to read its parameter first 
	// and hence initializes its data members
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();   // We get a pointer to the Grid from the ApplicationManager
	bool status = startPos.IsValidCell();

	if (status)
	{

		// Create a Ladder object with the parameters read from the user
		Ladder* pLadder = new Ladder(startPos, endPos);
		// Add the object to the GameObject of its Cell:
		bool added = pGrid->AddObjectToCell(pLadder);

		// if the GameObject cannot be added
		if (!added)
		{
			// Print an appropriate message
			pGrid->PrintErrorMessage("Error: Cell already has an object ! Click to continue ...");
			delete pLadder; // unused ladder
		}
		
		// Here, the ladder is created and added to the GameObject of its Cell, so we finished executing the AddLadderAction

	}
	else
	{
		pGrid->PrintErrorMessage("Error: Cells chosen are invalid ! Click to continue ...");
	}

}
