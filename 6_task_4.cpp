#include <iostream>
#include <cstring>

using std::cout;
using std::cin;
using std::endl;

const int strsize = 40;

struct bop
{
	char fullname[strsize];
	char title[strsize];
	char bopname[strsize];
	int preference;
};

int main() 
{
	const int number_of_programmers = 5;
	char choice;
	int i;
	bop programmers[5] = {
		{"Fullname 1", "Title 1", "Bop name 1", 1},
		{"Fullname 2", "Title 2", "Bop name 2", 0},
		{"Fullname 3", "Title 3", "Bop name 3", 2},
		{"Fullname 4", "Title 4", "Bop name 4", 1},
		{"Fullname 5", "Title 5", "Bop name 5", 2}
	};
	cout << "Benevolent Order of Programmers Report\n";
	cout << "a. display by name\tb. display by title\n";
	cout << "c. display by bopname\td. display by preference\n";
	cout << "q. quit\n";
	cout << "Enter your choice: ";
	choice = cin.get();
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	while (choice != 'q')
	{
		switch (choice)
		{
		case 'a':
			for (i = 0; i < number_of_programmers; ++i)
			{
				cout << programmers[i].fullname << endl;
			}
			break;
		case 'b':
			for (i = 0; i < number_of_programmers; ++i)
			{
				cout << programmers[i].title << endl;
			}
			break;
		case 'c':
			for (i = 0; i < number_of_programmers; ++i)
			{
				cout << programmers[i].bopname << endl;
			}
			break;
		case 'd':
			for (i = 0; i < number_of_programmers; ++i)
			{
				switch (programmers[i].preference)
				{
				case 0:
					cout << programmers[i].fullname << endl;
					break;
				case 1:
					cout << programmers[i].title << endl;
					break;
				case 2:
					cout << programmers[i].bopname << endl;
					break;
				default:
					cout << "Wrong input was\n";
					break;
				}
			}
			break;
		default:
			cout << "Bad input.\n";
			break;
		}
		cout << "Next choice: ";
		choice = cin.get();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	cout << "Bye!\n";

	cin.get();
	cin.get();

	return 0;
}