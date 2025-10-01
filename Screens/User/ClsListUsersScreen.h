#pragma once


#include <iostream>
#include <vector>
#include <iomanip>
#include "ClsUser.h";
#include "clsScreen.h";

using namespace std;

class ClsListUsersScreen : protected ClsScreen
{

	static void _PrintUserRecordLine(ClsUser User)
	{
		cout << "\t|" << setw(15) << left << User.UserName
			<< "|" << setw(20) << left << User.FullName()
			<< "|" << setw(16) << left << User.Phone
			<< "|" << setw(27) << left << User.Email
			<< "|" << setw(15) << left << User.Password
			<< "|" << setw(19) << left << User.Permession;
	}

public :

	static void ShowListUsersScreen()
	{
		vector <ClsUser> vUser = ClsUser::GetUserList();

		string Title = "\tList Users Screen";

		string SubTitle = "\t (" + to_string(vUser.size()) + ") Client";
		_drawScreenHeader(Title, SubTitle);

		cout << "\t--------------------------------------------------------------------------------------------------------------------\n";
		cout << "\t|" << setw(15) << left << "User Name" << "|" << setw(20) << left << "Full Name"
			<< "|" << setw(16) << left << "Phone" << "|" << setw(27) << left << "Email"
			<< "|" << setw(15) << left << "Password" << "|" << setw(19) << left << "Permession";
		cout << "\n\t--------------------------------------------------------------------------------------------------------------------\n";

		if (vUser.size() == 0)
		{
			cout << "\t\t\t\tNo Users available in the system !\n";
		}
		else
		{
			for (ClsUser& U : vUser)
			{
				_PrintUserRecordLine(U);
				cout << endl;
			}
		}
		cout << "\t--------------------------------------------------------------------------------------------------------------------\n";


	}
};

