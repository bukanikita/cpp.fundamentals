#include "9_task_4_sales.h"

using namespace SALES; 

int main() 
{
	Sales sale_1, sale_2;
	double sales_ar[] = {2.0, 32.2, 1.2, 3.0};

	cout << "Please, enter info about sales:\n";
	setSales(sale_1);

	setSales(sale_2, sales_ar, 4);

	showSales(sale_1);
	showSales(sale_2);

	cin.get();
	cin.get();

	return 0;
}