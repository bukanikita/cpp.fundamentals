#ifndef _11_TASK_6_STONEWT_H_
#define _11_TASK_6_STONEWT_H_

#include "11_task_6_includes.h"

class Stonewt
{
private:
	enum {Lbs_per_stn = 14};      // pounds per stone
	int stone;                    // whole stones
	double pds_left;              // fractional pounds
	double pounds;                // entire weight in pounds
public:
	Stonewt(double lbs);          // constructor for double pounds
	Stonewt(int stn, double lbs); // constructor for stone, lbs
	Stonewt();                    // default constructor
	~Stonewt();
	void show_lbs() const;        // show weight in pounds format
	void show_stn() const;        // show weight in stone format
	operator double() const { return pounds; }; // VS 2012 don't support explicit

	inline friend bool operator == (const Stonewt & st, double val) { return st.pounds == val; };
	inline friend bool operator != (const Stonewt & st, double val) { return st.pounds != val; };
	inline friend bool operator > (const Stonewt & st, double val) { return st.pounds > val; };
	inline friend bool operator < (const Stonewt & st, double val) { return !(st > val); };
	inline friend bool operator >= (const Stonewt & st, double val) { return (st > val || st == val); };
	inline friend bool operator <= (const Stonewt & st, double val) { return (st < val || st == val); };
};

#endif
