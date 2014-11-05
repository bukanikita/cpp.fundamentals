#include "12_task_4_stack.h"

const int STKS = 4;

int main()
{
	int stack_size;
	cout << "Please, enter size of stack: ";
	while (!(cin >> stack_size) && cin.fail())
	{
		wrong_input();		
	}
	Stack st(stack_size), st_assign(1); // create an empty stack
	char ch;
	unsigned long po;
	cout << "Please enter A to add a purchase order,\n"
		<< "P to process a PO, or Q to quit.\n";
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
		case 'a': cout << "Enter a PO number to add: ";
			cin >> po;
			if (st.isfull())
				cout << "stack already full\n";
			else
				st.push(po);
			break;
		case 'P':
		case 'p': if (st.isempty())
					  cout << "stack already empty\n";
				  else {
					  st.pop(po);
					  cout << "PO #" << po << " popped\n";
				  }
				  break;
		}
		cout << "Please enter A to add a purchase order,\n"
			<< "P to process a PO, or Q to quit.\n";
	}
	cout << "Let's demonstrate copy constructor and assign operation.\n";
	cout << "Create new stack on base of old one:\n";
	Stack st_copy(st);
	while (st_copy.pop(po))
	{
		cout << po << " from st_copy" << endl;
	}
	cout << "Create to st_assign st:\n";
	st_assign = st;
	while (st_assign.pop(po))
	{
		cout << po << " from st_assign" << endl;
	}
	cout << "Bye\n";

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

