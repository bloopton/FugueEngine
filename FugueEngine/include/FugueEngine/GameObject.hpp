#ifndef GAMEOBJECT_HPP
#define GAMEOBJECT_HPP

#include <OOGL\oogl.hpp>
#include <fstream>
#include <memory>

class GameObject
{
private:
	const gl::Drawable* currentDraw;
protected:
	void setDraw(const gl::Drawable& newDraw) {currentDraw = &newDraw;}
public:
	void draw() const {currentDraw->draw();}
	virtual void update(float) = 0;
	virtual ~GameObject() {}

};
typedef std::unique_ptr<GameObject> objPtr;



//Game Object Behaviors
class Collidable
{
public:
	virtual ~Collidable() {};
protected:
	virtual void setCollision() = 0;
};

class Loadable
{
public:
	static objPtr load(std::ifstream&);
	virtual void save(std::ofstream&) const = 0;
	virtual ~Loadable() {}
protected:
	virtual void loadInternal(std::ifstream&) = 0;
	virtual void saveInternal(std::ofstream&) const = 0;
};

#endif