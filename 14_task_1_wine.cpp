#include "14_task_1_wine.h"

Wine::Wine() : name ("none"), year_and_count(), years(0)
{
}

Wine::Wine(const char * l, int y, const int yr[], const int bot[]) : name(l), year_and_count(ArrayInt(yr, y), ArrayInt(bot, y)), years(y)
{
}

Wine::Wine(const char * l, int y) : name(l), year_and_count(ArrayInt(y), ArrayInt(y)), years(y)
{
}

void Wine::GetBottles()
{
	cout << "Enter " << name << " data for " << years << " year(s):\n";
	for (int i = 0; i < years; ++i)
	{
		cout << "Enter year: ";
		cin >> year_and_count.first()[i];
		cout << "Enter bottles for that year: ";
		cin >> year_and_count.second()[i];
	}
}

void Wine::Show()
{
	cout << "Wine: " << name << endl << "\tYear\tBottles\n";
	for (int i = 0; i < years; ++i)
	{
		cout << "\t" << year_and_count.first()[i] << "\t" << year_and_count.second()[i] << endl;
	}
}

