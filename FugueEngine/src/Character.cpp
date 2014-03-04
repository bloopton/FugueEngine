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