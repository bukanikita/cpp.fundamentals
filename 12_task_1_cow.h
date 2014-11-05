#ifndef _12_TASK_1_COW_H_
#define _12_TASK_1_COW_H_

#include "12_task_1_includes.h"

class Cow 
{
	static const int NAME_LENGTH = 20;
	char name[NAME_LENGTH];
	char * hobby;
	double weight;
public:
	Cow();
	Cow(const char * nm, const char * ho, double wt);
	Cow(const Cow &c);
	~Cow();
	Cow & operator=(const Cow & c);
	void ShowCow() const; // display all cow data
};

#endif
