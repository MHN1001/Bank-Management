#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h";
#include "ClsListUsersScreen.h";
#include "ClsAddNewUserScreen.h";
#include "ClsDeleteUsersScreen.h";
#include "ClsUser.h";


using namespace std;



class ClsUpdateUserScreen : protected ClsScreen
{

private:

	static int _ReadPermessionToset()
	{
		int Permession = 0;
		char Answer = 'n';

		cout << "\nDo you want to give full access ? [Y]/[N] ";
		cin >> Answer;
		if (toupper(Answer) == 'Y')
		{
			return -1;
		}

		cout << "\nDo you Want To give access To : ";

		cout << "\nShow Client List [Y]/[N] : ";
		cin >> Answer;
		if (toupper(Answer) == 'Y')
		{
			Permession += ClsUser::pListClient;
		}

		cout << "\nAdd New Client [Y]/[N] : ";
		cin >> Answer;
		if (toupper(Answer) == 'Y')
		{
			Permession += ClsUser::pAddClient;
		}


		cout << "\nDelete Client [Y]/[N] : ";
		cin >> Answer;
		if (toupper(Answer) == 'Y')
		{
			Permession += ClsUser::pDeleteClient;
		}

		cout << "\nUpdate Client [Y]/[N] : ";
		cin >> Answer;
		if (toupper(Answer) == 'Y')
		{
			Permession += ClsUser::pUpdateCleint;
		}

		cout << "\nFind Client [Y]/[N] : ";
		cin >> Answer;
		if (toupper(Answer) == 'Y')
		{
			Permession += ClsUser::pFindClient;
		}

		cout << "\nManage Users [Y]/[N] : ";
		cin >> Answer;
		if (toupper(Answer) == 'Y')
		{
			Permession += ClsUser::pManageUsers;
		}

		cout << "\nShow Login Register [Y]/[N] : ";
		cin >> Answer;
		if (toupper(Answer) == 'Y')
		{
			Permession += ClsUser::pLoginRegister;
		}

		return Permession;


	}

	static void _UpdateUser(ClsUser& NewUser)
	{
		cout << "First Name : ";
		NewUser.FirstName = ClsInputValidate::ReadString();

		cout << "Last Name : ";
		NewUser.LastName = ClsInputValidate::ReadString();

		cout << "Email : ";
		NewUser.Email = ClsInputValidate::ReadString();

		cout << "Phone : ";
		NewUser.Phone = ClsInputValidate::ReadString();

		cout << "PassWord : ";
		NewUser.Password = ClsInputValidate::ReadString();

		NewUser.Permession = _ReadPermessionToset();
	}

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

	static void ShowUpdateClientScreen()
	{

		_drawScreenHeader("\tUpdate User screen");

		string UserName = "";

		cout << "\nEnter Account Number : ";
		UserName = ClsInputValidate::ReadString();

		while (!ClsUser::IfUserExist(UserName))
		{
			cout << "Invalide Account Number , Enter Another Account Number : ";
			UserName = ClsInputValidate::ReadString();
		}

		ClsUser User = ClsUser::Find(UserName);
		_Print(User);

		char Answer = 'n';
		cout << "\nDo You Want To Update This Client [Y]/[N] : ";
		cin >> Answer;

		if (toupper(Answer) == 'Y')
		{
			cout << "\n Update User : ";
			cout << "\n-------------------\n";
			_UpdateUser(User);

			//Saving

			ClsUser::enSaveResult SaveResult;

			SaveResult = User.Save();

			switch (SaveResult)
			{
			case ClsUser::saveSucceeded:
			{
				cout << "\n Save Succeeded :)\n";
				_Print(User);
				break;
			}
			case ClsUser::SaveFaildUserNameEmpty:
			{
				cout << "\n Faild Save Because Your Object is Empty !\n";
				break;
			}
			}

		}

	}
};

