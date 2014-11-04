#ifndef _10_TASK_7_PLORG_H_
#define _10_TASK_7_PLORG_H_

#include "10_task_7_includes.h"

class Plorg
{
private:
	static const int NAME_LENGTH = 35, DEF_CI = 50;
	char name[NAME_LENGTH];
	int CI;
public:
	Plorg (const char *_name = "Plorga"); // default constructor
	void changeCI(int); // changing CI
	void showPlorg() const;
	~Plorg() {};
};

#endif
