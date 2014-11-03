#include <iostream>
#include <string>
#include <fstream>

using std::cout;
using std::cin;
using std::endl;

int get_data(double *, int);
void show_results(const double *, int);
double average(const double *, int);
void wrong_input();

int main() 
{
	const int size = 10;
	double results[size], average_res;
	int real_size;

	real_size = get_data(results, size);
	show_results(results, real_size);
	average_res = average(results, real_size);
	cout << "Average: " << average_res << endl;

	cin.get();
	cin.get();

	return 0;
}

int get_data(double *res, int _size)
{
	int i = 0;
	do
	{
		cout << "Please, enter " << i+1 << " result (negative value to stop): ";
		while (!(cin >> res[i]) && cin.fail())
		{
			wrong_input();		
		}
		++i;
	}while (i < _size && res[i - 1] >= 0);
	return (i == _size) ? i : i -1;
}

void show_results(const double *res, int _size)
{
	int i;
	cout << "Results:\n";
	for (i = 0; i < _size; ++i)
	{
		cout << res[i] << endl;
	}
}

double average(const double *res, int _size)
{
	double sum = 0.0;
	int i;
	for (i = 0; i < _size; ++i)
	{
		sum += res[i];
	}
	return sum / _size;
}

void wrong_input()
{
	cout << "Wrong input. Please try again\n";
	cin.clear();
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');		
}