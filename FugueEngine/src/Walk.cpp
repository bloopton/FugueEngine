#include <FugueEngine\Walk.hpp>


void Walk::stand()
{
	action = STAND;
}


void Walk::walk(float deltaTime, Direction dir)
{
	action = WALK;
	Direction prevDir = (Direction)direction;
	direction = dir;
	if(isColision())
	{
		if(prevDir == RIGHT)
		{
			direction = LEFT;
			move(deltaTime);
			direction = RIGHT;
		}
		else
		{
			direction = RIGHT;
			move(deltaTime);
			direction = LEFT;
		}
	}
	else
		move(deltaTime);
}