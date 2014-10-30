#include <iostream>
#include <cctype>

using std::cout;
using std::cin;
using std::endl;

int main() 
{
	cout << "Please, enter something:\n";
	char charcter;
	do
	{
		cin.get(charcter);
		if (isdigit(charcter))
		{
			continue;   
		}
		else if (isalpha(charcter))
		{
			if (islower(charcter)) 
			{
				charcter = toupper(charcter);
			} 
			else 
			{ 
				charcter = tolower(charcter);
			}
		}
		cout << charcter;
	}while (charcter != '@') ;

	cout << endl;

	cin.get();
	cin.get();

	return 0;
}