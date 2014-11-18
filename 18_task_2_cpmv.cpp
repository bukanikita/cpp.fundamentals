#include "18_task_2_cpmv.h"

Cpmv::Cpmv()
{
	cout << "Default constructor of " << this << ".\n";
	pi = new Info;
	pi->qcode = "";
	pi->zcode = "";
	Display();
}

Cpmv::Cpmv(std::string q, std::string z)
{
	cout << "Constructor with string objects of " << this << ".\n";
	pi = new Info;
	pi->qcode = q;
	pi->zcode = z;
	Display();
}

Cpmv::Cpmv(const Cpmv & cp)
{
	cout << "Copy constructor of " << this << ". Called with " << &cp << " object" << ".\n";
	pi = new Info;
	pi->qcode = cp.pi->qcode;
	pi->zcode = cp.pi->zcode;
	Display();
}

Cpmv::Cpmv(Cpmv && mv)
{
	cout << "Move constructor of " << this << ". Called with " << &mv << " object" << ".\n";
	pi = mv.pi;
	mv.pi = nullptr;
	Display();
}

Cpmv::~Cpmv()
{
	cout << "Destructor of " << this << ".\n";
	Display();
	delete pi;
}

Cpmv & Cpmv::operator=(const Cpmv & cp)
{
	cout << "Assign copy operation of " << this << ". Called with " << &cp << " object" << ".\n";
	Display();
	if (this == &cp)
	{
		return *this;
	}
	delete pi;
	pi = new Info;
	pi->qcode = cp.pi->qcode;
	pi->zcode = cp.pi->zcode;	
	return *this;
}

Cpmv & Cpmv::operator=(Cpmv && mv)
{
	cout << "Assign move operation of " << this << ". Called with " << &mv << " object" << ".\n";
	Display();
	if (this == &mv)
	{
		return *this;
	}
	delete pi;
	pi = new Info;
	pi = mv.pi;
	mv.pi = nullptr;	
	return *this;
}

Cpmv Cpmv::operator+(const Cpmv & obj) const
{
	cout << "Operator+ of " << this << ". Called with " << &obj << " object" << ".\n";
	Display();
	return Cpmv(pi->qcode + obj.pi->qcode, pi->zcode + obj.pi->zcode);
}

void Cpmv::Display() const
{
	if (pi != nullptr)
	{
		cout << "qcode: " << pi->qcode << endl
			<< "zcode: " << pi->zcode << endl;
	}
	else
	{
		cout << "nullptr in pi.\n";
	}
}
