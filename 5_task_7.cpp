#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

struct car
{
	string name;
	int year;
};

void wrong_input();

int main()
{
	int number_of_cars;
	car *cars;
	int i;

	cout << "How many cars do you wish to catalog? ";
	while (!(cin >> number_of_cars) && cin.fail())
	{
		wrong_input();		
	}

	cars = new car [number_of_cars];

	for (i = 0; i < number_of_cars; ++i)
	{
		cout << "Car #" << i+1 << ":\n";
		cout << "Please enter the make: ";
		cin.get();
		std::getline(cin, cars[i].name);
		cout << "Please enter the year made: ";
		cin >> cars[i].year;
	}
	cout << "Here is your collection:\n";
	for (i = 0; i < number_of_cars; ++i)
	{
		cout << cars[i].year << " " << cars[i].name << endl;
	}
	
	delete [] cars;

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