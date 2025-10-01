#pragma once
#include <iostream>
#include <iomanip>
#include "ClsScreen.h";

using namespace std;


class ClsLoginRegisterScreen : protected ClsScreen
{
private :

	static void _printLoginRegisterData(ClsUser::stLoginRegisterRecord LR)
	{
		cout << "\t\t|" << setw(25) << left << LR.DateAndTime
			 << "|" << setw(20) << left << LR.UserName
			 << "|" << setw(16) << left << LR.Password
			 << "|" << setw(4) << left << LR.Permession;
	}

public :

	static void ShowLoginRegisterScreen()
	{
		if (!CheckAccessRights(ClsUser::pLoginRegister))
		{
			return;
		}

		vector <ClsUser::stLoginRegisterRecord> LRvector = ClsUser::GetLoginRegisterList();

		string Title = "\t SHOW LOGIN REGISTER SCREEN";
		string SubTitle = "\t\t( " + to_string(LRvector.size()) + " ) Logins.";


		_drawScreenHeader(Title , SubTitle);

		cout << "\t\t----------------------------------------------------------------------------\n";
		cout << "\t\t|" << setw(25) << left << "Date/Time" << "|" << setw(20) << left << "User Name"
		   	 << "|" << setw(16) << left << "PassWord" << "|" << setw(4) << left << "Permession";
		cout << "\n\t\t---------------------------------------------------------------------------\n";

		if (LRvector.size() == 0)
		{
			cout << "\t\t No Logins Availble In The system !";
		}

		for (ClsUser::stLoginRegisterRecord& LR : LRvector)
		{
			_printLoginRegisterData(LR);
			cout << endl;
		}

		cout << "\n\t\t----------------------------------------------------------------------------\n";
	}
};

