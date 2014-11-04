#include "10_task_3_golf.h"


Golf::Golf()
{
	cout << "Please, enter information about player:\n";
	char fullname_temp[LIMIT];
	int handicap_temp;
	cout << "Please, enter handicap: ";
	while (!(cin >> handicap_temp) && cin.fail())
	{
		wrong_input();
	}
	cin.get();
	cout << "Please, enter name: ";
	cin.getline(fullname_temp, LIMIT);
	Golf temp (fullname_temp, handicap_temp); // temp object for *this declaration
	*this = temp;
}

Golf::Golf(const char *_fullname, int _handicap)
{
	handicap = _handicap;
	strncpy_s(fullname, LIMIT, _fullname, LIMIT); // because we use char array 
}

Golf::~Golf()
{
}

void Golf::Handicap(int hc)
{
	handicap = hc;
}

void Golf::Show() const
{
	cout << "Name: " << fullname << endl 
		 << "Handicap: " << handicap << endl;
}






