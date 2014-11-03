#include <iostream>

long double probability(unsigned short numbers, unsigned short picks, unsigned short mega);

int main()
{
	using namespace std;

	unsigned short numbers, choices, meganumber;

	cout << "Enter the total numbers, number of choices and meganumber:\n";

	while ((cin >> numbers >> choices >> meganumber) && choices <= numbers)
	{
		cout << "You have one chance in ";
		cout << probability(numbers, choices, meganumber);
		cout << " of winning.\n";
		cout << "Next numbers (q to quit): ";
	}
	cout << "bye\n";
	cin.get();
	cin.get();
	return 0;
}

long double probability(unsigned short numbers, unsigned short picks, unsigned short mega)
{
	long double result = 1.0;
	long double n;
	unsigned p;

	for (n = numbers, p = picks; p > 0; n--, p--)
	{
		result *= n / p; 
	}
	result *= mega;

	return result;
}