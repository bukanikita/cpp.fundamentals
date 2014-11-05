#include "11_task_5_stonewt.h"

int main()
{
	Stonewt incognito = 275; // uses constructor to initialize
	Stonewt wolfe(285.7);    // same as Stonewt wolfe = 285.7;
	Stonewt taft(21, 8);

	cout << "The celebrity weighed " << incognito << endl;
	cout << "The detective weighed " << wolfe << endl;
	cout << "The President weighed " << taft << endl;
	cout << "incognito + taft " << incognito + taft << endl;
	cout << "incognito - taft " << incognito - taft << endl;
	cout << "incognito * taft " << incognito * taft << endl;
	std::cin.get();
	std::cin.get();
	return 0;
}