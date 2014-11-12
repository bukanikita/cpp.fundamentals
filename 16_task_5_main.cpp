#include <iostream>
#include <algorithm>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

void wrong_input();
int Fill_array(long *, int);
int Fill_array(string *, int);
template <typename T>
void Show(T);
template <typename T>
int reduce(T ar[], int n);

int main()
{
	long *Ar;
	string *Ar_str;
	int max_num, real_num, reduced_num;

	cout << "Please, enter number of elements in array: ";
	while (!(cin >> max_num) && cin.fail())
	{
		wrong_input();		
	}

	Ar = new long [max_num];
	Ar_str = new string [max_num];

	real_num = Fill_array(Ar, max_num);

	cout << "Array at start (long):\n";

	std::for_each(Ar, Ar + real_num, Show<long>);

	reduced_num = reduce(Ar, real_num);

	cout << "result array:\n";

	std::for_each(Ar, Ar + reduced_num, Show<long>);

	real_num = Fill_array(Ar_str, max_num);

	cout << "Array at start (string):\n";

	std::for_each(Ar_str, Ar_str + real_num, Show<string>);

	reduced_num = reduce(Ar_str, real_num);

	cout << "result array:\n";

	std::for_each(Ar_str, Ar_str + reduced_num, Show<string>);
	
	
	cin.get();
	cin.get();

	return 0; 
}

void wrong_input()
{
	std::cout << "Wrong input. Please try again\n";
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');		
}

template <typename T>
void Show(T val)
{
	cout << val << endl;
}


int Fill_array(long *val, int _size)
{
	int i = 0;
	do
	{
		if (i != _size)
		{
			cout << "Please, enter " << i+1 << " result (character for exit): ";
		}
		++i;
	}while (i <= _size && cin >> val[i-1]);

	return (i == _size) ? i : i -1;
}

int Fill_array(string *val, int _size)
{
	int i = 0;
	do
	{
		if (i != _size)
		{
			cout << "Please, enter " << i+1 << " result (quit for exit): ";
		}
		++i;
	}while (i <= _size && cin >> val[i-1] && val[i-1] != "quit");

	return (i == _size) ? i : i -1;
}

template <typename T>
int reduce(T ar[], int n)
{
	T *last;
	std::sort(ar, ar + n);

	cout << "Array after sort:\n";

	std::for_each(ar, ar + n, Show<T>);

	last = std::unique(ar, ar + n);

	cout << "Array after unique:\n";

	std::for_each(ar, ar + n, Show<T>);

	return static_cast<int> (last - ar);
}