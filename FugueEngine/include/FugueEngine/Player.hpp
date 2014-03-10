#ifndef PLAYER_H
#define PLAYER_H

#include "Character.hpp"
#include <fstream>
#include <SFML\System.hpp>
#include <SFML\Window.hpp>
#include <SFML\Audio.hpp>

class Player : public Character
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
	static std::vector<std::vector< gl::Animation>> refrences;
	static gl::Rectangle bounds, wcBoundsY, wcBoundsX;

	virtual bool isColision();
	void stand();
	void walk(float, Direction);
};
#endif