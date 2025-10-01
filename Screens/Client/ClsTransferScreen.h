#pragma once
#include <iostream>
#include <vector>
#include <iomanip>
#include "ClsBankClient.h";
#include "clsScreen.h";
#include "ClsInputValidate.h";

using namespace std;



class ClsTransferScreen : protected ClsScreen 
{

private:

	static void _Print(ClsBankClient Client)
	{
		cout << "\nClient Card : ";
		cout << "\n------------------------------------";
		cout << "\nFull Name      : " << Client.FullName();
		cout << "\nAccount Number : " << Client.GetAccountNumber();
		cout << "\nAccount Balance: " << Client.AccountBalance;
		cout << "\n------------------------------------\n";
	}

	static string _ReadAccountNumber(string FromOrTo)
	{
		string AccountNnumber = "";

		cout << "\nEnter Account Number To Transfer " << FromOrTo << " : ";
		AccountNnumber = ClsInputValidate::ReadString();

		while (!ClsBankClient::IfClientExist(AccountNnumber))
		{
			cout << "Invalide Account Number , Enter Another Account Number : ";
			AccountNnumber = ClsInputValidate::ReadString();
		}

		return AccountNnumber;
	}

	static float _ReadAmount(ClsBankClient SourceClient)
	{
		float Amount;
		cout << "\nPlease Enter Deposit Amount : ";
		Amount = ClsInputValidate::ReadDBLNumber();

		while (Amount > SourceClient.AccountBalance)
		{
			cout << "Amount Exeeds the available balance , Enter another amount : ";
			Amount = ClsInputValidate::ReadDBLNumber();
		}

		return Amount;
	}


public :

	static void  ShowTransferScreen()
	{
		_drawScreenHeader("\tTransfer Screen");

		ClsBankClient SourceClient = ClsBankClient::Find(_ReadAccountNumber("from"));
		_Print(SourceClient);

		ClsBankClient DestinationClient = ClsBankClient::Find(_ReadAccountNumber("To"));

		while (DestinationClient.GetAccountNumber() == SourceClient.GetAccountNumber())
		{
			cout << "\nyou can't perform this operation between similar account numbers !\n";
			DestinationClient = ClsBankClient::Find(_ReadAccountNumber("To"));
		}
		_Print(DestinationClient);
         

		float amount = _ReadAmount(SourceClient);

		cout << "\nAre You sure Do You want to Perfform this oparetion ? [Y]/[N] : ";
		char answer = 'n';
		cin >> answer;

		if (toupper(answer) == 'Y')
		{
			if (SourceClient.Transfer(amount, DestinationClient, CurrentUser.GetUsername()))
			{
				cout << "\nTransfer done suceessfully !";
			}
			else
			{
				cout << "\nTransfer Fsiled !";

			}
		}
		_Print(SourceClient);
		_Print(DestinationClient);
	}
};

