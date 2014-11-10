#ifndef _14_TASK_4_CARD_H_
#define _14_TASK_4_CARD_H_

#include "14_task_4_includes.h"
#include <cstdlib>
#include <ctime>

class Card
{
public:
	enum SUIT {SPADES, HEARTS, CLUBS, DIAMONDS};
private:
	static bool was_init;
	int value;
	SUIT suit;
public:
	explicit Card();
	virtual ~Card() {};
	friend std::ostream & operator<<(std::ostream &, const Card &);
};

#endif
