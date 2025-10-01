#pragma once
#include <iostream>
#include "ClsBankClient.h";
#include "ClsScreen.h";
#include "ClsInputValidate.h";

using namespace std;


class ClsUpdateClientScreen : protected ClsScreen
{

	static void _ReadClientInfo(ClsBankClient& Client)
	{
		cout << "First Name : ";
		Client.FirstName = ClsInputValidate::ReadString();

		cout << "Last Name : ";
		Client.LastName = ClsInputValidate::ReadString();

		cout << "Email : ";
		Client.Email = ClsInputValidate::ReadString();

		cout << "Phone : ";
		Client.Phone = ClsInputValidate::ReadString();

		cout << "Pin Code : ";
		Client.PinCode = ClsInputValidate::ReadString();

		cout << "Account Balance : ";
		Client.AccountBalance = ClsInputValidate::ReadDBLNumber();
	}

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

	static void ShowUpdateClientScreen()
	{
		if (!CheckAccessRights(ClsUser::pUpdateCleint))
		{
			return;
		}


		_drawScreenHeader("\tUpdate Client screen");

		string AccountNnumber = "";

		cout << "\nEnter Account Number : ";
		AccountNnumber = ClsInputValidate::ReadString();

		while (!ClsBankClient::IfClientExist(AccountNnumber))
		{
			cout << "Invalide Account Number , Enter Another Account Number : ";
			AccountNnumber = ClsInputValidate::ReadString();
		}

		ClsBankClient Client = ClsBankClient::Find(AccountNnumber);
		_Print(Client);

		cout << "\n Update Client : ";
		cout << "\n-------------------\n";
		_ReadClientInfo(Client);

		//Saving

		ClsBankClient::enSaveResult SaveResult;

		SaveResult = Client.Save();

		switch (SaveResult)
		{
		case ClsBankClient::saveSucceeded:
		{
			cout << "\n Save Succeeded :)\n";
			_Print(Client);
			break;
		}
		case ClsBankClient::SaveFaildAccountNumberEmpty:
		{
			cout << "\n Faild Save Because Your Object is Empty !\n";
			break;
		}
		}
	}
};

