#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <iterator>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::ofstream;
using std::string;
using std::ifstream;
using std::set;

class Line
{
private:
	string lineData;
public:
	operator std::string() const
	{
		return lineData;
	}
	string & getLinedata() { return lineData; };
	friend std::istream & operator>>(std::istream &str,Line &data);
};

std::istream & operator>>(std::istream &is, Line &data)
{
	std::getline(is, data.getLinedata());
	return is;
}

int main(int argc, char *argv[])
{
	const string pat_file_name = "17_task_5_pat.dat", mat_file_name = "17_task_5_mat.dat", both_file_name = "17_task_5_matnpat.dat";
	set<string> mat_friends, pat_friends, both_friends;
	string name;
	string files_path;
	ifstream mat_file, pat_file;
	ofstream both_file;
	std::istream_iterator<Line> it_str;
	cout << "Please, enter path to mat.dat and pat.dat:\n";
	std::getline(cin,files_path);
	mat_file.open((files_path + mat_file_name).c_str());
	pat_file.open((files_path + pat_file_name).c_str());
	both_file.open((files_path + both_file_name).c_str());

	if (!mat_file.is_open() || !pat_file.is_open() || !both_file.is_open())
	{
		std::cerr << "Can't open file(s).\n";
		exit(1);
	}

	it_str = mat_file;
	
	std::copy(it_str, std::istream_iterator<Line>(), std::insert_iterator < set<string> > (mat_friends, mat_friends.begin()));

	cout << "Mat's friends:\n";
	std::copy(mat_friends.begin(), mat_friends.end(), std::ostream_iterator<string, char> (cout, "\n"));

	it_str = pat_file;

	std::copy(it_str, std::istream_iterator<Line>(), std::insert_iterator < set<string> > (pat_friends, pat_friends.begin()));

	cout << "Pat's friends:\n";
	std::copy(pat_friends.begin(), pat_friends.end(), std::ostream_iterator<string, char> (cout, "\n"));

	set_union(mat_friends.begin(), mat_friends.end(), pat_friends.begin(), pat_friends.end(), std::insert_iterator<set<string>>(both_friends, both_friends.begin()));

	std::copy(both_friends.begin(), both_friends.end(), std::ostream_iterator<string, char> (both_file, "\n"));
	cout << endl;

	std::cin.get();
	std::cin.get();
	return 0;
}