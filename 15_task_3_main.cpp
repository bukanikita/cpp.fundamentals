#include "15_task_3_badmean.h"

double hmean(double a, double b);
double gmean(double a, double b);

int main()
{
	double x, y, z;

	cout << "Enter two numbers: ";
	while (cin >> x >> y)
	{
		try {                  // start of try block
			z = hmean(x,y);
			cout << "Harmonic mean of " << x << " and " << y
				<< " is " << z << endl;
			cout << "Geometric mean of " << x << " and " << y
				<< " is " << gmean(x,y) << endl;
			cout << "Enter next set of numbers <q to quit>: ";
		}// end of try block
		catch (abstr_mean & bg)    // start of catch block
		{
			cout << bg.what();
			break;
		}                  
		cout << "Sorry, you don't get to play any more.\n";
	}
	cout << "Bye!\n";
	
	cin.get();
	cin.get();

	return 0;
}

double hmean(double a, double b)
{
	if (a == -b)
		throw bad_hmean("hmean: invalid arguments: a = -b\n", a, b);
	return 2.0 * a * b / (a + b);
}

double gmean(double a, double b)
{
	if (a < 0 || b < 0)
		throw bad_gmean("gmean() arguments should be >= 0\n", a, b);
	return std::sqrt(a * b); 
}

void wrong_input()
{
	cout << "Wrong input. Please try again\n";
	cin.clear();
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');		
}