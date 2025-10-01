#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h";
#include "ClsInputValidate.h";
#include "ClsCurrencies.h";

using namespace std;


class ClsFindCurrencyScreen : protected ClsScreen
{


private:
	enum enFindCurrencyChoice { eFindByCode = 1, eFindByCountry = 2 };

    static void _PrintCurrency(clsCurrency Currency)
    {
        cout << "\nCurrency Card:\n";
        cout << "_____________________________\n";

        cout << "\nCountry    : " << Currency.Country();
        cout << "\nCode       : " << Currency.CurrencyCode();
        cout << "\nName       : " << Currency.CurrencyName();
        cout << "\nRate(1$) = : " << Currency.Rate();

        cout << "\n_____________________________\n";

    }

    static short _ReadFindCurrencyOption()
    {
        cout << "\nFind By [1] Code [2] Country : ";

        short Option = ClsInputValidate::ReadIntNumberBetween(1, 2);

        return  Option;
    }

    static string _ReadCurrencyCode()
    {
        cout << "\nPlease Enter CurrencyCode : ";

        string Currencycode = ClsInputValidate::ReadString();

        return Currencycode;
    }

    static string _ReadCountry()
    {
        cout << "\nPlease Enter country name : ";

        string Country = ClsInputValidate::ReadString();

        return Country;
    }

    static void _showResult(clsCurrency Currency)
    {
        if (Currency.IsEmpty())
        {
            cout << "\nCurrency was Not Found !\n";
        }
        else
        {
            cout << "\nCurrency Found :)\n";
            _PrintCurrency(Currency);
        }
    }

    static void _PerformFindCurrencyOption(enFindCurrencyChoice Option)
    {
        switch (Option)
        {
        case enFindCurrencyChoice::eFindByCode:
        {

            clsCurrency Currency = clsCurrency::clsCurrency::FindByCode(_ReadCurrencyCode());

            _showResult(Currency);

            break;
        }
        case enFindCurrencyChoice::eFindByCountry:
        {
            clsCurrency Currency = clsCurrency::clsCurrency::FindByCountry(_ReadCountry());

            _showResult(Currency);

            break;
        }
        }
    }

public:

    static void _ShowFindCurremcyScreen()
    {
        _drawScreenHeader("\tFind Currency Screen");

        _PerformFindCurrencyOption(enFindCurrencyChoice(_ReadFindCurrencyOption()));
    }
};

