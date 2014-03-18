#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <FugueEngine/Character.hpp>
#include <SFML\Window.hpp>
#include <fstream>

class Player : public Character
{
public:
	static void loadReferences();
	static void releaseReferences();

	Player();
	Player(std::ifstream&);
	virtual void load(std::ifstream&);
	virtual void save(std::ofstream&);
	virtual void update(float);

	virtual void setAnimations();
};
#endif