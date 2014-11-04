// static.cpp -- using a static local variable
#include <iostream>
#include <string>

// function prototype
void strcount(const std::string&);

int main()
{
    using namespace std;
    string input;

    cout << "Enter a line:\n";
	getline(cin, input);
    while (input != "")
    {
        strcount(input);
        cout << "Enter next line (empty line to quit):\n";
        getline(cin, input);
    }
    cout << "Bye\n";
	cin.get();
	cin.get();
    return 0;
}

void strcount(const std::string &str)
{
    using namespace std;
    static int total = 0;        // static local variable

    cout << "\"" << str <<"\" contains ";
    
    total += str.length();
    cout << str.length() << " characters\n";
    cout << total << " characters total\n";
}
