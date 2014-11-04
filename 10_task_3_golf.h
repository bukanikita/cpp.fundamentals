#ifndef _10_TASK_3_GOLF_H_
#define _10_TASK_3_GOLF_H_

#include "10_task_3_includes.h"

class Golf 
{
private:
	static const int LIMIT = 40;
	char fullname[LIMIT];
	int handicap; // Person's last name
	
public:
	Golf(); // default constructor
	Golf(const char *, int); // Constructor
	void Handicap(int); // change handicap
	void Show() const; // show class
	~Golf(); // Desstructor
};

#endif