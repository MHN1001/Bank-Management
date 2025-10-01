#pragma once
#include <iostream>
#include "clsperson.h";
#include "clsString.h";
#include <string>
#include <vector>
#include <fstream>
#include "ClsUtility.h"

using namespace std;


class ClsUser : public clsPerson
{

private:

	enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2 };
	enMode _Mode;
	string _UserName;
	string _passWord;
	int _Permession;

	bool _MarkAsDeleted = false;

	static vector <ClsUser> _LoadUserDataFromFile()
	{
		vector <ClsUser> VUser;

		fstream UserFile;

		UserFile.open("Users.txt", ios::in);

		if (UserFile.is_open())
		{
			string Line;

			while (getline(UserFile, Line))
			{
				ClsUser User = _convertLineToUserObject(Line);

				VUser.push_back(User);
			}
			UserFile.close();
		}
		return VUser;
	}


	//here i decryption the password
	static ClsUser _convertLineToUserObject(string Line, string Delimiter = "#//#")
	{
		vector <string> Vuser = clsString::Split(Line, Delimiter);

		return ClsUser(ClsUser::UpdateMode, Vuser[0], Vuser[1], Vuser[2], Vuser[3], Vuser[4],
		                                  ClsUtility::DecryptionTEXT(Vuser[5]), stoi(Vuser[6]));
	}


	//here i encryption the password
	string _ConvertUserObjectToLine(ClsUser User, string Delim = "#//#")
	{
		string str = "";

		str += User.FirstName + Delim;
		str += User.LastName + Delim;
		str += User.Email + Delim;
		str += User.Phone + Delim;
		str += User.GetUsername() + Delim;
		str += ClsUtility::EncryptionTEXT(User.GetPassword()) + Delim;
		str += to_string(User.GetPermession());

		return str;
	}

	void _SaveUserDataToFile(vector <ClsUser> Vuser)
	{
		fstream UserFile;

		UserFile.open("Users.txt", ios::out);

		if (UserFile.is_open())
		{
			string UserDataLine;

			for (ClsUser& C : Vuser)
			{
				if (C._MarkAsDeleted == false)
				{

					UserDataLine = _ConvertUserObjectToLine(C);

					UserFile << UserDataLine << endl;

				}
			}
		}
		UserFile.close();
	}

	void _Update()
	{
		vector <ClsUser> Vuser = _LoadUserDataFromFile();

		for (ClsUser& C : Vuser)
		{
			if (C.GetUsername() == GetUsername())
			{
				C = *this;
			}
		}
		_SaveUserDataToFile(Vuser);
	}

	void _AddUserDataLineToFile(string UserDataLine)
	{
		fstream UserFile;

		UserFile.open("Users.txt", ios::app);

		if (UserFile.is_open())
		{
			UserFile << UserDataLine << endl;
		}

		UserFile.close();
	}

	void _Add()
	{
		_AddUserDataLineToFile(_ConvertUserObjectToLine(*this));
	}

	//here i encryption the password
	string _PrepareLogInRecord(string Delimiter = "#//#")
	{
		string RegisterDataLine = "";

		RegisterDataLine += clsdate::GetSystemDateTimeString() + Delimiter;
		RegisterDataLine += _UserName + Delimiter;
		RegisterDataLine += ClsUtility::EncryptionTEXT(GetPassword()) + Delimiter;
		RegisterDataLine += to_string(_Permession);

		return RegisterDataLine;
	}

	//structure Declaration
	struct stLoginRegisterRecord;


	//here i Decryption the password
	static stLoginRegisterRecord _ConvertLineToLoginRegisterRecord(string Line, string Delim = "#//#")
	{
		stLoginRegisterRecord LRrecord;

		vector <string> vLRrecord = clsString::Split(Line, Delim);

		LRrecord.DateAndTime = vLRrecord[0];
		LRrecord.UserName = vLRrecord[1];
		LRrecord.Password = ClsUtility::DecryptionTEXT(vLRrecord[2]);
		LRrecord.Permession = stoi(vLRrecord[3]);

		return LRrecord;
	}

