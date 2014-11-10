#include "14_task_4_card.h"

bool Card::was_init = false;

Card::Card()
{
	if (!was_init)
	{
		srand(time(0));
	}
	value = rand() % 52 + 1;
	suit = static_cast<SUIT> (rand() % 3);
}

std::ostream & operator<<(std::ostream &os, const Card &c)
{
	cout << "Value: " << c.value << endl;
	cout << "Suit: ";
	switch (c.suit)
	{
	case Card::SPADES:
		cout << "Spades";
		break;
	case Card::HEARTS:
		cout << "Hearts";
		break;
	case Card::CLUBS:
		cout << "Clubs";
		break;
	case Card::DIAMONDS:
		cout << "Diamonds";
		break;
	default:
		cout << "I don't know this suit.";
		break;
	}
	cout << endl;
	return os;
}