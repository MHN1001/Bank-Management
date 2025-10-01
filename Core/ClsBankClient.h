#pragma once

#include <iostream>
#include <string>
#include "clsperson.h";
#include "clsString.h";
#include <vector>
#include <fstream>
#include "ClsUser.h";

using namespace std;


class ClsBankClient : public clsPerson
{
private:


	enum enMode { EmptyMode = 0, UpdateMode = 1 , AddNewMode=2};
	enMode _Mode;

	string _AccountNumber;
	string _PinCode;
	double _AccountBalance;
	bool _MarkAsDeleted = false;


	static ClsBankClient _convertLineToClientObject(string Line, string Delim = "#//#")
	{
		vector <string> Vvector = clsString::Split(Line, Delim);

		return ClsBankClient(ClsBankClient::UpdateMode, Vvector[0], Vvector[1], Vvector[2], Vvector[3]
			, Vvector[4], Vvector[5], stod(Vvector[6]));
	}

	static ClsBankClient _GetEmptyClientObject()
	{
		return ClsBankClient(ClsBankClient::EmptyMode, "", "", "", "", "", "", 0);
	}
	
    static vector <ClsBankClient> _LoadClientDateFromFile()
	{
		vector <ClsBankClient> Vclient;

		fstream ClientFile;

		ClientFile.open("Clients.txt", ios::in);

		if (ClientFile.is_open())
		{
			string Line;

			while (getline(ClientFile, Line))
			{
				ClsBankClient Client = _convertLineToClientObject(Line);

				Vclient.push_back(Client);
			}
		}
		return Vclient;
	}

	string _ConvertClientObjectToLine(ClsBankClient VClient, string Delim = "#//#")
	{
		string str = "";

		str += VClient.FirstName + Delim;
		str += VClient.LastName + Delim;
		str += VClient.Email + Delim;
		str += VClient.Phone + Delim;
		str += VClient.GetAccountNumber() + Delim;
		str += VClient.PinCode + Delim;
		str += to_string(VClient.AccountBalance);

		return str;
	}

	void _SaveClientDateToFile(vector <ClsBankClient> Vclient)
	{
		fstream ClientFile;

		ClientFile.open("Clients.txt", ios::out);

		if (ClientFile.is_open())
		{
			string ClientDateLine;

			for (ClsBankClient& C : Vclient)
			{
				if (C._MarkAsDeleted == false)
				{

				ClientDateLine = _ConvertClientObjectToLine(C);

				ClientFile << ClientDateLine << endl;
				
				}
			}
		}
			ClientFile.close();
	}

    void _Update()
	{ 
		vector <ClsBankClient> Vclient = _LoadClientDateFromFile();

		for (ClsBankClient& C : Vclient)
		{
			if (C.GetAccountNumber() == GetAccountNumber())
			{
				C = *this;
				break;
			}
		}

		_SaveClientDateToFile(Vclient);
    }

	void _AddDataLineToFile(string DateLine)
	{
		fstream ClientFile;

		ClientFile.open("Clients.txt", ios::app);

		if (ClientFile.is_open())
		{
		 	ClientFile << DateLine << endl;
		}

		ClientFile.close();
	}

	void _AddNew()
	{
		_AddDataLineToFile(_ConvertClientObjectToLine(*this));
	}

	string _prepareTransferLogRecord(float  Amount, ClsBankClient DestinationClient, string UserName, string DElimiter="#//#")
	{
		string TransferDataLine = "";

		TransferDataLine += clsdate::GetSystemDateTimeString() + DElimiter;
		TransferDataLine += GetAccountNumber() + DElimiter;
		TransferDataLine += DestinationClient.GetAccountNumber() + DElimiter;
		TransferDataLine += to_string(Amount) + DElimiter;
		TransferDataLine += to_string(GetAccountBalance()) + DElimiter;
		TransferDataLine += to_string(DestinationClient.GetAccountBalance()) + DElimiter;
		TransferDataLine += UserName;

		return TransferDataLine;
		
	}

     void _SaveTransferLog(float Amount ,ClsBankClient DestinationClient, string UserName)
	 {

		string TransferDataLine = _prepareTransferLogRecord(Amount, DestinationClient, UserName);

		fstream TransferLogFile;

		TransferLogFile.open("TransferLog.txt", ios::out | ios::app);

		if (TransferLogFile.is_open())
		{
			TransferLogFile << TransferDataLine << endl;
		}
		TransferLogFile.close();
	}
	 
	 //Structure declaration
	 struct stRegisterLog;

	 static stRegisterLog _ConvertLineToREgisterLogRecord(string Line, string Delimiter = "#//#")
	 {
		 vector <string> VregisterLogRecord = clsString::Split(Line, Delimiter);

		 stRegisterLog StRLRecord;

		 StRLRecord.DateAndTime = VregisterLogRecord[0];
		 StRLRecord.SourceAccountNumber = VregisterLogRecord[1];
		 StRLRecord.DestinationAccountNumber = VregisterLogRecord[2];
		 StRLRecord.Amount = stof(VregisterLogRecord[3]);
		 StRLRecord.SourceAccountBalnace = stof(VregisterLogRecord[4]);
		 StRLRecord.DestinationAccountBalnace = stof(VregisterLogRecord[5]);
		 StRLRecord.UserName = VregisterLogRecord[6];

		 return StRLRecord;
 	 }

