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

	virtual void update(GLfloat);
	void draw();

protected:
	float speed;

	Direction direction;
	Action action;

	oogl::Vec2<int> currentSeg, currentTile;
	oogl::Vec2<GLfloat> tilePos, position;

	std::vector<std::vector<oogl::Animation>> animations;
		
	void move(float);
};
#endif // !CHARACTER_H