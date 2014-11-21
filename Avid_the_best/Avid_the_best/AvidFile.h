#include "includes.h"

class AvidFile
{
private:
	CStringW all_info;
	CStringW name;
	void get_info();
public:
	explicit AvidFile(wchar_t *);
	bool operator<(const AvidFile &)const;
	CStringW Show() const { return all_info; } ;
};