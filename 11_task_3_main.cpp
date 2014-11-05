#include "11_task_3_vector.h"

int main()
{
	using VECTOR::Vector;
	srand(time(0)); // seed random-number generator
	double direction;
	Vector step;
	Vector result(0.0, 0.0);
	unsigned long steps = 0;
	double target;
	double dstep;

	unsigned int maxsteps, minsteps, totalsteps = 0;
	int i;
	int num_of_trials;

	cout << "How many trials do you want: ";
	while ((!(cin >> num_of_trials) && cin.fail()) || (num_of_trials <= 0))
	{
		wrong_input();		
	}

	for(i = 0; i < num_of_trials; i++) 
	{
		cout << "Enter target distance: ";

		cin >> target;
		cout << "Enter step length: ";
		if (!(cin >> dstep))
		{
			break;
		}
		while (result.magval() < target) 
		{
			direction = rand() % 360;
			step.reset(dstep, direction, Vector::POL);
			result = result + step;

			steps++;
		}
		result.polar_mode();

		totalsteps += steps;

		if (i == 0) 
		{
			minsteps = steps;
			maxsteps=steps;
		}
		if (minsteps > steps) 
		{
			minsteps = steps;
		}
		if (maxsteps < steps) 
		{
			maxsteps = steps;
		}

		steps = 0;
		result.reset(0.0, 0.0);
	}
	cout << endl << "Total steps: " << totalsteps << endl
		<< "Lowest steps: " << minsteps << endl
		<< "Highest steps: " << maxsteps << endl
		<< "Average steps: " << totalsteps / num_of_trials << endl
		<< endl << "Bye!" << endl;

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