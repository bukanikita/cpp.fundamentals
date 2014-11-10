#ifndef _14_TASK_4_PERSON_H_
#define _14_TASK_4_PERSON_H_

#include "14_task_4_includes.h"

class Person
{
private:
	string name;
	string surname;
public:
	Person(const string &_name = "No name", const string &_surname = "No surname") : name (_name), surname (_surname) {};
	virtual ~Person() = 0;
	virtual void Show() const = 0;
	virtual void Set();
};

#endif
