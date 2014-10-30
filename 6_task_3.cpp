#include <iostream>
#include <cstring>

using std::cout;
using std::cin;
using std::endl;

int main() 
{
	char choice;
	cout << "Please enter one of the following choices:\n";
	cout << "c) carnivore\tp) pianist\n";
	cout << "t) tree\tg) game\n";
	while (!strchr("cptg",choice = cin.get()) )
	{
		cout << "Please enter a c, p, t, or g: ";
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	cout << "A maple is a ";
	switch (choice)
	{
	case 'c':
		cout << "carnivore.\n";
		break;
	case 'p':
		cout << "pianist.\n";
		break;
	case 't':
		cout << "tree.\n";
		break;
	case 'g':
		cout << "game.\n";
		break;
	default:
		cout << "TROUBLE!!!!!!!!!!!\n";
		break;
	}

	cin.get();
	cin.get();

	return 0;
}