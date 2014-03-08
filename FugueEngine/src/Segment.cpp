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

	fileStream.open(save);
	std::vector<std::string> chrSaves;
	while(fileStream.eof() == false)
	{
		std::string line;
		std::getline(fileStream, line);
		chrSaves.push_back(line);
	}
	fileStream.close();

	for(std::string s : chrSaves)
		characters.push_back(Character::load(s));
}


void Segment::save()
{
	std::vector<std::string> chrSaves;
	int count = 0;
	for(chrPtr& p : characters)
	{
		chrSaves.push_back(p->save(saveFile + std::to_string(count)));
		count++;
	}

	std::ofstream saveStream(saveFile);
	saveStream.clear();
	for(int i = 0; i < count; i++)
	{
		saveStream << chrSaves[i];
		if(i < count - 1)
			saveStream << std::endl;
	}
}


bool Segment::getTileInfo(const gl::Vec2u& tilePos)
{
	if(map[tilePos.x][tilePos.y].solid)
		return true;
	else
		return false;
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