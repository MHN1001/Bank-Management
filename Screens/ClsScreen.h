#pragma once
#include <iostream>
#include "ClsUser.h"
#include "clsdate.h";
#include <iomanip>

using namespace std;


class ClsScreen
{


protected:

	static void _drawScreenHeader(string Title, string SubTiTle="")
	{
		cout << setw(37) << left << "" << "----------------------------------\n";
		cout << setw(37) << left << "" << Title << "\n";
		if (SubTiTle != "")
		{
	       cout << setw(37) << left << "" << SubTiTle << "\n";
		}
		cout << setw(37) << left << "" << "----------------------------------\n";
		cout << setw(37) << left << "" << "User : " << CurrentUser.UserName << "\n";
		cout << setw(37) << left << "" << "Date : " << clsdate::DateToString(clsdate());
	}

    static bool CheckAccessRights(ClsUser::enPermession Permession)
	{
		if (!CurrentUser.checkAccessPermession(Permession))
		{
			cout << setw(37) << left << "" << "----------------------------------\n";
			cout << setw(37) << left << "" << "ACCESS DENIED . CONTACT YOUR ADMIN\n";
			cout << setw(37) << left << "" << "----------------------------------\n";
			return false;
		}
		else
		{
			return true;
		}
	}
};


