#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

struct donations
{
	string name;
	double sum;

};

void wrong_input();

int main() 
{
	int number_of_patrons;
	donations *data_of_donations;
	int i;
	bool flag = true;

	cout << "Please, enter number of patrons: ";
	while (!(cin >> number_of_patrons) && cin.fail())
	{
		wrong_input();		
	}

	data_of_donations = new donations [number_of_patrons];

	for (i = 0; i < number_of_patrons; ++i)
	{	
		cin.get();
		cout << "Please, enter name of " << i+1 << " patron: ";
		std::getline(cin, data_of_donations[i].name);
		cout << "Please, enter sum of donations of " << i+1 << " patron: ";
		while (!(cin >> data_of_donations[i].sum) && cin.fail())
		{
			wrong_input();		
		}
	}
	cout << "Grand Patrons:\n";
	for (i = 0; i < number_of_patrons; ++i)
	{
		if (data_of_donations[i].sum >= 10000.0)
		{
			cout << "Name: " << data_of_donations[i].name << endl;
			cout << "Sum: " << data_of_donations[i].sum << endl;
			flag = false;
		}
	}
	if (flag)
	{
		cout << "none\n";
	}
	flag = true;
	cout << "Patrons:\n";
	for (i = 0; i < number_of_patrons; ++i)
	{
		if (data_of_donations[i].sum < 10000.0)
		{
			cout << "Name: " << data_of_donations[i].name << endl;
			cout << "Sum: " << data_of_donations[i].sum << endl;
			flag = false;
		}
	}
	if (flag)
	{
		cout << "none\n";
	}

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