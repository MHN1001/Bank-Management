#pragma once
#include <iostream>
#include "clsdate.h";
#include "clsperiod.h";

using namespace std;


class ClsInputValidate
{
public:

	static bool IsNumberBetween(short from, short NumberToCompare, short To)
	{
		NumberToCompare >= from && NumberToCompare <= To ? true : false;
	}

	static bool IsNumberBetween(int from, int NumberToCompare, int To)
	{
		return  NumberToCompare >= from && NumberToCompare <= To ? true : false;
	}

	static bool IsNumberBetween(float from, float NumberToCompare, float To)
	{
		NumberToCompare > from&& NumberToCompare < To ? true : false;
	}

	static bool IsNumberBetween(double from, double NumberToCompare, double To)
	{
		NumberToCompare > from&& NumberToCompare < To ? true : false;
	}

	static bool IsDateBetween(clsdate Date, clsdate DateFrom, clsdate DateTo)
	{
		//date>=datefrom && Date<=dateto
		if ((clsdate::IfDate1AfterDate2(Date, DateFrom) || clsdate::IfDate1lEqualToDate2(Date, DateFrom)
			&&
			clsdate::IfDate1beforDate2(Date, DateTo) || clsdate::IfDate1lEqualToDate2(Date, DateTo)))
		{
			return true;
		}

		//date>=Dateto  && Date<=Datefrom
		if ((clsdate::IfDate1AfterDate2(Date, DateTo) || clsdate::IfDate1lEqualToDate2(Date, DateTo)
			&&
			clsdate::IfDate1beforDate2(Date, DateFrom) || clsdate::IfDate1lEqualToDate2(Date, DateFrom)))
		{
			return true;
		}

	}

	static int ReadIntNumber(string ErrorMessage = "Invalid Number, Enter Again : ")
	{
		int number;

		while (!(cin >> number))
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			cout << ErrorMessage;
		}
		return number;
	}

	static int ReadIntNumberBetween(int from, int to, string ErrorMessage = "Invalid Number, Enter Again : ")
	{
		int number = ReadIntNumber();

		while (!(IsNumberBetween(from, number, to)))
		{
			cout << ErrorMessage;
			number = ReadIntNumber();
		}

		return number;
	}

	static double ReadDBLNumber(string ErrorMessage = "Invalid Number, Enter Again : ")
	{
		double number;
		while (!(cin >> number))
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			cout << ErrorMessage;
		}
		return number;
	}

	static double ReadDBLNumber(double from, double to, string ErrorMessage = "Invalid Number, Enter Again : ")
	{
		double number = ReadDBLNumber();

		while (!(IsNumberBetween(from, number, to)))
		{
			cout << ErrorMessage;
			number = ReadDBLNumber();
		}

		return number;
	}

	static double ReadFloatNumber(string ErrorMessage = "Invalid Number, Enter Again : ")
	{
		float number;
		while (!(cin >> number))
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			cout << ErrorMessage;
		}
		return number;
	}

	static  bool IsValideDate(clsdate Date)
	{
		return  clsdate::ValidateDate(Date);
	}

	static string ReadString()
	{
		string str;
		getline(cin >> ws, str);
		return str;
	}



};

