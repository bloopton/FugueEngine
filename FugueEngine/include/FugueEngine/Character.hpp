#ifndef CHARACTER_H
#define CHARACTER_H

#include <OOGL/oogl.hpp>
#include <memory>
#include <string>

class World;

class Character
{
public:
	enum Direction
	{
		UP = 0,
		DOWN,
		RIGHT,
		LEFT	
	};

	static World* worldRef;

	virtual ~Character() {};
	static std::unique_ptr<Character> load(const std::string&);
	virtual std::string save(const std::string&) = 0;
	virtual void update(GLfloat) = 0;
	virtual void draw() = 0;

protected:
	std::vector<std::vector<gl::Animation>> animations;
	gl::Animation* currentAnimation;
	void (*currentAction)(float);
	std::string name;
	gl::Vec2f position;
	Direction direction;
	int maxHealth, health, attack, defense;
	float speed;

	static gl::Vec2f getDirectionVec(Direction);
	virtual void move(float);
	virtual bool isColision() = 0;
};

typedef std::unique_ptr<Character> chrPtr;
#endif // !CHARACTER_H