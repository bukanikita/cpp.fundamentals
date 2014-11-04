#include "10_task_3_golf.h"

int main() 
{
	int number_of_players;
	Golf * golf_players;
	int i = 1;

	cout << "Please, enter number of players: ";
	while ((!(cin >> number_of_players) && cin.fail()) || (number_of_players <= 0))
	{
		wrong_input();
	}

	golf_players = new Golf [number_of_players];

	for (int j = 0; j < number_of_players; ++j)
	{
		cout << "Information before handicap()\n"; 
		golf_players[j].Show();
		golf_players[j].Handicap(j);
		cout << "Information after handicap()\n"; 
		golf_players[j].Show();
	}

	delete [] golf_players;

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