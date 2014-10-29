#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

struct CandyBar
{
	string name;
	float weight;
	int calories;
};

int main()
{
	CandyBar snack = {"Mocha Munch", 2.3f, 350};

	cout << "snack variable:\n" 
		 << "Name: " << snack.name << endl
		 << "Weight: " << snack.weight << endl
		 << "Calories: " << snack.calories << endl;

	cin.get();
	cin.get();

	return 0;
}