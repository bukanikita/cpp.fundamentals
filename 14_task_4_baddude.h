#ifndef _14_TASK_4_BADDUDE_H_
#define _14_TASK_4_BADDUDE_H_

#include "14_task_4_pokerplayer.h"
#include "14_task_4_gunslinger.h"

class BadDude : public PokerPlayer, public Gunslinger
{
protected:
	virtual void Get();
public:
	BadDude(const string &_name = "No name", const string &_surname = "No surname", double t = 0.0, int n = 0) :
		Person(_name, _surname), Gunslinger(_name, _surname, t, n), PokerPlayer(_name, _surname) {};
	BadDude(const Person &per, double t = 0.0, int n = 0) :
		Person(per), Gunslinger(per, t, n), PokerPlayer( per) {};
	BadDude(const Gunslinger &per) : 
		Person(per), Gunslinger(per), PokerPlayer( per) {};
	BadDude(const PokerPlayer &per, double t = 0.0, int n = 0):
		Person(per), Gunslinger(per, t, n), PokerPlayer(per) {};
	virtual ~BadDude() {};
	virtual void Show() const;
	Card Cdraw() const { return PokerPlayer::Draw(); };
	double Gdraw() const { return Gunslinger::Draw(); };
	virtual void Set();
};

#endif