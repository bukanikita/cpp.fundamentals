#ifndef _15_TASK_3_BADMEAN_H_
#define _15_TASK_3_BADMEAN_H_

#include "15_task_3_includes.h"
#include <stdexcept>

class abstr_mean : public std::logic_error
{
protected:
	double val_1;
	double val_2;
public:
	abstr_mean(const char *str, double _val_1, double _val_2) : std::logic_error(str), val_1 (_val_1), val_2 (_val_2) {};
	virtual const char* what() const = 0;
};

inline const char* abstr_mean::what() const 
{
	return std::logic_error::what(); 
}


class bad_hmean : public abstr_mean
{
public:
	bad_hmean(const char *str, double v_1, double v_2) : abstr_mean(str, v_1, v_2) {};
	virtual const char* what() const 
	{ 
		cout << "Arguments  are " << val_1 << " " << val_2 << endl;
		return abstr_mean::what(); 
	};
};

class bad_gmean : public abstr_mean
{
public:
	bad_gmean(const char *str, double v_1, double v_2) : abstr_mean(str, v_1, v_2) {};
	virtual const char* what() const 
	{ 
		cout << "Arguments  are " << val_1 << " " << val_2 << endl;
		return abstr_mean::what(); 
	};
};

#endif
