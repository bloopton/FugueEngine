#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Person.hpp"
#include <SFML\Window.hpp>
#include <fstream>

class Player : public Person
{
public:
	static void loadReferences();
	static void releaseReferences();

	Player();
	Player(std::ifstream&);
	virtual void save(std::ofstream&);
	virtual void update(GLfloat);
	virtual void draw();

protected:
	static std::vector<std::vector<gl::Animation>> refrences;
	virtual bool isColision();
};
#endif