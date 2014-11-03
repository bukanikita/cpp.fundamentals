#include <iostream>
#include <string>
#include <fstream>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ifstream;

struct donations
{
	string name;
	double sum;

};

int main() 
{
	string file_name;
	ifstream file;
	int number_of_patrons;
	donations *data_of_donations;
	int i;
	bool flag = true;

	cout << "Please, enter path to file with information:\n";
	std::getline(cin, file_name);

	file.open(file_name.c_str());

	if (!file.is_open())
	{
		cout << "File can't be opened.\n";
		return 1;
	}
	try
	{
		if (!(file >> number_of_patrons))
		{
			cout << "Error in the first parameter in file.\n";
			return 2;
		}
		if (number_of_patrons < 0)
		{
			throw std::invalid_argument("Invalid number of patrons.\n");
		}
	}
	catch (const std::invalid_argument& e)
	{
		cout << e.what() << endl;
		return 3;
	}

	try 
	{
		data_of_donations = new donations [number_of_patrons];
	}
	catch (std::bad_alloc &e)
	{
		cout << e.what() << endl;
		return 4;
	}

	for (i = 0; i < number_of_patrons && flag; ++i)
	{
		file.get();
		std::getline (file, data_of_donations[i].name);
		flag = file.good();
		if (flag)
		{
			file >> data_of_donations[i].sum;
			flag = file.good();
		}
	}

	if (i != number_of_patrons)
	{
		cout << "Data in file is corrupted\n";
		return 5;
	}

	flag = true;

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
	
	delete [] data_of_donations;
	
	cin.get();
	cin.get();

	return 0;
}