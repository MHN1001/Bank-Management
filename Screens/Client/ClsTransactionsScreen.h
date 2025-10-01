#pragma once
#include <iostream>
#include "ClsInputValidate.h";
#include "ClsBankClient.h";
#include <iomanip>
#include "ClsMainScreen.h";
#include "ClsDepositScreen.h";
#include "ClsWithdrawScreen.h";
#include "ClsTotalBalanceScreeen.h";
#include "ClsTransferScreen.h";
#include "ClsTransferLogScreen.h";

using namespace std;

class ClsTransactionsScreen : protected ClsScreen
{
private:
	enum enTransactiosMenueOption {edeposit=1 , eWhithdraw=2 
		                          , eShowTotalBalance=3, eTransfer=4 ,eTransferLogList=5, eShowMainMenue=6};


	static void _GoBackToTransactionMenue()
	{
		cout << "\nPress Any Key To Go Back To Transaction Menue ... ";
		system("pause > 0");
		system("cls");
		ShowTransactionMenue();
	}

	static void _ShowDepositScreen()
	{
		ClsDepositScreen::ShowDepositScreen();
	}

	static void _ShowWithdrawScreen()
	{
		ClsWithdrawScreen::ShowWithdrawScreen();
	}

	static void _ShowTotalBalanceScreen()
	{
		ClsTotalBalanceScreen::ShowTotalBalanceScreen();
	}

	static void _ShowTransferScreen()
	{
		ClsTransferScreen::ShowTransferScreen();
	}

	static void _ShowTransferLogList()
	{
		ClsTransferLogScreen::ShowTransferLogScreen();
	}

	static void _PerformTransactiosMenueOption(enTransactiosMenueOption TransactionMenueOption)
	{
		switch (TransactionMenueOption)
		{
		case enTransactiosMenueOption::edeposit:
		{
			system("cls");
			_ShowDepositScreen();
			_GoBackToTransactionMenue();
			break;

		}
		case enTransactiosMenueOption::eWhithdraw:
		{
			system("cls");
			_ShowWithdrawScreen();
			_GoBackToTransactionMenue();
			break;
		}
		case enTransactiosMenueOption::eShowTotalBalance:
		{
			system("cls");
			_ShowTotalBalanceScreen();
			_GoBackToTransactionMenue();
			break;
		}
		case enTransactiosMenueOption::eTransfer:
		{
			system("cls");
			_ShowTransferScreen();
			_GoBackToTransactionMenue();
			break;
		}
		case enTransactiosMenueOption::eTransferLogList:
		{
			system("cls");
			_ShowTransferLogList();
			_GoBackToTransactionMenue();
			break;
		}
		case enTransactiosMenueOption::eShowMainMenue:
		{
			// do nothis 
		}
		}
	}

	static short _ReadTransactionchoice()
	{
		    short Choice = 0;
			cout << "choose What Do Want To Do ? ";
			Choice = ClsInputValidate::ReadIntNumberBetween(1, 6);
			return Choice;
	}


public:

	static void ShowTransactionMenue()
	{
		if (!CheckAccessRights(ClsUser::pTransaction))
		{
			return;
		}


		system("cls");
		_drawScreenHeader("\t     Transaction Screen");

		cout << setw(37) << left << "" << "==================================\n";
		cout << setw(43) << left << "" << "TRANSACTION MENUE SCREEN\n";
		cout << setw(37) << left << "" << "==================================\n";
		cout << setw(45) << left << "" <<  "[1] Deposit.\n";
		cout << setw(45) << left << "" <<  "[2] withdraw.\n";
		cout << setw(45) << left << "" <<  "[3] Total Balances.\n";
		cout << setw(45) << left << "" <<  "[4] Transfer.\n";
		cout << setw(45) << left << "" <<  "[5] Transfer Log List.\n";
		cout << setw(45) << left << "" <<  "[6] Main Menue.\n";
		cout << setw(37) << left << "" << "==================================\n";


		_PerformTransactiosMenueOption(enTransactiosMenueOption(_ReadTransactionchoice()));
	}
};

