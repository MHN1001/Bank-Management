#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h";
#include "ClsInputValidate.h";
#include "clsString.h";
#include "ClsCurrencies.h";


using namespace std;



class ClsUpdateCurrencyRateScreen : protected ClsScreen
{
private :

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

    static float _readRate()
    {
        cout << "\nEnter New Rate : ";
        float NewRate = ClsInputValidate::ReadFloatNumber();

        return  NewRate;
    }

public : 

	static void _ShowUpdateCurrencyScreen()
	{
		_drawScreenHeader("\t  Update Currency Screen");


        cout << "\nPlease enter currency code : ";
        string CurrencyCode = clsString::UpperAll(ClsInputValidate::ReadString());

        while (!clsCurrency::IsCurrencyExist(CurrencyCode))
        {
            cout << "\nInvalid currency code, Try Again : ";
            CurrencyCode = clsString::UpperAll(ClsInputValidate::ReadString());
        }

        clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
        _PrintCurrency(Currency);

   
        cout << "\nAre you sure you want to Update the rate of this currency [Y]/[N] : ";
        char answer; cin >> answer;

        if (toupper(answer) == 'Y')
        {

           cout << "\nUpdate Currency Rate";
           cout << "\n-----------------------";
           Currency.UpdateRate(_readRate());

            cout << "\nCurrency Rate Updated Successfully :)\n";
            _PrintCurrency(Currency);
        }

	}
};

