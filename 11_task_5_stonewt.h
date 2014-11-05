#ifndef _11_TASK_5_STONEWT_H_
#define _11_TASK_5_STONEWT_H_

#include "11_task_5_includes.h"

class Stonewt
{
private:
	enum MODE {STONE, POUNDS};
	enum {Lbs_per_stn = 14};      // pounds per stone
	int stone;                    // whole stones
	double pds_left;              // fractional pounds
	double pounds;                // entire weight in pounds
	MODE mode;

	void set_stone();
	void set_pounds();
public:
	Stonewt(double lbs, MODE _mode = POUNDS);          // constructor for double pounds
	Stonewt(int stn, double lbs, MODE _mode = STONE); // constructor for stone, lbs
	Stonewt(MODE _mode = POUNDS);                    // default constructor
	~Stonewt();
	void stone_mode() {  mode = STONE; }; // set mode to stone
	void pounds_mode() {  mode = POUNDS; }; // set mode to stone

	friend std::ostream & operator << (std::ostream &, const Stonewt &);
	friend Stonewt operator + (const Stonewt &, const Stonewt &);
	friend Stonewt operator - (const Stonewt &, const Stonewt &);
	friend Stonewt operator * (const Stonewt &, const Stonewt &);
};

#endif
