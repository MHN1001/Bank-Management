#pragma once
#include <iostream>
#include "ClsScreen.h";
#include "ClsBankClient.h";
#include "ClsInputValidate.h";
#include <iomanip>
#include <vector>
#include "clsUser.h";
#include "ClsUtility.h";

using namespace std;



class ClsAddNewUserScreen : protected ClsScreen
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
         if(toupper(Answer) == 'Y')
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

	static void _AddNewUser(ClsUser &NewUser)
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
		NewUser.Password  =  ClsInputValidate::ReadString();

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
	static void ShowAddNewUserScreen()
	{
		_drawScreenHeader("\tAdd New User Screen");

		cout << "\nEnter Account Number : ";
		string UserName = ClsInputValidate::ReadString();

		while (ClsUser::IfUserExist(UserName))
		{
			cout << "\nInvalide Account Number , choose another one : \n";
			UserName = ClsInputValidate::ReadString();
		}

		ClsUser NewUser = ClsUser::GetAddNewUserObject(UserName);
		_AddNewUser(NewUser);

		ClsUser::enSaveResult SaveResult;

		SaveResult = NewUser.Save();

		switch (SaveResult)
		{
		case ClsUser::saveSucceeded:
		{
			cout << "\n Save Succeeded :)\n";
			_Print(NewUser);
			break;
		}
		case ClsUser::SaveFaildUserNameEmpty:
		{
			cout << "\n Faild Save Because Your Object is Empty !\n";
			break;
		}
		case ClsUser::SaveFaildUserNameExist:
		{
			cout << "\nFaild Save Because This User Name Already Exist !\n";
		}
	   }
	}
};