public : 

	ClsUser(enMode Mode, string FirstName, string LastName, string Email
		   , string phone, string UserName, string PassWord, int Permession)
		   : clsPerson(FirstName, LastName, Email, phone)
	{
		_Mode = Mode;
		_UserName = UserName;
		_passWord = PassWord;
		_Permession = Permession;
	}

	struct stLoginRegisterRecord
	{
		string DateAndTime, UserName, Password;
		short Permession;
	};

	enum enPermession
	{
		eAll = -1, pListClient = 1, pAddClient = 2, pDeleteClient = 4,
		pUpdateCleint = 8, pFindClient = 16, pTransaction = 32,
		pManageUsers = 64 , pLoginRegister = 128
	};

	void SetUserName(string Username)
	{
		_UserName = Username;
	}
	string GetUsername()
	{
		return _UserName;
	}
	__declspec(property(get = GetUsername, put = SetUserName)) string UserName;

	void SetPassword(string Password)
	{
		_passWord = Password;
	}
	string GetPassword()
	{
		return _passWord;
	}
	__declspec(property(get = GetPassword, put = SetPassword)) string Password;

	void SetPermession(int Permession)
	{
		_Permession = Permession;
	}
	int GetPermession()
	{
		return _Permession;
	}
	__declspec(property(get = GetPermession, put = SetPermession)) int Permession;

	bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	}

	bool MarkedForDeleted()
	{
		return _MarkAsDeleted;
	}

	static ClsUser _GetEmptyUserObject()
	{
		return ClsUser(ClsUser::EmptyMode, "", "", "", "", "", "", 0);
	}

	static ClsUser Find(string UserName)
	{
		vector <ClsUser> Cvector;

		fstream UserFile;

		UserFile.open("Users.txt", ios::in);

		if (UserFile.is_open())
		{
			string Line;

			while (getline(UserFile, Line))
			{
				ClsUser User = _convertLineToUserObject(Line, "#//#");

				if (User.UserName == UserName)
				{
					UserFile.close();

					return User;
				}

				Cvector.push_back(User);
			}

			UserFile.close();
		}
		return _GetEmptyUserObject();
	}
	static ClsUser Find(string UserName, string Password)
	{
		vector <ClsUser> Cvector;

		fstream UserFile;

		UserFile.open("Users.txt", ios::in);

		if (UserFile.is_open())
		{
			string Line;

			while (getline(UserFile, Line))
			{
				ClsUser User = _convertLineToUserObject(Line, "#//#");

				if (User.UserName == UserName && User.Password == Password)
				{
					UserFile.close();

					return User;
				}

				Cvector.push_back(User);
			}

			UserFile.close();
		}
		return _GetEmptyUserObject();
	}

	static bool IfUserExist(string UserName)
	{
		ClsUser User = ClsUser::Find(UserName);

		return(!User.IsEmpty());
	}

	enum enSaveResult {
		SaveFaildUserNameEmpty = 0, saveSucceeded = 1,
		SaveFaildUserNameExist = 2,
	};

	enSaveResult Save()
	{
		switch (_Mode)
		{
		case enMode::EmptyMode:
		{
			return enSaveResult::SaveFaildUserNameEmpty;
		}
		case enMode::UpdateMode:
		{
			_Update();

			return enSaveResult::saveSucceeded;
		}
		case enMode::AddNewMode:
		{
			if (ClsUser::IfUserExist(_UserName))
			{
				return enSaveResult::SaveFaildUserNameExist;
			}
			else
			{
				_Add();

				_Mode = enMode::UpdateMode;

				return enSaveResult::saveSucceeded;
			}
		}
		}
	}

	static  ClsUser GetAddNewUserObject(string username)
	{
		return ClsUser(ClsUser::AddNewMode, "", "", "", "", username, "", 0);
	}

	static vector <ClsUser> GetUserList()
	{
		return _LoadUserDataFromFile();
	}

	bool Delete()
	{
		vector <ClsUser> Vvector = GetUserList();

		for (ClsUser& C : Vvector)
		{
			if (C.GetUsername() == GetUsername())
			{
				C._MarkAsDeleted = true;
				break;
			}
		}

		_SaveUserDataToFile(Vvector);

		*this = _GetEmptyUserObject();

		return true;
	}

	bool checkAccessPermession(enPermession Permession)
	{
		if (this->Permession == enPermession::eAll)
			return true;

		if ((Permession & this->Permession) == Permession)
			return true;
		else
			false;
	}

	void RegisterLogins()
	{
		string RegisterDataLine = _PrepareLogInRecord();

		fstream RegisterLoginFile;

		RegisterLoginFile.open("RegisterLogin.txt", ios::out | ios::app);

		if (RegisterLoginFile.is_open())
		{
	
			RegisterLoginFile << RegisterDataLine << endl;
		}

		RegisterLoginFile.close();
	}

	static vector <stLoginRegisterRecord> GetLoginRegisterList()
	{
		vector <stLoginRegisterRecord> vLoginRegister;

		fstream LoginRegisterFile;

		LoginRegisterFile.open("RegisterLogin.txt", ios::in);

		if (LoginRegisterFile.is_open())
		{
			string Line;
			stLoginRegisterRecord LoginRegisterRecord;

			while (getline(LoginRegisterFile, Line))
			{
				LoginRegisterRecord = _ConvertLineToLoginRegisterRecord(Line);

				vLoginRegister.push_back(LoginRegisterRecord);
			}

			LoginRegisterFile.close();
		}

		return vLoginRegister;
	}
};

