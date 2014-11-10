#ifndef _14_TASK_4_GUNSLINGER_H_
#define _14_TASK_4_GUNSLINGER_H_

#include "14_task_4_person.h"

class Gunslinger : public virtual Person
{
private:
	double time;
	int notches;
protected:
	virtual void Get();
	virtual void Data() const;
public:
	Gunslinger(const string &_name = "No name", const string &_surname = "No surname", double t = 0.0, int n = 0) : Person(_name, _surname), time (t), notches (n) {};
	Gunslinger(const Person &per, double t = 0.0, int n = 0) : Person(per), time (t), notches (n) {};
	virtual ~Gunslinger() {};
	virtual void Show() const;
	double Draw() const { return time; };
	virtual void Set();
};

#endif