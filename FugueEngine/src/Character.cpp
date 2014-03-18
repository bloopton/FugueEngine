#include <FugueEngine\Character.hpp>
#include <FugueEngine\Player.hpp>
#include <fstream>

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

Character::Direction Character::getDirection()
{
	if(direction == Movable::UP)		 return UP;
	else if(direction == Movable::DOWN)  return DOWN;
	else if(direction == Movable::RIGHT) return RIGHT; 
	else   return LEFT;
}

void Character::setDraw(std::array<gl::Animation, 4>& animation)
{
	gl::Animation* current = &animation[getDirection()];
	current->setPoint(position);
	currentDraw = current;
}


void Character::move(float, gl::Vec2f newDir)
{
	direction = newDir;
	position += direction * speed;

	setDraw(drawMove);
}

void Character::testCollision()
{

}

void Character::setCollision()
{

}