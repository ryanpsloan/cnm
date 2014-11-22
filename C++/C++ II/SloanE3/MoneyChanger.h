// Ryan Sloan
// rsloan2@cnm.edu
// MoneyChanger.h

#ifndef _MONEYCHANGER_H
#define _MONEYCHANGER_H

void Header();

class MoneyChanger
{

private:
	double totalCost;
	double amountGiven;
	double totalChange;
    void determineChange();
	int remainingAmount;

public:
	MoneyChanger();
	void setTotalCost(double purchasePrice, double amountPaid);
	double getTotalChange() {return totalChange;}
	void getBills(int &v20s, int &v10s, int &v5s, int &v1s);
	void getCoins(int &Quarters,int &Dimes, int &Nickles, int &Pennies);

};

#endif