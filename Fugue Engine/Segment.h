#ifndef SEGMENT_H
#define SEGMENT_H

#include <Libraries\OOGL\include\oogl.hpp>

class Segment
{
public:
		Segment();
		Segment(oogl::Texture, const char*);

private:
		const int size = 128;
		Entity mapImg;
		struct tile
		{
			bool solid;
			oogl::Vec2 position;
		};

		tile map[size][size];

}
#endif


