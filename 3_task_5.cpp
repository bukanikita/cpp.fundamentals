#include <iostream>

typedef unsigned long long un_llong;

using std::cout;
using std::cin;
using std::endl;

void wrong_input();

int main()
{

	un_llong people_in_world, people_in_country;
	
	cout << "Enter the world's population: ";
	while (!(cin >> people_in_world) && cin.fail())
	{
		wrong_input();		
	}

	cout << "Enter the population of the US: ";
	while (!(cin >> people_in_country) && cin.fail())
	{
		wrong_input();		
	}

	cout << "The population of the US is " << 100 * (double(people_in_country) / people_in_world) << "% of the world population.";

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