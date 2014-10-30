#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void wrong_input();

int main()
{
	int start, end, sum = 0;
	int i;
	
	cout << "Please, enter the start number: ";
	while (!(cin >> start) && cin.fail())
	{
		wrong_input();		
	}

	cout << "Please, enter the end number: ";
	while (!(cin >> end) && cin.fail())
	{
		wrong_input();		
	}

	for (i = start; i <= end; ++i)
	{
		sum += i;
	}

	cout << "Sum of all numbers from " << start << " to " << end << " is equal to " << sum <<endl;
	
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
