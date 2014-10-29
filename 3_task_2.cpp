#include <iostream>
#include <math.h>

typedef unsigned short un_short;

using std::cout;
using std::cin;
using std::endl;

void wrong_input();

int main()
{
	const un_short inches_in_feet = 12;
	const float feet_to_meter = 0.0254f;
	const float pound_to_kg = 2.2f;
	un_short inches, feet;
	float pound;

	cout << "Enter feet in your height:\n";
	while (!(cin >> feet) && cin.fail())
	{
		wrong_input();		
	}
	cout << "Enter inches in your height:\n";
	while (!(cin >> inches) && cin.fail())
	{
		wrong_input();		
	}
	cout << "Enter pound in your weight:\n";
	while (!(cin >> pound) && cin.fail())
	{
		wrong_input();		
	}

	cout << "Your BMI is " << (pound / pound_to_kg) / pow((feet * inches_in_feet + inches) * feet_to_meter,2) << endl;

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