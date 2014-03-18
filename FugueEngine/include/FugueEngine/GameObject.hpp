#ifndef GAMEOBJECT_HPP
#define GAMEOBJECT_HPP

#include <OOGL\oogl.hpp>

class GameObject : public gl::Drawable
{
public:
	virtual void update(float) = 0;
	virtual ~GameObject() {}
};

#endif