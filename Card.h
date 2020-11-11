#pragma once

#include "GameObject.h"
#include "Player.h"
#include<fstream>

// Base Class of All Types of Cards (CardOne, CardTwo, CardThree, ...etc.)
// Note: We will make each type of Card in a separate class because:
// it may have additional data members and functions like: Apply(), ...etc. which have different implementation depending on Card Number
class Card : public GameObject
{
protected:
	int cardNumber; // an integer representing the card number
	static int NumOfCards;
public:
	Card(const CellPosition& pos); // A Constructor for card that takes the cell position of it
	void SetCardNumber(int cnum);   // The setter of card number
	int GetCardNumber();            // The getter of card number

	void Draw(Output* pOut) const;  // Draws the card number in the cell position of the card
									// It has the same implementation for all Card Types (Non-Virtual)

	virtual void ReadCardParameters(Grid* pGrid); // It reads the parameters specific for each Card Type
												   // It is a virtual function (implementation depends on Card Type)

	virtual void Apply(Grid* pGrid, Player* pPlayer);  // It applies the effect of the Card Type on the passed player
	virtual void save(ofstream& outfile, int type) = 0;                                        // It is a virtual function (implementation depends on Card Type)
	static int getnumofcards();
	virtual void setwalletamount(int a);
	virtual int getwalletamount();
	virtual void setpos(CellPosition p);
	virtual void setprice(int a);
	virtual void setfees(int a);
	virtual int getfees();
	virtual int getprice();
	virtual bool getaddstat();
	virtual void setaddstat(bool stat);
	virtual void increaseNOC();
	virtual void setsaved(bool stat);
	virtual ~Card(); // A Virtual Destructor
};

