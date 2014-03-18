#ifndef GAMEOBJECT_HPP
#define GAMEOBJECT_HPP

#include <FugueEngine/Behaviors.hpp>
#include <OOGL\oogl.hpp>

class GameObject : public gl::Drawable
{
protected:
	gl::Drawable* currentDraw;

public:
	virtual void draw() const {currentDraw->draw();}
	virtual void update(float) = 0;
	virtual ~GameObject() {}
};
#endif