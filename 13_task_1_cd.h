#ifndef _13_TASK_1_CD_H_
#define _13_TASK_1_CD_H_

#include "13_task_1_includes.h"

// base class
class Cd // represents a CD disk
{ 
private:
	char performers[50];
	char label[20];
	int selections; // number of selections
	double playtime; // playing time in minutes
public:
	Cd(char * s1, char * s2, int n, double x);
	Cd(const Cd & d);
	Cd();
	virtual ~Cd() {};
	virtual void Report() const; // reports all CD data
	//Cd & operator=(const Cd & d);
};

#endif
