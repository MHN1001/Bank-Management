#pragma once
#include <iostream>
#include <vector>
#include <iomanip>
#include "ClsBankClient.h";
#include "clsScreen.h";
#include "ClsInputValidate.h";

using namespace std;



class ClsFindUserScreen : protected ClsScreen
{
private:

	static void _Print(ClsUser  NewUser)
	{
		cout << "\nUser Card : ";
		cout << "\n----------------------------------------";
		cout << "\nFirst Name     : " << NewUser.FirstName;
		cout << "\nLast Name      : " << NewUser.LastName;
		cout << "\nFull Name      : " << NewUser.FullName();
		cout << "\nEmail          : " << NewUser.Email;
		cout << "\nPhone          : " << NewUser.Phone;
		cout << "\nUserName       : " << NewUser.UserName;
		cout << "\nPassword       : " << NewUser.Password;
		cout << "\nPermession     : " << NewUser.Permession;
		cout << "\n----------------------------------------\n";
	}



public:

	static void ShowFindClientScreen()
	{
		_drawScreenHeader("\tFind User Screen");

		string UserName = "";
		cout << "\nEnter User Name : ";
		UserName = ClsInputValidate::ReadString();

		while (!ClsUser::IfUserExist(UserName))
		{
			cout << "\nInvalid Account Number , Ennter Another User Name : ";
			UserName = ClsInputValidate::ReadString();
		}

		ClsUser user = ClsUser::Find(UserName);

		if (!user.IsEmpty())
		{
			cout << "\nUser Found :)\n";
			_Print(user);

		}
		else
		{
			cout << "\nUser Not Found :(";
		}
	}
};

