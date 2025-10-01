#pragma once
#include <iostream>
#include <vector>
#include "ClsUtility.h";
#include "clsString.h";
#include  <fstream>;
#include  <string>;

using namespace std;


class clsCurrency
{
private:
	enum enMode {EmptyMode=0, UpdateMode=1};
	enMode _Mode;

	string _Country;
	string _CurrencyCode;
	string _CurrencyName;
	float _Rate;

     static clsCurrency _ConvertLineToCurrencyObject(string Line, string Delim="#//#")
    {
        vector <string> VcurrencyDataLine = clsString::Split(Line, Delim);

        return clsCurrency(clsCurrency::UpdateMode, VcurrencyDataLine[0], VcurrencyDataLine[1]
                           , VcurrencyDataLine[2], stof(VcurrencyDataLine[3]));
    }

     static  vector <clsCurrency> _LoadCurrencyDataFromFile()
    {
        vector <clsCurrency> VcurrencyObject;

        fstream CurrencyFile;

        CurrencyFile.open("Cirrencies.txt", ios::in);

        if (CurrencyFile.is_open())
        {
            string Line;

            while (getline(CurrencyFile, Line))
            {
                clsCurrency Currency = _ConvertLineToCurrencyObject(Line);

                VcurrencyObject.push_back(Currency);
            }
            CurrencyFile.close();
        }
        return VcurrencyObject;
    }

     static string _convertCurrencyObjectToLine(clsCurrency currensyObject, string Delimiter="#//#")
    {
         string Line;

         Line += currensyObject.Country() + Delimiter;
         Line += currensyObject.CurrencyCode() + Delimiter;
         Line += currensyObject.CurrencyName() + Delimiter;
         Line += to_string(currensyObject.Rate());

         return Line;
    }

     static void _saveCurrenciesObjectToFile(vector <clsCurrency> Vcurrency)
    {
        fstream CurrenciesFile;

        CurrenciesFile.open("Cirrencies.txt", ios::out);

        if (CurrenciesFile.is_open())
        {
            string Line;

            for (clsCurrency& C : Vcurrency)
            {
                Line = _convertCurrencyObjectToLine(C);

                CurrenciesFile << Line << endl;
            }
            CurrenciesFile.close();
        }
    }

     void _Update()
    {
        vector <clsCurrency> Vcurrency = _LoadCurrencyDataFromFile();

        for (clsCurrency& C : Vcurrency)
        {
            if (C.Country() == this->Country())
            {
                C = *this;
                break;
            }
        }

        _saveCurrenciesObjectToFile(Vcurrency);

    }

     static clsCurrency _GetEmptyCurrencyObject()
     {
         return  clsCurrency(clsCurrency::EmptyMode, "", "", "", 0);
     }

public:

	clsCurrency(enMode Mode, string Country, string CurrencyCode, string CurrencyName, float Rate)
	{
		_Mode = Mode;
		_Country = Country;
		_CurrencyCode = CurrencyCode;
		_CurrencyName = CurrencyName;
		_Rate = Rate;
	}

    bool IsEmpty()
    {
        return (_Mode == enMode::EmptyMode);
    }

    string Country()
    {
        return _Country;
    }

    string CurrencyCode()
    {
        return _CurrencyCode;
    }

    string CurrencyName()
    {
        return _CurrencyName;
    }

    void UpdateRate(float NewRate)
    {
        _Rate = NewRate;
        _Update();
    }

    float Rate()
    {
        return _Rate;
    }

    static clsCurrency FindByCode(string CurrencyCode)
    {
        CurrencyCode = clsString::UpperAll(CurrencyCode);

        fstream CurrencyFile;

        CurrencyFile.open("Cirrencies.txt", ios::in);

        if (CurrencyFile.is_open())
        {
            string Line="";

            while (getline(CurrencyFile, Line))
            {
                clsCurrency CurrencyObject = _ConvertLineToCurrencyObject(Line);

                if (CurrencyObject.CurrencyCode() == CurrencyCode)
                {
                    CurrencyFile.close();

                    return CurrencyObject;
                }
            }
                CurrencyFile.close();
        }
            return _GetEmptyCurrencyObject();
    }

    static clsCurrency FindByCountry(string Country)
    {
        Country = clsString::UpperAll(Country);

        fstream CurrencyFile;

        CurrencyFile.open("Cirrencies.txt", ios::in);

        if (CurrencyFile.is_open())
        {
            string Line;

            while (getline(CurrencyFile, Line))
            {
                clsCurrency CurrencyObject = _ConvertLineToCurrencyObject(Line);

                if (clsString::UpperAll(CurrencyObject.Country()) == Country)
                {
                    CurrencyFile.close();

                    return CurrencyObject;
                }
            }
                CurrencyFile.close();
        }
            return _GetEmptyCurrencyObject();
    }

    static bool IsCurrencyExist(string CurrencyCode)
    {
        clsCurrency currencyObject = clsCurrency::FindByCode(CurrencyCode);

        return (!(currencyObject.IsEmpty()));
    }

    static vector <clsCurrency> GetCurrenciesList()
    {
        return _LoadCurrencyDataFromFile();
    }

    float ConvertToUSD(float Amount)
    {
        return  float(Amount / Rate());
    }

    float ConvertToOtherCurrency(float Amount, clsCurrency CurrencyTo)
    {
        float AmountInUSD = ConvertToUSD(Amount);

        if (CurrencyTo.CurrencyCode() == "USD")
        {
            return AmountInUSD;
        }

        return float(AmountInUSD * CurrencyTo.Rate());
    }


};

