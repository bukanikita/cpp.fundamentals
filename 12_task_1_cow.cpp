#include "12_task_1_cow.h"

Cow::Cow()
{
	name[0] = '\0';
	hobby = new char [1];
	hobby[0] = '\0';
	weight = 0.0;
}

Cow::Cow(const char * nm, const char * ho, double wt)
{
	int len;
	strncpy_s(name,NAME_LENGTH,nm,NAME_LENGTH);	
	len = strlen(ho);
	hobby = new char [len + 1];
	strncpy_s(hobby,len + 1,ho,len + 1);
	weight = wt;
}

Cow::Cow(const Cow &c)
{
	int len;
	strncpy_s(name,NAME_LENGTH,c.name,NAME_LENGTH);	
	len = strlen(c.hobby);
	hobby = new char [len + 1];
	strncpy_s(hobby,len + 1,c.hobby,len + 1);
	weight = c.weight;
}

Cow::~Cow()
{
	delete [] hobby;
}

Cow & Cow::operator=(const Cow & c)
{
	if (this == &c)
	{
		return *this;
	}
	int len;
	strncpy_s(name,NAME_LENGTH,c.name,NAME_LENGTH);
	delete [] hobby;
	len = strlen(c.hobby) + 1;
	hobby = new char [len];
	strncpy_s(hobby,len,c.hobby,len);
	weight = c.weight;
	return *this;
}

void Cow::ShowCow() const
{
	cout << "Name: " << name << endl
		 << "Hobby: " << hobby << endl
		 << "Weight: " << weight << endl;
}