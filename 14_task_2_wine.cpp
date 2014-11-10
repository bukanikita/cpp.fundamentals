#include "14_task_2_wine.h"

Wine::Wine() : string ("none"), PairArray(), years(0)
{
}

Wine::Wine(const char * l, int y, const int yr[], const int bot[]) : string(l), PairArray(ArrayInt(yr, y), ArrayInt(bot, y)), years(y)
{
}

Wine::Wine(const char * l, int y) : string(l), PairArray(ArrayInt(y), ArrayInt(y)), years(y)
{
}

void Wine::GetBottles()
{
	try 
	{
		cout << "Enter " << dynamic_cast<string &> (*this) << " data for " << years << " year(s):\n";
	}
	catch (std::bad_cast &e)
	{
		cout << e.what() << endl;
	}
	ArrayInt temp_year (years), temp_bottles (years);
	for (int i = 0; i < years; ++i)
	{
		cout << "Enter year: ";
		cin >> temp_year[i];
		cout << "Enter bottles for that year: ";
		cin >> temp_bottles[i];
	}
	PairArray::operator=(PairArray(temp_year,temp_bottles));
}

void Wine::Show()
{
	try 
	{
		cout << "Wine: " << dynamic_cast<string &> (*this) << endl << "\tYear\tBottles\n";
	}
	catch (std::bad_cast &e)
	{
		cout << e.what() << endl;
	}
	for (int i = 0; i < years; ++i)
	{
		cout << "\t" << PairArray::first()[i] << "\t" << PairArray::second()[i] << endl;
	}
}

string & Wine::Label()
{
	try
	{
		return dynamic_cast<string &> (*this);
	}
	catch (std::bad_cast &e)
	{
		cout << e.what() << endl;
	}
}

