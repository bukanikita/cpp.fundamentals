#include <iostream>
using namespace std;
#include <cstring> // for strlen(), strcpy()
struct stringy {
	char * str; // points to a string
	int ct; // length of string (not counting '\0')
};

// prototypes for set(), show(), and show() go here
void set(stringy &, const char*);
void show(const stringy & _str, int times = 1);
	void show(const char * _str, int times = 1);

int main()
{
	stringy beany;
	char testing[] = "Reality isn't what it used to be.";
	set(beany, testing); // first argument is a reference,
	// allocates space to hold copy of testing,
	// sets str member of beany to point to the
	// new block, copies testing to new block,
	// and sets ct member of beany
	show(beany); // prints member string once
	show(beany, 2); //prints member string twice
	testing[0] = 'D';
	testing[1] = 'u';
	show(testing); // prints testing string once
	show(testing, 3); // prints testing string thrice
	show("Done!");
	delete [] beany.str;
	return 0;
}

void set(stringy & _str, const char* str_to_fill)
{
	_str.ct = strlen(str_to_fill);
	_str.str = new char [_str.ct + 1];
	strncpy_s (_str.str, _str.ct + 1, str_to_fill, _str.ct + 1);
}

void show(const stringy & _str, int times)
{
	for (int i = 0; i < times; ++i)
	{
		cout << _str.str <<endl;
	}
}

void show(const char * _str, int times)
{
	for (int i = 0; i < times; ++i)
	{
		cout << _str <<endl;
	}
}