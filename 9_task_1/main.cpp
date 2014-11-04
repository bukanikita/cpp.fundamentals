#include "golf.h"

int main() 
{
	int number_of_players;
	golf * golf_players;
	int i = 1;

	cout << "Please, enter number of players: ";
	while ((!(cin >> number_of_players) && cin.fail()) || (number_of_players <= 0))
	{
		wrong_input();
	}

	golf_players = new golf [number_of_players];

	setgolf(golf_players[0], "Player 1", 12);

	while (i < number_of_players && setgolf(golf_players[i]))
	{
		++i;
	}

	for (int j = 0; j < i; ++j)
	{
		cout << "Information before handicap()\n"; 
		showgolf(golf_players[j]);
		handicap(golf_players[j], j);
		cout << "Information after handicap()\n"; 
		showgolf(golf_players[j]);
	}

	delete [] golf_players;

	cin.get();
	cin.get();

	return 0;
}