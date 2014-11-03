#include <iostream>
#include <string>
#include <fstream>

using std::cout;
using std::cin;
using std::endl;

long long fact(int);
void wrong_input();

int main() 
{
	int number;
	long long factorial;

	cout << "Please, enter number for factorial calculation:\n";

	while (!(cin >> number) && cin.fail())
	{
		wrong_input();		
	}

	factorial = fact(number);
	cout <<"Factorial for " << number << " is " << factorial << endl;

	cin.get();
	cin.get();

	return 0;
}

long long fact(int num)
{
	return num == 0 ? 1 : num*fact(num-1);
}

void wrong_input()
{
	cout << "Wrong input. Please try again\n";
	cin.clear();
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');		
}