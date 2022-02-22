#include "Client.h"

bool findByID(Client *client, int size, int ID);
Client& findByDigitalSignature(Client *client, int size, string digitalSignature);
void withdrawCash(Client *c, int size, string digitalSignature, float cash);
void depositCash(Client *c, int size, const string &digitalSignature, float cash);
void deleteAccount(Client *c, const string &digitalSignature);
void transferMoney(Client &c,  Client &d, float cash);
void informCustomers(Client c);
