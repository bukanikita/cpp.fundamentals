#ifndef _13_TASK_3_DMA_H_
#define _13_TASK_3_DMA_H_

#include "13_task_3_includes.h"

class abstractDMA
{
private:
	char * label;
	int rating;
public:
	abstractDMA(const char * l = "null", int r = 0);
	abstractDMA(const abstractDMA & rs);
	virtual ~abstractDMA();
	abstractDMA & operator=(const abstractDMA & rs);
	virtual void View () const = 0;
};

//  Base Class Using DMA
class baseDMA : public abstractDMA
{
public:
	baseDMA(const char * l = "null", int r = 0) : abstractDMA(l, r) {};
	virtual void View () const;
	//friend std::ostream & operator<<(std::ostream & os, 
		//const baseDMA & rs);
};

// derived class without DMA
// no destructor needed
// uses implicit copy constructor
// uses implicit assignment operator
class lacksDMA :public abstractDMA
{
private:
	enum {COL_LEN = 40};
	char color[COL_LEN];
public:
	lacksDMA(const char * c = "blank", const char * l = "null",
		int r = 0);
	lacksDMA(const char * c, const abstractDMA & rs);
	virtual void View () const;
	//friend std::ostream & operator<<(std::ostream & os, 
		//const lacksDMA & rs);
};

// derived class with DMA
class hasDMA :public abstractDMA
{
private:
	char * style;
public:
	hasDMA(const char * s = "none", const char * l = "null",
		int r = 0);
	hasDMA(const char * s, const abstractDMA & rs);
	hasDMA(const hasDMA & hs);
	virtual ~hasDMA();
	hasDMA & operator=(const hasDMA & rs);  
	virtual void View () const;
	//friend std::ostream & operator<<(std::ostream & os, 
		//const hasDMA & rs);
};

#endif
