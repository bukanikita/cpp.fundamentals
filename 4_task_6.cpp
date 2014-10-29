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
	const int size = 3;
	CandyBar snack[size] = 
	{
		{"Mocha Munch", 2.3f, 350},
		{"Ptichie Moloko", 5.6f, 150},
		{"Trufel", 12.0f, 123}
	};
	int i;
	cout << "snack array:\n";
	for (i = 0; i < size; ++i)
	{
		cout << i << ":\n" 
			 << "Name: " << snack[i].name << endl
			 << "Weight: " << snack[i].weight << endl
			 << "Calories: " << snack[i].calories << endl;
	}

	cin.get();
	cin.get();

	return 0;
}