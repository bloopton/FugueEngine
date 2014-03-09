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
	const std::string folder;

	Segment();
	Segment(const gl::Vec2u&);
	void drawBase();
	void drawTop();

private:
	const std::string saveFile;
	gl::Entity baseImg, topImg;
};

typedef std::unique_ptr<Segment> segPtr;
#endif