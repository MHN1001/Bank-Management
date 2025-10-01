#pragma once

#include <iostream>
#include <vector>
using namespace std;

class clsString
{

private:

	string _Value;

public:


	clsString()
	{
		_Value = "";
	}

	clsString(string value)
	{
		_Value = value;
	}


	void SetValue(string Value)
	{
		_Value = Value;
	}

	string GetValue()
	{
		return _Value;
	}

	_declspec(property(get = GetValue, put = SetValue)) string Value;

	//***********************COUNT WORD***********************************
	static short CountWords(string str)
	{
		string Delimiter = " ";
		short pos;
		string UpdateStr;
		short Counter = 0;

		while ((pos = str.find(Delimiter)) != std::string::npos)
		{
			UpdateStr = str.substr(0, pos);

			if (UpdateStr != "")
			{
				Counter++;
			}

			str.erase(0, pos + Delimiter.length());
		}
		if (str != "")
		{
			Counter++;
		}

		return Counter;
	}

	short CountWords()
	{
		return CountWords(_Value);
	}
	//*************************************************************


	//*************************REPLACE WORD******************
    static string ReplaceWord(string Str, string TheRequiredWord, string replacementWord)
	{
		short pos = Str.find(TheRequiredWord);

		while (pos != std::string::npos)
		{
			Str.replace(pos, TheRequiredWord.length(), replacementWord);

			pos = Str.find(TheRequiredWord);
		}
		return Str;
	}

	void ReplaceWord(string TheRequiredWord, string replacementWord)
	{
		_Value = ReplaceWord(_Value, TheRequiredWord, replacementWord);
	}
	//***************************************************************


	//*******************lower All string*****************************
	static string lowerAll(string str)
	{
		for (short loop = 0; loop < str.length(); loop++)
		{
			str[loop] = tolower(str[loop]);
		}
		return str;
	}

	void lowerAll()
	{
		_Value = lowerAll(_Value);
	}
	//******************************************************************


	//*******************Upper all string**********************
	static string UpperAll(string str)
	{
		for (short loop = 0; loop <= str.length(); loop++)
		{
			str[loop] = toupper(str[loop]);
		}
		return str;
	}

	string UpperAll()
	{
		_Value = UpperAll(_Value);
	}
	//****************************************************************


	//***********************Split String******************************
	static vector <string> Split(string Str, string Delimiter="#//#")
	{
		vector <string> Vvector;

		short pos = 0;
		string Cword;

		while ((pos = Str.find(Delimiter)) != std::string::npos)
		{
			Cword = Str.substr(0, pos);

			/*if (Cword != "")
			{*/
				Vvector.push_back(Cword);
			//}

			Str.erase(0, pos + Delimiter.length());
		}

		if (Str != "")
		{
			Vvector.push_back(Str);
		}

		return Vvector;
	}

	vector <string> Split(string Delimiter)
	{
		return Split(_Value, Delimiter);
	}
	//************************************************************************


    // *************print first letter in string*****************
	static void PrintEachFirstLetter(string str)
	{
		bool isFirstLetter = true;

		for (short i = 0; i < str.length(); i++)
		{

			if (str[i] != ' ' && isFirstLetter)
			{
				cout << str[i];
			}

			isFirstLetter = (str[i] == ' ' ? true : false);
		}
	}

	void PrintEachFirstLetter()
	{
		 PrintEachFirstLetter(_Value);
	}
	//****************************************************************************

    
	// *************count letter In string*********************
	static int countSpecificLetter(string str, char letter_to_count)
	{
		short counter = 0;

		for (short loop = 0; loop < str.length(); loop++)
		{
			if (str[loop] == letter_to_count)
			{
				counter += 1;
			}
		}
		return (counter == 0 ? 0 : counter);
	}

	int countSpecificLetter(char LetterToCount)
	{
		return countSpecificLetter(_Value, LetterToCount);
	}
	//**********************************************************************


	//**********how many vowels in string******************
	static bool checkVowels(char character)
	{
		character = tolower(character);

		return (character == 'a' || character == 'o' || character == 'i' || character == 'e' || character == 'u');

	}

