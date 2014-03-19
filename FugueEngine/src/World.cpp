#include <FugueEngine\World.hpp>
#include <FugueEngine\Character.hpp>
#include <FugueEngine\Player.hpp>
#include <FugueEngine\Behaviors.hpp>
#include <iostream>
#include <fstream>
#include <math.h>

const float World::tileSize = (float)scale/(float)tiles;
World* World::currentWorld = NULL;

World::World() {}

World::World(const std::string& save)
	: saveFile(save)
{
	currentWorld = this;
	segMap.resize(size);
	for(auto& i : segMap)
		i.resize(size);

	segMap[0][0].reset(new Segment(gl::Vec2u(0, 0)));
	segMap[1][0].reset(new Segment(gl::Vec2u(1, 0)));
	loadSegInfo(gl::Vec2u(0, 0));
	loadSegInfo(gl::Vec2u(1, 0));

	loadGameObjects();
}


void World::loadGameObjects()
{
	std::ifstream stream(saveFile);
	bool loading = true;
	while(loading == true)
	{
		objPtr newObj = NULL;
		std::string type; stream >> type;
		if(type.compare("Player") == 0) newObj = Player::load(stream);

		if(newObj == NULL) loading = false;
		else gameObjects.push_back(std::move(newObj));
	}
	stream.close();
}


void World::loadSegInfo(const gl::Vec2u& index)
{
	std::string file("resources/segments/" + std::to_string(index.x) + " " + std::to_string(index.x) + "/collisions.txt");
	std::ifstream fileStream(file);

	int segY = tiles * index.y;
	int segX = tiles * index.x;
	for(int y = tiles + segY - 1;  y >= segY; y--)
		for(int x = segX; x < tiles + segX; x++)
		{
			if(fileStream.get() == '0')
				tileMap[x][y].solid = false;
			else
				tileMap[x][y].solid = true;
		}
		fileStream.close();
}


void World::save()
{
	std::ofstream saveStream(saveFile);
	for(auto& c : gameObjects)
	{
		Loadable* l = dynamic_cast<Loadable*>(c.get());
		if(l) l->save(saveStream);
	}
	saveStream.close();
}


void World::update(float deltaTime)
{
	for(objPtr& c : gameObjects) 
		c->update(deltaTime);
}


void World::draw()
{
	for(auto& v : segMap)
		for(auto& p : v)
			if(p != NULL)
				p->drawBase();

	for(objPtr& c : gameObjects)
		c->draw();

	for(auto& v : segMap)
		for(auto& p : v)
			if(p != NULL)
				p->drawTop();
}


bool World::testCollsion(const gl::VertexArray& rect)
{    
	std::vector<gl::Vec2u> tiles;
	int xMax = int((rect.getPoint().x + rect.getSize().x / 2.0f) / tileSize);
	int xMin = int((rect.getPoint().x - rect.getSize().x / 2.0f) / tileSize);
	int yMax = int((rect.getPoint().y + rect.getSize().y / 2.0f) / tileSize);
	int yMin = int((rect.getPoint().y - rect.getSize().y / 2.0f) / tileSize);

	for(int x = xMin; x <= xMax; x++)
		for(int y = yMin; y <= yMax; y++)
			tiles.push_back(gl::Vec2u(x, y));

	for(gl::Vec2u& v : tiles)
		if(World::currentWorld->tileMap[v.x][v.y].solid)
			return true;

	return false;
}