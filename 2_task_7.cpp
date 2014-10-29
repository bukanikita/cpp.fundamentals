#include <iostream>

typedef unsigned short un_short;

using std::cout;
using std::cin;
using std::endl;

void wrong_input();
void show_time(un_short, un_short);

int main()
{
	un_short hours, minutes;
	std::cout << "Enter the number of hours:\n";
	while (!(std::cin >> hours) && std::cin.fail())
	{
		wrong_input();
	}
	std::cout << "Enter the number of minutes:\n";
	while (!(std::cin >> minutes) && std::cin.fail())
	{
		wrong_input();
	}
	show_time(hours, minutes);
	std::cin.get();
	std::cin.get();
	return 0;
}

void wrong_input()
{
	std::cout << "Wrong input. Please try again\n";
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');		
}

void show_time(un_short h, un_short m)
{
	const int minutes_in_hour = 60;
	cout << "Time: " << h + m / 60 << ":" << m % 60 << endl;
}