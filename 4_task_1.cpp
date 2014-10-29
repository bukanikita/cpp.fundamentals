#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

void wrong_input();

int main()
{
	string first_name, last_name;
	int age;
	char grade;
	cout << "What is your first name? ";
	std::getline (cin,first_name);
	cout << "What is your last name? ";
	std::getline (cin,last_name);
	cout << "What letter grade do you deserve? ";
	while (!(cin >> grade) && cin.fail())
	{
		wrong_input();		
	}
	cout << "What is your age? ";
	while (!(cin >> age) && cin.fail())
	{
		wrong_input();		
	}

	cout << "Name: " << last_name << ", " << first_name << endl
		 << "Grade: " << ++grade << endl
		 << "Age: " << age << endl;
	return 0;
}

void wrong_input()
{
	cout << "Wrong input. Please try again\n";
	cin.clear();
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');		
}

