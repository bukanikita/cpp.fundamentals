#include <iostream>
#include <array>

using std::cout;
using std::cin;
using std::endl;
using std::array;

int main()
{
	const int size = 3;
	array<int, size> results;
	int i;
	int average = 0;

	cout << "Please, enter times of 40-meter dash.\n";
	for (i = 0; i < size; ++i)
	{
		cout << "Please, enter the " << i+1 << " result: ";
		cin >> results[i];
	}

	for (i = 0; i < size; ++i)
	{
		cout << i+1 << " result is: " << results[i] << endl;
		average += results[i];
	}

	average /= size;

	cout << "Average of results is: " << average << endl;

	cin.get();
	cin.get();

	return 0;
}