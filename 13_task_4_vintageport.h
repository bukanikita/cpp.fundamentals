#ifndef _13_TASK_4_VINTAGEPORT_H_
#define _13_TASK_4_VINTAGEPORT_H_

#include "13_task_4_port.h"

class VintagePort : public Port // style necessarily = "vintage"
{
private:
	char * nickname; // i.e., "The Noble" or "Old Velvet", etc.
	int year; // vintage year
public:
	VintagePort();
	VintagePort(const char * br, const char * st, int b, const char * nn, int y);
	VintagePort(const VintagePort & vp);
	virtual ~VintagePort() { delete [] nickname; }
	VintagePort & operator=(const VintagePort & vp);

	virtual void Show() const;
	friend std::ostream & operator<<(std::ostream & os, const VintagePort & vp);
};

#endif