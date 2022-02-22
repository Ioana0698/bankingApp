
#include "Client.h"
#include "functions.h"
int Client::id=0;
int size=10;

Client& findClient(Client *client, int sizet, int id)
{
	for(int i = 0; i < sizet; ++i)
	{
		if(client[i].GetIdentificationNumber() == id)
		{
			return client[i];
		}
	}
	return client[9];
}

void ClientsMenu()
{
	cout << "\nPlease select number.";
	cout << "\nMENU:";
	cout << "\n1.See the account details.";
	cout << "\n2.Deposit Cash.";
	cout << "\n3.WithdrawCash.";
}
void EmployeeMenu()
{
	cout << "\nPlease select number.";
	cout << "\nMENU:";
	cout << "\n1.Open a new account.";
	cout << "\n2.Search for a client based on ID.";
	cout << "\n3.Edit current Accounts.";
	cout << "\n4.WithdrawCash based on digital signature.";
	cout << "\n5.Deposit cash based on digital signature.";
	cout << "\n6.Transfer money into another account.";
	cout << "\n7.Inform customers about changes/announcements.";
}
int main()
{

	Client *clients = new Client[size];
	int  i= 0;
	clients[i].openAccount("Burbulea Ioana", 100, "ioana");
	clients[i].depositCash(300);
	i++;
	clients[i].openAccount("Popescu Ion", 101, "ion");
	i++;
	clients[i].openAccount("Tudose Georgiana", 102, "georgiana");
	i++;
	for(int j = 0; j < i ; ++j)
	{
		clients[j].seeAccountDetails();
	}
	int choice;
	int actionChoice;
	int restart = 0;
	float cash;
	int newClient;
	int identificationN;
	float amount;
	while(restart == 0)
	{
		cout << "Are you a client or an employee?"<<endl;
		cout << "Insert 1 for client or 2 for employee:";
		cin >> choice;
		//choice=1;
		while(choice != 1 && choice != 2){
			cout << endl << "Invalid number! Please insert again:";
			cin >> choice;
		}
		cin.sync();
		if(choice == 1)
		{
			cout << "\nAre you a new client or an existing one? Insert 1 if yes and 0 if not:";
			cin >> newClient;
			//newClient=0;
			if(newClient == 1)
			{
				///////////////////OPEN NEW ACCOUNT
				cin.sync();
				cout << endl << "Please insert your name:";
				string name;
				getline(cin,name);

				cout << "\nPlease insert an account number:";
				int accountNumber;
				cin >> accountNumber;

				cout << endl << "Please insert your digital signature:";
				cin.sync();
				string digitalSignature;
			    getline(cin, digitalSignature);

			    clients[i].openAccount(name, accountNumber, digitalSignature);
				i++;
			}
			else if(newClient == 0)
			{
				cout << "Please insert your ID:";
				cin >> identificationN;
				//identificationN=2;
				cin.sync();
				Client &c = findClient(clients, size, identificationN);
				cout << c.GetName();
				ClientsMenu();
				cin >> actionChoice;
			//////SEE ACCOUNT DETAILS
				if(actionChoice == 1)
				{
					c.seeAccountDetails();
				}
			////////////////DEPOSIT CASH
				else if(actionChoice == 2)
				{
					cout << "\nPlease insert the amount you want to deposit:";
					cin >> cash;
					c.depositCash(cash);
					c.seeAccountDetails();
				}

			////////////////////WITHDRAW CASH
				else if(actionChoice == 3)
				{
					cout << "\nPlease insert the amount you want to withdraw:";
					cin >> cash;
					c.withdrawCash(cash);
				}
			}
		}
		else if(choice == 2)
		{
			cout << endl << "You are an employee!\n";
			EmployeeMenu();
			cin >> actionChoice;
			////////OPEN NEW ACCOUNT
			if(actionChoice == 1)
			{
				cin.sync();
				cout << endl <<"Please insert your name:";
				string name;
				getline(cin, name);
				cout << "\nPlease insert an account number:";
				int accountNumber;
				cin >> accountNumber;
				cout << endl << "Please insert your digital signature:";
				cin.sync();
			    string digitalSignature;
				getline(cin, digitalSignature);
				clients[i].openAccount(name, accountNumber, digitalSignature);
				i++;
			}
			/////SEARCH FOR A CLIENT BASED ON ID
			else if(actionChoice == 2)
			{
				cout<<"Please insert the ID for the client you are looking for:";
				int ID;
				cin >> ID;
				bool found = findByID(clients, size, ID);

				if(found == true)
				{
					cout<<"\nClientul exista in baza noastra de date!";
				}
				else
				{
					cout<<"\nClientul nu exista in baza noastra de date!";
				}
			}
			////EDIT ACCOUNTS
			else if(actionChoice == 3)
			{

			}
			//WITHDRAW BASED ON DIGITAL SIGNATURE
			else if(actionChoice == 4)
			{
				cin.sync();
				cout << endl <<"Please insert your digital signature:";
				string digitalS;
				getline(cin, digitalS);
				cin.sync();
				cout << endl << "Please insert the amount you want to withdraw:";
				cin >> amount;
				withdrawCash(clients, size, digitalS, amount);
			}
			///DEPOSIT BASED ON DIGITAL SIGNATURE
			else if(actionChoice == 5)
			{
				cin.sync();
				cout << endl << "\nPlease insert your digital signature:";
				string digitalS;
				getline(cin, digitalS);
				cin.sync();
				cout << endl << "\nPlease insert the amount you want to deposit:";
				cin >> amount;
				depositCash(clients, size, digitalS, amount);
			}
			////TRANSFER MONEY
			else if(actionChoice == 6)
			{

				transferMoney(clients[0], clients[1], 100);
			}
			else
			{
				cout <<"\nInvalid number! Please try again.";
			}
		}
		cout << "\nDo you want to see again the menu?\n Insert 0 for yes and 1 if you want to quit:";
		cin >> restart;
	}
	for(int j = 0; j < i; ++j)
	{
		clients[j].seeAccountDetails();
	}

	return 0;
}
