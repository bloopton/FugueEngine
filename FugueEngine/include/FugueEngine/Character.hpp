#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <FugueEngine\GameObject.hpp>
#include <fstream>
#include <memory>
#include <string>
#include <array>

class World;
class Character : public GameObject, public Movable, public Collidable, public Loadable
{
public:
	enum Direction { UP = 0, DOWN, RIGHT, LEFT };

protected:
	std::string name;
	gl::Vec2f position;
	Direction direction;
	float speed;

	virtual void move(float);
	gl::Vec2f getVec(Direction);
};


//Character Behaviors
class CanStand
{
public:
	virtual ~CanStand() {}
protected:
	std::array<gl::Animation, 4> drawStand;
	virtual void stand(float) = 0;
};

class CanWalk
{
public:
	virtual ~CanWalk() {}
protected:
	std::array<gl::Animation, 4> drawWalk;
	virtual void walk(float, Character::Direction) = 0;
};
#endif