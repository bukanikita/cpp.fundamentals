#ifndef _10_TASK_1_ACCOUNT_H_
#define _10_TASK_1_ACCOUNT_H_

#include "10_task_1_includes.h"

class Account
{
private:
	string name;
	string ac_number;
	double bal;
public:
	Account(const string &_name = "No name", const string &_ac_number = "0000", double _bal = 0.0);
	void show() const;
	void add_bal(double sum) { bal += sum; };
	void get_money(double sum);
	~Account();
};

#endif
