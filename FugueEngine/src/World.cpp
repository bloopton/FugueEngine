#include<FugueEngine\World.hpp>

World::World() {}

World::World(std::vector<std::vector<Segment>> segMap)
	: worldMap(segMap)
{
	for(int x = 0; x < worldMap.size(); x++)
		for(int y = 0; y < worldMap[x].size(); y++)
			worldMap[x][y].setPosition(oogl::Vec2i(x, y));
}


void World::update(float deltaTime)
{
	for(int x = 0; x < worldMap.size(); x++)
		for(int y = 0; y < worldMap[x].size(); y++)
			worldMap[x][y].update(deltaTime);
}


void World::draw()
{
	for(int x = 0; x < worldMap.size(); x++)
		for(int y = 0; y < worldMap[x].size(); y++)
			worldMap[x][y].draw();
}