#include "14_task_4_baddude.h"

void BadDude::Show() const
{
	Person::Show();
	PokerPlayer::Data();
	Gunslinger::Data();
}

void BadDude::Set()
{
	cout << "Please, enter bad dude ingormation:\n";
	Person::Set();
	Get();
}

void BadDude::Get()
{
	Gunslinger::Get();
}