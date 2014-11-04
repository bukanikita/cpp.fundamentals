#include "10_task_2_person.h"

int main() 
{
	Person one; // use default constructor
	Person two("Smythecraft"); // use #2 with one default argument
	Person three("Dimwiddy", "Sam"); // use #2, no defaults
	one.Show();
	one.FormalShow();
	cout << endl;
	two.Show();
	two.FormalShow();
	cout << endl;
	three.Show();
	three.FormalShow();
	

	cin.get();
	cin.get();

	return 0;
}