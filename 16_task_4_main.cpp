#include <iostream>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;

void wrong_input();
int Fill_array(long *, int);
void Show(long);
int reduce(long ar[], int n);

int main()
{
	long *Ar;
	int max_num, real_num, reduced_num;

	cout << "Please, enter number of elements in array: ";
	while (!(cin >> max_num) && cin.fail())
	{
		wrong_input();		
	}

	Ar = new long [max_num];

	real_num = Fill_array(Ar, max_num);

	cout << "Array at start:\n";

	std::for_each(Ar, Ar + real_num, Show);

	reduced_num = reduce(Ar, real_num);

	cout << "result array:\n";

	std::for_each(Ar, Ar + reduced_num, Show);
	
	
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

void Show(long val)
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

int reduce(long ar[], int n)
{
	long *last;
	std::sort(ar, ar + n);

	cout << "Array after sort:\n";

	std::for_each(ar, ar + n, Show);

	last = std::unique(ar, ar + n);

	cout << "Array after unique:\n";

	std::for_each(ar, ar + n, Show);

	return static_cast<int> (last - ar);
}