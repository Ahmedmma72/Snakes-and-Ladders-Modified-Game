#include "SwitchToPlayMode.h"
#include"Grid.h"

#include "Input.h"
#include "Output.h"

void SwitchToPlayMode::ReadActionParameters()
{
	//no parameters
}

void SwitchToPlayMode::Execute()
{
	// Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	//Input* pIn = pGrid->GetInput();
	pOut->CreatePlayModeToolBar();
}

SwitchToPlayMode::SwitchToPlayMode(ApplicationManager* pApp) : Action(pApp)
{
}
