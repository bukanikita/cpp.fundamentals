#ifndef _15_TASK_1_TV_H_
#define _15_TASK_1_TV_H_

#include "15_task_1_includes.h"

class Tv
{
public:
	friend class Remote;   // Remote can access Tv private parts
	enum {Off, On};
	enum {MinVal,MaxVal = 20};
	enum {Antenna, Cable};
	enum {TV, DVD};

	Tv(int s = Off, int mc = 125) : state(s), volume(5),
		maxchannel(mc), channel(2), mode(Cable), input(TV) {}
	void onoff() {state = (state == On)? Off : On;}
	bool ison() const {return state == On;}
	bool volup();
	bool voldown();
	void chanup();
	void chandown();
	void set_mode() {mode = (mode == Antenna)? Cable : Antenna;}
	void set_input() {input = (input == TV)? DVD : TV;}
	void settings() const; // display all settings
	void change_rem_mode(Remote & rem);
private:
	int state;             // on or off
	int volume;            // assumed to be digitized
	int maxchannel;        // maximum number of channels
	int channel;           // current channel setting
	int mode;              // broadcast or cable
	int input;             // TV or DVD
};

class Remote
{
private:
	enum REM_MODE {NORM, INTER};
	int mode;              // controls TV or DVD
	REM_MODE rem_mode;
public:
	friend class Tv;   // Remote can access Tv private parts
	Remote(int m = Tv::TV, REM_MODE _rem_mode = NORM) : mode(m), rem_mode(_rem_mode) {}
	bool volup(Tv & t) { return t.volup();}
	bool voldown(Tv & t) { return t.voldown();}
	void onoff(Tv & t) { t.onoff(); }
	void chanup(Tv & t) {t.chanup();}
	void chandown(Tv & t) {t.chandown();}
	void set_chan(Tv & t, int c) {t.channel = c;}
	void set_mode(Tv & t) {t.set_mode();}
	void set_input(Tv & t) {t.set_input();}
	void show_rem_mode () const {cout << (rem_mode == NORM ? "Normal " : "Interactive") << "remote mode\n"; };
};
#endif
