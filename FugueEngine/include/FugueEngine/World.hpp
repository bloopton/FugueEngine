#ifndef WORLD_HPP
#define WORLD_HPP

#include <OOGL\oogl.hpp>
#include "GameObject.hpp"
#include "Segment.hpp"
#include <memory>

class World
{
public:
	struct tile
	{
		bool solid;
	};
	static const int tiles = 512;
	static const int scale = 12;
	static const int size = 2;
	static const float tileSize;
	  
	World();
	World(const std::string&);  
	void update(float);
	void draw();
	void save();

	static bool testCollsion(const gl::VertexArray&);

private:
	static World* currentWorld;

	tile tileMap[tiles * 2][tiles];
	std::vector<std::vector<segPtr>> segMap;
	std::vector<objPtr> gameObjects;
	std::string saveFile;

	void loadGameObjects();
	void loadSegInfo(const gl::Vec2u&);
};
#endif // !WORLD
