#include "functions.h"


Client& findByDigitalSignature(Client *client, int size, string digitalSignature)
{
	for(int i = 0; i < size; ++i)
		{
			if(client[i].GetDigitalSignature() == digitalSignature)
			{
				return client[i];
			}
		}
	return client[0];
}
bool findByID(Client *client, int size, int ID)
{
	bool found = false;
	for(int i = 0; i < size; ++i)
			{
				if(client[i].GetIdentificationNumber() == ID && client[i].GetName() != "")
				{
					return found=true;
				}
			}
	return found;
}
void withdrawCash(Client *c, int size, string digitalSignature, float cash)
{
	Client &client = findByDigitalSignature(c, size, digitalSignature);
	client.withdrawCash(cash);
}
void depositCash(Client *c, int size, const string &digitalSignature, float cash)
{
	Client &client = findByDigitalSignature(c, size, digitalSignature);
	client.depositCash(cash);
}

void transferMoney(Client &c, Client &d, float cash)
{
	c.withdrawCash(cash);
	d.depositCash(cash);
}
