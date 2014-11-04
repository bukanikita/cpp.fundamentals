#include "10_task_8_list.h"

int main()
{
	int num_of_elements;
	int number;
	string choice;
	cout << "Please, enter number of elements in int's list: ";
	while (!(cin >> num_of_elements) && cin.fail())
	{
		wrong_input();
	}
	cin.get();

	List<int> list(num_of_elements);

	do
	{
		cout << "Please, enter the action. Possible: add, show, add_to_every (add 1 to every element).\n";
		getline(cin, choice);
		if (choice == "add")
		{
			cout << "Please, enter element: ";
			while (!(cin >> number) && cin.fail())
			{
				wrong_input();
			}
			list.push_back(number);
			cin.get();
		}
		else if (choice == "show")
		{
			list.visit(show);
			cout << endl;
		}
		else if (choice == "add_to_every")
		{
			list.visit(add);
		}
		else if (choice != "quit")
		{
			cout << "Bad choice, try again.\n";
		}
	}while(choice != "quit");

	cin.get();
	cin.get();
	return 0; 
}

void wrong_input()
{
	std::cout << "Wrong input. Please try again\n";
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');		
}

void show(int &el)
{
	cout << el << " ";
}

void add(int &el)
{
	el++;
}