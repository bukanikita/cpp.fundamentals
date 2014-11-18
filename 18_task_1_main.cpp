#include <iostream>
#include <initializer_list>

using std::cout;
using std::cin;
using std::endl;

template <typename T>
T average_list(const std::initializer_list<T> &in_list);

int main()
{
	using namespace std;
	// list of double deduced from list contents
	auto q = average_list({15.4, 10.7, 9.0});
	cout << q << endl;
	// list of int deduced from list contents
	cout << average_list({20, 30, 19, 17, 45, 38} ) << endl;
	// forced list of double
	auto ad = average_list<double>({'A', 70, 65.33});
	cout << ad << endl;
	cin.get();
	cin.get();
	return 0;
}

template <typename T>
T average_list(const std::initializer_list<T> &in_list)
{
	T sum = 0;
	int count = 0;
	if (in_list.size() == 0)
	{
		cout << "List is empty.\n";
		return sum;
	}
	for (auto x : in_list)
	{
		sum += x;
		++count;
	}
	return sum / count;
}