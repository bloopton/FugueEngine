#ifndef WORLD_H
#define WORLD_H

#include <OOGL\oogl.hpp>
#include "Segment.h"
#include "Character.h"

class World
{
public:
	World();
	World(std::vector<std::vector<Segment>>, std::vector<Character>, Character); 

	void draw();

private:
	Character player;
	std::vector<std::vector<Segment>> worldMap;
	std::vector<Character> NPCS;

};
#endif // !WORLD
