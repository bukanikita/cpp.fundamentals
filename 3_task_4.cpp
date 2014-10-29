#include <iostream>

typedef unsigned long long un_llong;
typedef unsigned short un_short;

using std::cout;
using std::cin;
using std::endl;

void wrong_input();

int main()
{

	un_llong full_seconds;
	const un_short hours_in_day = 24, min_in_hour = 60, sec_in_min = 60; 
	un_short hours, minutes, seconds;
	un_llong m_remaing, h_remain, days;

	cout << "Enter the number of seconds: ";
	while (!(cin >> full_seconds) && cin.fail())
	{
		wrong_input();		
	}

	seconds = full_seconds % sec_in_min;
	m_remaing = full_seconds / sec_in_min;

	minutes = m_remaing % min_in_hour;
	h_remain = m_remaing / min_in_hour;

	hours = h_remain % hours_in_day;
	days = h_remain / hours_in_day;

	cout << full_seconds << " seconds = " << days << " days, " << hours << " hours, " << minutes << " minutes, " << seconds << " seconds\n"  ;

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