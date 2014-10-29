#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void wrong_input();

int main()
{

	double kilometers, liters;
	
	cout << "Enter range in kilometers: ";
	while (!(cin >> kilometers) && cin.fail())
	{
		wrong_input();		
	}

	cout << "Enter petrol in liters: ";
	while (!(cin >> liters) && cin.fail())
	{
		wrong_input();		
	}

	cout << "Liters per 100 kilometers is " << (100.0 * liters) / kilometers << endl;

	cin.get();
	cin.get();
	return 0;
}

void wrong_input()
{
	std::cout << "Wrong input. Please try again\n";
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');		
}