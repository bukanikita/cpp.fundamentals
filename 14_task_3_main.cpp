#include "14_task_3_queuetp.h"
#include "14_task_3_worker.h"

int main()
{
	int queue_size;
	int ct;
	Worker * temp;
	cout << "Please, enter queue size: ";
	while (!(cin >> queue_size) && cin.fail())
	{
		wrong_input();		
	}

	QueueTp<Worker *> lolas(queue_size);

	for (ct = 0; ct < queue_size; ct++)
	{
		char choice;
		cout << "Enter the employee category:\n"
			<< "w: waiter  s: singer  "
			<< "t: singing waiter  q: quit\n";
		cin >> choice;
		while (strchr("wstq", choice) == NULL)
		{
			cout << "Please enter a w, s, t, or q: ";
			cin >> choice;
		}
		if (choice == 'q')
			break;
		switch(choice)
		{
		case 'w':   temp = new Waiter;
			break;
		case 's':   temp = new Singer;
			break;
		case 't':   temp = new SingingWaiter;
			break;
		default:	temp = new Waiter;
			break;
		}
		cin.get();
		temp->Set();
		lolas.enqueue(temp);
	}

	cout << "\nHere is your staff:\n";
	int i;
	for (i = 0; i < ct; i++)
	{
		cout << endl;
		lolas.dequeue(temp);
		temp->Show();
		delete temp;
	}
	cout << "Bye.\n";
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