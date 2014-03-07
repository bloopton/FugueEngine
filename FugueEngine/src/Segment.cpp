#include <FugueEngine\Segment.hpp>
#include <sstream>
#include <fstream>

const float Segment::tileSize = (float)scale/(float)tiles;

namespace
{
	gl::Vec2f gridPosition(const std::string& folderName)
	{
		std::stringstream ss(folderName);
		gl::Vec2f gridIndex;
		ss >> gridIndex.x;
		ss >> gridIndex.y;

		gl::Vec2f pos = gl::Vec2f(Segment::scale * gridIndex.x, Segment::scale * gridIndex.y);
		pos += float(Segment::scale) / 2.0f;
		return pos;
	}
}

Segment::Segment() {}

Segment::Segment(const std::string& save, const std::string& folder)
	: baseImg(gl::Rectangle(gridPosition(folder), scale), gl::Texture(folder + "/base.png")),
	  topImg(gl::Rectangle(gridPosition(folder), scale), gl::Texture(folder + "/top.png")),
	  characters(0), saveFile(save)
{
	std::ifstream fileStream(folder + "/collisions.txt");
	for(int y = tiles - 1; y >= 0; y--)
		for(int x = 0; x < tiles; x++)
		{
			if(fileStream.get() == '0')
				map[x][y].solid = false;
			else
				map[x][y].solid = true;
		}
	fileStream.close();


	std::vector<std::string> chrSaves;
	fileStream.open(save);
	while(fileStream.eof() == false)
	{
		std::string line;
		std::getline(fileStream, line);
		chrSaves.push_back(line);
	}

	for(std::string s : chrSaves)
		characters.push_back(Character::load(s));
}


void Segment::save()
{
	std::vector<std::string> chrSaves;

	for(auto& p : characters)
		chrSaves
}


void Segment::update(float deltaTime)
{
	for(chrPtr& c : characters)
		c->update(deltaTime);
}
void Segment::draw()
{
	baseImg.draw();
	
	for(chrPtr& c : characters)
		c->draw();

	topImg.draw();
}