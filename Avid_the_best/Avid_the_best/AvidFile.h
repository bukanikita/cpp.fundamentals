#ifndef AVID_FILE_H_
#define AVID_FILE_H_

#include "includes.h"

using std::wstring;

class FileProc;

class AvidFile
{
private:
	friend class FileProc; // use it, because get_info must be in private
	typedef unsigned long long un_l_l;

	bool ready; // if file is processed 
	wstring all_info;
	wstring name;

	void get_info(); // function, which start calculation of information
	void get_size(const HANDLE &); // function for getting size
	void get_date(const HANDLE &); // function for getting date
	void get_sum(); // function for getting per byte sum
public:
	explicit AvidFile(const wstring &);
	bool operator<(const AvidFile &)const; // needed for set container
	wstring Show() const { return (all_info + L"\n"); } ;
	bool isReady() const { return ready; };
};

#endif;