// hangman.cpp -- some string methods
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <vector>
#include <fstream>
using std::string;
using std::vector;
using std::ifstream;

int main()
{
	using std::cout;
	using std::cin;
	using std::tolower;
	using std::endl;

	std::srand(std::time(0));

	string file_name;
	vector<string> wordlist;
	ifstream file;

	cout << "Please, enter path to file:\n";
	std::getline(cin, file_name);

	file.open(file_name.c_str());

	if (!file.is_open())
	{
		cout << "File can't be opened.\n";
		return 1;
	}

	std::copy(std::istream_iterator<string>(file), std::istream_iterator<string>(), std::back_inserter(wordlist));

	for (auto x : wordlist)
	{
		cout << x << endl;
	}
	cout << wordlist.size();
	
	char play;
	cout << "Will you play a word game? <y/n> ";
	cin >> play;
	play = tolower(play);
	while (play == 'y')
	{
		string target = wordlist[std::rand() % wordlist.size()];
		int length = target.length();
		string attempt(length, '-');
		string badchars;
		int guesses = 6;
		cout << "Guess my secret word. It has " << length
			<< " letters, and you guess\n"
			<< "one letter at a time. You get " << guesses
			<< " wrong guesses.\n";
		cout << "Your word: " << attempt << endl;
		while (guesses > 0 && attempt != target)
		{
			char letter;
			cout << "Guess a letter: ";
			cin >> letter;
			if (badchars.find(letter) != string::npos
				|| attempt.find(letter) != string::npos)
			{
				cout << "You already guessed that. Try again.\n";
				continue;
			}
			int loc = target.find(letter);
			if (loc == string::npos)
			{
				cout << "Oh, bad guess!\n";
				--guesses;
				badchars += letter; // add to string
			}
			else
			{
				cout << "Good guess!\n";
				attempt[loc]=letter;
				// check if letter appears again
				loc = target.find(letter, loc + 1);
				while (loc != string::npos)
				{
					attempt[loc]=letter;
					loc = target.find(letter, loc + 1);
				}
			}
			cout << "Your word: " << attempt << endl;
			if (attempt != target)
			{
				if (badchars.length() > 0)
					cout << "Bad choices: " << badchars << endl;
				cout << guesses << " bad guesses left\n";
			}
		}
		if (guesses > 0)
			cout << "That's right!\n";
		else
			cout << "Sorry, the word is " << target << ".\n";

		cout << "Will you play another? <y/n> ";
		cin >> play;
		play = tolower(play);
	}

	cout << "Bye\n";
	file.close();

	cin.get();
	cin.get();

	return 0; 
}
