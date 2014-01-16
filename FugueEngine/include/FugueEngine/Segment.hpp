#ifndef SEGMENT_H
#define SEGMENT_H

#include <OOGL\oogl.hpp>
#include "Character.hpp"
#include "Player.hpp"

class Segment
{
public:

	Segment();
	Segment(const oogl::Texture&, const oogl::Texture&, const char*);
	void setPosition(const oogl::Vec2<int>&);
	void addCharacter(Character&);
	bool isTileSolid(const oogl::Vec2<int>&);
	void update(float);
	void draw();

	static const int tiles = 64;
	static const int scale = 12;
	static const float tileSize;

private:
	oogl::Entity baseImg;
	oogl::Entity alphaImg;


	struct tile
	{
		bool solid;
	};

	tile map[tiles][tiles];
	std::vector<Character*> characters;
};
#endif