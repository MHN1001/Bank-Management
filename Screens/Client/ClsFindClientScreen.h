#pragma once
#include <iostream>
#include <vector>
#include <iomanip>
#include "ClsBankClient.h";
#include "clsScreen.h";
#include "ClsInputValidate.h";

using namespace std;



class ClsFindClientScreen : protected ClsScreen
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

	static void ShowFindClientScreen()
	{
		if (!CheckAccessRights(ClsUser::pFindClient))
		{
			return;
		}


		_drawScreenHeader("\tFind Client Screen");

		string AccountNumber = "";
		cout << "\nEnter Account Number : ";
		AccountNumber = ClsInputValidate::ReadString();

		while (!ClsBankClient::IfClientExist(AccountNumber))
		{
			cout << "\nInvalid Account Number , Ennter Another Account Number : ";
			AccountNumber = ClsInputValidate::ReadString();
		}

		ClsBankClient Client = ClsBankClient::Find(AccountNumber);

		if(!Client.IsEmpty())
		{
			cout << "\nClient Found :)";
		   _Print(Client);
 
		}
		else
		{
			cout << "\nClient Not Found :(";
		}
	}
};

