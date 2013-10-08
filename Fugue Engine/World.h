#ifndef WORLD_H
#define WORLD_H

#include <Libraries\OOGL\include\oogl.hpp>
#include "Segment.h"
#include "Character.h"

class World
{
public:
	World();
	World(std::vector<std::vector<Segment>>, 
	Movement();

private:
	Character player;
	std::vector<std::vector<Segment>> worldMap;
	std::vector<Character> NPCS;

}


#endif // !WORLD
