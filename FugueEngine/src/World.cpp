#include<FugueEngine\World.hpp>


World::World() {}

World::World(const std::string& saveFile)
{
	worldMap.resize(size);
	for(auto& i : worldMap)
		i.resize(size);

	worldMap[0][0].reset(new Segment(saveFile, "resources/segments/0 0"));
}


void World::update(float deltaTime)
{
	for(std::vector<segPtr>& v : worldMap)
		for(segPtr& p : v)
			if(p != NULL)
				p->update(deltaTime);
}


void World::draw()
{
	for(std::vector<segPtr>& v : worldMap)
		for(segPtr& p : v)
			if(p != NULL)
				p->draw();
}