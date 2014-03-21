#ifndef BEHAVIORS_HPP
#define BEHAVIORS_HPP

#include <FugueEngine\GameObject.hpp>
#include <OOGL\oogl.hpp>
#include <fstream>


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
	virtual bool isCollision() = 0;
	virtual void setCollision() = 0;
};

class Loadable
{
public:
	static objPtr load(std::ifstream&);
	virtual void save(std::ofstream&) const = 0;
	virtual ~Loadable() {}
};


#endif