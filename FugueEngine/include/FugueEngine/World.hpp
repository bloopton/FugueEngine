#ifndef WORLD_H
#define WORLD_H

#include <OOGL\oogl.hpp>
#include "Character.hpp"
#include "Segment.hpp"
#include <memory>

class World
{
public:
	struct tile
	{
		bool solid;
	};
	static const float tileSize;
	static const int tiles = 512;
	static const int scale = 12;
	static const int size = 2;


	World();
	World(const std::string&);  

	void save();
	void update(float);
	void draw();
	
	bool testCollsion(const gl::Rectangle&);

private:
	tile tileMap[tiles * 2][tiles];
	std::vector<std::vector<segPtr>> segMap;
	std::vector<chrPtr> characters;

	std::string saveFile;

	void loadSegInfo(const gl::Vec2u&);
};
#endif // !WORLD
