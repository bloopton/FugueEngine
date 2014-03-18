#ifndef WALK_HPP
#define WALK_HPP

#include "Character.hpp"

class Walk : public Character
{
protected:
	static const int STAND = 0;
	static const int WALK = 1;

	virtual bool isColision() = 0;
	virtual void walk(float, Direction);
	virtual void stand();
};
#endif