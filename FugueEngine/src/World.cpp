#include <FugueEngine\World.hpp>
#include <iostream>
#include <fstream>
#include <math.h>

const float World::tileSize = (float)scale/(float)tiles;

World::World() {}

World::World(const std::string& save)
	: saveFile(save)
{
	Character::worldRef = this;
	segMap.resize(size);
	for(auto& i : segMap)
		i.resize(size);

	segMap[0][0].reset(new Segment(gl::Vec2u(0, 0)));
	segMap[1][0].reset(new Segment(gl::Vec2u(1, 0)));
	loadSegInfo(gl::Vec2u(0, 0));
	loadSegInfo(gl::Vec2u(1, 0));


	std::ifstream fileStream(save);
	std::vector<std::string> chrSaves;
	while(fileStream.eof() == false)
	{
		std::string line;
		std::getline(fileStream, line);

		if(line.compare("") != 0)
			chrSaves.push_back(line);
	}
	fileStream.close();

	for(std::string s : chrSaves)
		characters.push_back(Character::load(s));
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
	std::vector<std::string> chrSaves;
	int count = 0;
	for(chrPtr& p : characters)
	{
		chrSaves.push_back(p->save(saveFile + std::to_string(count)));
		count++;
	}

	std::ofstream saveStream(saveFile);
	saveStream.clear();
	for(int i = 0; i < count; i++)
	{
		saveStream << chrSaves[i];
		if(i < count - 1)
			saveStream << std::endl;
	}
	saveStream.close();
}


void World::update(float deltaTime)
{
	for(chrPtr& c : characters)
		c->update(deltaTime);
}


void World::draw()
{
	for(auto& v : segMap)
		for(auto& p : v)
			if(p != NULL)
				p->drawBase();

	for(chrPtr& c : characters)
		c->draw();


	for(auto& v : segMap)
		for(auto& p : v)
			if(p != NULL)
				p->drawTop();
}


bool World::testCollsion(const gl::Rectangle& rect)
{    
	std::vector<gl::Vec2u> tiles;
	int xMax = int((rect.position.x + rect.scale.x / 2.0f) / tileSize);
	int xMin = int((rect.position.x - rect.scale.x / 2.0f) / tileSize);
	int yMax = int((rect.position.y + rect.scale.y / 2.0f) / tileSize);
	int yMin = int((rect.position.y - rect.scale.y / 2.0f) / tileSize);

	for(int x = xMin; x <= xMax; x++)
		for(int y = yMin; y <= yMax; y++)
			tiles.push_back(gl::Vec2u(x, y));

	for(gl::Vec2u& v : tiles)
		if(tileMap[v.x][v.y].solid)
			return true;

	return false;
}