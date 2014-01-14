#ifndef WORLD_H
#define WORLD_H

#include <OOGL\oogl.hpp>
#include "Character.hpp"
#include "Segment.hpp"

class World
{
public:
	World();
	World(std::vector<std::vector<Segment>>); 

	void update(float);
	void draw();

private:
	std::vector<std::vector<Segment>> worldMap;
};
#endif // !WORLD
