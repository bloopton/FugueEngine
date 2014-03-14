#ifndef PERSON_HPP
#define PERSON_HPP

#include "Character.hpp"

class Person : public Character
{
protected:
	static const int STAND = 0;
	static const int WALK = 1;

	virtual bool isColision() = 0;
	virtual void walk(float, Direction);
	virtual void stand();
};
#endif