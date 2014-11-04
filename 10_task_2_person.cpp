#include "10_task_2_person.h"

Person::Person(const string & ln, const char * fn)
{
	lname = ln;
	strncpy_s(fname, LIMIT, fn, LIMIT);
}

void Person::Show() const
{
	cout << fname << " " << lname << endl;
}

void Person::FormalShow() const
{
	cout << lname << ", " << fname << endl;
}

