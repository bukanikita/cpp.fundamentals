#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{
	const int months_in_year = 12;
	int years, months;
	std::cout << "Please, your age in years\n";
	while (!(std::cin >> years) && std::cin.fail())
	{
		std::cout << "Wrong inpuit. Please try again\n";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');		
	}
	months = months_in_year * years;
	std::cout << "Your age in months is " << months << endl;
	std::cin.get();
	std::cin.get();
	return 0;
}