#include <iostream>

using std::cout;
using std::endl;

void first_phrase();
void second_phrase();

int main()
{
	first_phrase();
	first_phrase();
	second_phrase();
	second_phrase();
	return 0;
}

void first_phrase()
{
	cout << "Three blind mice" << endl;
}

void second_phrase()
{
	cout << "See how they run" << endl;
}
