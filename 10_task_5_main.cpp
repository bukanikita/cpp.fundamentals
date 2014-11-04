#include "10_task_5_stack.h"

int main()
{
	Stack st; // create an empty stack
	char ch;
	customer cust;
	double total = 0.0;
	cout << "Please enter A to add a purchase order,\n"
		<< "P to process a customer, or Q to quit.\n";
	while (cin >> ch && toupper(ch) != 'Q')
	{
		while (cin.get() != '\n')   
			continue;
		if (!isalpha(ch))
		{
			cout << '\a';
			continue;
		}
		switch(ch)
		{
		case 'A':
		case 'a': 
			if (st.isfull())
			{
				cout << "stack already full\n";
			}
			else
			{
				cout << "Enter a customer name to add: ";
				cin.getline(cust.fullname, NAME_LENGTH);
				cout << "Enter a payment for customer : ";
				while (!(cin >> cust.payment) && cin.fail())
				{
					wrong_input();		
				}
				st.push(cust);
			}
			break;
		case 'P':
		case 'p': 
			if (st.isempty())
			{
				cout << "stack already empty\n";
			}
			else 
			{
				st.pop(cust);
				cout << "Customer with name " << cust.fullname << " popped\n";
				total += cust.payment;
				cout << "Total for now: " << total <<endl;
			}
			break;
		}
		cout << "Please enter A to add a purchase order,\n"
			<< "P to process a customer, or Q to quit.\n";
	}
	cout << "Total: " << total << endl;
	cout << "Bye\n";
	return 0; 
}

void wrong_input()
{
	std::cout << "Wrong input. Please try again\n";
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');		
}