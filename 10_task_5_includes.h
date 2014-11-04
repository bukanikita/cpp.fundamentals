#ifndef _10_TASK_5_INCLUDES_H_
#define _10_TASK_5_INCLUDES_H_

#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

const int NAME_LENGTH = 35;

struct customer
{
	char fullname[NAME_LENGTH];
	double payment;
};

void wrong_input();

#endif