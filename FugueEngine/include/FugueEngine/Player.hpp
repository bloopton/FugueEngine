#ifndef PLAYER_H
#define PLAYER_H

#include "Character.hpp"

class Player : public Character
{
public:
	Player();
	Player(const Player&);
	Player(const char*);

	void update(float);
};
#endif