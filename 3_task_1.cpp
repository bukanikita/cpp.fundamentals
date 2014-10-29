#include <iostream>

typedef unsigned short un_short;

using std::cout;
using std::cin;
using std::endl;

int main()
{
	const un_short inches_in_feet = 12;
	un_short inches, feet;
	cout << "Enter height in inches: ___\b\b\b";
	while (!(cin >> inches) && cin.fail())
	{
		cout << "Wrong input. Please try again\n";
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');		
	}
	feet = inches / inches_in_feet;
	inches %= inches_in_feet;

	cout << "Your height is " << feet << " feet and " << inches << " inches\n";

	cin.get();
	cin.get();
	return 0;
}