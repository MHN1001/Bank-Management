#pragma once

#include <iostream>
#include <iomanip>
#include "clsScreen.h";
#include "ClsListUsersScreen.h";
#include "ClsAddNewUserScreen.h";
#include "ClsDeleteUsersScreen.h";
#include "ClsUpdateUserScreen.h";
#include "ClsFindUserScreen.h";


using namespace std;

class ClsManageUserScreen : protected ClsScreen
{

private:
	enum enManageUsers
	{
		eListUser = 1, eAddUser = 2,
		eDeleteUser = 3, eUpdateUser = 4,
		eFindUser = 5, eMainMenue = 6
	};

	static short _ReadManageUsersMenueOption()
	{
		cout << setw(37) << left << "" << "Choose what do you want Between [1] & [6] : ";
		short choice = ClsInputValidate::ReadIntNumberBetween(1, 6);
		return choice;
	}

	static void _GoBackToManageUsersMenue()
	{
		cout << "\nPress any key to go back to Manage User Screen : ";
		system("pause>0");
		system("cls");
		ShowManageUserScreen();
	}

	static void _ShowListUsersScreen()
	{
		ClsListUsersScreen::ShowListUsersScreen();
	}

	static void _ShowAddNewUserScreen()
	{
		ClsAddNewUserScreen::ShowAddNewUserScreen();
	}

	static void _ShowDeleteUserScreen()
	{
		ClsDeleteUsersScreen::ShowDeleteUsersScreen();
	}

	static void _ShowUpdateUsersScreen()
	{
		ClsUpdateUserScreen::ShowUpdateClientScreen();
	}
	
	static void _ShowFindUsersScreen()
	{
		ClsFindUserScreen::ShowFindClientScreen();
	}


	static void _PerformManageUsersMenueOption(enManageUsers Option)
	{
		switch (Option)
		{
		case enManageUsers::eListUser:
		{
			system("cls");
			_ShowListUsersScreen();
			_GoBackToManageUsersMenue();
			break;
		}
		case enManageUsers::eAddUser:
		{
			system("cls");
			_ShowAddNewUserScreen();
			_GoBackToManageUsersMenue();
			break;
		}
		case enManageUsers::eDeleteUser:
		{
			system("cls");
			_ShowDeleteUserScreen();
			_GoBackToManageUsersMenue();
			break;
		}
		case enManageUsers::eUpdateUser:
		{
			system("cls");
			_ShowUpdateUsersScreen();
			_GoBackToManageUsersMenue();
			break;
		}
		case enManageUsers::eFindUser:
		{
			system("cls");
			_ShowFindUsersScreen();
			_GoBackToManageUsersMenue();
			break;
		}
		case enManageUsers::eMainMenue:
		{

		}
		}
	}

public :

	static void ShowManageUserScreen()
	{

		if (!CheckAccessRights(ClsUser::pManageUsers))
		{
			return;
		}


		_drawScreenHeader("\t    Manage User Screen");


		cout << setw(37) << left << "" << "==================================\n";
		cout << setw(37) << left << "" << "\tMANAGE USERS MENUE SCREEN\n";
		cout << setw(37) << left << "" << "==================================\n";
		cout << setw(37) << left << "" << " [1] Lists Users.\n";
		cout << setw(37) << left << "" << " [2] Add New User.\n";
		cout << setw(37) << left << "" << " [3] Delete User.\n";
		cout << setw(37) << left << "" << " [4] Update User.\n";
		cout << setw(37) << left << "" << " [5] Find User.\n";
		cout << setw(37) << left << "" << " [6] Main Menue.\n";
		cout << setw(37) << left << "" << "===================================\n";


		_PerformManageUsersMenueOption(enManageUsers(_ReadManageUsersMenueOption()));
	}
};

