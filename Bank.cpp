#include <iostream>
#include<string>
using namespace std;
int i = 0;
struct account
 {
	int num;
	string name;
	char type;
	int amount;
};
void ShowAcc(int s, account acc [])
{
	cout << "Account no. :" << acc[s].num << endl;
	cout << " Account Name holder " << acc[s].name << endl;
	cout << " type of account " << acc[s].type<<endl;
	cout << "Initial amount " << acc[s].amount <<endl;
}
void newAcc(account a[100], int &i)
{
	system("cls");
	cout << endl << endl << "Enter account number please : ";
	cin >> a[i].num;
	cout << endl << endl << "Enter the name of the account holder : ";
	getline(cin, a[i].name);
	getline(cin, a[i].name);
	cout << endl << endl << "Enter the type of account (C/S) : ";
	cin >> a[i].type;
	if (a[i].type != 'c'&&a[i].type != 's')
	{
		cout << "WRONG CHOICE ! PLEASE CHOICE BETWEEN (C/S) " << endl;
		cin >> a[i].type;
	}
	cout << endl << endl << "Enter the initial amount : ";
	cin >> a[i].amount;
	cout << endl << endl << "Account created  " << endl;
	i++;
	system("pause ");

}
int findAcc(account acc[], int j)
{

	for (int i = 0; i < 100; i++)
	{
		if (acc[i].num == j)
		{
			return i;
			break;
		}
	}return -1;
}
void deposit(account acc [])
{
	system("cls");
	int number;
	int moreAmount;
	cout << "Enter the account number " << endl;
	cin >> number;
	cout << endl << endl;
	int c = findAcc(acc, number);
	ShowAcc(c, acc);
	cout << "                                 TO DEPOSIT ACCOUNT : ENTER THE AMOUNT TO DEPOSIT                        " << endl;
	cin >> moreAmount;
	acc[c].amount += moreAmount;
	cout << "                               RECORD UPDATED                    " << endl;
	cout << acc[c].amount << endl;
	system("pause");

}
void WithDraw(account acc[])
{
	system("cls");
	int cash;
	int no;
	cout << "Enter the account number " << endl;
	cin >> no;
	cout << endl << endl;
	int q = findAcc(acc, no);
	ShowAcc(q, acc);
	cout << "                                         TO WITH DRAW AMOUNT : Enter the amount                                    " << endl;
	cin >> cash;
	acc[q].amount -= cash;
	cout << "                                         Record Updated                               " << endl;
	cout << acc[q].amount << endl;
	system("pause");
}
void Balance(account acc[])
{
	system("cls");
	cout << " Enter the account number " << endl;
	int w;
	cin >> w;
	int r = findAcc(acc,w);
	ShowAcc(r, acc);
	system("pause");

}
void list(account acc[], int g)
{
	system("cls");
	cout << " Account number.                              name               type                          balance  " << endl;
	for (int t = 0; t < g; t++)
	{
		cout << " --------------------------------------------------------------------------------------------------- " << endl;
		cout << acc[t].num << "                            " << acc[t].name << "    " << acc[t].type << "  " << acc[t].amount << endl;
	}
	system("pause");
}
void Modify(account acc[],int&i)
{
	system("cls");
	int f;
	cout << "Enter the account number : " << endl;
	cin >> f;
	cout << endl << endl;
	int o = findAcc(acc, f);
	ShowAcc(o, acc);
	cout << endl << endl;
	cout << "Modify Your account " << endl;
	cout << " -------------------------------------------------     " << endl;
	cout << "Account no. :"  << endl;
	cin >> acc[i].num;
	cout << " Account Name holder "  << endl;
	getline(cin, acc[i].name);
	getline(cin, acc[i].name);
	cout << " type of account "  << endl;
	cin >> acc[i].type;
	cout << "Initial amount " << endl;
	cin >> acc[i].amount;
	cout << "                                        Record Updated                          " << endl;
	system("pause");

}
void Exit()
{
	system("cls");
	cout << " Thank you for using Bank Managment System " << endl;
	system("pause");
}

void welcome(){
	system("cls");
	cout << "                           WELCOME TO BANK MANAGMENT SYSTEM                             " << endl;
	cout << " ---------------------------------------------------------------------------------------" << endl;
	system("pause");
}

int MainMenu()
{

	system("cls");
	int x;
	cout << "                     Main Menu                         " << endl;
	cout << " -------------------------------------------------     " << endl;
	cout << " 1- Create a New Account                               " << endl;
	cout << " -------------------------------------------------     " << endl;
	cout << " 2- Deposit Amount                                     " << endl;
	cout << " -------------------------------------------------     " << endl;
	cout << " 3- With Draw Amount                                   " << endl;
	cout << " -------------------------------------------------     " << endl;
	cout << " 4- Balance Enquiry                                    " << endl;
	cout << " -------------------------------------------------     " << endl;
	cout << " 5- All Account Holder List                            " << endl;
	cout << " -------------------------------------------------     " << endl;
	cout << " 6- Close An Account                                   " << endl;
	cout << " -------------------------------------------------     " << endl;
	cout << " 7- Modify An Account                                  " << endl;
	cout << " -------------------------------------------------     " << endl;
	cout << " 8- Exit                                               " << endl;
	cout << " -------------------------------------------------     " << endl;
	cout << " Select your Option from (1-8)                         " << endl;
	cin >> x;
	return x;
}


int main()
{
	account acc[100];
	welcome();
	do {
		int y = MainMenu();
		if (y == 1)
		{
			newAcc(acc,i);
		}

		if (y == 2)
		{
			deposit(acc);
		}

		if (y == 3)
		{
			WithDraw(acc);
		}
		if (y == 4)
		{
			Balance(acc);
		}

		if (y == 5)
		{
			list(acc, i);
		}

		if (y == 7)
		{
			Modify(acc, i);
		}
		if (y == 8)
		{
			Exit();
			break;
		}
	} while (true);

	system("pause");
}
