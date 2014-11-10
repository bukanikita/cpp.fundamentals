#include "14_task_4_gunslinger.h"

void Gunslinger::Show() const
{
	Person::Show();
	Data();
}

void Gunslinger::Data() const
{
	cout << "Time: " << time << endl;
	cout << "Notches: " << notches << endl;
}

void Gunslinger::Set()
{
	cout << "Please, enter gunslinger ingormation:\n";
	Person::Set();
	Get();
}

void Gunslinger::Get()
{
	cout << "Time: ";
	while (!(cin >> time) && cin.fail())
	{
		wrong_input();		
	}
	cout << "Notches: ";
	while (!(cin >> notches) && cin.fail())
	{
		wrong_input();		
	}
}