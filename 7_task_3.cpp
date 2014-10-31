#include <iostream>
#include <string>
#include <fstream>

using std::cout;
using std::cin;
using std::endl;

struct box
{
	char marker[40];
	float height;
	float width;
	float length;
	float volume;
};

void fill_volume(box *);
void show_box(box);
void wrong_input();

int main() 
{
	box data_box = {"MARKER", 3.0, 2.0, 4.0};

	fill_volume (&data_box);
	show_box(data_box);
	
	cin.get();
	cin.get();

	return 0;
}

void fill_volume(box *b)
{
	b->volume = b->height * b->width * b->length;
}

void show_box(box b)
{
	cout << "Marker: " << b.marker <<endl;
	cout << "Height: " << b.height <<endl;
	cout << "Width: " << b.width <<endl;
	cout << "Length: " << b.length <<endl;
	cout << "Volume: " << b.volume <<endl;
}