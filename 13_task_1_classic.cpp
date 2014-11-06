#include "13_task_1_classic.h"

Classic::Classic() : Cd()
{
	desc[0] = '\0';
}

Classic::Classic(const char *_desc, char * s1, char * s2, int n, double x) : Cd(s1, s2, n, x)
{
	strcpy(desc, _desc);
}

Classic::Classic(const Classic & d) : Cd(d)
{
	strcpy(desc, d.desc);
}

void Classic::Report() const
{
	Cd::Report();
	cout << "Description: " << desc << endl;;
};