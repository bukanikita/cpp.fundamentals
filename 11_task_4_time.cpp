#include "11_task_4_time.h"

Time::Time()
{
	hours = minutes = 0;
}

Time::Time(int h, int m )
{
	hours = h;
	minutes = m;
}

void Time::AddMin(int m)
{
	minutes += m;
	hours += minutes / 60;
	minutes %= 60;
}

void Time::AddHr(int h)
{
	hours += h;
}

void Time::Reset(int h, int m)
{
	hours = h;
	minutes = m;
}

Time operator+(const Time & t_1, const Time & t_2)
{
	Time sum;
	sum.minutes = t_1.minutes + t_2.minutes;
	sum.hours = t_1.hours + t_2.hours + sum.minutes / 60;
	sum.minutes %= 60;
	return sum;
}

Time operator-(const Time & t_1, const Time & t_2)
{
	Time diff;
	int tot1, tot2;
	tot1 = t_2.minutes + 60 * t_2.hours;
	tot2 = t_1.minutes + 60 * t_2.hours;
	diff.minutes = (tot2 - tot1) % 60;
	diff.hours = (tot2 - tot1) / 60;
	return diff;
}

Time operator*(const Time & t, double m)
{
	Time result;
	long totalminutes = t.hours * m * 60 + t.minutes * m;
	result.hours = totalminutes / 60;
	result.minutes = totalminutes % 60;
	return result;
}
std::ostream & operator<<(std::ostream & os, const Time & t)
{
	os << t.hours << " hours, " << t.minutes << " minutes";
	return os; 
}
