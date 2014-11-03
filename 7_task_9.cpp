#include <iostream>
using namespace std;

const int SLEN = 30;
struct student {
	char fullname[SLEN];
	char hobby[SLEN];
	int ooplevel;
};
void wrong_input();
// getinfo() has two arguments: a pointer to the first element of
// an array of student structures and an int representing the
// number of elements of the array. The function solicits and
// stores data about students. It terminates input upon filling
// the array or upon encountering a blank line for the student
// name. The function returns the actual number of array elements
// filled.
int getinfo(student pa[], int n);
// display1() takes a student structure as an argument
// and displays its contents
void display1(student st);
// display2() takes the addressof student structure as an
// argument and displays the structure's contents
void display2(const student * ps);
// display3() takes the address of the first element of an array
// of student structures and the number of array elements as
// arguments and displays the contents of the structures
void display3(const student pa[], int n);
int main()
{
	cout << "Enter class size: ";
	int class_size;
	cin >> class_size;
	while (cin.get() != '\n')
		continue;
	student * ptr_stu = new student[class_size];
	int entered = getinfo(ptr_stu, class_size);
	for (int i = 0; i < entered; i++)
	{
		display1(ptr_stu[i]);
		display2(&ptr_stu[i]);
	}
	display3(ptr_stu, entered);
	delete [] ptr_stu;
	cout << "Done\n";
	return 0;
}

void wrong_input()
{
	cout << "Wrong input. Please try again\n";
	cin.clear();
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');		
}

int getinfo(student pa[], int n)
{
	int i;
	cout << "Please, enter information about students (empty name for exit):\n";
	for (i = 0; i < n; ++i)
	{
		cout << "Please, enter name of " << (i+1) << " student: ";
		cin.getline(pa[i].fullname, SLEN);
		if (pa[i].fullname[0] == '\0')
		{
			break;
		}
		cout << "Please, enter hobby of " << (i+1) << " student: ";
		cin.getline(pa[i].hobby, SLEN);
		cout << "Please, enter ooplevel of " << (i+1) << " student: ";
		while (!(cin >> pa[i].ooplevel) && cin.fail())
		{
			wrong_input();		
		}
		cin.get();
	}
	return i;
}

void display1(student st)
{
	cout << "Information about student(way 1):\n";
	cout << st.fullname << endl << st.hobby << endl << st.ooplevel << endl;	
}

void display2(const student * ps)
{
	cout << "Information about student(way 2):\n";
	cout << ps->fullname << endl << ps->hobby << endl << ps->ooplevel << endl;	
}

void display3(const student pa[], int n)
{
	cout << "Information about student(way 3):\n";
	for (int i = 0; i < n; i++)
	{
		cout << "Student number " << i+1 << endl
			 << pa[i].fullname << endl 
			 << pa[i].hobby << endl 
			 << pa[i].ooplevel << endl;	
	}
}