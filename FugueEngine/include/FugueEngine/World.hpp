#ifndef WORLD_H
#define WORLD_H

#include <OOGL\oogl.hpp>
#include <memory>
#include "Character.hpp"
#include "Segment.hpp"

class World
{
public:
	static const int size = 50;

	World();
	World(std::vector<std::unique_ptr<Segment>>); 

	void update(float);
	void draw();

private:
	std::unique_ptr<Segment> worldMap[size][size];
};
#endif // !WORLD
