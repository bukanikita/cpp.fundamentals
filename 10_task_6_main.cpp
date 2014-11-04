#include "10_task_6_move.h"

int main()
{
	Move move_1, move_2(1), move_3(1,2);
	cout << "All three move objects:\n";
	move_1.showmove();
	move_2.showmove();
	move_3.showmove();
	cout << "Reset without arguments:\n";
	move_3.reset();
	move_3.showmove();
	cout << "Reset with arguments:\n";
	move_3.reset(3);
	move_2.reset(2, 4);
	move_2.showmove();
	move_3.showmove();
	move_3.reset(3,5);
	cout << "Add:\n";
	move_1 = move_2.add(move_3);
	move_1.showmove();

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