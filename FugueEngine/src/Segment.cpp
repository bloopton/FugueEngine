#include <FugueEngine\Segment.hpp>
#include <FugueEngine\World.hpp>
#include <fstream>
#include <iostream>

namespace
{
	gl::Vec2f gridPosition(const gl::Vec2u& index)
	{
		gl::Vec2f pos = gl::Vec2f(World::scale * index.x, World::scale * index.y);
		pos += float(World::scale) / 2.0f;
		return pos;
	}
}

Segment::Segment() {}

Segment::Segment(const gl::Vec2u& index)
	: folder("resources/segments/" + std::to_string(index.x) + " " + std::to_string(index.x)),
	baseImg(gl::Rectangle(gridPosition(index), World::scale), gl::Texture(folder + "/base.png")),
	topImg(gl::Rectangle(gridPosition(index), World::scale), gl::Texture(folder + "/top.png")) {}


void Segment::drawBase()
{
	baseImg.draw();
}

void Segment::drawTop()
{
	topImg.draw();
}