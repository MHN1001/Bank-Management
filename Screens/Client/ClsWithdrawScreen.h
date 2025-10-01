#pragma once
#include <iostream>
#include "ClsScreen.h";
#include "ClsBankClient.h";
#include "ClsInputValidate.h";

using namespace std;


class ClsWithdrawScreen : protected ClsScreen
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

	static void ShowWithdrawScreen()
	{
		_drawScreenHeader("\t    Withdraw Screen");

		string AccountNumber = "";
		cout << "\nEnter Account Number : ";
		AccountNumber = ClsInputValidate::ReadString();

		while (!ClsBankClient::IfClientExist(AccountNumber))
		{
			cout << "\nInvalid Account Number , Ennter Another Account Number : ";
			AccountNumber = ClsInputValidate::ReadString();
		}

		ClsBankClient Client = ClsBankClient::Find(AccountNumber);
		_Print(Client);

		double Amount;
		cout << "\nPlease Enter Withraw Amount : ";
		Amount = ClsInputValidate::ReadDBLNumber();

		char answer;
		cout << "\nAre sure Do You Want To Confirm This Transaction [Y]/[N] : ";
		cin >> answer;

		if (toupper(answer) == 'Y')
		{
			if (Client.Withdraw(Amount))
			{
			cout << "\nAmount Withdrawn Successfully.";
			cout << "\n\nNew Balance = " << Client.GetAccountBalance();

			}
		else
		{
			cout << "\nCannot Withraw , Incffecient Balance !";
			cout << "\nAmount to withdraw is = " << Amount;
			cout << "\nYour Balnace = " << Client.GetAccountBalance();
		}
		}
		else
		{
			cout << "\nOparetoin was Cancelled !";
		}
	}

};

