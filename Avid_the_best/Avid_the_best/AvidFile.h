#include "includes.h"

using std::wstring;

class AvidFile
{
private:
	typedef unsigned long long un_l_l;
	wstring all_info;
	wstring name;
	void get_info();
	void get_size(const HANDLE &);
	void get_date(const HANDLE &);
	void get_checksum();
public:
	explicit AvidFile(const wstring &);
	bool operator<(const AvidFile &)const;
	wstring Show() const { return (all_info + L"\n"); } ;
};