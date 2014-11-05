#include "11_task_7_complex.h"

std::ostream & operator << (std::ostream &os, const complex &comp)
{
	os << "(" << comp.real << "," << comp.imagine << "i)";
	return os;
}

std::istream & operator >> (std::istream &is, complex &comp)
{
	cout << "real: ";
	is >> comp.real;
	cout << "imagine: ";
	is >> comp.imagine;
	return is;
}