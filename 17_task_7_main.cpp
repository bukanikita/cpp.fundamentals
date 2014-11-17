#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>

inline void ShowStr(const std::string &s) {std::cout << s << std::endl;};

class Store
{
private:
	std::ofstream & fout;
public:
	Store(std::ofstream &_fout) : fout(_fout) {};
	void operator()(const std::string &s)
	{
		size_t len = s.size();
		fout.write((char *)&len, sizeof(std::size_t)); // store length
		fout.write(s.data(), len); // store characters
	}
};

void GetStrs(std::ifstream &, std::vector<std::string> &);

int main()
{
	using namespace std;
	vector<string> vostr;
	string temp;
	// acquire strings
	cout << "Enter strings (empty line to quit):\n";
	while (getline(cin,temp) && temp[0] != '\0')
		vostr.push_back(temp);
	cout << "Here is your input.\n";
	for_each(vostr.begin(), vostr.end(), ShowStr);
	// store in a file
	ofstream fout("strings.dat", ios_base::out | ios_base::binary);
	for_each(vostr.begin(), vostr.end(), Store(fout));
	fout.close();
	// recover file contents
	vector<string> vistr;
	ifstream fin("strings.dat", ios_base::in | ios_base::binary);
	if (!fin.is_open())
	{
		cerr << "Could not open file for input.\n";

		exit(EXIT_FAILURE);
	}
	GetStrs(fin, vistr);
	cout << "\nHere are the strings read from the file:\n";
	for_each(vistr.begin(), vistr.end(), ShowStr);
	cin.get();
	cin.get();
	return 0;
}

void GetStrs(std::ifstream &fin, std::vector<std::string> &v)
{
	while (!fin.eof())
	{
		std::string temp;
		size_t len;
		fin.read((char *)&len, sizeof(std::size_t)); // store 
		temp.resize(len);
		fin.read(&temp[0], len);
		v.push_back(temp);
	}
}