#ifndef PLAYER_H
#define PLAYER_H

#include "Character.hpp"
#include <SFML\System.hpp>
#include <SFML\Window.hpp>
#include <SFML\Audio.hpp>

class Player : public Character
{
public:
	Player();
	Player(const std::string&);

	std::string save(const std::string&);
	void update(GLfloat);
	void draw();

	static void loadReferences();
	static void releaseReferences();

protected:
	static std::vector<std::vector< gl::Animation>> refrences;
	static gl::Rectangle bounds, wcBoundsY, wcBoundsX;

	bool isColision();
};
#endif