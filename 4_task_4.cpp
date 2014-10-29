#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main()
{
	string first_name, last_name, full_name;
	cout << "Enter your first name: ";
	std::getline(cin, first_name);
	cout << "Enter your last name: ";
	std::getline(cin, last_name);

	full_name = first_name;
	full_name.append(", ");
	full_name.append(last_name);
	//it's faster than full_name = first_name + ", " + last_name; because in this approach we create a lot of temp objects

	cout << "Here's the information in a single string: " << full_name << endl;

	cin.get();
	cin.get();

	return 0;
}