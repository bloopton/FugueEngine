#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Walk.hpp"
#include <SFML\Window.hpp>
#include <fstream>

class Player : public Walk
{
public:
	static void loadReferences();
	static void releaseReferences();

	Player();
	Player(std::ifstream&);
	virtual void save(std::ofstream&);
	virtual void update(float);
	virtual void draw() const;

protected:
	virtual bool isColision();
};
#endif