#ifndef _11_TASK_7_COMPLEX_H_
#define _11_TASK_7_COMPLEX_H_

#include "11_task_7_includes.h"

class complex
{
private:
	double real;
	double imagine;
public:
	explicit complex(double _real = 0.0, double _imagine = 0.0) : real (_real), imagine (_imagine) {};          // constructor for double pounds
	~complex() {};

	friend std::ostream & operator << (std::ostream &, const complex &);
	friend std::istream & operator >> (std::istream &, complex &);

	friend complex operator + (const complex &comp_1, const complex &comp_2) 
	{
		return complex(comp_1.real + comp_2.real, comp_1.imagine + comp_2.imagine);
	};
	friend complex operator - (const complex &comp_1, const complex &comp_2) 
	{
		return complex(comp_1.real - comp_2.real, comp_1.imagine - comp_2.imagine);
	};
	friend complex operator * (const complex &comp_1, const complex &comp_2) 
	{
		return complex(comp_1.real * comp_2.real - comp_1.imagine * comp_2.imagine, comp_1.real * comp_2.imagine + comp_1.imagine * comp_2.real);
	};
	friend complex operator * (int val, const complex &comp) 
	{
		return complex(val*comp.real, val*comp.imagine);
	};
	complex operator ~ () 
	{
		return complex(real, -imagine);
	};

};

#endif
