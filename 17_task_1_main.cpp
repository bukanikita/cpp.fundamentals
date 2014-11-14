#include <iostream>

int main()
{
	char ch;
	int count = 0;
	do 
	{
		std::cin.get(ch);
		++count;
	} while (std::cin.peek() != '$');

	std::cout << "Number of entered symbols: " << count << std::endl;

	std::cin.get();
	std::cin.get();
	return 0;
}