#include <iostream>
#include <fstream>

using std::cout;
using std::cin;
using std::endl;
using std::ofstream;

int main(int argc, char *argv[])
{
	ofstream file;
	char ch;
	if (argc != 2)
	{
		std::cerr << "The start of program is " << argv[0] << " filename.\n";
		exit(1);
	}

	file.open(argv[1]);

	if (!file.is_open())
	{
		std::cerr << "Can't open file.\n";
		exit(2);
	}

	do 
	{
		cin.get(ch);
		file << ch;
	} while (!cin.eof());

	std::cin.get();
	std::cin.get();
	return 0;
}