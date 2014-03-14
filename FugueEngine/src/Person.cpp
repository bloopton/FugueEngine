#include <FugueEngine\Person.hpp>


void Person::stand()
{
	action = STAND;
}


void Person::walk(float deltaTime, Direction dir)
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