#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <time.h>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::list;

int main()
{
	int size = 100000;
	clock_t start, end;
	double vect_sort, list_sort, list_copy_1, list_copy_2;

	srand(time(NULL));
	vector<int> vi0(size);
	vector<int> vi(size);
	list<int> li(size);

	std::generate(vi0.begin(), vi0.end(), rand);
	copy(vi0.begin(), vi0.end(), li.begin());
	
	//list sort
	start = clock();
	li.sort();
	end = clock();
	list_sort = (double) (end - start) / CLOCKS_PER_SEC;

	//li not sorted
	copy(vi0.begin(), vi0.end(), li.begin());
	
	//copy list to vector
	start = clock();
	copy(li.begin(), li.end(), vi.begin());
	end = clock();
	list_copy_1 = (double) (end - start) / CLOCKS_PER_SEC;
	
	//vector sort
	start = clock();
	sort(vi.begin(), vi.end());
	end = clock();
	vect_sort = (double) (end - start) / CLOCKS_PER_SEC;

	//copy vector to list
	start = clock();
	copy(vi.begin(), vi.end(), li.begin());
	end = clock();
	list_copy_2 = (double) (end - start) / CLOCKS_PER_SEC;

	cout << "For " << size << " size:\n";
	cout << "Time for list sort " << list_sort << endl;
	cout << "Time copy list to vector " << list_copy_1 << endl;
	cout << "Time for vector sort " << vect_sort << endl;
	cout << "Time copy vector to list " << list_copy_2 << endl;
	cout << "Total time for sorting list with help of vector: " << list_copy_1 + vect_sort + list_copy_2 << endl;


	cin.get();
	cin.get();
	return 0;
}
