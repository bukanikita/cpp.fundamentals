#include "10_task_4_sales.h"

namespace SALES
{
	Sales::Sales()
	{
		double sum = 0.0;
		min = std::numeric_limits<double>::max();
		max = std::numeric_limits<double>::min();
		for (int i = 0; i < Sales::QUARTERS; ++i)
		{
			while (!(cin >> sales[i]) && cin.fail())
			{
				wrong_input();		
			}
			if (sales[i] > max)
			{
				max = sales[i];
			}
			if (sales[i] < min)
			{
				min = sales[i];
			}
			sum += sales[i];
		}
		average = sum / Sales::QUARTERS;
	}

	Sales::Sales(const double *ar, int n)
	{
		int to_copy = n < Sales::QUARTERS ? n : Sales::QUARTERS;
		if (n < QUARTERS)
		{
			min = 0.0;
			max = 0.0;
		}
		else
		{
			min = ar[0];
			max = ar[0];
		}
		double sum = 0.0;
		for (int i = 0; i < to_copy; ++i)
		{
			sales[i] = ar[i];
			if (ar[i] > max)
			{
				max = ar[i];
			}
			if (ar[i] < min)
			{
				min = ar[i];
			}
			sum += sales[i];
		}
		if (to_copy < Sales::QUARTERS)
		{
			memset(sales + to_copy, 0, (Sales::QUARTERS - to_copy)*sizeof(double));
		}
		average = sum / Sales::QUARTERS;
	}

	void Sales::ShowSales() const
	{
		cout << "Sales: ";
		for (int i = 0; i < Sales::QUARTERS; ++i)
		{
			cout << sales[i] << " ";
		}
		cout << endl;
		cout << "Min: " << min << endl
			 << "Max: " << max << endl
			 << "Average: " << average << endl;
	}
}