#include <iostream>
#include <string>
#include <fstream>

using std::cout;
using std::cin;
using std::endl;

double harmonic(double, double);
void wrong_input();

int main() 
{
	double number_1, number_2, harm;

	cout << "Please, enter two values for harmonic calculation (one of them 0 for exit):\n";

	while (!(cin >> number_1) && cin.fail())
	{
		wrong_input();		
	}

	while (!(cin >> number_2) && cin.fail())
	{
		wrong_input();		
	}

	while(number_1 != 0.0 && number_2 != 0.0)
	{
		try
		{
			harm = harmonic(number_1, number_2);
			cout << "Harmonic for " << number_1 << " and " << number_2 << " is " << harm <<endl;
		}
		catch (const std::invalid_argument& e)
		{
			cout << e.what() << endl;
		}
		cout << "Please, enter new values for harmonic calculation (one of them 0 for exit):\n";
		while (!(cin >> number_1) && cin.fail())
		{
			wrong_input();		
		}

		while (!(cin >> number_2) && cin.fail())
		{
			wrong_input();		
		}
	}
	
	cin.get();
	cin.get();

	return 0;
}

double harmonic(double n_1, double n_2)
{
	if (n_1 == -n_2)
	{
		throw std::invalid_argument("Division for 0. ERROR! \n");
	}
	return 2.0 * n_1 * n_2 / (n_1 + n_2);
}

void wrong_input()
{
	cout << "Wrong input. Please try again\n";
	cin.clear();
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');		
}