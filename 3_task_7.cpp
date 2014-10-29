#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void wrong_input();

int main()
{
	const float miles_per_100_kilometers = 62.14f;
	const float liters_per_gallon = 3.875f;
	double liters_per_100_kilometers;
	
	cout << "Enter liters per 100 kilometers: ";
	while (!(cin >> liters_per_100_kilometers) && cin.fail())
	{
		wrong_input();		
	}

	cout << liters_per_100_kilometers << " liters per 100 kilometers is " << 
		miles_per_100_kilometers * liters_per_gallon / liters_per_100_kilometers << " miles per gallon" << endl;

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