#include "15_task_1_tv.h"

const int SIZE = 5;

int main()
{
	Tv s42;
	cout << "Initial settings for 42\" TV:\n";
	s42.settings();
	s42.onoff();
	s42.chanup();
	cout << "\nAdjusted settings for 42\" TV:\n";
	s42.settings();

	Remote grey;

	grey.set_chan(s42, 10);
	grey.volup(s42);
	grey.volup(s42);
	cout << "\n42\" settings after using remote:\n";
	s42.settings();

	Tv s58(Tv::On);
	s58.set_mode();
	grey.set_chan(s58,28);
	cout << "\n58\" settings:\n";
	s58.settings();

	cout << "\nRemote mode for 58\": \n";
	grey.show_rem_mode();

	s58.change_rem_mode(grey);
	cout << "\nRemote mode for 58\" after change mode: \n";
	grey.show_rem_mode();

	s58.onoff();
	s58.settings();
	s58.change_rem_mode(grey);
	cout << "\nRemote mode for 58\" after change mode (and Off state): \n";
	grey.show_rem_mode();
	
	cin.get();
	cin.get();

	return 0;
}

void wrong_input()
{
	cout << "Wrong input. Please try again\n";
	cin.clear();
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');		
}