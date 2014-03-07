#include <FugueEngine\Character.hpp>
#include <FugueEngine\Player.hpp>
#include <FugueEngine\Segment.hpp>


chrPtr Character::load(const std::string& file)
{
	chrPtr loadedChr;
	std::string type(file.end() - 4, file.end());

	if(type.compare(".plr") == 0)
	{
		loadedChr.reset(new Player("saves/" + file));
	}

	return loadedChr;
}


gl::Vec2f Character::getDirectionVec(Direction dir)
{
	switch (dir)
	{
	case Character::UP:
		return gl::Vec2f(0,1);
		break;
	case Character::DOWN:
		return gl::Vec2f(0, -1);
		break;
	case Character::RIGHT:
		return gl::Vec2f(1, 0);
		break;
	case Character::LEFT:
		return gl::Vec2f(-1, 0);
		break;
	}
}


void Character::move(float deltaTime)
{
	position += speed * deltaTime * getDirectionVec(direction);
}