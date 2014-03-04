#ifndef CHARACTER_H
#define CHARACTER_H

#include <OOGL/oogl.hpp>
#include <memory>
#include <string>


class Character
{
public:
	enum Direction 
	{
		FRONT = 0,
		BACK,
		RIGHT,
		LEFT	
	};

	static std::unique_ptr<Character> load(const std::string&);

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

	virtual void move(float) = 0;
};

typedef std::unique_ptr<Character> chrPtr;

#endif // !CHARACTER_H