#ifndef SEGMENT_H
#define SEGMENT_H

#include <OOGL\oogl.hpp>

class Segment : public oogl::Entity
{
public:
		Segment();
		Segment(const oogl::Texture&, const char*);

private:
		static const int tiles = 128;
		static const int scale = 20;

		struct tile
		{
			bool solid;
			oogl::Vec2<int> position;
		};

		tile map[tiles][tiles];
};
#endif