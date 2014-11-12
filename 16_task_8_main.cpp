#include <iostream>
#include <set>
#include <iterator>
#include <algorithm>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::set;
using std::string;

int main()
{
	set<string> met_friends, pet_friends, both_friends;
	string name;
	cout << "Met, please insert your friend's name (quit for exit):\n";
	while (cin >> name && name != "quit")
	{
		met_friends.insert(name);
	}
	cout << "Met's friends:\n";
	std::copy(met_friends.begin(), met_friends.end(), std::ostream_iterator<string, char> (cout, "\n"));
	cout << endl;
	cout << "Pet, please insert your friend's name (quit for exit):\n";
	while (cin >> name && name != "quit")
	{
		pet_friends.insert(name);
	}
	cout << "Pet's friends:\n";
	std::copy(pet_friends.begin(), pet_friends.end(), std::ostream_iterator<string, char> (cout, "\n"));
	cout << endl;

	set_union(met_friends.begin(), met_friends.end(), pet_friends.begin(), pet_friends.end(), std::insert_iterator<set<string>>(both_friends, both_friends.begin()));

	cout << "Both friends:\n";
	std::copy(both_friends.begin(), both_friends.end(), std::ostream_iterator<string, char> (cout, "\n"));
	cout << endl;
	
	cin.get();
	cin.get();
	return 0;
}
