#pragma once
#include <iostream>
#include <string>
using namespace std;

class ClientInterface
{
protected:
	string client_name;
	int account_number;
	string digital_Signature;
	float balance;
	int identificationNumber;
public:
	static int id;

	virtual void openAccount(const string &name, int account_number, const string &digital_Signature) = 0;
	virtual void withdrawCash(float cash) = 0;
	virtual void depositCash(float cash) = 0;
	virtual void seeAccountDetails() = 0;

	virtual string GetName() = 0;
	virtual int GetAccountNumber() = 0;
	virtual int GetIdentificationNumber() = 0;
	virtual string GetDigitalSignature() = 0;

	virtual void setName(const string &name) = 0;
	virtual void setDigitalSignature(const string &digital_Sign) = 0;
	virtual void setAccountNumber(int number) = 0;

	virtual ~ClientInterface()
	{
		cout << "\n~ClientInterface()";
	}
};


