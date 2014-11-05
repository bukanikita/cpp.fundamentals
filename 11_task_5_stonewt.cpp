#include "11_task_5_stonewt.h"

// construct Stonewt object from double value
Stonewt::Stonewt(double lbs, MODE _mode)
{
	pounds = lbs;
	mode = _mode;
	set_stone();
}

// construct Stonewt object from stone, double values
Stonewt::Stonewt(int stn, double lbs, MODE _mode)
{
	stone = stn;
	pds_left = lbs;
	mode = _mode;
	set_pounds();
}

Stonewt::Stonewt(MODE _mode)          // default constructor, wt = 0
{
	stone = pounds = pds_left = 0;
	mode = _mode;
}

Stonewt::~Stonewt()         // destructor
{
}

//convert weight to stone to store two variants of variables
void Stonewt::set_stone()
{
	stone = int (pounds) / Lbs_per_stn;    // integer division
	pds_left = int (pounds) % Lbs_per_stn + pounds - int(pounds);
}

//convert weight to pounds to store two variants of variables
inline void Stonewt::set_pounds()
{
	pounds =  stone * Lbs_per_stn +pds_left;
}

// Overloading showing operation
std::ostream & operator << (std::ostream &os, const Stonewt &st)
{
	if (st.mode == Stonewt::STONE)
	{
		os << st.stone << " stone, " << st.pds_left << " pounds\n";
	}
	else if (st.mode == Stonewt::POUNDS)
	{
		os << st.pounds << " pounds\n";
	}
	else
	{
		os << "Unknown data foramt!\n";
	}
	return os;
}

Stonewt operator + (const Stonewt & st_1, const Stonewt & st_2)
{
	return Stonewt(st_1.pounds + st_2.pounds);
}

Stonewt operator - (const Stonewt & st_1, const Stonewt & st_2)
{
	return Stonewt(st_1.pounds - st_2.pounds);
}

Stonewt operator * (const Stonewt & st_1, const Stonewt & st_2)
{
	return Stonewt(st_1.pounds * st_2.pounds);
}

