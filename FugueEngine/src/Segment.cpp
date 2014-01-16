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


void Segment::setPosition(const oogl::Vec2<int>& index)
{
	oogl::Vec2<GLfloat> pos(scale * index.x, scale * index.y);
	pos += (float)scale / 2.0f;

	baseImg.setPosition(pos);
	alphaImg.setPosition(pos);
}


void Segment::addCharacter(Character& character)
{
	character.seg = this;
	characters.push_back(&character);
}


bool Segment::isTileSolid(const oogl::Vec2<int>& pos)
{
	return map[pos.x][pos.y].solid;
}


void Segment::update(float deltaTime)
{
	for(int i = 0; i < characters.size(); i++)
		characters[i]->update(deltaTime);
}


void Segment::draw()
{
	baseImg.draw();
	
	for(int i = 0; i < characters.size(); i++)
		characters[i]->draw();

	alphaImg.draw();
}