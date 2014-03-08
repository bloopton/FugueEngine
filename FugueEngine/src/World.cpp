#include <FugueEngine\World.hpp>
#include <iostream>
#include <math.h>


World::World() {}

World::World(const std::string& saveFile)
{
	worldMap.resize(size);
	for(auto& i : worldMap)
		i.resize(size);

	worldMap[0][0].reset(new Segment(saveFile + "0-0", "resources/segments/0 0"));
}


void World::save()
{
	worldMap[0][0]->save();
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


bool World::testCollsion(const gl::Rectangle& rect)
{
	std::vector<gl::Vec2u> tiles;
	
	int xMax = (rect.position.x + rect.scale.x / 2.0f) / Segment::tileSize;
	int xMin = (rect.position.x - rect.scale.x / 2.0f) / Segment::tileSize;
	int yMax = (rect.position.y + rect.scale.y / 2.0f) / Segment::tileSize;
	int yMin = (rect.position.y - rect.scale.y / 2.0f) / Segment::tileSize;

	for(int x = xMin; x <= xMax; x++)
		for(int y = yMin; y <= yMax; y++)
			tiles.push_back(gl::Vec2u(x, y));

	for(gl::Vec2u& v : tiles)
	{
		int xSeg = v.x / Segment::tiles;
		v.x -= xSeg * Segment::tiles;
		int ySeg = v.y / Segment::tiles;
		v.y -= ySeg * Segment::tiles;

		if(worldMap[xSeg][ySeg]->getTileInfo(v))
			return true;
	}
	return false;
}