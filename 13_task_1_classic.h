#ifndef _13_TASK_1_CLASSIC_H_
#define _13_TASK_1_CLASSIC_H_

#include "13_task_1_cd.h"

// child class
class Classic : public Cd // represents a Classic CD disk
{
private:
	static const int str_desc_len = 100;
	char desc[str_desc_len];
public:
	Classic(const char *desc, char * s1, char * s2, int n, double x);
	Classic(const Classic & d);
	Classic();
	virtual ~Classic() {};
	virtual void Report() const; // reports all CD data
	//Cd & operator=(const Cd & d);
};

#endif
