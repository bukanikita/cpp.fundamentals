#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

struct CandyBar
{
	string name;
	double weight;
	int calories;
};

void fill_candy(CandyBar &, const char * _name = "Millenium Munch", double _weight = 2.85, int _calories = 350);
void show_candy(const CandyBar &);

int main() 
{
	const int size = 4;
	CandyBar cbArr[size];

	fill_candy(cbArr[0]);
	fill_candy(cbArr[1], "Name of candyBar 1");
	fill_candy(cbArr[2], "Name of candyBar 2", 1.5);
	fill_candy(cbArr[3], "Name of candyBar 3", 1.5, 150);

	for (int i = 0; i < size; ++i)
	{
		show_candy(cbArr[i]);
	}

	cin.get();
	cin.get();

	return 0;
}

void fill_candy(CandyBar & cb, const char * _name, double _weight, int _calories)
{
	cb.name = _name;
	cb.weight = _weight;
	cb.calories = _calories;
}

void show_candy(const CandyBar & cb)
{
	cout << "Information about CandyBar:\n";
	cout << "Name: " << cb.name << endl
		 << "Weight: " << cb.weight << endl
		 << "Calories: " << cb.calories << endl;
}