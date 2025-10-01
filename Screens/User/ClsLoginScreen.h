#pragma once
#include <iostream>
#include "ClsUser.h";
#include "Global.h";
#include "ClsMainScreen.h";
#include "clsdate.h";
#include <fstream>;

using namespace std;

class ClsLoginScreen : protected ClsScreen
{

private:

	static bool _login()
	{
		bool LoginFaild = false;
		string UserName, Password;
		short FaildLoginCount = 0;

		do
		{

			if (LoginFaild)
			{
				FaildLoginCount++;

				cout << "\nInvalide UserName/Password , Please Try Again !";
				cout << "\nYou Have " << (3-FaildLoginCount) << " Tials To login !\n";
				
			}

			if (FaildLoginCount == 3)
			{
				cout << "\nYou are locked after 3 Faild Trials !\n\n";
				return false;
			}

			cout << "\nEnter UserName : ";
			cin >> UserName;

			cout << "\nEnter Password : ";
			cin >> Password;


			CurrentUser = ClsUser::Find(UserName, Password);

			LoginFaild = CurrentUser.IsEmpty();

		} while (LoginFaild);

		CurrentUser.RegisterLogins();

		ClsMainScreen::ShowMainMenue();

		return true;
	}

public:

	static bool ShowLoginScreen()
	{
		system("cls");
		_drawScreenHeader("\t\tLogin Screen");
		return _login();
	}
};

