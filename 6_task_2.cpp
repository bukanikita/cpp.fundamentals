#include <iostream>
#include <array>

using std::cout;
using std::cin;
using std::endl;
using std::array;

int main() 
{
	const short max_values_number = 10;
	array <double, max_values_number> values;
	int real_values_count = 0, i;
	double average = 0;
	int big_than_av = 0;
	cout << "Please enter ten or less values or non-digit value for exit:\n";
	do
	{
		cin >> values[real_values_count];
		average += values[real_values_count];
		real_values_count++;
	} while (!cin.fail() && real_values_count < max_values_number);

	average /= real_values_count;

	for (i = 0; i < real_values_count; ++i)
	{
		if (values[i] > average)
		{
			big_than_av++;
		}
	}

	cout << "Average: " << average << " and values bigger than average: " << big_than_av << endl;

	cin.get();
	cin.get();

	return 0;
}