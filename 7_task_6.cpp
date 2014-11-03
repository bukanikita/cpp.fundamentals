#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;

int Fill_array(double *, int);
void Show_array(double *, int);
void Reverse_array(double *, int);

int main() 
{
	int size;
	double *values;
	int real_size;

	cout << "Please, enter array size: ";
	cin >> size;

	values = new double [size];

	real_size = Fill_array(values, size);
	cout <<"Array before reversing:\n";
	Show_array(values, real_size);
	cout <<"Array after reversing:\n";
	Reverse_array(values, real_size);
	Show_array(values, real_size);

	delete [] values;

	cin.get();
	cin.get();

	return 0;
}

int Fill_array(double *val, int _size)
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

void Show_array(double *val, int _size)
{
	int i;
	for (i = 0; i < _size; ++i)
	{
		cout << val[i] << endl;
	}
}

void Reverse_array(double *val, int _size)
{
	double temp;
	int i;
	for (i = 1; i < _size/2; ++i)
	{
		temp = val[i];
		val[i] = val[_size - i - 1];
		val[_size - i - 1] = temp;
	}
}