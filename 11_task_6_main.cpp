#include "11_task_6_stonewt.h"

int main()
{
	const int stone_count = 6;
	Stonewt st_arr[stone_count] = {100.0, 200.0, 300.0};
	int i;
	int count_bigger = 0;
	double stone_val;
	double max, min;

	for (i = stone_count / 2; i < stone_count; ++i)
	{
		cout << "Please, enter stone value: ";
		while (!(cin >> stone_val) && cin.fail())
		{
			wrong_input();		
		}
		st_arr[i] = stone_val;
	}

	max = min = double(st_arr[0]);

	for (i = 0; i < stone_count; ++i)
	{
		if (max > double(st_arr[i]))
		{
			max = double(st_arr[i]);
		}
		if (min < double(st_arr[i]))
		{
			min = double(st_arr[i]);
		}
		if (st_arr[i] >= 11.0)
		{
			count_bigger++;
		}
	}

	cout << "Minimum: " << min << endl
		 << "Maximum: " << max << endl
		 << "Bigger than 11: " << count_bigger << endl;


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

