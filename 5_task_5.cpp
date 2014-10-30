#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

void wrong_input();

int main()
{
	const short number_of_months = 12;
	string months [number_of_months] = {
		"January", "February", "March",
		"April", "May", "June",
		"July", "August", "September",
		"October", "November", "December"};
	int sales[number_of_months], total_sales = 0;
	int i;

	for (i = 0; i < number_of_months; ++i)
	{
		cout << "Please, enters sales for " << months[i] << " month: ";
		while (!(cin >> sales[i]) && cin.fail())
		{
			wrong_input();		
		}
	}

	for (auto sale_for_month : sales)
	{
		total_sales += sale_for_month;
	}

	cout << "All sales for year: " << total_sales << endl;

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
