#include <FugueEngine\Segment.h>
#include <iostream>
#include <fstream>

Segment::Segment() {}


Segment::Segment(const oogl::Texture& baseT, const oogl::Texture& alphaT, const char* fileLocation)
	: baseImg(oogl::Model(oogl::Vec2<GLfloat>(0, 0), scale), baseT), 
	  alphaImg(oogl::Model(oogl::Vec2<GLfloat>(0, 0), scale), alphaT)
{
	std::ifstream collisionFile(fileLocation);

	for(int i = 0; i < tiles; i++)
		for(int j = 0; j < tiles; j++)
		{
			if(collisionFile.get() == '0')
				map[i][j].solid = false;
			else
				map[i][j].solid = true;

			map[i][j].position = oogl::Vec2<int>(i, j);
		}

		collisionFile.close();
}


void Segment::draw()
{
	baseImg.draw();
	//draw characters
	alphaImg.draw();
}