#ifndef BEHAVIORS_HPP
#define BEHAVIORS_HPP

class Movable
{
protected:
	virtual void move(float) = 0;
	virtual ~Movable() {};
};

class Collidable
{
protected:
	virtual void testCollision() = 0;
	virtual void setCollision() = 0;
	virtual ~Collidable() {};
};

#endif