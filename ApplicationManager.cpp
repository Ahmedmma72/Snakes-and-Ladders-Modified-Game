#include "ApplicationManager.h"

#include "Grid.h"
#include "AddLadderAction.h"
#include"AddSnakeAction.h"
#include "AddCardAction.h"
#include "RollDiceAction.h"
#include "SwitchToPlayMode.h"
#include"SwitchToDesignMode.h"
#include"Copy.h"
#include"Deleteto.h"
#include"Paste.h"
#include"Cut.h"
#include "NewGame.h"
#include"SaveGridAction.h"
#include"OpenGridAction.h"
#include"InputDiceValue.h"
#include"EditCard.h"
///TODO: Add #include for all action types

ApplicationManager::ApplicationManager()
{
	// Create Input, output and Grid
	pOut = new Output();
	pIn = pOut->CreateInput();
	pGrid = new Grid(pIn, pOut);
}

////////////////////////////////////////////////////////////////////////////////////

ApplicationManager::~ApplicationManager()
{
	delete pGrid;
}

//==================================================================================//
//								Interface Management Functions						//
//==================================================================================//

Grid * ApplicationManager::GetGrid() const
{
	return pGrid;
}

void ApplicationManager::UpdateInterface() const
{
	pGrid->UpdateInterface();
}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//

ActionType ApplicationManager::GetUserAction() const
{
	// Ask the input to get the action from the user.
	return pIn->GetUserAction();
}

////////////////////////////////////////////////////////////////////////////////////

// Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType) 
{
	Action* pAct = NULL;

	// According to Action Type, create the corresponding action object
	switch (ActType)
	{
	case ADD_LADDER:
		pAct = new AddLadderAction(this);
		break;
	case ADD_SNAKE:
		pAct = new AddSnakeAction(this);
		break;
	case ADD_CARD:
		// create an object of AddCardAction here
		pAct = new AddCardAction(this);
		break;

	case EXIT:
		break;

	case TO_PLAY_MODE:
		//pOut->CreatePlayModeToolBar();// temporary till you made its action class (CHANGE THIS LATTER)
		pAct = new SwitchToPlayMode(this);
		break;

	case copycard:
		pAct = new Copy(this);
		break;

	case ROLL_DICE:
		// create an object of RollDiceAction here
		pAct = new RollDiceAction(this);
		break;

	case TO_DESIGN_MODE:
		
		//pOut->CreateDesignModeToolBar(); // temporary till you made its action class (CHANGE THIS LATTER)
		pAct = new SwitchToDesignMode(this);
		break;

	case paste:
		pAct = new Paste(this);
		break;
	case cut:
		pAct = new Cut(this);
		break;
	case deletegame:
		pAct = new Deleteto(this);
		break;
		///TODO: Add a case for EACH Action type in the Design mode or Play mode

	case newgame:
		pAct = new NewGame(this);
		break;
	case savegrid:
		pAct = new SaveGridAction(this);
		break;
	case opengrid:
		pAct = new OpenGridAction(this);
		break;
	case input:
		pAct = new InputDiceValue(this);
		break;
	case editcard:
		pAct = new EditCard(this);
		break;
	case STATUS:	// a click on the status bar ==> no action
		return;

	}
     
	// Execute the created action
	if(pAct != NULL)
	{
		pAct->Execute(); // Execute
		delete pAct;	 // Action is not needed any more after executing ==> delete it
		pAct = NULL;
	}

}
