#pragma once
#include <iostream>
#include <vector>
#include <iomanip>
#include "ClsBankClient.h";
#include "clsScreen.h";

using namespace std;


class ClsTotalBalanceScreen  : protected ClsScreen
{
private:

	static void _PrintClientRecordBalanceLine(ClsBankClient Client)
	{
		cout << "\t\t\t|" << setw(14) << left << Client.GetAccountNumber();
		cout << "|" << setw(35) << left << Client.FullName();
		cout << "|" << setw(14) << left << Client.AccountBalance;
	}


public :


	static void ShowTotalBalanceScreen()
	{
		vector <ClsBankClient> VClients = ClsBankClient::GetClientList();


		string Title = "\t\tClient List";
		string SubTitle = "\t\t" + to_string(VClients.size()) + "Client(s)";

		_drawScreenHeader(Title, SubTitle);

		cout << "\t\t-------------------------------------------------------------------------------\n";
		cout << "\t\t\t|" << setw(14) << left << "Account Number" << "|" << setw(35) << left << "Client Name"
			<< "|" << setw(14) << left << "Account Balance"
			<< "\n\t\t-------------------------------------------------------------------------------\n";

		double TotalBalances = ClsBankClient::GetTotallBalances();

		if (VClients.size() == 0)
		{
			cout << "\t\t\tNo clients available in the system !\n";
		}
		else
		{
			for (ClsBankClient& Client : VClients)
			{
				_PrintClientRecordBalanceLine(Client);
				cout << endl;
			}
		}
		cout << "\n\t\t------------------------------------------------------------------------------\n";


		cout << "\t\t\t\t\t\t\t   Total Balances : " << TotalBalances;
		cout << "\n\t\t\t( " << ClsUtility::NumberToText(TotalBalances) << ")\n\n";
	}
	};

