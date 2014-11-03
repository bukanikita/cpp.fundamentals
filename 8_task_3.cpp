#include <iostream>
#include <string>
#include <cctype>

using std::cout;
using std::cin;
using std::endl;
using std::string;

void to_upper(string &);

int main() 
{
	string str;
	cout << "Enter a string (q to quit): ";
	std::getline(cin, str);
	while (str != "q")
	{
		to_upper(str);
		cout << str <<endl;
		cout << "Next string (q to quit): ";
		std::getline(cin, str);
	}
	cout << "Bye!\n";

	cin.get();
	cin.get();

	return 0;
}

void to_upper(string &_str)
{
	for (auto &ch : _str)
	{
		ch = toupper(ch);
	}
}