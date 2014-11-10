#ifndef _14_TASK_1_WINE_H_
#define _14_TASK_1_WINE_H_

#include <valarray>
#include "14_task_1_includes.h"
#include "14_task_1_pair.h"

class Wine
{
private:
	typedef std::valarray<int> ArrayInt;
	typedef Pair<ArrayInt, ArrayInt> PairArray;
	string name;
	//Pair<std::valarray<int>, std::valarray<int>> year_and_count;
	PairArray year_and_count;
	int years;
public:
	Wine();
	Wine(const char * l, int y, const int yr[], const int bot[]);
	Wine(const char * l, int y);
	void GetBottles();
	string & Label() { return name; };
	int sum() { return year_and_count.second().sum(); };
	void Show();
};

#endif
