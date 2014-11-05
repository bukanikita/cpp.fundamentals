#include "11_task_1_vector.h"

int main()
{
	using VECTOR::Vector;
	srand(time(0));     // seed random-number generator
	double direction;
	Vector step;
	Vector result(0.0, 0.0);
	unsigned long steps = 0;
	double target;
	double dstep;
	ofstream output_file;
	string file_name;
	cout << "Please, enter path to file for writing:\n";
	std::getline(cin, file_name);

	output_file.open(file_name.c_str());

	if (!output_file.is_open())
	{
		cout << "File can't be opened.\n";
		return 1;
	}

	cout << "Enter target distance (q to quit): ";
	while (cin >> target)
	{
		cout << "Enter step length: ";
		if (!(cin >> dstep))
			break;

		output_file << "Target Distance: " << target << ", Step Size: " << dstep << endl;

		while (result.magval() < target)
		{
			step.rect_mode();
			output_file << step << endl;
			direction = rand() % 360;
			step.magval();
			step.reset(dstep, direction, VECTOR::Vector::POL);
			result = result + step;
			steps++;
		}
		cout << "After " << steps << " steps, the subject "
			"has the following location:\n";
		cout << result << endl;
		// for file
		output_file << "After " << steps << " steps, the subject "
			"has the following location:\n";
		output_file << result << endl;
		result.polar_mode();
		cout << " or\n" << result << endl;
		cout << "Average outward distance per step = "
			<< result.magval()/steps << endl;
		// for file
		output_file << " or\n" << result << endl;
		output_file << "Average outward distance per step = "
			<< result.magval()/steps << endl;
		steps = 0;
		result.reset(0.0, 0.0);
		cout << "Enter target distance (q to quit): ";
	}
	cout << "Bye!\n";

	output_file.close();

	cin.get();
	cin.get();
	return 0; 
}