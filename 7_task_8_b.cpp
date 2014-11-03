#include <iostream>
const int Seasons = 4;
const char * const Snames[Seasons] =
{"Spring", "Summer", "Fall", "Winter"};

struct d_exp
{
	double exp[Seasons];
};

void fill(d_exp * const);
void show(d_exp);

int main()
{
	d_exp expenses;
	fill(&expenses);
	show(expenses);

	std::cin.get();
	std::cin.get();
	return 0;
}

void fill(d_exp * const exp_)
{
	for (int i = 0; i < Seasons; i++)
	{
		std::cout << "Enter " << Snames[i] << " expenses: ";
		std::cin >> exp_->exp[i];
	}
}

void show(d_exp exp_)
{
	double total = 0.0;
	std::cout << "\nEXPENSES\n";
	for (int i = 0; i < Seasons; i++)
	{
		std::cout << Snames[i] << ": $" << exp_.exp[i] << '\n';
		total += exp_.exp[i];
	}
	std::cout << "Total: $" << total << '\n';
}