	static short HowManyVowels(string str)
	{
		short counter = 0;

		for (short loop = 0; loop < str.length(); loop++)
		{
			if (checkVowels(str[loop]))
			{
				counter += 1;
			}
		}
		return counter;
	}

	short HowManyVowels()
	{
		return HowManyVowels(_Value);
	}
	//**********************************************************


	//********************printEachWordInString********************
	static void PrintEachWord(string str)
	{
		string Delimiter = " ";
		short pos = 0;
		string sword;

		while ((pos = str.find(Delimiter)) != std::string::npos)
		{
			
			sword = str.substr(0, pos);

			if (sword != " ")
			{
				cout << sword << endl;
			}


			str.erase(0, pos + Delimiter.length());
		}
		if (str != " ")
		{
			cout << str << endl;
		}
	}

	void PrintEachWord()
	{
		return PrintEachWord(_Value);
	}
	//**********************************************************************


	//****************how Many Word In string*************************
    static int howManyWord(string str)
	{

		string Delimiter = " ";
		short pos = 0;
		string Sword;
		short counter = 0;

		while ((pos = str.find(Delimiter)) != std::string::npos)
		{
			Sword = str.substr(0, pos);
			if (Sword != " ")
			{
				counter += 1;
			}

			str.erase(0, pos + Delimiter.length());

		}

		if (str != " ")
		{
			counter += 1;
		} 

		return counter;
	}

	int howManyWord()
	{
		return howManyWord(_Value);
	}
	//****************************************************************


	//**************remove spaces from left************
	static string leftTrim(string str)
	{
		for (short i = 0; i < str.length(); i++)
		{
			if (str[i] != ' ')
			{
				return str.substr(i, str.length() - i);
			}
		}
		return "";
	}

	void leftTrim()
	{
		_Value = leftTrim(_Value);
	}
	//*****************************************************************************


	//**************remove spaces from right*********************
	static string RigthTrim(string str)
	{
		for (short i = str.length() - 1 ; i >= 0 ; i--)
		{
			if (str[i] != ' ')
			{
				return str.substr(0, i + 1);
			}
		}
		return "";
	}

	void RigthTrim()
	{
		_Value =  RigthTrim(_Value);
	}
	//**********************************************************************************


	//*****************************trim**************************
	static string trim(string str)
	{
		return (leftTrim(RigthTrim(str)));
	}

	string trim()
	{
		_Value = trim(_Value);
	}
	//**************************************************************************



	//************join string with array and vector**************
	string joinString(vector <string> Vvecto, string delimiter)
	{
		string string_result = "";

		for (string& Cstr : Vvecto)
		{
			string_result += Cstr + delimiter;
		}

		return string_result.substr(0, string_result.length() - delimiter.length());

	}


	string joinString(string  arr[], short length, string delimiter)
	{
		string string_result = "";

		for (short loop = 0; loop < length; loop++)
		{
			string_result += arr[loop] + delimiter;
		}
		return string_result.substr(0, string_result.length() - delimiter.length());
	}
	//************************************************************************************



	//*******************reverse string************************
	string reverse_string(string str)
	{

		 vector <string> vvector;
		string string_reversed = "";

		vvector = Split(str, " ");

		vector <string>::iterator Vkey = vvector.end();

		while (Vkey != vvector.begin())
		{
			--Vkey;
			string_reversed += *Vkey + " ";
		}

		return string_reversed.substr(0, string_reversed.length() - 1);
	}

	void reverse_string()
	{
		_Value = reverse_string(_Value);
	}
	//*****************************************************


	//******************Remove punctuation*********************
	static string RemovePunctuations(string str)
	{
		string UpdateString;
		for (short loop = 0; loop < str.length(); loop++)
		{
			if (!ispunct(str[loop]))
			{
				UpdateString += str[loop];
			}
		}
		return UpdateString;
	}
    
	void RemovePunctuations()
	{
		_Value = RemovePunctuations(_Value);
	}
	//*********************************************************************
};
