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
	CandyBar *snack = new CandyBar [size];

	snack[0].name = "Mocha Munch";
	snack[0].weight= 2.3f;
	snack[0].calories = 350;

	snack[1].name = "Ptichie Moloko";
	snack[1].weight= 5.6f;
	snack[1].calories = 150;

	snack[2].name = "Trufel";
	snack[2].weight= 12.0f;
	snack[2].calories = 123;

	int i;
	cout << "snack array:\n";
	for (i = 0; i < size; ++i)
	{
		cout << i << ":\n" 
			<< "Name: " << snack[i].name << endl
			<< "Weight: " << snack[i].weight << endl
			<< "Calories: " << snack[i].calories << endl;
	}
	
	delete [] snack;

	cin.get();
	cin.get();

	return 0;
}