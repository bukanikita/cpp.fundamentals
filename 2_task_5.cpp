#include <iostream>

using std::cout;
using std::cin;
using std::endl;

double celsius_to_fahrenheit(double);

int main()
{
	//const int months_in_year = 12;
	double celsius, fahrenheit;
	std::cout << "Please enter a Celsius value:\n";
	while (!(std::cin >> celsius) && std::cin.fail())
	{
		std::cout << "Wrong input. Please try again\n";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');		
	}
	fahrenheit = celsius_to_fahrenheit(celsius);
	std::cout << celsius << " degrees Celsius is " << fahrenheit << " degrees Fahrenheit." << endl;
	std::cin.get();
	std::cin.get();
	return 0;
}

double celsius_to_fahrenheit(double cels)
{
	const double koef_cels_to_fahr = 1.8, free_cels_to_fahr = 32.0;
	return cels * koef_cels_to_fahr + free_cels_to_fahr;
}