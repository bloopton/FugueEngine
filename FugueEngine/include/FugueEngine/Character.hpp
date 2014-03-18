#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <FugueEngine\GameObject.hpp>
#include <array>
#include <fstream>
#include <memory>
#include <string>

class World;
class Character : public GameObject, public Movable, public Collidable, public Loadable
{
public:
	static std::unique_ptr<Character> load(std::ifstream&);

protected:
	std::string name;
	gl::Vec2f position, direction;
	float speed;

	enum Direction { UP = 0, DOWN, RIGHT, LEFT };
	Direction getDirection();
	std::array<gl::Animation, 4> drawStill, drawMove;
	void setDraw(std::array<gl::Animation, 4>&);

	virtual void move(float, gl::Vec2f);
	virtual void testCollision();
	virtual void setCollision();
	virtual void setAnimations() = 0;
};

typedef std::unique_ptr<Character> chrPtr;
#endif