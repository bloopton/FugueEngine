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
		enum direction;
	

private:

	oogl::Vec2 pos;
	bool moving;
	bool living;



	int level;
	int health;
	int maxHealth;
	int concentration;
	int maxConcentration;
	int strength;
	int defense;
	int speed;
	int exp;
	int maxExp;

	void attack();
	void track();
	void levelUp();


}
#endif // !CHARACTER_H