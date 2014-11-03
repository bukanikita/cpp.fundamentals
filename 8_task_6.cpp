#include <iostream>

using std::cout;
using std::cin;
using std::endl;

template <typename T> 
T maxn(T *, int);
template <> 
char* maxn (char **, int);

int main() 
{
	const int size_for_int = 6, size_for_double = 4, size_for_char = 5;
	int Arr1[size_for_int] = {1,2,34,5,6, 7};
	double Arr2[size_for_double] = {10.0,2.0,3.0,5.6};
	char *Arr3[size_for_char] = {
		"abs",
		"String 1",
		"Z123",
		"String 2",
		"asd"
	};

	cout << maxn(Arr1, size_for_int) << endl;
	cout << maxn(Arr2, size_for_double) << endl;
	cout << maxn(Arr3, size_for_char) << endl;

	cin.get();
	cin.get();

	return 0;
}

template <typename T> 
T maxn(T *arr, int size)
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

template <> 
char* maxn (char **arr, int size)
{
	char *max = arr[0];
	size_t max_len = strlen(arr[0]);
	for (int i = 0; i < size; ++i)
	{
		if (strlen(arr[i]) > max_len)
		{
			max_len = strlen(arr[i]);
			max = arr[i];
		}
	}
	return max;
}