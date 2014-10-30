#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

void wrong_input();

struct pizza
{
	string company_name;
	float diameter;
	float weight;
};

int main()
{
	pizza *Margarita = new pizza;

	cout << "Please, enter information about pizza.\nPlease, enter diameter of pizza: ";
	while (!(cin >> Margarita->diameter) && cin.fail())
	{
		wrong_input();		
	}
	cin.get();

	cout << "Please, enter name of company, which produces this pizza: ";
	std::getline(cin, Margarita->company_name);

	cout << "Please, enter weight of pizza: ";
	while (!(cin >> Margarita->weight) && cin.fail())
	{
		wrong_input();		
	}

	cout << "Information about pizza.\nName of company, which produce it: " << Margarita->company_name 
		 << "\nDiameter: "<< Margarita->diameter
		 << "\nWeight: "<< Margarita->weight << endl;

	delete Margarita;

	cin.get();
	cin.get();
}

void wrong_input()
{
	cout << "Wrong input. Please try again\n";
	cin.clear();
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');		
}
