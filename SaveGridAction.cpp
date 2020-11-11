#include "SaveGridAction.h"

#include "Input.h"
#include "Output.h"
#include "Grid.h"
#include "Ladder.h"
#include "Snake.h"
#include "Card.h"
#include <string>
#include<fstream>
SaveGridAction::SaveGridAction(ApplicationManager* pApp):Action(pApp)
{
}
void SaveGridAction::ReadActionParameters()
{

	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	pOut->PrintMessage("Enter Your File Name");
	string Name = pIn->GetSrting(pOut)+".txt";
	strcpy(name, Name.c_str());
	checkfile.open(name);
	bool status = checkfile.is_open();
	if (status)
	{
		checkfile.close();
		remove(name);
		
		/*pOut->PrintMessage("there already a file with the same name.Please enter another name");
		Name = pIn->GetSrting(pOut);
		strcpy(name, Name.c_str());
		checkfile.open(name);
		status = checkfile.is_open();*/

	}
	
}

void SaveGridAction::Execute()
{
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	outputfile.open(name);



	outputfile << Ladder::getnumofladders() << endl;
	pGrid->saveAll(outputfile, 0);
	outputfile << Snake::getnumofsnakes() << endl;
	pGrid->saveAll(outputfile, 1);
	outputfile << Card::getnumofcards() << endl;
	pGrid->saveAll(outputfile, 2);

	pGrid->PrintErrorMessage("File was saved succesfully,Click to continue");
	outputfile.close();

}
SaveGridAction::~SaveGridAction()
{
}
