#pragma once
#include <iostream>
#include <string>
#include "ClsScreen.h";
#include <iomanip>;
#include "ClsInputValidate.h";
#include "ClsListCurrensiesScreen.h";
#include "ClsFindCurrencyScreen.h";
#include "ClsUpdateCurrencyRateScreen.h";
#include "ClsCurrencyCalculatorScreen.h";

using namespace std;


class ClsCurrensyMainScreen : protected ClsScreen
{

	enum enExchangeOption {eListCurrencies=1, eFindCurrency=2, eUpdateRate=3
	                       , eCurencyCalculator=4, eMainMenue=5 };

	static short _ReadExchangeOption()
	{
		cout << setw(37) << left << "" << "Choose what do you want Between [1] & [5] : ";
		short choice = 0;
		choice = ClsInputValidate::ReadIntNumberBetween(1, 5);
		return choice;
	}

	static void _GoBacktoCurrencyExchangeOption()
	{
		cout << "\nPress any key to go back to Currency Main Screen : ";
		system("pause>0");
		system("cls");
		ShowCurrencyMainScreen();
	}

	static void _ShowListCurrenciesScreen()
	{
		ClsListCurrensiesScreen::ShowListCurrenciesScreen();
	}

	static void _ShowFindCurrencyScreen()
	{
		ClsFindCurrencyScreen::_ShowFindCurremcyScreen();
	}

	static void _ShowUpdateCurrencyScreen()
	{
		ClsUpdateCurrencyRateScreen::_ShowUpdateCurrencyScreen();
	}

	static void _ShowCurrencyCalculatorScreen()
	{
		ClsCurrencyCalculatorScreen::ShowCalculatoeCurrencyScreen();
	}

	static void _performmCurrencyExchangeOption(enExchangeOption option)
	{
		switch (option)
		{
		case enExchangeOption::eListCurrencies:
		{
			system("cls");
			_ShowListCurrenciesScreen();
			_GoBacktoCurrencyExchangeOption();
			break;
		}
		case enExchangeOption::eFindCurrency:
		{
			system("cls");
			_ShowFindCurrencyScreen();
			_GoBacktoCurrencyExchangeOption();
			break;
		}
		case enExchangeOption::eUpdateRate:
		{
			system("cls");
			_ShowUpdateCurrencyScreen();
			_GoBacktoCurrencyExchangeOption();
			break;
		}
		case enExchangeOption::eCurencyCalculator:
		{
			system("cls");
			_ShowCurrencyCalculatorScreen();
			_GoBacktoCurrencyExchangeOption();
			break;
		}
		case enExchangeOption::eMainMenue:
		{

		}
		}
	}

public:

	static void ShowCurrencyMainScreen()
	{
		system("cls");
		_drawScreenHeader("\t  Currency Main Screen");

		cout << setw(37) << left << "" << "==================================\n";
		cout << setw(37) << left << "" << "\t   Currency Exchange Menue\n";
		cout << setw(37) << left << "" << "==================================\n";
		cout << setw(37) << left << "" << "\t" << "[1] List Currencies.\n";
		cout << setw(37) << left << "" << "\t" << "[2] Find Currency.\n";
		cout << setw(37) << left << "" << "\t" << "[3] Update Rate.\n";
		cout << setw(37) << left << "" << "\t" << "[4] Cureency Calculator.\n";
		cout << setw(37) << left << "" << "\t" << "[5] Main Menue.\n";
		cout << setw(37) << left << "" << "==================================\n";


		_performmCurrencyExchangeOption(enExchangeOption(_ReadExchangeOption()));
	}
};

