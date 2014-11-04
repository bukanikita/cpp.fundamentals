#include "10_task_7_plorg.h"

Plorg::Plorg(const char *_name)
{
	strncpy_s(name, NAME_LENGTH, _name, NAME_LENGTH);
	CI = DEF_CI;
}

void Plorg::changeCI(int new_CI)
{
	CI = new_CI;
}

void Plorg::showPlorg() const
{
	cout << "Name: " << name << endl
		 << "CI: " << CI << endl;
}