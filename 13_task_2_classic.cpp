#include "13_task_2_classic.h"

Classic::Classic() : Cd()
{
	desc = new char [1];
	desc[0] = '\0';
}

Classic::Classic(const char *_desc, char * s1, char * s2, int n, double x) : Cd(s1, s2, n, x)
{
	desc = new char [strlen(_desc) + 1];
	strcpy(desc, _desc);
}

Classic::Classic(const Classic & d) : Cd(d)
{
	desc = new char [strlen(d.desc) + 1];
	strcpy(desc, d.desc);
}

void Classic::Report() const
{
	Cd::Report();
	cout << "Description: " << desc << endl;;
}

Classic & Classic::operator=(const Classic & d)
{
	if (this == &d)
	{
		return *this;
	}
	Cd::operator=(d);
	delete [] desc;
	desc = new char [strlen(d.desc) + 1];
	strcpy(desc, d.desc);
	return *this;
}

Classic::~Classic()
{
	delete [] desc;
}