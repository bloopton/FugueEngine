#include<FugueEngine\Segment.h>

Segment::Segment()
{

}


Segment::Segment(oogl::Texture tex, const char*)
	: mapImg(oogl::Model(oogl::Vec2(0,0), 1), tex, oogl::NORMAL) 
{

}


