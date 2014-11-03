#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

void show_srting(string, int count = 0);

int main() 
{
	show_srting ("STRING1");
	show_srting ("STRING2", 0);
	show_srting ("STRING3", 1);
	show_srting ("STRING4", 1);

	cin.get();
	cin.get();

	return 0;
}

void show_srting(string str, int count)
{
	static int number_of_calls = 0;
	for (int i = 0; count != 0 ? i < number_of_calls: i < 1; ++i)
	{
		cout << str << endl;
	}
	number_of_calls++;
}
