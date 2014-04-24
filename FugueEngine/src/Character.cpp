#include <FugueEngine\Character.hpp>
#include <FugueEngine\Player.hpp>
#include <fstream>


void Character::loadInternal(std::ifstream& stream)
{
	stream >> name;
	stream >> position.x;
	stream >> position.y;
	int dir; stream >> dir; direction = (Direction)dir;
}

void Character::saveInternal(std::ofstream& stream) const
{
	stream << name << std::endl;
	stream << position.x << std::endl;
	stream << position.y << std::endl;
	stream << direction << std::endl;
}


void Character::move(float deltaTime, float speed, gl::Vec2f dir)
{
	position += dir * speed * deltaTime;
}


gl::Vec2f Character::getPosition()
{
	return position;
}

Character::Direction Character::getDirection()
{
	return direction;
}

void Character::setDirection(Direction newDir)
{
	direction = newDir;
}

gl::Vec2f Character::getDirectionVec()
{
	return getDirectionVec(direction);
}

gl::Vec2f Character::getDirectionVec(Direction dir)
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