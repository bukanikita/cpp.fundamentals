#ifndef _14_TASK_1_PAIR_H_
#define _14_TASK_1_PAIR_H_

#include "14_task_1_includes.h"

template <class T1, class T2>
class Pair
{
private:
	T1 a;
	T2 b;
public:
	T1 & first();
	T2 & second();
	T1 first() const { return a; }
	T2 second() const { return b; }
	Pair(const T1 & aval, const T2 & bval) : a(aval), b(bval) { }
	Pair() {}
};

template<class T1, class T2>
T1 & Pair<T1,T2>::first()
{
	return a;
}
template<class T1, class T2>
T2 & Pair<T1,T2>::second()
{
	return b;
}

#endif