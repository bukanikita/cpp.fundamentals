#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

void wrong_input();

int main() 
{
	int number_of_rows;
	cout << "Enter number of rows: ";
	while (!(cin >> number_of_rows) && cin.fail())
	{
		wrong_input();		
	}
	int i, j, temp;

	for (i = 0; i < number_of_rows; ++i)
	{
		temp = number_of_rows - i - 1;
		for (j = 0; j < temp; ++j)
		{
			cout << ".";
		}
		for (j = i; j >= 0; --j)
		{
			cout << "*";
		}
		cout << endl;
	}

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