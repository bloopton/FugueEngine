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
	World(const std::string&);  

	void update(float);
	void draw();

private:
	std::vector<std::vector<segPtr>> worldMap;
};
#endif // !WORLD
