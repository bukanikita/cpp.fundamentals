#include "12_task_1_cow.h"

int main()
{
	Cow default_cow, not_default("Name 1", "Hobby 2", 0.0), copy_constructor_1 = not_default, copy_constructor_2(not_default),
		not_default_2("Name 2", "Hobby 2", 1.0);
	cout << "All created objects:\n";
	default_cow.ShowCow();
	not_default.ShowCow();
	copy_constructor_1.ShowCow();
	copy_constructor_2.ShowCow();
	not_default_2.ShowCow();

	cout << "not_default_2 = not_default_2:\n";
	not_default_2 = not_default_2;
	not_default_2.ShowCow();
	cout << "default_cow = not_default_2:\n";
	default_cow = not_default_2;
	default_cow.ShowCow();

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

