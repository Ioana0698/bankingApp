#pragma once
#include "ClientInterface.h"

class Client : public ClientInterface
{

public:
	static int id;
	/////////////////////////////////////////////////////////////////////
	Client()
	{
		cout << endl << "Client";
		this->client_name = "";
		this->account_number = 0;
		this->digital_Signature = "";
		this->balance = 0.0;
		this->identificationNumber = id++;
	}
	Client(const string &client_name, int account_number, const string &digital_Signature)
	{
		cout << endl << "Client";
		this->client_name = client_name;
		this->account_number = account_number;
		this->digital_Signature = digital_Signature;
		this->identificationNumber = id++;
		this->balance = 0.0;
		cout << "\nWelcome to our bank, "<< client_name << "!" << endl;
	}
	Client(const Client &c)
	{
		client_name = c.client_name;
		account_number = c.account_number;
		digital_Signature = c.digital_Signature;
		balance = c.balance;
		identificationNumber = c.identificationNumber;

	}
	////////////////////////////////////////////////////////////////////
	string GetName()
	{
		return client_name;
	}
	int GetAccountNumber()
	{
		return account_number;
	}
	int GetIdentificationNumber()
	{
		return identificationNumber;
	}
	string GetDigitalSignature()
	{
		return digital_Signature;
	}
	//////////////////////////////////////////////////////////////
	void setName(const string &name)
	{
		client_name = name;
	}
	void setDigitalSignature(const string &digital_Sign)
	{
		digital_Signature = digital_Sign;
	}
	void setAccountNumber(int number)
	{
		account_number = number;
	}
	///////////////////////////////////////////////////
	void openAccount(const string &name, int account_number, const string &digital_Signature)
	{

		this->account_number = account_number;
		this->client_name = name;
		this->digital_Signature = digital_Signature;
	}
	void withdrawCash(float cash)
	{

		if(cash < this->balance && this->balance > 0)
		{
			this->balance -= cash;
		}
		else
		{
			cout << "\nInsufficient balance!\n";
		}
	}
	void depositCash(float cash)
	{
		this->balance += cash;
	}

	void seeAccountDetails()
	{
		cout << "\n\nID:" << this->identificationNumber << endl << "Name:" <<
				this->client_name << endl << "Account number:" << this->account_number << endl <<
				"Digital Signature:" << this->digital_Signature << endl << "Balance:" << this->balance << endl;
	}
	///////////////////////////////////////////////////////////////
	virtual ~Client()
	{
		cout<<"\n~Client";
	}
};


