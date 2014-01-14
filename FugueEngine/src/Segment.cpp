#include <FugueEngine\Segment.hpp>
#include <iostream>
#include <fstream>

const float Segment::tileSize = (float)scale/(float)tiles;

Segment::Segment() {}

Segment::Segment(const oogl::Texture& baseT, const oogl::Texture& alphaT, const char* fileLocation)
	: baseImg(oogl::Model(oogl::Vec2<GLfloat>(0, 0), scale), baseT), 
	  alphaImg(oogl::Model(oogl::Vec2<GLfloat>(0, 0), scale), alphaT),
	  characters()
{
	std::ifstream collisionFile(fileLocation);

	for(int x = 0; x < tiles; x++)
		for(int y = 0; y < tiles; y++)
		{
			if(collisionFile.get() == '0')
				map[x][y].solid = false;
			else
				map[x][y].solid = true;

			map[x][y].position = oogl::Vec2<int>(x, y);
		}

		collisionFile.close();
}


void Segment::setPosition(const oogl::Vec2<int>& index)
{
	oogl::Vec2<GLfloat> pos(scale * index.x, scale * index.y);
	pos += (float)scale / 2.0f;

	baseImg.setPosition(pos);
	alphaImg.setPosition(pos);
}


void Segment::update(float deltaTime)
{
	for(int i = 0; i < characters.size(); i++)
		characters[i].update(deltaTime);
}


void Segment::draw()
{
	baseImg.draw();
	
	for(int i = 0; i < characters.size(); i++)
		characters[i].draw();

	alphaImg.draw();
}