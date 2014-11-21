#ifndef CLASS_FACTORY_H_
#define CLASS_FACTORY_H_

#include "includes.h"

class ClassFactory : public IClassFactory
{
private:
	long m_cRef; //number of created objects

protected:
	~ClassFactory();

public:
	ClassFactory();
	IFACEMETHODIMP QueryInterface(REFIID, void **); 
	IFACEMETHODIMP_(ULONG) AddRef();
	IFACEMETHODIMP_(ULONG) Release();
	IFACEMETHODIMP CreateInstance(IUnknown *, REFIID, void **);
	IFACEMETHODIMP LockServer(BOOL);
};

#endif