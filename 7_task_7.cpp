#include <iostream>
const int Max = 5;

const double* fill_array(double *ar, int limit);
void show_array(const double *ar, const double *);
void revalue(double r, double *ar, const double*);

int main()
{
	using namespace std;
	double properties[Max];

	const double *last_element = fill_array(properties, Max);
	show_array(properties, last_element);
	if (last_element != properties)
	{
		cout << "Enter revaluation factor: ";
		double factor;
		while (!(cin >> factor))
		{
			cin.clear();
			while (cin.get() != '\n')
				continue;
			cout << "Bad input; Please enter a number: ";
		}
		revalue(factor, properties, last_element);
		show_array(properties, last_element);
	}
	cout << "Done.\n";
	cin.get();
	cin.get();
	return 0;
}

const double* fill_array(double *ar, int limit)
{
	using namespace std;
	double temp;
	double *it;
	int i = 0;
	for (it = ar; it != &ar[limit]; ++it, ++i)
	{
		cout << "Enter value #" << (i + 1) << ": ";
		cin >> temp;
		if (!cin)
		{
			cin.clear();
			while (cin.get() != '\n')
				continue;
			cout << "Bad input; input process terminated.\n";
			break;
		}
		else if (temp < 0)
			break;
		*it = temp;
	}
	return it;
}

void show_array(const double *ar, const double* end)
{
	using namespace std;
	const double *it;
	int i = 0;
	for (it = ar; it != end; ++it, ++i)
	{
		cout << "Property #" << (i + 1) << ": $";
		cout << *it << endl;
	}
}

void revalue(double r, double *ar, const double *end)
{
	for (double *it = ar; it != end; ++it)
		*it *= r;
}
