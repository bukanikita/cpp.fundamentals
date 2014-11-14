#include <iostream>
#include <fstream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::ofstream;
using std::string;
using std::ifstream;

int main(int argc, char *argv[])
{
	const int NUM_OF_FILES = 3;
	string filename;
	string temp_1, temp_2;
	ifstream file_input_1, file_input_2;
	ofstream file_output;
	
	cout << "Please,enter filenames of files (two input and one output):\n";
	std::getline(cin, filename);
	file_input_1.open(filename.c_str());
	std::getline(cin, filename);
	file_input_2.open(filename.c_str());
	std::getline(cin, filename);
	file_output.open(filename.c_str());

	if (!file_output.is_open() || !file_input_1.is_open() || !file_input_2.is_open())
	{
		std::cerr << "Can't open file(s).\n";
		exit(2);
	}

	while ((file_input_1.good() || file_input_1.eof() && !file_input_2.eof() ) && (file_input_2.good() || file_input_2.eof() && !file_input_1.eof() ))
	{
		temp_1 = temp_2 = "";

		if (file_input_1.good())
		{
			std::getline(file_input_1, temp_1);
		}

		if (file_input_2.good())
		{
			std::getline(file_input_2, temp_2);	
		}

		file_output << temp_1;

		if (file_input_1.peek() != EOF || file_input_2.peek() != EOF)
		{
			file_output << " ";
		}

		file_output << temp_2 << endl;
	}

	cout << "Done\n";

	std::cin.get();
	std::cin.get();
	return 0;
}