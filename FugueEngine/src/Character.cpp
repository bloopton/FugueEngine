#include <FugueEngine\Character.hpp>
#include <FugueEngine\Player.hpp>
#include <fstream>

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


void Character::move(float deltaTime, gl::Vec2f newDir)
{
	direction = newDir;
	gl::Vec2f distance = direction * speed * deltaTime;
	position += distance;
	if(isCollision()) position -= distance;

	setDraw(drawMove);
}