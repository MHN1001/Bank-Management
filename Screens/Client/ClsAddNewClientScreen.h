#pragma once
#include <iostream>
#include "ClsScreen.h";
#include "ClsBankClient.h";
#include "ClsInputValidate.h";
#include <iomanip>
#include <vector>

using namespace std;


class ClsAddNewClientScreen : protected ClsScreen
{

private:

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

	static void ShowAddNewClientScreen()
	{
		if (!CheckAccessRights(ClsUser::pAddClient))
		{
			return;
		}

		_drawScreenHeader("\tAdd New Client Screen");

		vector <ClsBankClient> VClients = ClsBankClient::GetClientList();
		string AccountNumber = "";

		cout << "\nEnter Account Number : ";
		AccountNumber = ClsInputValidate::ReadString();

		while (ClsBankClient::IfClientExist(AccountNumber))
		{
			cout << "\nInvalide Account Number , choose another one : \n";
			AccountNumber = ClsInputValidate::ReadString();
		}

		ClsBankClient NewClient = ClsBankClient::GetAddNewClientObject(AccountNumber);
		_ReadClientInfo(NewClient);

		ClsBankClient::enSaveResult SaveResult;

		SaveResult = NewClient.Save();

		switch (SaveResult)
		{
		case ClsBankClient::saveSucceeded:
		{
			cout << "\n Save Succeeded :)\n";
			_Print(NewClient);
			break;
		}
		case ClsBankClient::SaveFaildAccountNumberEmpty:
		{
			cout << "\n Faild Save Because Your Object is Empty !\n";
			break;
		}
		case ClsBankClient::SaveFaildAccountNumberExist:
		{
			cout << "\nFaild Save Because This Account Number Already exist !\n";
		}

		}
	}
};

