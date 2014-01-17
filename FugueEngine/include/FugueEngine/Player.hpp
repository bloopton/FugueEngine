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
	Player(const Player&);
	Player(std::string);

	void update(float);

protected:

	sf::Sound walkSound;
};
#endif