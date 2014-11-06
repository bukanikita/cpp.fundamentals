#ifndef _13_TASK_2_CLASSIC_H_
#define _13_TASK_2_CLASSIC_H_

#include "13_task_2_cd.h"

// child class
class Classic : public Cd // represents a Classic CD disk
{
private:
	char *desc;
public:
	Classic(const char *desc, char * s1, char * s2, int n, double x);
	Classic(const Classic & d);
	Classic();
	virtual ~Classic();
	virtual void Report() const; // reports all CD data
	Classic & operator=(const Classic & d);
};

#endif
