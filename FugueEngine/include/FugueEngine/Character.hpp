#ifndef CHARACTER_H
#define CHARACTER_H

#include <OOGL/oogl.hpp>
#include <string>

class Segment;

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

	enum Action
	{
		STAND = 0,
		WALK
	};

	Segment* seg;

	Character();
	Character(const Character&);
	Character(std::string);

	virtual void update(GLfloat) = 0;
	void draw();

protected:
	std::string name;
	int maxHealth;
	int health;
	int attack;
	int defense;
	float speed;

	Direction direction;
	Action action;

	oogl::Vec2<int> 
		currentSeg,
		leftTile,
		rightTile;

	oogl::Vec2<GLfloat> 
		tilePosLeft, 
		tilePosRight, 
		position;

	std::vector<std::vector<oogl::Animation>> animations;
		
	virtual void move(float);
};
#endif // !CHARACTER_H