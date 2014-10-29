#include <iostream>
#include <cstring>

using std::cout;
using std::cin;
using std::endl;

int main()
{
	const int size = 4;
	char first_name[size], last_name[size], full_name[2*size + 1];
	cout << "Enter your first name: ";
	cin.getline(first_name, size);
	cout << "Enter your last name: ";
	cin.getline(last_name, size);

	strncpy_s(full_name, first_name, size);
	strncat_s(full_name, ", ", 2);
	strncat_s(full_name, last_name, size);

	cout << "Here's the information in a single string: " << full_name << endl;
	
	cin.get();
	cin.get();

	return 0;
}