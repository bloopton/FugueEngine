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
	struct tile
	{
		bool solid;
	};

	static const int tiles = 512;
	static const int scale = 12;
	static const float tileSize;

	Segment();
	Segment(const std::string&, const std::string&);

	void draw();
	void update(float);
	void save();

private:
	gl::Entity baseImg, topImg;
	tile map[tiles][tiles];
	std::vector<chrPtr> characters;
};

typedef std::unique_ptr<Segment> segPtr;

#endif