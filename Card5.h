#pragma once

#include "Card.h"



class Card5 : public Card
{
	

public:
	Card5(const CellPosition& pos); // A Constructor takes card position

	virtual void ReadCardParameters(Grid* pGrid); // Reads the parameters of CardOne which is: walletAmount

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardOne on the passed Player
													  // by decrementing the player's wallet by the walletAmount data member
	virtual void save(ofstream& outfile, int type);
	virtual ~Card5(); // A Virtual Destructor
};

