#pragma once

#include <iostream>
#include <vector>
#include <iomanip>
#include "ClsBankClient.h";
#include "clsScreen.h";

using namespace std;


class ClsListScreen : protected ClsScreen
{

private:


	 static void _printClientRecordLine(ClsBankClient Client)
	{
		cout << "\t|" << setw(15) << left << Client.GetAccountNumber()
		     << "|" << setw(20) << left << Client.FullName()
		     << "|" << setw(16) << left << Client.Phone
		     << "|" << setw(27) << left << Client.Email
		     << "|" << setw(15) << left << Client.PinCode
		     << "|" << setw(19) << left << Client.AccountBalance;
	}


public:


	static void  showClientList()
	{

		if (!CheckAccessRights(ClsUser::pListClient))
		{
			return;
		}


		vector <ClsBankClient> VClients = ClsBankClient::GetClientList();

		string Title = "\t\tClient List";
		string SubTitle = "\t\t" + to_string(VClients.size()) + "Client(s)";

		_drawScreenHeader(Title, SubTitle);

		cout << "\t--------------------------------------------------------------------------------------------------------------------\n";
		cout << "\t|" << setw(15) << left << "Account Number" << "|" << setw(20) << left << "Client Name"
			<< "|" << setw(16) << left << "Phone" << "|" << setw(27) << left << "Email"
			<< "|" << setw(15) << left << "Pin Code" << "|" << setw(19) << left << "Balance";
	   cout << "\n\t--------------------------------------------------------------------------------------------------------------------\n";

		if (VClients.size() == 0)
		{
			cout << "\t\t\t\tNo clients available in the system !\n";
		}
		else
		{
			for (ClsBankClient& Client : VClients)
			{
				_printClientRecordLine(Client);
				cout << endl;
			}
		}
		cout << "\t--------------------------------------------------------------------------------------------------------------------\n";
	}
};

