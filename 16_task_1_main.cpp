#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

void wrong_input();
bool is_palindrome(string &);

int main()
{
	string str;
	cout << "Please, enter the word:\n";

	do 
	{
		std::getline(cin, str);
		cout << (str.size() ? ( (is_palindrome(str) ? "Palindrome.\n" : "Not palindrome.\n")) : ("Empty string.\n"));
	} while (str != "quit");
	
	cin.get();
	cin.get();

	return 0;
}

void wrong_input()
{
	cout << "Wrong input. Please try again\n";
	cin.clear();
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');		
}

bool is_palindrome(string &s)
{
	string::const_iterator start = s.begin();
	string::const_iterator end = s.end() - 1;
	while (start < end)
	{
		if (*start != *end)
		{
			return false;
		}
		++start;
		--end;
	}
	return true;
}
