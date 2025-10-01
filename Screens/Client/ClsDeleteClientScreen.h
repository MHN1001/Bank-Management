#pragma once
#include <iostream>
#include "ClsBankClient.h";
#include "ClsScreen.h";
#include "ClsInputValidate.h";

using namespace std;



class ClsDeleteClientScreen : protected ClsScreen
{

private:

	static void _Print(ClsBankClient Client)
	{
		cout << "\nClient Card : ";
		cout << "\n----------------------------------------";
		cout << "\nFirst Name     : " << Client.FirstName;
		cout << "\nLast Name      : " << Client.LastName;
		cout << "\nFull Name      : " << Client.FullName();
		cout << "\nEmail          : " << Client.Email;
		cout << "\nPhone          : " << Client.Phone;
		cout << "\nAccount Number : " << Client.GetAccountNumber();
		cout << "\nPin Code       : " << Client.PinCode;
		cout << "\nAccount Balance: " << Client.AccountBalance;
		cout << "\n----------------------------------------\n";
	}

public:


	static void ShowDeleteClientScreen()
	{

		if(!CheckAccessRights(ClsUser::pDeleteClient))
		{
			return;
		}



		_drawScreenHeader("\tDelete Client Screen");

		string AccountNumber = "";

		cout << "\nEnter Account Number : ";
		AccountNumber = ClsInputValidate::ReadString();

		while (!ClsBankClient::IfClientExist(AccountNumber))
		{
			cout << "\nInvalide Account Number , choose another one : \n";
			AccountNumber = ClsInputValidate::ReadString();
		}

		ClsBankClient Client = ClsBankClient::Find(AccountNumber);

		_Print(Client);

		char Answer = ' ';
		cout << "\nAre You sure You Want To delete This Client ? [Y]/[N] : ";
		cin >> Answer;

		if (toupper(Answer) == 'Y')
		{
			if (Client.Delete())
			{
				cout << "\nClient Deleted Sccessfully!\n";

				_Print(Client);
			}
			else
			{
				cout << "\nError Client Was Not Deleted!\n";
			}
		}
	}
};

