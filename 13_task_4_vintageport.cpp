#include "13_task_4_vintageport.h"

VintagePort::VintagePort() : Port()
{
	nickname = new char [1];
	nickname[0] = '\0';
	year = 0;
}

VintagePort::VintagePort(const char * br, const char * st, int b, const char * nn, int y) : Port(br, st, b)
{
	nickname = new char [strlen(nn) + 1];
	strcpy(nickname, nn);
	year = y;
}

VintagePort::VintagePort(const VintagePort & vp) : Port(vp)
{
	nickname = new char [strlen(vp.nickname) + 1];
	strcpy(nickname, vp.nickname);
	year = vp.year;
}

VintagePort & VintagePort::operator=(const VintagePort & vp)
{
	if (this == &vp)
	{
		return *this;
	}
	delete [] nickname;
	Port::operator=(vp);
	nickname = new char [strlen(vp.nickname) + 1];
	strcpy(nickname, vp.nickname);
	year = vp.year;
	return *this;
}

void VintagePort::Show() const
{
	Port::Show();
	cout << "Nickname: " << nickname <<endl
		 << "Year: " << year << endl;
}

std::ostream & operator<<(std::ostream & os, const VintagePort & p)
{
	try 
	{
		os << dynamic_cast<const Port &> (p);
	}
	catch (std::bad_cast &e)
	{
		cout << e.what() << endl;
	}
	os << ", " << p.nickname << ", " << p.year;
	return os;
}