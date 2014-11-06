#include "13_task_4_port.h"

Port::Port(const char * br, const char * st, int b)
{
	brand = new char [strlen(br) + 1];
	strcpy(brand, br);
	strcpy(style, st);
	bottles = b;
}

Port::Port(const Port & p)
{
	brand = new char [strlen(p.brand) + 1];
	strcpy(brand, p.brand);
	strcpy(style, p.style);
	bottles = p.bottles;
}

Port & Port::operator=(const Port & p)
{
	if (this == &p)
	{
		return *this;
	}
	delete [] brand;
	brand = new char [strlen(p.brand) + 1];
	strcpy(brand, p.brand);
	strcpy(style, p.style);
	bottles = p.bottles;
	return *this;
}

Port & Port::operator+=(int b)
{
	bottles += b;
	return *this;
}

Port & Port::operator-=(int b)
{
	if (bottles >= b)
	{
		bottles -= b;
	}
	else
	{
		cout << "You haven't got " << b << " bottles, so operation can't be executed.\n" << endl;
	}
	return *this;
}

void Port::Show() const
{
	cout << "Brand: " << brand <<endl
		 << "Kind: " << style << endl
		 << "Bottles: " << bottles << endl;
}

std::ostream & operator<<(std::ostream & os, const Port & p)
{
	os << p.brand << ", " << p.style << ", " << p.bottles;
	return os;
}