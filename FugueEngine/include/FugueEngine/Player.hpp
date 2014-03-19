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
	static objPtr load(std::ifstream&);
	virtual void save(std::ofstream&) const;
	virtual void update(float);

	virtual void setAnimations();
};
#endif