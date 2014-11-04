#ifndef _10_TASK_6_MOVE_H_
#define _10_TASK_6_MOVE_H_

#include "10_task_6_includes.h"

class Move
{
private:
	double x;
	double y;
public:
	Move(double a = 0, double b = 0) : x(a), y(b) {}; // sets x, y to a, b
	void showmove() const { cout << "x = " << x << ", y = " << y << endl; }; // shows current x, y values
	Move add(const Move & m) const;
	// this function adds x of m to x of invoking object to get new x,
	// adds y of m to y of invoking object to get new y, creates a new
	// move object initialized to new x, y values and returns it
	void reset(double a = 0, double b = 0) { x = a; y = b; }; // resets x,y to a, b
	~Move() {};
};

#endif