	 static vector <ClsBankClient::stRegisterLog>  LoadREgisterLogDataFromFile()
	 {
		 vector <ClsBankClient::stRegisterLog> vRLData;

		 fstream RegisterLogFile;

		 RegisterLogFile.open("TransferLog.txt", ios::in);

		 if (RegisterLogFile.is_open())
		 {
			 string Line;
			 stRegisterLog stRLRecord;

			 while (getline(RegisterLogFile, Line))
			 {
				 stRLRecord = _ConvertLineToREgisterLogRecord(Line);
				 vRLData.push_back(stRLRecord);
			 }
			 RegisterLogFile.close();
		 }

		 return vRLData;
	 }

public:

	ClsBankClient(enMode Mode, string FirstName, string LastName, string Email, string Phone,
		string AccountNumber, string PinCode, double AccountBalance) :
		clsPerson(FirstName, LastName, Email, Phone)
	{
		_Mode = Mode;
		_AccountNumber = AccountNumber;
		_PinCode = PinCode;
		_AccountBalance = AccountBalance;
	}

	bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	}


	string GetAccountNumber()
	{
		return _AccountNumber;
	}


	void SetPinCode(string PinCode)
	{
		_PinCode = PinCode;
	}
	string GetPinCode()
	{
		return _PinCode;
	}
	__declspec(property(get = GetPinCode, put = SetPinCode)) string PinCode;


	void SetAccountBalance(float AccountBlance)
	{
		_AccountBalance = AccountBlance;
	}
	float GetAccountBalance()
	{
		return _AccountBalance;
	}
	__declspec(property(get = GetAccountBalance, put = SetAccountBalance)) float AccountBalance;


	static ClsBankClient Find(string AccountNumber)
	{
		vector <ClsBankClient> Cvector;

		fstream MyFile;

		MyFile.open("Clients.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;

			while (getline(MyFile, Line))
			{
				ClsBankClient Client = _convertLineToClientObject(Line, "#//#");

				if (Client.GetAccountNumber() == AccountNumber)
				{
					MyFile.close();

					return Client;
				}

				Cvector.push_back(Client);
			}

			MyFile.close();
		}
		return _GetEmptyClientObject();
	}

	static ClsBankClient Find(string AccountNumber, string pincode)
	{
		vector <ClsBankClient> Cvector;

		fstream MyFile;

		MyFile.open("Clients.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;

			while (getline(MyFile, Line))
			{
				ClsBankClient Client = _convertLineToClientObject(Line, "#//#");

				if (Client.GetAccountNumber() == AccountNumber && Client.PinCode == pincode)
				{
					MyFile.close();

					return Client;
				}

				Cvector.push_back(Client);
			}

			MyFile.close();
		}
		return _GetEmptyClientObject();
	}

	static bool IfClientExist(string AccountNumber)
	{
		ClsBankClient Client = ClsBankClient::Find(AccountNumber);

		return (!(Client.IsEmpty()));
	}

	static  ClsBankClient GetAddNewClientObject(string AccountNumber)
	{
		return ClsBankClient(ClsBankClient::AddNewMode, "", "", "", "", AccountNumber, "", 0);
	}
	
	static vector <ClsBankClient> GetClientList()
	{
		return _LoadClientDateFromFile();
	}

	static double GetTotallBalances()
	{
		vector <ClsBankClient> Vvector = _LoadClientDateFromFile();

		double TotalBalalances = 0;

		for (ClsBankClient& C : Vvector)
		{
			TotalBalalances += C.AccountBalance;
		}

		return TotalBalalances;
	}
	
	bool Delete()
	{
		vector <ClsBankClient> Vvector = _LoadClientDateFromFile();

		for (ClsBankClient& C : Vvector)
		{
			if (C.GetAccountNumber() == GetAccountNumber())
			{
				C._MarkAsDeleted = true;
				break;
			}
		}

		_SaveClientDateToFile(Vvector);

		*this = _GetEmptyClientObject();

		return true;
	}

	void Diposite(double Amount)
	{
		_AccountBalance += Amount;

		Save();
	}

	bool Withdraw(double Amount)
	{
		if (Amount > _AccountBalance)
		{
			return false;
	    }
		else
		{
			_AccountBalance -= Amount;

			Save();

			return true;
		}
	}

	enum enSaveResult {SaveFaildAccountNumberEmpty=0 , saveSucceeded=1, 
		               SaveFaildAccountNumberExist=2, };

	enSaveResult Save()
	{
		switch (_Mode)
		{
		case enMode::EmptyMode:
		{
			return enSaveResult::SaveFaildAccountNumberEmpty;
		}
		case enMode::UpdateMode:
		{
			_Update();

			return enSaveResult::saveSucceeded;
		}
		case enMode::AddNewMode:
		{
			if (ClsBankClient::IfClientExist(_AccountNumber))
			{
				return enSaveResult::SaveFaildAccountNumberExist;
			}
			else
			{
				_AddNew();

				_Mode = enMode::UpdateMode;

				return enSaveResult::saveSucceeded;
			}
		}
		}
	}

	bool Transfer(double Amount, ClsBankClient &DestinationClient, string UserName)
	{
		if (Amount > _AccountBalance)
		{
			return false;
		}
		else
		{
			Withdraw(Amount);
			DestinationClient.Diposite(Amount);
			_SaveTransferLog(Amount, DestinationClient, UserName);
			return true;
		}
	}

	struct stRegisterLog
	{
		string DateAndTime;
		string SourceAccountNumber;
		string DestinationAccountNumber;
		float  Amount;
		float SourceAccountBalnace;
		float DestinationAccountBalnace;
		string UserName;
	};

	static vector <stRegisterLog> GeTransferLogList()
	{
		return LoadREgisterLogDataFromFile();
	}
};
