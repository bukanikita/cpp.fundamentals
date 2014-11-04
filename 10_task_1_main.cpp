#include "10_task_1_account.h"

int main() 
{
	Account ac_1, ac_2 ("Name 1", "1111", 13.0);

	ac_1.show();
	ac_2.show();

	ac_2.add_bal(29.0);
	ac_2.show();
	ac_2.get_money(100.0);
	ac_2.get_money(10.0);
	ac_2.show();

	cin.get();
	cin.get();

	return 0;
}