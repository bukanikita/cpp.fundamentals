#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

vector<int> Lotto(int, int);

int main()
{
	vector<int> winners;
	winners = Lotto(51,6);

	std::copy(winners.begin(), winners.end(), std::ostream_iterator<int, char> (cout, " "));
	cout << endl;
	
	cin.get();
	cin.get();
	return 0;
}

vector<int> Lotto(int total, int to_choose)
{
	vector<int> temp;
	for (int i = 1; i < total; ++i)
	{
		temp.push_back(i);
	}
	std::copy(temp.begin(), temp.end(), std::ostream_iterator<int, char> (cout, " "));
	std::random_shuffle(temp.begin(), temp.end());
	std::copy(temp.begin(), temp.end(), std::ostream_iterator<int, char> (cout, " "));
	temp.erase(temp.begin() + to_choose, temp.end());
	return temp;
}
