#include "13_task_4_vintageport.h"

int main()
{
	const int STYLE_LENGTH = 20;
	int bottles_count;
	Port **port_bottles;
	string temp_brand;
	char kind;
	int temp_bottles;
	char temp_style[STYLE_LENGTH];
	cout << "Please, enter number of bottles of port: ";
	while (!(cin >> bottles_count) && cin.fail())
	{
		wrong_input();		
	}
	cin.get();
	port_bottles = new Port * [bottles_count];

	for (int i = 0; i < bottles_count; ++i)
	{
		cout << "Enter brand of port: ";
		getline(cin,temp_brand);
		cout << "Enter style of port: ";
		cin.getline(temp_style, STYLE_LENGTH);
		cout << "Enter bottles of port: ";
		while (!(cin >> temp_bottles) && cin.fail())
		{
			wrong_input();		
		}
		cout << "Enter 1 for usual port and 2 vintage port: ";
		while (cin >> kind && (kind != '1' && kind != '2'))
			cout <<"Enter either 1, 2: ";
		if (kind == '1')
		{
			port_bottles[i] = new Port(temp_brand.c_str(), temp_style, temp_bottles);
			while (cin.get() != '\n')
				continue;
		}
		else
		{
			cin.get();
			std::string temp_nickname;
			int temp_year;
			cout << "Enter port nickname style: ";
			getline(cin, temp_nickname);
			cout << "Enter port year: ";
			while (!(cin >> temp_year) && cin.fail())
			{
				wrong_input();		
			}
			port_bottles[i] = new VintagePort(temp_brand.c_str(), temp_style, temp_bottles, temp_nickname.c_str(), temp_year);
			cin.get();
		}
	}

	cout << "Show every port in two ways: \n";
	for (int i = 0; i < bottles_count; ++i)
	{
		port_bottles[i]->Show();
		try
		{
			cout << dynamic_cast<const VintagePort &> (*port_bottles[i]) << endl;
		}
		catch (std::bad_cast)
		{
			cout <<*port_bottles[i] << endl;
		}
	}

	cout << "Add to every port 1 bottle:\n";
	for (int i = 0; i < bottles_count; ++i)
	{
		*port_bottles[i] += 1;
		try
		{
			cout << dynamic_cast<const VintagePort &> (*port_bottles[i]) << endl;
		}
		catch (std::bad_cast)
		{
			cout <<*port_bottles[i] << endl;
		}
	}

	cout << "Getting from every port 10 bottle:\n";
	for (int i = 0; i < bottles_count; ++i)
	{
		*port_bottles[i] -= 10;
		try
		{
			cout << dynamic_cast<const VintagePort &> (*port_bottles[i]) << endl;
		}
		catch (std::bad_cast)
		{
			cout <<*port_bottles[i] << endl;
		}
	}

	cout << "Creating default and non-default VintagePort object: \n";
	VintagePort default_vintage_port, nondefault_vintage_port("NON DEF BRAND", "NON DEF STYLE", 20, "NON DEF NICK", 1903);
	default_vintage_port.Show();
	nondefault_vintage_port.Show();
	cout << "Assign operation: \n";
	default_vintage_port = nondefault_vintage_port;
	default_vintage_port.Show();
	cout << default_vintage_port << endl;

	cout << "Copy constructor:\n";
	VintagePort copy_VintagePort(nondefault_vintage_port);

	copy_VintagePort.Show();


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