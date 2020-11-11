#pragma once
#include "Card.h"
class Card14 :
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
	Card14(const CellPosition& pos);

	virtual void ReadCardParameters(Grid* pGrid); 

	virtual void Apply(Grid* pGrid, Player* pPlayer); 
	void setprice(int a);
	void setfees(int a);
	int getfees();
	int getprice();
	virtual void save(ofstream& outfile, int type);
	bool getaddstat();
	virtual void setaddstat(bool stat);
	void setsaved(bool stat);
	virtual ~Card14(); // A Virtual Destructor
};

