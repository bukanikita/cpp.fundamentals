#include "sales.h"
#include <cstring>

namespace SALES
{
	void setSales(Sales & s, const double ar[], int n)
	{
		int to_copy = n < QUARTERS ? n : QUARTERS;
		double sum = 0.0;
		if (n < QUARTERS)
		{
			s.min = 0.0;
			s.max = 0.0;
		}
		else
		{
			s.min = ar[0];
			s.max = ar[0];
		}
		for (int i = 0; i < to_copy; ++i)
		{
			s.sales[i] = ar[i];
			if (ar[i] > s.max)
			{
				s.max = ar[i];
			}
			if (ar[i] < s.min)
			{
				s.min = ar[i];
			}
			sum += s.sales[i];
		}
		if (to_copy < QUARTERS)
		{
			memset(s.sales + to_copy, 0, (QUARTERS - to_copy)*sizeof(double));
		}
		s.average = sum / QUARTERS;
	}

	void setSales(Sales & s)
	{
		double sum = 0.0;
		s.min = std::numeric_limits<double>::max();
		s.max = std::numeric_limits<double>::min();
		for (int i = 0; i < QUARTERS; ++i)
		{
			while (!(cin >> s.sales[i]) && cin.fail())
			{
				wrong_input();		
			}
			if (s.sales[i] > s.max)
			{
				s.max = s.sales[i];
			}
			if (s.sales[i] < s.min)
			{
				s.min = s.sales[i];
			}
			sum += s.sales[i];
		}
		s.average = sum / QUARTERS;
	}

	void showSales(const Sales & s)
	{
		cout << "Sales: ";
		for (int i = 0; i < QUARTERS; ++i)
		{
			cout << s.sales[i] << " ";
		}
		cout << endl;
		cout << "Min: " << s.min << endl
			 << "Max: " << s.max << endl
			 << "Average: " << s.average << endl;
	}

	void wrong_input()
	{
		cout << "Wrong input. Please try again\n";
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');		
	}
}