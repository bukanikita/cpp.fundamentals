#include <iostream>

typedef unsigned short un_short;

using std::cout;
using std::cin;
using std::endl;

void wrong_input();

int main()
{
	const un_short min_to_sec = 60;
	const un_short deg_to_min = 60;
	un_short degree, minutes, seconds;
	double total_min;

	cout << "Enter a latitude in degrees, minutes, and seconds:\n";
	cout << "First, enter the degrees: ";
	while (!(cin >> degree) && cin.fail())
	{
		wrong_input();		
	}
	cout << "Next, enter the minutes of arc: ";
	while (!(cin >> minutes) && cin.fail())
	{
		wrong_input();		
	}
	cout << "Finally, enter the seconds of arc: ";
	while (!(cin >> seconds) && cin.fail())
	{
		wrong_input();		
	}

	total_min = minutes + double(seconds) / min_to_sec;

	cout << degree << " degrees, " << minutes << " minutes, " << seconds <<
		" seconds = " << degree + total_min / deg_to_min << " degrees\n";

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