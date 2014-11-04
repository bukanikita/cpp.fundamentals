#include "10_task_4_sales.h"

using namespace SALES;

int main() 
{
	cout << "Please, enter info about sales:\n";
	Sales sale_1;
	double sales_ar[] = {2.0, 32.2, 1.2, 3.0};

	Sales sale_2(sales_ar, 4);

	sale_1.ShowSales();
	sale_2.ShowSales();

	cin.get();
	cin.get();

	return 0;
}

void wrong_input()
{
	cout << "Wrong input. Please try again\n";
	cin.clear();
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');		
}