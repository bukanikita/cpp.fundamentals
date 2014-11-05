#include "11_task_7_complex.h"

int main()
{
	complex a(3.0, 4.0); // initialize to (3,4i) 
	complex c;
	cout << "Enter a complex number (q to quit):\n";
	while (cin >> c)
	{
		cout << "c is " << c << "\n";
		cout << "complex conjugate is " << ~c << "\n";
		cout << "a is " << a << "\n";
			cout << "a + c is " << a + c << "\n";
		cout << "a - c is " << a - c << "\n";
		cout << "a * c is " << a * c<< "\n";
		cout << "2 * c is " << 2 * c << "\n";
		cout << "Enter a complex number (q to quit):\n";
	}
	cout << "Done!\n";

	cin.get();
	cin.get();
	return 0;
}

void wrong_input()
{
	cout << "Wrong input. Please try again\n";
	cin.clear();
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');		
}

