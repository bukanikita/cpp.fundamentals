#include "14_task_4_pokerplayer.h"

PokerPlayer::PokerPlayer(const string &_name, const string &_surname) : Person(_name, _surname)
{
}

PokerPlayer::PokerPlayer(const Person &per) : Person(per)
{
}

void PokerPlayer::Show() const
{
	Person::Show();
	Data();
}

void PokerPlayer::Data() const
{
	cout << card;
}

void PokerPlayer::Set()
{
	cout << "Please, enter poker player ingormation:\n";
	Person::Set();
}