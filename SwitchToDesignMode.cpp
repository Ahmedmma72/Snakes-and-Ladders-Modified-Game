#include "SwitchToDesignMode.h"
#include"Grid.h"

#include "Input.h"
#include "Output.h"

void SwitchToDesignMode::ReadActionParameters()
{
	//no parameters
}

void SwitchToDesignMode::Execute()
{
	// Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	//Input* pIn = pGrid->GetInput();
	pOut->CreateDesignModeToolBar();
}

SwitchToDesignMode::SwitchToDesignMode(ApplicationManager* pApp) : Action(pApp)
{
}