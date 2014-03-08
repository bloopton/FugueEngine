#ifndef WORLD_H
#define WORLD_H

#include <OOGL\oogl.hpp>
#include <memory>
#include "Segment.hpp"

class World
{
public:
	static const int size = 50;

	World();
	World(const std::string&);  

	void save();
	void update(float);
	void draw();
	
	bool testCollsion(const gl::Rectangle&);

private:
	std::vector<std::vector<segPtr>> worldMap;
};
#endif // !WORLD
