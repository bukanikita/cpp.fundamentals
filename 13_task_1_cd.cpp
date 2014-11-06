#include "13_task_1_cd.h"

Cd::Cd()
{
	performers[0] = '\0';
	label[0] = '\0';
	selections = 0;
	playtime = 0.0;
}

Cd::Cd(char * s1, char * s2, int n, double x)
{
	strcpy(performers, s1);
	strcpy(label, s2);
	selections = n;
	playtime = x;
}

Cd::Cd(const Cd & d)
{
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
};