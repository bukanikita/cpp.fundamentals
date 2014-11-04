#ifndef _10_TASK_4_SALES_H_
#define _10_TASK_4_SALES_H_

#include "10_task_4_includes.h"

namespace SALES
{
	class Sales 
	{
	private:
		static const int QUARTERS = 4;
		double sales[QUARTERS];
		double average;
		double max; 
		double min; 

	public:
		Sales(); // default constructor
		Sales(const double *, int); // Constructor
		void ShowSales() const; // show class
		~Sales() {}; // Destructor
	};
}

#endif