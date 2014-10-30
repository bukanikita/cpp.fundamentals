#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void wrong_input();

int main()
{
	double number, sum = 0;

	cout << "Please, enter numbers for getting their sum. 0 for exit.\n";

	do
	{
		cout << "Enter number: ";
		while (!(cin >> number) && cin.fail())
		{
			wrong_input();		
		}
		sum += number;
		cout << "Cumulative sum of the entries is: " << sum << endl;
	} while (number != 0);
	
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
