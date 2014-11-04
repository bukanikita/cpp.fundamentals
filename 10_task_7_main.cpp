#include "10_task_7_Plorg.h"

int main()
{
	Plorg def_plorg, not_def_plorg("Difficult name");
	cout << "Constructors: \n";
	def_plorg.showPlorg();
	not_def_plorg.showPlorg();
	cout << "Change CI:\n";
	def_plorg.changeCI(10);
	def_plorg.showPlorg();

	cin.get();
	cin.get();
	return 0; 
}

void wrong_input()
{
	std::cout << "Wrong input. Please try again\n";
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');		
}