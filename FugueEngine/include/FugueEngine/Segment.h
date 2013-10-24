#ifndef SEGMENT_H
#define SEGMENT_H

#include <OOGL\oogl.hpp>

class Segment
{
public:
		Segment();
		Segment(oogl::Texture, const char*);

private:
		static const int size = 128;
		oogl::Entity mapImg;
		struct tile
		{
			bool solid;
			oogl::Vec2 position;
		};

		tile map[size][size];

};
#endif


