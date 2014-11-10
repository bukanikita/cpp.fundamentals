#include "14_task_4_baddude.h"

const int SIZE = 5;

int main()
{
	Person * people[SIZE];

	int ct;
	for (ct = 0; ct < SIZE; ct++)
	{
		char choice;
		cout << "Enter the employee category:\n"
			<< "g: guns linger  p: poker player  "
			<< "b: bad dude  q: quit\n";
		cin >> choice;
		while (strchr("gpbq", choice) == NULL)
		{
			cout << "Please enter a g, p, b, or q: ";
			cin >> choice;
		}
		if (choice == 'q')
			break;
		switch(choice)
		{
		case 'g':   people[ct] = new Gunslinger;
			break;
		case 'p':   people[ct] = new PokerPlayer;
			break;
		case 'b':   people[ct] = new BadDude;
			break;
		}
		cout << "After default constructor:\n";	
		people[ct]->Show();
		cout << "Let's set all fields:\n";
		cin.get();
		people[ct]->Set();
	}

	cout << "\nHere is your people:\n";
	int i;
	for (i = 0; i < ct; i++)
	{
		cout << endl;
		people[i]->Show();
		try
		{
			if (typeid(BadDude) == typeid(*people[i]))
			{
				cout << "Work of functions Cdraw and Gdraw:\n";
				cout << dynamic_cast<BadDude *> (people[i])->Cdraw() << endl;
				cout << dynamic_cast<BadDude *> (people[i])->Gdraw() << endl;
			}
			else if (typeid(PokerPlayer) == typeid(*people[i]))
			{
				cout << "Work of functions Draw:\n";
				cout << dynamic_cast<PokerPlayer *> (people[i])->Draw() << endl;
			}
			else
			{
				cout << "Work of functions Draw:\n";
				cout << dynamic_cast<Gunslinger *> (people[i])->Draw() << endl;
			}
		}
		catch(std::bad_cast &e)
		{
			cout << e.what() << endl;
		}
	}
	for (i = 0; i < ct; i++)
		delete people[i];
	cout << "Bye.\n";
	
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