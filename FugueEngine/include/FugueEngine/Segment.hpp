#ifndef SEGMENT_H
#define SEGMENT_H

#include <OOGL\oogl.hpp>
#include <string>
#include <memory>
#include "Character.hpp"
#include "Player.hpp"

class Segment
{
public:
	static const int tiles = 512;
	static const int scale = 12;
	static const float tileSize;

	Segment();
	Segment(const gl::Texture&, const gl::Texture&, const std::string&, const gl::Vec2u&);

	const gl::Vec2u& getGridIndex();


	void update(float);
	void draw();

private:
	gl::Vec2u gridIndex;
	gl::Entity baseImg, alphaImg;

	struct tile
	{
		bool solid;
	};

	tile map[tiles][tiles];
	std::vector<std::unique_ptr<Character>> characters;
};
#endif