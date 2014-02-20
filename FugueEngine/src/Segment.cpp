#include <FugueEngine\Segment.hpp>
#include <iostream>
#include <fstream>

const float Segment::tileSize = (float)scale/(float)tiles;

namespace
{
	gl::Vec2f gridPosition(const gl::Vec2u& gridIndex)
	{
		gl::Vec2f pos = gl::Vec2f(Segment::scale * gridIndex.x, Segment::scale * gridIndex.y);
		pos += float(Segment::scale) / 2.0f;
		return pos;
	}
}

Segment::Segment() {}

Segment::Segment(const gl::Texture& baseT, const gl::Texture& alphaT, const std::string& fileLocation, const gl::Vec2u& inGridIndex)
	: baseImg(gl::Rectangle(gridPosition(inGridIndex), scale), baseT), 
	  alphaImg(gl::Rectangle(gridPosition(inGridIndex), scale), alphaT),
	  gridIndex(inGridIndex)
{
	std::ifstream collisionFile(fileLocation);

	for(int y = tiles - 1; y >= 0; y--)
		for(int x = 0; x < tiles; x++)
		{
			if(collisionFile.get() == '0')
				map[x][y].solid = false;
			else
				map[x][y].solid = true;
		}

	collisionFile.close();
}


const gl::Vec2u& Segment::getGridIndex()
{
	return gridIndex;
}


void Segment::update(float deltaTime)
{
	for(int i = 0; i < characters.size(); i++)
	{
		if(characters[i] == NULL)
			characters.erase(characters.begin() + i);

		characters[i]->update(deltaTime);
	}
}


void Segment::draw()
{
	baseImg.draw();
	
	for(int i = 0; i < characters.size(); i++)
		characters[i]->draw();

	alphaImg.draw();
}