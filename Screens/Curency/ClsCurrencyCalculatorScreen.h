#pragma once
#include <iostream>
#include <string>
#include "ClsScreen.h";
#include "ClsCurrencies.h";
#include "ClsInputValidate.h";

using namespace std;



class ClsCurrencyCalculatorScreen : protected ClsScreen
{
private:

	static clsCurrency _GetCurrencyObject(string Message = "Please Enter currency Code : ")
	{
		cout << Message << endl;
		string CurrencyCode = clsString::UpperAll(ClsInputValidate::ReadString());

		while (!clsCurrency::IsCurrencyExist(CurrencyCode))
		{
			cout << "\nInvalid currency code, Try Again : ";
			CurrencyCode = clsString::UpperAll(ClsInputValidate::ReadString());
		}

		clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);

		return Currency;
	}

	static void _PrintCurrencyCard(clsCurrency Currency, string Message)
	{
		cout << Message << endl;
		cout << "_____________________________\n";
		cout << "\nCountry    : " << Currency.Country();
		cout << "\nCode       : " << Currency.CurrencyCode();
		cout << "\nName       : " << Currency.CurrencyName();
		cout << "\nRate(1$) = : " << Currency.Rate();
		cout << "\n_____________________________\n";

	}

	static float _ReadAmount()
	{
		cout << "\nEnter Amount To Exchange : ";
		float Amount = ClsInputValidate::ReadFloatNumber();

		return Amount;
	}

	static void _PrintCalculationResult(float Amount, clsCurrency Currencyfrom, clsCurrency currencyTo)
	{

		_PrintCurrencyCard(Currencyfrom, "\nCurrency From");

		float AmountInUSD = Currencyfrom.ConvertToUSD(Amount);

		cout << "\n" << Amount << " " << Currencyfrom.CurrencyCode() << " = " << AmountInUSD << " USD\n";

		if (currencyTo.CurrencyCode() == "USD")
		{
			return;
		}

		cout << "\nConverting From USD To : \n";
		_PrintCurrencyCard(currencyTo, "\nTo : ");

		float AmountInCurrency2 = Currencyfrom.ConvertToOtherCurrency(Amount, currencyTo);

		cout << "\n" << Amount << " " << Currencyfrom.CurrencyCode() << " = " << AmountInCurrency2 << " " << currencyTo.CurrencyCode();

	}

public:

	static void ShowCalculatoeCurrencyScreen()
	{
		char Continue = 'Y';
		while(toupper(Continue) == 'Y' )
		{
			system("cls");
			_drawScreenHeader("\tCalculator Currency Screen");

			clsCurrency Currency1 = _GetCurrencyObject("\nPlease Enter currency1 Code : ");

			clsCurrency Currency2 = _GetCurrencyObject("\nPlease Enter currency2 Code : ");

			float Amount = _ReadAmount();

			_PrintCalculationResult(Amount, Currency1, Currency2);
			

			cout << "\n\nDo you want To perform another calculation [Y]/[N] : ";
			cin >> Continue;
		} 
	}
};

