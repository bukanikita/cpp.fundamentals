#include <iostream>
#include <fstream>

using std::cout;
using std::cin;
using std::endl;
using std::ofstream;
using std::ifstream;

int main(int argc, char *argv[])
{
	ifstream file_input;
	ofstream file_output;
	char ch;
	if (argc != 3)
	{
		std::cerr << "The start of program is " << argv[0] << " filename_output filename_input.\n";
		exit(1);
	}

	file_output.open(argv[1]);
	file_input.open(argv[2]);

	if (!file_output.is_open() || !file_input.is_open())
	{
		std::cerr << "Can't open file(s).\n";
		exit(2);
	}

	while (file_input.good() && file_input.peek() != EOF)
	{
		file_input.get(ch);
		file_output << ch;
	}

	cout << "Done\n";

	std::cin.get();
	std::cin.get();
	return 0;
}