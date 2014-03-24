#ifndef GAMEOBJECT_HPP
#define GAMEOBJECT_HPP

#include <OOGL\oogl.hpp>
#include <fstream>
#include <memory>

class GameObject
{
private:
	const gl::Drawable* currentDraw;
public:
	void draw() const {currentDraw->draw();}
	void setDraw(const gl::Drawable& newDraw) {currentDraw = &newDraw;}
	virtual void update(float) = 0;
	virtual ~GameObject() {}
};
typedef std::unique_ptr<GameObject> objPtr;



//Game Object Behaviors
class Movable
{
public:
	virtual ~Movable() {};
protected:
	virtual void move(float) = 0;
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