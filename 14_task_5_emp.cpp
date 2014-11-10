#include "14_task_5_emp.h"

abstr_emp::abstr_emp() : fname ("No name"), lname ("No last name"), job("No job")
{
}

abstr_emp::abstr_emp(const std::string & fn, const std::string & ln,
					 const std::string & j) : fname (fn), lname (ln), job(j)
{
}

void abstr_emp::ShowAll() const
{
	cout << (*this) << "Job: " << job << endl;
}

void abstr_emp::SetAll()
{
	cout << "Name: ";
	std::getline(cin, fname);
	cout << "Last name: ";
	std::getline(cin, lname);
	cout << "Job: ";
	std::getline(cin, job);
}

std::ostream &operator<<(std::ostream & os, const abstr_emp & e)
{
	cout << "Name: " << e.fname << endl
		 << "Last name: " << e.lname << endl;
	return os;
}

abstr_emp::~abstr_emp()
{
}

employee::employee() : abstr_emp()
{
}

employee::employee(const std::string & fn, const std::string & ln, const std::string & j) : abstr_emp(fn, ln, j)
{
}

void employee::ShowAll() const
{
	abstr_emp::ShowAll();
}

void employee::SetAll()
{
	abstr_emp::SetAll();
}

manager::manager() : abstr_emp(), inchargeof(0)
{
}

manager::manager(const std::string & fn, const std::string & ln, const std::string & j, int ico) : abstr_emp(fn, ln, j), inchargeof(ico)
{
}

manager::manager(const abstr_emp & e, int ico) : abstr_emp(e), inchargeof(ico)
{
}

manager::manager(const manager & m) : abstr_emp(m)
{
	inchargeof = m.inchargeof;
}

void manager::ShowAll() const
{
	abstr_emp::ShowAll();
	cout << "In charge: " << InChargeOf() << endl;
}

void manager::SetAll()
{
	abstr_emp::SetAll();
	cout << "Enter in charge: ";
	cin >> InChargeOf();
}

fink::fink() : abstr_emp(), reportsto("No reports")
{
}

fink::fink(const std::string & fn, const std::string & ln, const std::string & j, const std::string & rpo) : abstr_emp(fn, ln, j), reportsto(rpo)
{
}

fink::fink(const abstr_emp & e, const std::string & rpo) : abstr_emp(e), reportsto(rpo)
{
}

fink::fink(const fink & e) : abstr_emp(e)
{
	reportsto = e.reportsto;
}

void fink::ShowAll() const
{
	abstr_emp::ShowAll();
	cout << "Reports to: " << ReportsTo() << endl;
}

void fink::SetAll()
{
	abstr_emp::SetAll();
	cout << "Enter to whom reports: ";
	cin >> ReportsTo();
}

highfink::highfink() : abstr_emp(), manager(), fink()
{
}

highfink::highfink(const std::string & fn, const std::string & ln,
				   const std::string & j, const std::string & rpo,
				   int ico) : abstr_emp(fn, ln, j), manager(fn, ln, j, ico), fink(fn, ln, j, rpo)
{
}

highfink::highfink(const abstr_emp & e, const std::string & rpo, int ico) : abstr_emp(e), manager(e, ico), fink(e, rpo)
{
}

highfink::highfink(const fink & f, int ico) : abstr_emp(f), manager(f, ico), fink(f)
{
}

highfink::highfink(const manager & m, const std::string & rpo) : abstr_emp(m), manager(m), fink(m, rpo)
{
}

highfink::highfink(const highfink & h) : abstr_emp(h), manager(h), fink(h)
{
}

void highfink::ShowAll() const
{
	abstr_emp::ShowAll();
	cout << "In charge: " << InChargeOf() << endl;
	cout << "Reports to: " << ReportsTo() << endl;
}

void highfink::SetAll()
{
	abstr_emp::SetAll();
	cout << "Enter in charge: ";
	cin >> InChargeOf();
	cout << "Enter to whom reports: ";
	cin >> ReportsTo();
}