#include <iostream>

using std::cout;
using std::cin;
using std::endl;

struct sum_and_taxes
{
	int sums;
	float rates;

};

int main() 
{
	const int number_of_taxes = 4;
	const sum_and_taxes taxes[number_of_taxes] = {
		{5000, 0.0f},
		{10000, 0.1f},
		{20000, 0.15f},
		{35000, 0.2f},
	};
	int tvarp;
	double tax;
	int i;
	cout << "Please, enter sum (negative or non-digit value for exit): ";
	while (cin >> tvarp && !cin.fail() && tvarp >= 0)
	{
		tax = 0.0;
		cout << "Your tax will be:\n";
		for (i=0; i < number_of_taxes && tvarp >=0 ; ++i) 
		{
			if ( i < number_of_taxes - 1 && tvarp >= taxes[i].sums) 
			{
				tax += taxes[i].sums * taxes[i].rates;
			} 
			else 
			{
				tax += tvarp * taxes[i].rates;
			}
			tvarp -= taxes[i].sums;
		}
		cout << tax << endl;
		cout << "Please, enter sum again: ";
	}

	cin.get();
	cin.get();

	return 0;
}