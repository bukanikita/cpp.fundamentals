#include "17_task_6_emp.h"

int main(int argc, char *argv[])
{
	const int SIZE = 10;
	abstr_emp *emp_arr[SIZE];
	string filename;
	enum classkind{Employee, Manager, Fink, Highfink};
	int choice;
	int cur_emp = 0;

	cout << "Please,enter filename with data:\n";
	std::getline(cin, filename);

	ifstream fin;
	fin.open(filename.c_str());

	if (fin.is_open())
	{
		cout << "Here are the current contents of the "
			<< filename << " file:\n";
		while (!fin.eof())
		{
			fin >> choice;
			fin.get();
			switch (choice)
			{
			case Employee:
				emp_arr[cur_emp] = new employee;
				break;
			case Manager:
				emp_arr[cur_emp] = new manager;
				break;
			case Fink:
				emp_arr[cur_emp] = new fink;
				break;
			case Highfink:
				emp_arr[cur_emp] = new highfink;
				break;
			default:
				cout << "Wrong input, try again.\n";
				break;
			}
			emp_arr[cur_emp]->getall(fin);
			emp_arr[cur_emp]->ShowAll();
			++cur_emp;
		}

		fin.close();
	}


	ofstream fout(filename, std::ios_base::out | std::ios_base::app);
	
	if (!fout.is_open())
	{
		cerr << "Can't open " << filename << " file for output.\n";
		exit(EXIT_FAILURE);
	}

	cout << "Enter employee number (0 - employee, 1 - manager, 2 - fink, 3 - highfink, 4 - exit):\n";
	while (!(cin >> choice) && cin.fail())
	{
		wrong_input();		
	}

	while (choice != 4 && cur_emp < SIZE)
	{
		cin.get();
		switch (choice)
		{
		case Employee:
			emp_arr[cur_emp] = new employee;
			break;
		case Manager:
			emp_arr[cur_emp] = new manager;
			break;
		case Fink:
			emp_arr[cur_emp] = new fink;
			break;
		case Highfink:
			emp_arr[cur_emp] = new highfink;
			break;
		default:
			cout << "Wrong input, try again.\n";
			break;
		}
		if (choice >= Employee && choice <= Highfink)
		{
			if (cur_emp != 0)
			{
				fout << endl;
			}
			fout << choice << endl; // for type
			emp_arr[cur_emp]->SetAll();
			emp_arr[cur_emp]->writeall(fout);
			++cur_emp;
		}
		cout << "Enter employee number (0 - employee, 1 - manager, 2 - fink, 3 - highfink, 4 - exit):\n";
		while (!(cin >> choice) && cin.fail())
		{
			wrong_input();		
		}
	}
	fout.close();

	for (int i = 0; i < cur_emp; ++i)
	{
		delete emp_arr[i];
	}

	cur_emp = 0;

	// show revised file
	fin.clear();    // not required for some implementations, but won't hurt
	fin.open(filename);
	if (fin.is_open())
	{
		cout << "Here are the new contents of the "
			<< filename << " file:\n";
		while (!fin.eof())
		{
			fin >> choice;
			fin.get();
			switch (choice)
			{
			case Employee:
				emp_arr[cur_emp] = new employee;
				break;
			case Manager:
				emp_arr[cur_emp] = new manager;
				break;
			case Fink:
				emp_arr[cur_emp] = new fink;
				break;
			case Highfink:
				emp_arr[cur_emp] = new highfink;
				break;
			default:
				cout << "Wrong input, try again.\n";
				break;
			}
			emp_arr[cur_emp]->getall(fin);
			emp_arr[cur_emp]->ShowAll();
			++cur_emp;
		}
		fin.close();
	}
	cout << "Done.\n";

	for (int i = 0; i < cur_emp; ++i)
	{
		delete emp_arr[i];
	}

	std::cin.get();
	std::cin.get();
	return 0;
}

void wrong_input()
{
	std::cout << "Wrong input. Please try again\n";
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');		
}