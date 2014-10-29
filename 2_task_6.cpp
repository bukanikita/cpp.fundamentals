#include <iostream>

using std::cout;
using std::cin;
using std::endl;

double light_to_astronomical(double);

int main()
{
	double light_years, astronomical_years;
	std::cout << "Enter the number of light years:\n";
	while (!(std::cin >> light_years) && std::cin.fail())
	{
		std::cout << "Wrong input. Please try again\n";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');		
	}
	astronomical_years = light_to_astronomical(light_years);
	std::cout << light_years << " light years = " << astronomical_years << " astronomical units." << endl;
	std::cin.get();
	std::cin.get();
	return 0;
}

double light_to_astronomical(double light)
{
	const int light_to_astronomical = 63240;
	return light * light_to_astronomical;
}