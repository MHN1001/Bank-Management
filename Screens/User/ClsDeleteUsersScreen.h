#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h";
#include "ClsListUsersScreen.h";
#include "ClsAddNewUserScreen.h";


using namespace std;



class ClsDeleteUsersScreen : protected ClsScreen 
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

	static void ShowDeleteUsersScreen()
	{
		_drawScreenHeader("\tDelete User Screen");

		string UserName = "";

		cout << "\nEnter Account Number : ";
		UserName = ClsInputValidate::ReadString();

		while (!ClsUser::IfUserExist(UserName))
		{
			cout << "\nInvalide Account Number , choose another one : \n";
			UserName = ClsInputValidate::ReadString();
		}

		ClsUser User = ClsUser::Find(UserName);

		_Print(User);

		char Answer = ' ';
		cout << "\nAre You sure You Want To delete This User ? [Y]/[N] : ";
		cin >> Answer;

		if (toupper(Answer) == 'Y')
		{
			if (User.Delete())
			{
				cout << "\nUser Deleted Sccessfully!\n";

				_Print(User);
			}
			else
			{
				cout << "\nError User Was Not Deleted!\n";
			}
		}
	}
};

