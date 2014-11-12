#ifndef _15_TASK_2_BADMEAN_H_
#define _15_TASK_2_BADMEAN_H_

#include "15_task_2_includes.h"
#include <stdexcept>

class bad_hmean : public std::logic_error
{
public:
	bad_hmean(const char *str) : std::logic_error(str) {};
	virtual const char* what() { return std::logic_error::what(); };
};

class bad_gmean : public std::logic_error
{
public:
	bad_gmean(const char *str) : std::logic_error(str) {};
	virtual const char* what() const { return std::logic_error::what(); };
};

#endif
