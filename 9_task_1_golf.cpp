#include "9_task_1_golf.h"

void setgolf(golf & g, const char * name, int hc)
{
	strncpy_s(g.fullname, Len, name, Len);
	g.handicap = hc;
}

int setgolf(golf & g)
{
	cout << "Please, enter handicap: ";
	while (!(cin >> g.handicap) && cin.fail())
	{
		wrong_input();
	}
	cin.get();
	cout << "Please, enter name: ";
	cin.getline(g.fullname, Len);
	return g.fullname[0] == '\0' ? 0 : 1;

}

void handicap(golf & g, int hc)
{
	g.handicap = hc;
}

void showgolf(const golf & g)
{
	cout << "Information about player:\n";
	cout << "Name: " << g.fullname << endl;
	cout << "Handicap: " << g.handicap << endl;
}

void wrong_input()
{
	cout << "Wrong input. Please try again\n";
	cin.clear();
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');		
}