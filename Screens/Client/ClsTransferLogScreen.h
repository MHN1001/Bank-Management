#pragma once
#include <iostream>
#include <vector>
#include <iomanip>
#include "ClsUser.h";
#include "clsScreen.h";
#include "ClsBankClient.h";

using namespace std;



class ClsTransferLogScreen : protected ClsScreen
{
private:

	static void _PrintTransferLogRecordLine(ClsBankClient::stRegisterLog stRegisterLogLine)
	{
		cout << "\t|" << setw(25) << left << stRegisterLogLine.DateAndTime
			<< "|" << setw(10) << left << stRegisterLogLine.SourceAccountNumber
			<< "|" << setw(10) << left << stRegisterLogLine.DestinationAccountBalnace
			<< "|" << setw(10) << left << stRegisterLogLine.Amount
			<< "|" << setw(10) << left << stRegisterLogLine.SourceAccountBalnace
			<< "|" << setw(10) << left << stRegisterLogLine.DestinationAccountBalnace
			<< "|" << setw(10) << left << stRegisterLogLine.UserName;
	}



public:

	static void ShowTransferLogScreen()
	{
		vector <ClsBankClient::stRegisterLog> vTransferLogRecords = ClsBankClient::GeTransferLogList();
		
		string Title = "\tTransfer Log List";
		string SubTitle = "\t ( " + to_string(vTransferLogRecords.size()) + " ) Logins";
		
		
		_drawScreenHeader(Title , SubTitle);

		cout << "\t------------------------------------------------------------------------------------------\n";
		cout << "\t|" << setw(25) << left << "Date/Time" << "|" << setw(10) << left << "S.Acc"		
			<< "|" << setw(10) << left << "D.Acc" << "|" << setw(10) << left << "Amount"			
			<< "|" << setw(10) << left << "S.Balance" << "|" << setw(10) << left << "D.Balance"		
			<< "|" << setw(10) << left << "User Name";												
		cout << "\n\t------------------------------------------------------------------------------------------\n";
																									 
		if (vTransferLogRecords.size() == 0)														 
		{																							 
			cout << "\t\t\t\tNo Users available in the system !\n";									 
		}																							 
																									 
		for (ClsBankClient::stRegisterLog& stRegisterLogLine : vTransferLogRecords)
		{																							 
			_PrintTransferLogRecordLine(stRegisterLogLine);
			cout << endl;																			 
		}																							 
																									 
		cout << "\n\t------------------------------------------------------------------------------------------\n";
	}
};

