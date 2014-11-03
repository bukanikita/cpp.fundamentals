#include <iostream>

using std::cout;
using std::cin;
using std::endl;

const int size = 5;

template <typename T> T max5(T *);

int main() 
{
	int Arr1[size] = {1,2,34,5,6};
	double Arr2[size] = {10.0,2.0,3.0,5.6,6.7};

	cout << max5(Arr1) << endl;
	cout << max5(Arr2) << endl;

	cin.get();
	cin.get();

	return 0;
}

template <typename T> T max5(T *arr)
{
	T max = arr[0];
	for (int i = 1; i < size; ++i)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}
	return max;
}

