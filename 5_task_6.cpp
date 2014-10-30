#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

void wrong_input();

int main()
{
	const short number_of_months = 12, number_of_years = 3;
	string months [number_of_months] = {
		"January", "February", "March",
		"April", "May", "June",
		"July", "August", "September",
		"October", "November", "December"};
	int sales[number_of_years][number_of_months], total_sales[number_of_years] = {0}, total_for_all_years = 0;
	int i, j;

	for (i = 0; i < number_of_years; ++i)
	{
		for (j = 0; j < number_of_months; ++j)
		{
			cout << "Please, enters sales for the " << i+1 << " year and for " << months[j] << " month: ";
			while (!(cin >> sales[i][j]) && cin.fail())
			{
				wrong_input();		
			}
			total_sales[i] += sales[i][j];
		}
		total_for_all_years += total_sales[i];
	}

	for (i = 0; i < number_of_years; ++i)
	{
		cout << "Sales for " << i+1 << "year: " << total_sales[i] << endl;
	}

	cout << "Total sales for all years: " << total_for_all_years << endl;

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
