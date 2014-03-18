#ifndef BEHAVIORS_HPP
#define BEHAVIORS_HPP

#include <fstream>
#include <OOGL\oogl.hpp>


class Movable
{
public:
	static gl::Vec2f UP, DOWN, RIGHT, LEFT;
	virtual ~Movable() {};
protected:
	virtual void move(float, gl::Vec2f) = 0;
};

class Collidable
{
public:
	virtual ~Collidable() {};
protected:
	virtual void testCollision() = 0;
	virtual void setCollision() = 0;
};

class Loadable
{
public:
	virtual void load(std::ifstream&) = 0;
	virtual void save(std::ofstream&) = 0;
	virtual ~Loadable() {}
};


#endif