#include <FugueEngine\Character.hpp>
#include <FugueEngine\Player.hpp>
#include <fstream>


void Character::move(float deltaTime)
{
	gl::Vec2f distance = getVec(direction) * speed * deltaTime;
	position += distance;
	if(isCollision()) position -= distance;
}

gl::Vec2f Character::getVec(Direction dir)
{
	switch (dir)
	{
	case Character::UP:
		return gl::Vec2f(0, 1);
		break;
	case Character::DOWN:
		return gl::Vec2f(0, -1);
		break;
	case Character::RIGHT:
		return gl::Vec2f(1, 0);
		break;
	case Character::LEFT:
		return gl::Vec2f(-1, 0);
		break;
	default:
		return gl::Vec2f(0, 0);
		break;
	}
}