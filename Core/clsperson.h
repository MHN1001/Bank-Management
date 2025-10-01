#pragma once

#include <iostream>
using namespace std;



class clsPerson
{

private:

	string _firstName, _LastName, _email, _Phone;

public:

	clsPerson( string FirstName, string LastName, string Email, string Phone)
	{
		_firstName = FirstName;
		_LastName = LastName;
		_email = Email;
		_Phone = Phone;
	}




	void SetFirstName(string FirstName)
	{
		_firstName = FirstName;
	}
	string GetFirstName()
	{
		return _firstName;
	}
	__declspec(property(get = GetFirstName, put = SetFirstName)) string FirstName;

	void SetLastName(string LastName)
	{
		_LastName = LastName;
	}
	string GetLastName()
	{
		return _LastName;
	}
	__declspec(property(get = GetLastName, put = SetLastName)) string LastName;


	void SetEmail(string email)
	{
		_email = email;
	}
	string GetEmail()
	{
		return _email;
	}
	__declspec(property(get = GetEmail, put = SetEmail)) string Email;


	void SetPhone(string Phone)
	{
		_Phone = Phone;
	}
	string Getphone()
	{
		return _Phone;
	}
	__declspec(property(get = Getphone, put = SetPhone)) string Phone;


	string FullName()
	{
		return _firstName + " " + _LastName;
	}

	void Print()
	{
		cout << "Info : \n";
		cout << "-------------------------";
		cout << "\nFirst Name : " << _firstName;
		cout << "\nLast Name  : " << _LastName;
		cout << "\nFull Name : " << FullName();
		cout << "\nEmail : " << _email;
		cout << "\nPhone : " << _Phone;
		cout << "\n-------------------------\n";
	}

	void SendEmail(string Subject, string body)
	{
		cout << "\nThe following message sent successfully to email : " << _email;
		cout << "\nSubject : " << Subject;
		cout << "\nBody : " << body;
	}

	void SendSMS(string SMS)
	{
		cout << "\n\nThe following SMS sent successfully to Phone : " << _Phone;
		cout << "\nSMS : " << SMS;
	}


};