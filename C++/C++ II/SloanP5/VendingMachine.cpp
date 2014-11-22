// Ryan Sloan
// ryansdeal@hotmail.com	
// VendingMachine.cpp
#include "stdafx.h"
#include "VendingMachine.h"
#include "MoneyCtr.h"
#include "Logger.h"
#include <sstream>
#include <string>

using namespace std;


VendingMachine::VendingMachine()
{
	selection = 0;
	dispenseString = "Nothing Dispensed";
	int vol = 10;
	D[0].SetStock("12oz. Space Barley", 2.75, vol);
	D[1].SetStock("16oz. Premium Beer", 3.25, vol);
	D[2].SetStock("20.3oz. Premium Beer", 4.00, vol);
	D[3].SetStock("22 oz. Can Premium Beer", 4.25, vol);
	D[4].SetStock("22 oz. Can Reserve Beer", 4.50, vol);
	double bankAmt = bank.GetTotMoney();
	stringstream ss;
	ss << "Start of Transaction History" << endl;
	ss << "The total amount in the bank is $" << bankAmt << endl;
	ss << "The total product in D0 is " << D[0].GetStock() << " bottles of " << D[0].GetSodaName() << endl;
	ss << "The total product in D1 is " << D[1].GetStock() << " bottles of " << D[1].GetSodaName() << endl;
	ss << "The total product in D2 is " << D[2].GetStock() << " bottles of " << D[2].GetSodaName() << endl;
	ss << "The total product in D3 is " << D[3].GetStock() << " cans of " << D[3].GetSodaName() << endl;
	ss << "The total product in D4 is " << D[4].GetStock() << " cans of " << D[4].GetSodaName() << endl;
	
	writeLogger.StartLog(ss.str() + "\n" + bank.GetBeginFile());
}

VendingMachine::~VendingMachine()
{
	stringstream ss;
	ss << bank.GetBeginFile() << endl;
	ss << "End of Transaction History";
	writeLogger.CloseLog(ss.str());
}

void VendingMachine::SetCoins(int dol, int qu, int di, int ni)
{
	bank.SetInputMoney(dol,qu,di,ni);
}

void VendingMachine::SetSelection(int sel)
{
	selection = sel;
	DispenseItem();
}

