#ifndef CHARACTER_H
#define CHARACTER_H

#include <OOGL/oogl.hpp>
#include <string>


enum Direction 
{
	FRONT = 0,
	BACK,
	RIGHT,
	LEFT	
};



class Character
{
public:
	Character();
	Character(const Character&);
	Character(std::string);

	Character& operator=(const Character&);

	virtual void update(GLfloat) = 0;
	virtual void draw() = 0;

	static void loadTextures();

protected:
	static std::vector<std::vector< gl::Texture>> textures;
	std::vector<std::vector<gl::Animation>> animations;


	void (*behavior)(float);
	Direction direction;
	std::string name;

	int maxHealth,
		health,
		attack,
		defense;

	float speed;


	virtual void defaultBehavior(float) = 0;
	virtual void flee(float) = 0;
	virtual void fight(float) = 0;


	virtual void move(float) = 0;

};
#endif // !CHARACTER_H