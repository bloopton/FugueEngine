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


void Character::move(float, gl::Vec2f newDir)
{
	direction = newDir;
	position += direction * speed;

	setDraw(drawMove);
}

void Character::testCollision(const gl::VertexArray&)
{

}

void Character::setCollision(const gl::VertexArray&)
{

}