void VendingMachine::DispenseItem()
{	
	if (selection == 0){
		if (D[0].GetStock() > 0 && D[0].GetCost() <= bank.GetHowMuchInput()) {
			bank.SetSodaCost(2.75);
			writeLogger.WriteLog("Cost: $2.75 \n");
			stringstream ss;
			ss << "Space Barley a Space Age Beer!" << "\r\n";
			ss << "Your change is $" << bank.GetChange() << "\r\n";
			dispenseString = ss.str();
			string dispSoda = D[0].DispenseSoda(); 
			string log = D[0].GetWriteLogEntry() + " ";
			string bankOutlook = bank.GetWriteLog();
			writeLogger.WriteLog(dispSoda + "\n" + log + "\n" + bankOutlook + "\n");
			writeLogger.WriteLog(bank.GetReturnMoney());
		}
		else {
			if (D[0].GetStock() == 0){
				stringstream ss;
				ss << "Selection out of Stock \r\n";
				ss << ReturnAllMoneyAndExit();
				dispenseString = ss.str();
			}
			else{				
				stringstream ss;
				ss << "Not Enough Money Entered \r\n";
				ss << ReturnAllMoneyAndExit();
				dispenseString = ss.str(); 
				bank.SetChange(0);
			}
		}
	}
	else if (selection == 1) {
		if (D[1].GetStock() > 0 && D[1].GetCost() <= bank.GetHowMuchInput()){
			bank.SetSodaCost(3.25);
			writeLogger.WriteLog("Cost: $3.25 \n");
			stringstream ss;
			ss << "Premium Beer, A Fine Choice!" << "\r\n";
			ss << "Your change is $" << bank.GetChange() << "\r\n";
			dispenseString = ss.str();
			string dispSoda = D[1].DispenseSoda();
			string log = D[1].GetWriteLogEntry() + " ";
			string bankOutlook = bank.GetWriteLog();
			writeLogger.WriteLog(dispSoda + "\n" + log + "\n" + bankOutlook + "\n");
			writeLogger.WriteLog(bank.GetReturnMoney());
		}
		else {
			if (D[1].GetStock() == 0){
				stringstream ss;
				ss << "Selection out of Stock \r\n";
				ss << ReturnAllMoneyAndExit();
				dispenseString = ss.str();
			}
				
			else{				
				stringstream ss;
				ss << "Not Enough Money Entered \r\n";
				ss << ReturnAllMoneyAndExit();
				dispenseString = ss.str();
				bank.SetChange(0);
			}
		}
	}
	else if (selection == 2){
		if (D[2].GetStock() > 0 && D[2].GetCost() <= bank.GetHowMuchInput()){
			bank.SetSodaCost(4.00);
			writeLogger.WriteLog("Cost: $4.00 \n");
			stringstream ss;
			ss << "Premium Beer, In a 20.3oz Bottle!" << "\r\n";
			ss << "Your change is $" << bank.GetChange() << "\r\n";
			dispenseString = ss.str();
			string dispSoda = D[2].DispenseSoda();
			string log = D[2].GetWriteLogEntry() + " ";
			string bankOutlook = bank.GetWriteLog();
			writeLogger.WriteLog(dispSoda + "\n" + log + "\n" + bankOutlook+ "\n");
			writeLogger.WriteLog(bank.GetReturnMoney());
		}
		else{
			if (D[2].GetStock() == 0){
				stringstream ss;
				ss << "Selection out of Stock \r\n";
				ss << ReturnAllMoneyAndExit();
				dispenseString = ss.str();
			}
			else{				
				stringstream ss;
				ss << "Not Enough Money Entered \r\n";
				ss << ReturnAllMoneyAndExit();
				dispenseString = ss.str();
				bank.SetChange(0);
			}
		}
	}
	else if (selection == 3){
		if (D[3].GetStock() > 0 && D[3].GetCost() <= bank.GetHowMuchInput()){
			bank.SetSodaCost(4.25);
			writeLogger.WriteLog("Cost: $4.25 \n");
			stringstream ss;
			ss << "Premium Beer, in a Space Age Can!" << "\r\n";
			ss << "Your change is $" << bank.GetChange() << "\r\n";
			dispenseString = ss.str();
			string dispSoda = D[3].DispenseSoda();
			string log = D[3].GetWriteLogEntry() + " ";
			string bankOutlook = bank.GetWriteLog();
			writeLogger.WriteLog(dispSoda + "\n" + log + "\n" + bankOutlook + "\n");
			writeLogger.WriteLog(bank.GetReturnMoney());
		}
		else {
			if (D[3].GetStock() == 0){
				stringstream ss;
				ss << "Selection out of Stock \r\n";
				ss << ReturnAllMoneyAndExit();
				dispenseString = ss.str();
			}
			else{				
				stringstream ss;
				ss << "Not Enough Money Entered \r\n";
				ss << ReturnAllMoneyAndExit();
				dispenseString = ss.str();
				bank.SetChange(0);
			}
		}
	}
	else if (selection == 4){
		if (D[4].GetStock() > 0 && D[4].GetCost() <= bank.GetHowMuchInput()) {
			bank.SetSodaCost(4.50);
			writeLogger.WriteLog("Cost: $4.50 \n");
			stringstream ss;
			ss << "Reserve Lager, Tasty!" << "\r\n";
			ss << "Your change is $" << bank.GetChange() << "\r\n";
			dispenseString = ss.str();
			string dispSoda = D[4].DispenseSoda();
			string log = D[4].GetWriteLogEntry() + " ";
			string bankOutlook = bank.GetWriteLog();
			writeLogger.WriteLog(dispSoda + "\n" + log + "\n" + bankOutlook + "\n");
			writeLogger.WriteLog(bank.GetReturnMoney());
		}
		else{
			if (D[4].GetStock() == 0){
				stringstream ss;
				ss << "Selection out of Stock \r\n";
				ss << ReturnAllMoneyAndExit();
				dispenseString = ss.str();
			}
			else{				
				stringstream ss;
				ss << "Not Enough Money Entered \r\n";
				ss << ReturnAllMoneyAndExit();
				dispenseString = ss.str();
				bank.SetChange(0);
			}
		}
	}
}


string VendingMachine::ReturnAllMoneyAndExit()
{
	
	string moneyBack = bank.GetReturnMoney();
	return moneyBack;
}

void VendingMachine::ResetBank() 
{ 
	bank.ResetBank();
	stringstream ss;
	ss << "Bank was reset";
	ss << bank.GetTotMoney();
	writeLogger.WriteLog(ss.str());
}

void VendingMachine::WriteLog(string s)
{
	writeLogger.WriteLog(s);
}