#pragma once

#include <iostream>
#include <vector>
#include <iomanip>
#include "ClsBankClient.h";
#include "clsScreen.h";
#include "ClsCurrencies.h";

using namespace std;


class ClsListCurrensiesScreen : protected ClsScreen
{
private:

	static void _printCurrenciesRecordLine(clsCurrency currency)
	{
		cout << "\t|" << setw(35) << left << currency.Country()
			<< "|" << setw(7) << left << currency.CurrencyCode()
			<< "|" << setw(40) << left << currency.CurrencyName()
			<< "|" << setw(8) << left << currency.Rate();
	}


public :

	static void ShowListCurrenciesScreen()
	{
		vector <clsCurrency> Vcurrencies = clsCurrency::GetCurrenciesList();

		string Title = "\t  Show List Currencies";
		string subtitle = "\t  ( " + to_string(Vcurrencies.size()) + " ) Currency";

		_drawScreenHeader(Title, subtitle);

		cout << "\t-------------------------------------------------------------------------------------------------\n";
		cout << "\t|" << setw(35) << left << "Country" << "|" << setw(7) << left << "Code"
			<< "|" << setw(40) << left << "Name" << "|" << setw(8) << left << "Rate/($)";
		cout << "\n\t-------------------------------------------------------------------------------------------------\n";

		if (Vcurrencies.size() == 0)
		{
			cout << "\t\t\t\tNo Currencies available in the system !\n";
		}


		for(clsCurrency& C : Vcurrencies)
		{
			_printCurrenciesRecordLine(C);
			cout << endl;
		}


		cout << "\n\t-------------------------------------------------------------------------------------------------\n";
	}
};

