#pragma once
#include "Card.h"
class Card13 :
	public Card
{
private:
	static int price;
	static int fees;
	static bool bought;
	static bool saved;
	static bool added;
	static int owner;
	static int thiscardsnum;
public:
	Card13(const CellPosition& pos); // A Constructor takes card position

	virtual void ReadCardParameters(Grid* pGrid); // Reads the parameters of CardOne which is: walletAmount

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardOne on the passed Player
													  // by decrementing the player's wallet by the walletAmount data member
	void setprice(int a);
	void setfees(int a);
	int getfees();
	int getprice();
	virtual void save(ofstream& outfile, int type);
	bool getaddstat();
	virtual void setaddstat(bool stat);
	void setsaved(bool stat);
	virtual ~Card13(); // A Virtual Destructor
};

