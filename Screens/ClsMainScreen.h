#pragma once
#include <iostream>
#include "ClsScreen.h";
#include <iomanip>
#include "ClsInputValidate.h";
#include "ClsClientListScreen.h";
#include "ClsAddNewClientScreen.h";
#include "ClsDeleteClientScreen.h";
#include "ClsUpdateClientScreen.h";
#include "ClsFindClientScreen.h";
#include "ClsTransactionsScreen.h";
#include "ClsManageUserScreen.h";
#include "ClsLoginRegisterScreen.h";
#include "Global.h";
#include "ClsCurrensyMainScreen.h";


using namespace std;


class ClsMainScreen : protected ClsScreen
{
private:

	enum enMainMenueOption {
		eListClient = 1, eAddNewClient = 2,
		eDeleteClient = 3, eUpdateClient = 4,
		eFindClient = 5, eShowTransactionMenue = 6,
		eManageUsers = 7,eLoginRegister = 8 ,eCurrencyExchange , eExit = 10
	};

	static short _ReadMainMenueOption()
	{
		cout << setw(37) << left << "" << "Choose what do you want Between [1] & [10] : ";
		short choice = 0;
		choice = ClsInputValidate::ReadIntNumber();
		return choice;
	}

	static void _ShowAllClientsScreen()
	{
		ClsListScreen::showClientList();
	}

	static void _ShowAddNewClientsScreen()
	{
		ClsAddNewClientScreen::ShowAddNewClientScreen();
	}

	static void _ShowAddDeleteClientsScreen()
	{
		ClsDeleteClientScreen::ShowDeleteClientScreen();
	}

	static void _ShowAddUpdateClientsScreen()
	{
		ClsUpdateClientScreen::ShowUpdateClientScreen();
	}

	static void _ShowAddFindClientsScreen()
	{
		ClsFindClientScreen::ShowFindClientScreen();
	}

	static void _ShowTransactionMenue()
	{
		ClsTransactionsScreen::ShowTransactionMenue();
	}

	static void _ShowManageUserMenue()
	{
		ClsManageUserScreen::ShowManageUserScreen();
	}

	static void _Logout()
	{
		CurrentUser = ClsUser::Find("", "");

		
	}

	static void _GoBacktoMainManue()
	{
		cout << "\nPress any key to go back to main menue screen : ";
		system("pause>0");
		system("cls");
		ShowMainMenue();
	}

	static void _ShowLoginRegisterScreen()
	{
		ClsLoginRegisterScreen::ShowLoginRegisterScreen();
	}

	static void _ShowCurrencyExchangeScreen()
	{
		ClsCurrensyMainScreen::ShowCurrencyMainScreen();
	}


	static void _performMainMenueOption(enMainMenueOption Option)
	{
		switch (Option)
		{
		case enMainMenueOption::eListClient:
		{
			system("cls");
			_ShowAllClientsScreen();
			_GoBacktoMainManue();
			break;
		}
		case enMainMenueOption::eAddNewClient:
		{
			system("cls");
			_ShowAddNewClientsScreen();
			_GoBacktoMainManue();
			break;
		}
		case enMainMenueOption::eDeleteClient:
		{
			system("cls");
			_ShowAddDeleteClientsScreen();
			_GoBacktoMainManue();
			break;
		}
		case enMainMenueOption::eUpdateClient:
		{
			system("cls");
			_ShowAddUpdateClientsScreen();
			_GoBacktoMainManue();
			break;
		}
		case  enMainMenueOption::eFindClient:
		{
			system("cls");
			_ShowAddFindClientsScreen();
			_GoBacktoMainManue();
			break;
		}
		case enMainMenueOption::eShowTransactionMenue:
		{
			system("cls");
			_ShowTransactionMenue();
			_GoBacktoMainManue();
			break;
		}
		case enMainMenueOption::eManageUsers:
		{
			system("cls");
			_ShowManageUserMenue();
			_GoBacktoMainManue();
			break;
		}
		case enMainMenueOption::eLoginRegister:
		{
			system("cls");
			_ShowLoginRegisterScreen();
			_GoBacktoMainManue();
			break;
		}
		case enMainMenueOption::eCurrencyExchange:
		{
			system("cls");
			_ShowCurrencyExchangeScreen();
			_GoBacktoMainManue();
			break;
		}
		case enMainMenueOption::eExit:
		{
			system("cls");
			_Logout();
			break;
		}
		}
	}


public:

	static void ShowMainMenue()
	{
		system("cls");
		_drawScreenHeader("\t\tMain Screen");


		cout << setw(37) << left << "" << "==================================\n";
		cout << setw(37) << left << "" << "\t\tMain Menue\n";
		cout << setw(37) << left << "" << "==================================\n";
		cout << setw(37) << left << "" << "\t" << "[1] Show Client List.\n";
		cout << setw(37) << left << "" << "\t" << "[2] Add new Client.\n";
		cout << setw(37) << left << "" << "\t" << "[3] Delete Client.\n";
		cout << setw(37) << left << "" << "\t" << "[4] Update Client Info.\n";
		cout << setw(37) << left << "" << "\t" << "[5] Find Client.\n";
		cout << setw(37) << left << "" << "\t" << "[6] Transaction.\n";
		cout << setw(37) << left << "" << "\t" << "[7] Manage Users.\n";
		cout << setw(37) << left << "" << "\t" << "[8] Login Register.\n";
		cout << setw(37) << left << "" << "\t" << "[9] Currency Exchange.\n";
		cout << setw(37) << left << "" << "\t" << "[10] Logout.\n";
		cout << setw(37) << left << "" << "==================================\n";

		
		_performMainMenueOption(enMainMenueOption(_ReadMainMenueOption()));
	}
};

