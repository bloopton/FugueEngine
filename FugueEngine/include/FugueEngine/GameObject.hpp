#ifndef GAMEOBJECT_HPP
#define GAMEOBJECT_HPP

#include <OOGL\oogl.hpp>
#include <memory>

class GameObject : public gl::Drawable
{
protected:
	gl::Drawable* currentDraw;

public:
	virtual void draw() const {currentDraw->draw();}
	virtual void update(float) = 0;
	virtual ~GameObject() {}
};
typedef std::unique_ptr<GameObject> objPtr;
#endif