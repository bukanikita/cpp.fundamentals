#include <iostream>
#include <string>
#include <cstring>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main() 
{
	string one_word;
	string vowels = "aeiouy";
	std::size_t is_vowel;
	int number_of_vowels = 0, number_of_consonants = 0, number_of_other = 0;

	cout << "Enter words (to stop, type the word done): \n";

	do
	{
		cin >> one_word;
		if (isalpha(one_word[0]))
		{
			one_word[0] = tolower(one_word[0]);
			is_vowel = vowels.find(one_word[0]);
			if (is_vowel != std::string::npos)
			{
				number_of_vowels++;
			}
			else
			{
				number_of_consonants++;
			}
		}
		else
		{
			number_of_other++;
		}
	} while (one_word != "q");

	number_of_consonants--;

	cout << number_of_vowels << " words beginning with vowels" << endl;
	cout << number_of_consonants << " words beginning with consonants" << endl;
	cout << number_of_other << " others" << endl;

	cin.get();
	cin.get();

	return 0;
}