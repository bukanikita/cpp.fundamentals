#include "13_task_2_cd.h"

Cd::Cd()
{
	performers = new char [1];
	label = new char [1];
	performers[0] = '\0';
	label[0] = '\0';
	selections = 0;
	playtime = 0.0;
}

Cd::Cd(char * s1, char * s2, int n, double x)
{
	performers = new char [strlen(s1) + 1];
	label = new char [strlen(s2) + 1];
	strcpy(performers, s1);
	strcpy(label, s2);
	selections = n;
	playtime = x;
}

Cd::Cd(const Cd & d)
{
	performers = new char [strlen(d.performers) + 1];
	label = new char [strlen(d.label) + 1];
	strcpy(performers, d.performers);
	strcpy(label, d.label);
	selections = d.selections;
	playtime = d.playtime;
}

void Cd::Report() const
{
	cout << "Performers: " << performers << endl
		 << "Label: " << label << endl
		 << "Selections: " << selections << endl
		 << "Playtime: " << playtime << endl;
}

Cd & Cd::operator=(const Cd & d)
{
	if (this == &d)
	{
		return *this;
	}
	delete [] performers;
	delete [] label;
	performers = new char [strlen(d.performers) + 1];
	label = new char [strlen(d.label) + 1];
	strcpy(performers, d.performers);
	strcpy(label, d.label);
	selections = d.selections;
	playtime = d.playtime;
	return *this;
}

Cd::~Cd()
{
	delete [] performers;
	delete [] label;
}