#ifndef SEGMENT_H
#define SEGMENT_H

#include <OOGL\oogl.hpp>
#include <FugueEngine\Character.h>

class Segment
{
public:
		Segment();
		Segment(const oogl::Texture&, const oogl::Texture&, const char*);
		void draw();

private:
		oogl::Entity baseImg;
		oogl::Entity alphaImg;

		std::vector<Character> characters;

		static const int tiles = 64;
		static const int scale = 20;

		struct tile
		{
			bool solid;
			oogl::Vec2<int> position;
		};

		tile map[tiles][tiles];
};
#endif