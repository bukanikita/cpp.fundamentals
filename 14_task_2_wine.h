#ifndef _14_TASK_2_WINE_H_
#define _14_TASK_2_WINE_H_

#include <valarray>
#include "14_task_2_includes.h"
#include "14_task_2_pair.h"

typedef std::valarray<int> ArrayInt;
typedef Pair<ArrayInt, ArrayInt> PairArray;

class Wine : PairArray, string
{
private:
	int years;
public:
	Wine();
	Wine(const char * l, int y, const int yr[], const int bot[]);
	Wine(const char * l, int y);
	void GetBottles();
	string & Label();
	int sum() { return PairArray::second().sum(); };
	void Show();
};

#endif
