#include <iostream>
#include <stdexcept>
#include <typeinfo>

using std::cout;
using std::cin;
using std::endl;

template <typename T, typename... Args>
long double sum_values(const T& val, const Args&... args);

template <typename T>
long double sum_values(const T &val);

int main()
{
	long double res;
	
	try 
	{
		res = sum_values(1, 2, 3.0, 4.5);
	}
	catch(const std::logic_error &e)
	{
		cout << e.what() << endl;
		return 1;
	}
	
	cout << static_cast<double>(res) << endl;
	
	cin.get();
	cin.get();
	return 0;
}

template <typename T, typename... Args>
long double sum_values(const T& val, const Args&... args)
{
	if (typeid(char) == typeid(val) || typeid(unsigned char) == typeid(val))
	{
		throw std::logic_error("Can't add char.\n");
	}
	return (static_cast<long double>(val) + static_cast<long double>(sum_values(args...)));
}

template <typename T>
long double sum_values(const T &val)
{
	if (typeid(char) == typeid(val) || typeid(unsigned char) == typeid(val))
	{
		throw std::logic_error("Can't add char.\n");
	}
	return static_cast<long double>(val);
}