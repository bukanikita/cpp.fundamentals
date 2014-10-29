#include <iostream>

int main()
{
	const int furlong_to_yard = 220;
	double furlongs, yards;
	std::cout << "Please, enter the distance in furlongs\n";
	while (!(std::cin >> furlongs) && std::cin.fail())
	{
		std::cout << "Please enter any double value\n";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');		
	}
	yards = furlong_to_yard * furlongs;
	std::cout << "In " << furlongs << " furlongs we have " << yards << " yards\n";
	std::cin.get();
	std::cin.get();
	return 0;
}