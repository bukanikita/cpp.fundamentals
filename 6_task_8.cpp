#include <iostream>
#include <string>
#include <fstream>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ifstream;

int main() 
{
	string file_name;
	ifstream file;
	long long number_of_symbols = 0;

	cout << "Please, enter path to file:\n";
	std::getline(cin, file_name);

	file.open(file_name.c_str());

	if (!file.is_open())
	{
		cout << "File can't be opened.\n";
		return 1;
	}

	while (!file.eof())
	{
		file.get();
		number_of_symbols++;
	}

	file.close();

	number_of_symbols--;
	
	cout << "Symbols in file: " << number_of_symbols << endl;

	cin.get();
	cin.get();

	return 0;
}