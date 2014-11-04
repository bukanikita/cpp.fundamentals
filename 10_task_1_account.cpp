#include "10_task_1_account.h"

Account::Account (const string &_name, const string &_ac_number, double _bal) : 
	name(_name), ac_number(_ac_number), bal(_bal) 
{
}

void Account::show() const
{
	cout << "Name: " << name << endl
		 << "Account number: " << ac_number << endl
		 << "Balance: " << bal << endl;
}

void Account::get_money(double sum)
{
	if (sum <= bal)
	{
		bal -= sum;
	}
	else
	{
		cout << "Invalid operation. You haven't got enough money";
	}
}

Account::~Account()
{
}