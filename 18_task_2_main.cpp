#include "18_task_2_cpmv.h"

int main()
{
	Cpmv cpmv_1, cpmv_2("qcode 2", "zcode 2"), cpmv_3(cpmv_2), cpmv_4(cpmv_2 + cpmv_3), cpmv_5;
	
	cout << "Objects after declaration:\n";
	cpmv_1.Display();
	cpmv_2.Display();
	cpmv_3.Display();
	cpmv_4.Display();
	cpmv_5.Display();

	cpmv_1 = cpmv_2;
	cpmv_5 = cpmv_2 + cpmv_4;

	cout << "Objects after adding:\n";
	cpmv_1.Display();
	cpmv_5.Display();

	cin.get();
	cin.get();
	return 0;
}