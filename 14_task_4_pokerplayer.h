#ifndef _14_TASK_4_POCKERPLAYER_H_
#define _14_TASK_4_POCKERPLAYER_H_

#include "14_task_4_person.h"
#include "14_task_4_card.h"

class PokerPlayer : public virtual Person
{
private:
	Card card;
protected:
	virtual void Data() const;
public:
	PokerPlayer(const string &_name = "No name", const string &_surname = "No surname");
	PokerPlayer(const Person &per);
	virtual ~PokerPlayer() {};
	virtual void Show() const;
	Card Draw() const { return card; };
	virtual void Set();
};

#endif