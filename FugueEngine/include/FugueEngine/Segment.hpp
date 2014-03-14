#ifndef SEGMENT_HPP
#define SEGMENT_HPP

#include <OOGL\oogl.hpp>
#include <string>
#include <memory>

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