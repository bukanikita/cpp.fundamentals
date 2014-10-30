#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main() 
{
	string one_word;
	int number_of_words = 0;

	cout << "Enter words (to stop, type the word done): \n";

	do
	{
		cin >> one_word;
		number_of_words++;
	} while (one_word != "done");

	number_of_words--;

	cout << "You entered a total of " << number_of_words << " words." << endl;

	cin.get();
	cin.get();

	return 0;
}