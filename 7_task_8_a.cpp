#include <iostream>
const int Seasons = 4;
const char * const Snames[Seasons] =
{"Spring", "Summer", "Fall", "Winter"};

void fill(double *);
void show(const double * const);
int main()
{
	double expenses[Seasons];
	fill(expenses);
	show(expenses);

	std::cin.get();
	std::cin.get();
	return 0;
}

void fill(double * exp)
{
	for (int i = 0; i < Seasons; i++)
	{
		std::cout << "Enter " << Snames[i] << " expenses: ";
		std::cin >> *(exp+i);
	}
}

void show(const double * const exp)
{
	double total = 0.0;
	std::cout << "\nEXPENSES\n";
	for (int i = 0; i < Seasons; i++)
	{
		std::cout << Snames[i] << ": $" << exp[i] << '\n';
		total += exp[i];
	}
	std::cout << "Total: $" << total << '\n';
}
