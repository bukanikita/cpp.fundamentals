#include "12_task_6_queue.h"

const int MIN_PER_HR = 60;

bool newcustomer(double x); // is there a new customer?

int main()
{
	// setting things up
	std::srand(std::time(0));    //  random initializing of rand()

	cout << "Case Study: Bank of Heather Automatic Teller\n";
	cout << "Enter maximum size of queue: ";
	int qs;
	cin >> qs;
	Queue line_1(qs);         // line_1 queue holds up to qs people
	Queue line_2(qs);         // line_2 queue holds up to qs people

	cout << "Enter the number of simulation hours: ";
	int hours;              //  hours of simulation
	cin >> hours;
	// simulation will run 1 cycle per minute
	long cyclelimit = MIN_PER_HR * hours; // # of cycles

	//cout << "Enter the average number of customers per hour: ";
	double perhour = 0.0;         //  average # of arrival per hour
	//cin >> perhour;
	double min_per_cust;    //  average time between arrivals
//	min_per_cust = MIN_PER_HR / perhour;

	Item temp;              //  new customer data
	long turnaways = 0;     //  turned away by full queue
	long customers = 0;     //  joined the queue
	long served = 0;        //  served during the simulation
	long sum_line = 0;      //  cumulative line length
	int wait_time_1 = 0, wait_time_2 = 0;      //  time until autoteller is free
	long line_wait = 0;     //  cumulative time in line
	double average_waiting_time = 0.0; // average time of waiting

	// running the simulation
	do
	{
		Item temp;
		turnaways	= 0;			// turned away by full queue
		customers	= 0;			// joined the queue
		served		= 0;			// served during the simulation
		sum_line    = 0;			// cumulative line length
		wait_time_1	= 0;			// time until autoteller is free
		wait_time_2	= 0;			// time until autoteller is free
		line_wait	= 0;			// cumulative time in line

		perhour = std::rand() % MIN_PER_HR + 1;
		min_per_cust = MIN_PER_HR / perhour;

		for (int cycle = 0; cycle < cyclelimit; cycle++)
		{
			if (newcustomer(min_per_cust))  // have newcomer
			{
				if (line_1.isfull() && line_2.isfull())
					turnaways++;
				else
				{
					customers++;
					temp.set(cycle);    // cycle = time of arrival
					if (line_1.queuecount() > line_2.queuecount() )
					{
						line_2.enqueue(temp);	// add newcomer to line2 
					}
					else
					{
						line_1.enqueue(temp); // add newcomer to line11
					}
				}
			}
			if (wait_time_1 <= 0 && !line_1.isempty())
			{
				line_1.dequeue (temp);      // attend next customer
				wait_time_1 = temp.ptime(); // for wait_time minutes
				line_wait += cycle - temp.when();
				served++;
			}
			if (wait_time_1 > 0)
				wait_time_1--;

			if (wait_time_2 <= 0 && !line_2.isempty())
			{
				line_2.dequeue (temp);      // attend next customer
				wait_time_2 = temp.ptime(); // for wait_time minutes
				line_wait += cycle - temp.when();
				served++;
			}
			if (wait_time_2 > 0)
				wait_time_2--;
			sum_line += line_1.queuecount() + line_2.queuecount();
		}
		average_waiting_time = (double) line_wait / served;
		cout << "average_waiting_time: " << average_waiting_time << endl;
	}while(average_waiting_time != 1.0);

	// reporting results
	if (customers > 0)
	{
		cout << "customers accepted: " << customers << endl;
		cout << "  customers served: " << served << endl;
		cout << "         turnaways: " << turnaways << endl;
		cout << "         perhour: "   << perhour << endl;
		cout << "average queue size: ";
		cout.precision(2);
		cout.setf(ios_base::fixed, ios_base::floatfield);
		cout << (double) sum_line / cyclelimit << endl;
		cout << " average wait time: "
			<< (double) line_wait / served << " minutes\n";
	}
	else
		cout << "No customers!\n";
	cout << "Done!\n";
	cin.get();
	cin.get();
	return 0;
}

//  x = average time, in minutes, between customers
//  return value is true if customer shows up this minute
bool newcustomer(double x)
{
	return (std::rand() * x / RAND_MAX < 1); 
}


void wrong_input()
{
	cout << "Wrong input. Please try again\n";
	cin.clear();
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');		
}

