#include <iostream>

using std::cout;
using std::cin;
using std::endl;

typedef double (*pf_for_calc)(double, double);

double add (double, double);
double sub (double, double);
double mul (double, double);
double div (double, double);
double calculate (double, double, pf_for_calc);

int main() 
{
	double number_1, number_2;
	const int number_of_op = 3;
	pf_for_calc pfAr[number_of_op] = {sub, mul, div};

	cout << "Please, enter two values for making operations:\n";

	while (cin >> number_1 >> number_2)
	{
		cout << "Results of operations: \n";
		cout << calculate(number_1,number_2, add) << endl;
		for (int i = 0; i < number_of_op; ++i)
		{
			try
			{
				cout << calculate(number_1,number_2, pfAr[i]) << endl;
			}
			catch (std::invalid_argument &e)
			{
				cout << e.what() << endl;
			}
		}
		cout << "Please, enter new values: \n";
	}

	

	cin.get();
	cin.get();

	return 0;
}

double calculate (double a, double b, pf_for_calc pf)
{
	return (*pf)(a,b);
}

double add (double a, double b)
{
	cout << "Adding: ";
	return a+b;
}

double sub (double a, double b)
{
	cout << "Subtraction: ";
	return a-b;
}

double mul (double a, double b)
{
	cout << "Multiplication: ";
	return a*b;
}

double div (double a, double b)
{
	cout << "division: ";
	if(b != 0) 
	{
		return a/b;
	}
	else
	{
		throw std::invalid_argument("Second argument can't be 0\n");
	}
}