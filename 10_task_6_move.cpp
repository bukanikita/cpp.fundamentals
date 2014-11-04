#include "10_task_6_move.h"

Move Move::add(const Move & m) const
{
	return Move (x + m.x, y + m.y); // creating and returning new object
}