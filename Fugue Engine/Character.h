#ifndef CHARACTER_H
#define CHARACTER_H
#include<Libraries\OOGL\\include\oogl.hpp>

enum direction 
{
	UP,
	DOWN,
	LEFT,
	RIGHT
};

class Character
{
public:
	
	

private:

	oogl::Vec2 pos;
	bool moving;

	int level;
	int health;
	int maxHealth;
	int concentration;
	int maxConcentration;
	int attack;
	int defense;
	int speed;
	int exp;
	int maxExp;

	attack();
	track();
	levelUp();


}
#endif // !CHARACTER_H