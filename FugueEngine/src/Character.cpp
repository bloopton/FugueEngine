#include <FugueEngine\Character.hpp>
#include <FugueEngine\Player.hpp>
#include <FugueEngine\World.hpp>
#include <FugueEngine\Segment.hpp>
#include <iostream>

chrPtr Character::load(std::ifstream& stream)
{
	if(stream.eof())
		return NULL;

	std::string type;
	stream >> type;

	if(type.compare("Player") == 0)
		return chrPtr(new Player(stream));

	else return NULL;
}


gl::Vec2f Character::getDirectionVec(int dir)
{
	switch (dir)
	{
	case UP:
		return gl::Vec2f(0,1);
		break;
	case DOWN:
		return gl::Vec2f(0, -1);
		break;
	case RIGHT:
		return gl::Vec2f(1, 0);
		break;
	case LEFT:
		return gl::Vec2f(-1, 0);
		break;
	default:
		return gl::Vec2f(0, 0);
	}
}


void Character::move(float deltaTime)
{
	position += speed * deltaTime * getDirectionVec(direction);

	if(isColision())
		position -= speed * deltaTime * getDirectionVec(direction);
}