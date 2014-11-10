#include "14_task_4_person.h"

Person::~Person()
{
}

void Person::Show() const
{
	cout << "Name: " << name << endl;
	cout << "Surname: " << surname << endl;
}

void Person::Set()
{
	cout << "Enter name: ";
	std::getline(cin, name);
	cout << "Enter surname: ";
	std::getline(cin, surname);
}