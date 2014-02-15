#include<FugueEngine\World.hpp>

World::World() {}

World::World(std::vector<std::unique_ptr<Segment>> segments)
{
	for(int i = 0; i < segments.size(); i++)
	{
		gl::Vec2u index = segments[i]->getGridIndex();
		worldMap[index.x][index.y] = std::move(segments[i]);
	}
}


void World::update(float deltaTime)
{
	for(int x = 0; x < size; x++)
		for(int y = 0; y < size; y++)
			worldMap[x][y]->update(deltaTime);
}


void World::draw()
{
	for(int x = 0; x < size; x++)
		for(int y = 0; y < size; y++)
			worldMap[x][y]->draw();
}