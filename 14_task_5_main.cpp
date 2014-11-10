#include "14_task_5_emp.h"

const int SIZE = 5;

int main()
{
	employee em("Trip", "Harris", "Thumper");
	cout << em << endl;
	em.ShowAll();
	manager ma("Amorphia", "Spindragon", "Nuancer", 5);
	cout << ma << endl;
	ma.ShowAll();
	fink fi("Matt", "Oggs", "Oiler", "Juno Barr");
	cout << fi << endl;
	fi.ShowAll();
	highfink hf(ma, "Curly Kew"); // recruitment?
	hf.ShowAll();
	cout << "Press a key for next phase:\n";
	cin.get();
	highfink hf2;
	hf2.SetAll();
	cout << "Using an abstr_emp * pointer:\n";
	abstr_emp * tri[4] = {&em, &fi, &hf, &hf2};
	for (int i = 0; i < 4; i++)
		tri[i]->ShowAll();
	
	cin.get();
	cin.get();

	return 0;
}

void wrong_input()
{
	cout << "Wrong input. Please try again\n";
	cin.clear();
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');		
}