#pragma once
#include  <iostream>
#include  <string>
#include  "clsdate.h";

using namespace std;


class ClsUtility
{

private:

	int _number;
	string _str;

public:

	static void Srand()
	{
		srand((unsigned)time(NULL));
	}

	static int RandomNumber(short from, short to)
	{
		int therandom_number = rand() % (to - from + 1) + from;
		return therandom_number;
	}

	enum enCharType { small_letters = 1, capital_letters = 2, Digit = 3, MixCharacter = 4, Special_characters= 5};
	static char GetRandomCharacter(enCharType charType)
	{

		if (charType == enCharType::MixCharacter)
		{
			charType = enCharType(RandomNumber(1, 3));
		}


		switch (charType)
		{
		case enCharType::small_letters:
			return char(RandomNumber(97, 122));
			break;

		case enCharType::capital_letters:
			return char(RandomNumber(65, 90));
			break;

		case enCharType::Special_characters:
			return char(RandomNumber(33, 47));
			break;

		case enCharType::Digit:
			return char(RandomNumber(49, 57));
			break;

		default:
			return char(RandomNumber(65, 90));
			break;

		}
	}

	static string GeneratWord(enCharType tool, short Wordlength)
	{
		string word;
		for (int loop = 1; loop <= Wordlength; loop += 1)
		{
			word = word + GetRandomCharacter(tool);
		}
		return word;
	}

	static string collectLetters(enCharType tool)
	{
		string _4_word = "";

		_4_word = GeneratWord(tool, 4) + "-";
		_4_word = _4_word + GeneratWord(tool, 4) + "-";
		_4_word = _4_word + GeneratWord(tool, 4) + "-";
		_4_word = _4_word + GeneratWord(tool, 4);

		return _4_word;

	}

	static string GenerateKey(enCharType tool)
	{
		return collectLetters(tool);
	}

	static string GenerateKeys(enCharType tool, short HowManyKeys)
	{
		string keys;
		for (short loop = 1; loop <= HowManyKeys; loop++)
		{
		 keys += "key [" + to_string(loop) + "]" + " : " + collectLetters(tool) + "\n";
		}
		return keys;
	}

	static void swap(int& A, int& B)
	{
		int swap;

		swap = A;
		A = B;
		B = swap;
	}

	static void swap(double& A, double& B)
	{
		double swap;

		swap = A;
		A = B;
		B = swap;
	}

	static void swap(string& A, string& B)
	{
		string swap;

		swap = A;
		A = B;
		B = swap;
	}

	static  void Swap(clsdate& Date1, clsdate& Date2)
	{
		clsdate::Swap(Date1, Date2);

	}

 	static void shuffle_array(int arr[50], int length)
	{
		for (int loop = 0; loop < length; loop += 1)
		{
			swap(arr[RandomNumber(1, length) - 1], arr[RandomNumber(1, length) - 1]);
		}

	}

	static void shuffle_array(string arr[50], int length)
	{
		for (int loop = 0; loop < length; loop += 1)
		{
			swap(arr[RandomNumber(1, length) - 1], arr[RandomNumber(1, length) - 1]);
		}

	}

	static void CopyArray(int arr[100], int& number, int arr2[100])
	{
		for (int loop = 0; loop <= number; loop += 1)
		{
			arr2[loop] = arr[loop];
		}
	}

	static void fillArrayWithRandorNumber(int arr[100], short Arraylength,short From, short To )
	{
		for (int loop = 0; loop <= Arraylength; loop += 1)
		{
			arr[loop] = RandomNumber(From, To);
		}
		cout << endl;
	}

	static void fillArrayWithRandorWords(string arr[100], short Arraylength, enCharType tool ,short wordLength )
	{
		for (int loop = 0; loop <= Arraylength; loop += 1)
		{
			arr[loop] = GeneratWord(tool, wordLength);
		}
		cout << endl;
	}

	static void printArray(int arr[100], int& number)
	{
		for (int loop = 1; loop <= number; loop += 1)
		{
			cout << arr[loop] << " ";
		}
		cout << endl;
	}

	static void printArray(string arr[100], int& number)
	{
		for (int loop = 1; loop <= number; loop += 1)
		{
			cout << arr[loop] << " ";
		}
		cout << endl;
	}

	static string Taps(double HowMany4Spaces)
	{
		string _4spaces = "";
		for (int loop = 1; loop <= HowMany4Spaces; loop += 1)
		{
			_4spaces = _4spaces + "\t";
			cout << _4spaces;
		}
		return _4spaces;
	}

	static string EncryptionTEXT(string text, int encryption_key=2)
	{
		for (int N = 0; N <= text.length(); N += 1)
		{
			text[N] = char(int(text[N] + encryption_key));
		}
		return text;

	}

	static string DecryptionTEXT(string text, int encryption_key=2)
	{
		for (int N = 0; N <= text.length(); N += 1)
		{
			text[N] = char(int(text[N] - encryption_key));
		}
		return text;

	}

	static int collectArrays(int arr[100], int& number)
	{
		int sum = 0;
		for (int loop = 1; loop <= number; loop += 1)
		{
			sum = sum + arr[loop];
		}
		return sum;

	}

	static short SearchForNumberInArray(int arr1[100], int length, int search_for)
	{

		for (int loop = 0; loop < length; loop += 1)
		{
			if (arr1[loop] == search_for)
			{

				return loop;

			}
		}
		return -1;

	}

	static bool IsNumberInArray(int arr1[100], int length, int search_for)
	{
		return (SearchForNumberInArray(arr1, length, search_for) != -1);
	}

	static string  NumberToText(int Number)
	{
		if (Number == 0)
		{
			return "";
		}

		if (Number >= 1 && Number <= 19)
		{
			string arr[] = { "" ,"One", "two", "three", "four", "five", "six", "seven", "eight",
							"nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen",
							"sixteen", "seventeen", "eighteen", "nineteen" };

			return arr[Number] + " ";
		}

		if (Number >= 20 && Number <= 99)
		{
			string arr[] = { "" , "" ,"Twenty", "thirty", "forty", "fifty",
							 "sixty", "seventy", "eighty", "ninety" };

			return arr[Number / 10] + " " + NumberToText(Number % 10);
		}

		if (Number >= 100 && Number <= 199)
		{
			return "One hundred " + NumberToText(Number % 100);
		}

		if (Number >= 200 && Number <= 999)
		{
			return NumberToText(Number / 100) + "Hundreds " + NumberToText(Number % 100);
		}

		if (Number >= 1000 && Number <= 1999)
		{
			return "One thousand " + NumberToText(Number % 1000);
		}


		if (Number >= 2000 && Number <= 999999)
		{
			return  NumberToText(Number / 1000) + "Thousands " + NumberToText(Number % 1000);
		}

		if (Number >= 1000000 && Number <= 1999999)
		{
			return  "One Million " + NumberToText(Number % 1000000);
		}

		if (Number >= 2000000 && Number <= 999999999)
		{
			return  NumberToText(Number / 1000000) + "Millions " + NumberToText(Number % 1000000);
		}

		if (Number >= 1000000000 && Number <= 1999999999)
		{
			return  "One billion " + NumberToText(Number / 1000000000);
		}

		else
		{
			return NumberToText(Number / 1000000000) + "Bellions " + NumberToText(Number % 1000000000);
		}
	}
};

